# C_Lib
C Library to simplify the use of multiple things

## Description
This library is composed of multiples modules that i build when i need them. Each of the module is independent (except if the opposite is precised) and has its own git branch.

# Linked_List
This Module allows you to easily use linked lists.

## Usage
All you need to do in order to use it is creating your structure with the library one in it like so :
```C
struct example {
    /* Your Datas */

    struct linked_list head;
    /* OR */
    linked_list_t head;
};
```

Make sure to replace ``<field_name>`` by whatever you want.  
Once this is done, call the function you need by sending :  
* A pointer to your structure (Here a ``struct example *``) when ``element``, ``list``, ``add`` or ``del`` is asked.
* The name of your field (Here ``head``) when ``field`` is asked
* An ``int`` (for exemple ``5``) just like you would do with a tab when ``idx`` is asked   

Warning, this lib DOES NOT ``free`` your structure (yet). In order to do so, here is a function you can use :
```C
void free_my_list(struct example *my_list)
{
    for (struct example *next = NULL; my_list != NULL; my_list = next) {
        next = list_next(my_list, head);

        /* Free datas that are in your structure*/

        free(my_list);
    }
    return;
}
```

# Log
This Module allows you to easily create lots of differents types of logs in both terminal **and**/**or** file depending of you needs

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

Here is all the outputs you can have :
![][Logger_Gif]

[ReadMe_Logger]: ./Docs/README_logger.md
[Logger_Gif]: https://s7.gifyu.com/images/lib_logger.gif

# Epitech Students
You are free to use this library as you want. A special branch has been created in which the [Epitech Coding Style][Epitech_WebSite] will be respected. I don't have time to check new [Coding Style][Epitech_CodingStyle] every years. If you find a norm error, please fix it and send a ``pull request`` or, if you can't figure how to fix it, message me with the **file(s)**, **line(s)**  and **type(s)** of error(s).  

## Disclaimer
Warning. Some modules use standard library functions such as ``malloc`` or ``printf`` make sure these functions are allowed for your project. All functions used in each Module are available in the ``README`` of the module.   
I'm **not** responsible if you get flaged for cheat because of the use of this library. You can use it but it will be at your own risks.

[Epitech_WebSite]: https://www.epitech.eu "Epitech Website"
[Epitech_CodingStyle]: https://intra.epitech.eu/file/public/technical-documentations/epitech_c_coding_style.pdf "Epitech Coding Style File"
