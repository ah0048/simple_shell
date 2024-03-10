#include "main.h"
/**
* _exit -  exit built-in
* Return: exit status
*/
int isExit(char *value_str)
{
    int tmp = 0;

    if (!value_str)
    {
        return (0);
    }
    tmp = atoi(value_str);
    if (tmp)
    {
        if (tmp >= 0)
            return (tmp);
        return (2);
    }
    return(2);

}
