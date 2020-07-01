# C_Lib
C Library to simplify use multiple things

## Description
This library is composed of multiples mudules that i build when i need them. Each of the module is independent (except if the opposite isn't say in it's part) and has it's own git branch.



# Log
This Module allow you to easily create lots of differents types of logs in both terminal **and**/**or** file depending of you needs

## Usage
All you need to do is create a new logger by calling ``create_logger`` function at the beginning of your program.
Once this is done, you can call ``log_msg`` like shown in this example : 
```C
int main(void)
{
    logger_t logger = create_logger(true, true, NULL, false); // See doxygen doc for more informations 

    log_message(logger, <Type of log>, asprinf(&logger->msg, "Your Log Message Here"));
    /* OR */
    logger->msg = strdup("Your Log Message Here");
    log_message(logger, <Type of log>, strlen(logger->msg));
    // Do not free logger->msg. it is free when needed

    free_logger(logger);
    return (0);
}
```
To see a full detailed list of available type of logs and how they can be combined, see [Log_README]([ReadMe_Logger])

Here is all outputs you can have :
![][Logger_Gif]

[ReadMe_Logger]: ./Docs/README_logger.md
[Logger_Gif]: https://s7.gifyu.com/images/lib_logger.gif

# Epitech Students
You are free to use this library as you want. A special branch has been created in which the [Epitech][Epitech_WebSite] [Coding Style][Epitech_WebSite] will be respected. I don't hav time to check new [Coding Style][Epitech_CodingStyle] every years. If you find a norm error, please fix it and send a ``pull request`` or, if you can't figure how to fix it, message me with the **file(s)**, **line(s)**  and **type(s)** of error(s).  

## Disclaimer
Warning. Some modules use standard library functions such as ``malloc`` or ``printf`` make sure these functions are allowed for your project. All functions used in each Module are available in the ``README`` of the module.   
I'm **not** responsible if you get flag for cheat beacause you use this library. You can use it but it will be at your own risks.

[Epitech_WebSite]: https://www.epitech.eu "Epitech Website"
[Epitech_CodingStyle]: https://intra.epitech.eu/file/public/technical-documentations/epitech_c_coding_style.pdf "Epitech Coding Style File"