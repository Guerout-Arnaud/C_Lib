#!/bin/python3

import sys
import subprocess
import re

symbol_map = {}
print_program_output = True

def get_symbol_map(input):
    output = subprocess.Popen(["objdump", "-t", input], stdout=subprocess.PIPE)
    objdump = output.communicate()[0].decode().split("\n") 

    for line in objdump:
        tokens = line.split()
        if (len(tokens) >= 2):
            try:
                address = int(tokens[0], 16)
                if address == 0: 
                    continue
                symbol_map[address] = tokens[-1]
            except:
                continue

def rreplace(s, old, new, occurrence):
    li = s.rsplit(old, occurrence)
    return new.join(li)

def get_adress(value):
    for address in symbol_map:
        if symbol_map[address] == value:
            return (address)
    return 0

def format_program_output():
    main_regex = "^\[Performance Logger]\[Main Address\] 0x([0-9a-fA-F]+)$"

    regex = "^\[Performance Logger\].*0x([0-9a-fA-F]+).*0x([0-9a-fA-F]+).*$"
    main_offset = None

    for line in sys.stdin:
        line = rreplace(line, '\n', '', 1)

        if main_offset == None:
            match = re.search(main_regex, line)
            # print(line)
            if match :
                table = "main"
                main_offset = int(match.group(1), 16) - get_adress(table)
                # print(f"Program Addess : {int(match.group(1), 16)}, Main Address : { get_adress(table)}, Offset : {main_offset}")
            else:
                if (print_program_output == True):
                    print(line)
                continue
        else :
            match = re.search(regex, line)
            if match :
                for i in range (1, 3):
                    # print(f"Program Address = {int(match.group(i), 16)}")
                    # print(f"True Address = {int(match.group(i), 16) - main_offset}")
                    # print()

                    if ((int(match.group(i), 16) - main_offset) in symbol_map):
                        # print(f"Address = {int(match.group(i), 16)}")
                        line = line.replace("0x" + match.group(i), symbol_map[int(match.group(i), 16) - main_offset] + "(0x" + match.group(i) + ")")
                    else :
                        closest = 0
                        for symbol_addr in symbol_map:
                            if symbol_addr < (int(match.group(i), 16) - main_offset) and symbol_addr > closest: 
                                closest = symbol_addr
                        line_id = (int(match.group(i), 16) - main_offset) - closest
                        # line = line.replace("0x" + match.group(i), symbol_map[closest] + f" on line {line_id}" + "(0x" + match.group(i) + ")")
                        line = line.replace("0x" + match.group(i), symbol_map[closest] + "(0x" + match.group(i) + ")")
                print(line)
            else:
                if (print_program_output == True):
                    print(line)
        # print()
        # print("----------------")
        # print()


def main():
    if len(sys.argv) < 2:
        sys.exit(-1)

    if len(sys.argv) == 3 and sys.argv[2] == "false":
        global print_program_output
        print_program_output = False

    get_symbol_map(sys.argv[1])
    # print()
    # for key in symbol_map:
    #     print(f"{key} : {symbol_map[key]}")
    # sys.exit(0)
    # print()
    format_program_output()


if __name__ == "__main__":
    main()
    sys.exit(0)