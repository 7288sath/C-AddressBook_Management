#include <stdio.h>
#include "contact.h"

//Implementation of my own function to calculate string length
int my_strlen(const char *string)
{
    int i=0;
    while(string[i] != '\0')
    {
        i++;
    }
    return i;
}

//Implementation of my own function to compare two strings 
int my_strcmp(const char *str1, const char *str2)
{
    int i=0;

    while(str1[i] && str2[i])
    {
        if(str1[i] != str2[i])
        {
            if(((str1[i] >= 'A' && str1[i] <= 'Z') && ((str1[i] + 32) == str2[i])) ||
                ((str2[i] >= 'A' && str2[i] <= 'Z') && ((str2[i] + 32) == str1[i])))
            {
                i++;
                continue;
            }
            break;
        }
        i++;
    }

    char a = str1[i];
    char b = str2[i];

    if (a >= 'A' && a <= 'Z') a = a + 32;
    if (b >= 'A' && b <= 'Z') b = b + 32;

    return a - b;
}

//Implementation of my own function to copy string

void my_strcpy(char *dest, const char *src)
{
    int i=0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//Implementation of my own function for sub string 

char *my_strstr(const char *str1, const char *str2)
{
    int i = 0, j= 0;

    if(str2[j] == '\0')
    {
        return (char *)str1;
    }

    while(str1[i] != '\0')
    {
        int j=0;
        for(j=0; str2[j] != '\0'; j++)
        {
            if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                if((str1[i] + 32) != str2[j])
                {
                    break;
                }
            }
            else if(str2[j] >= 'A' && str2[j] <= 'Z')
            {
                if((str2[j] + 32) != str1[i])
                {
                    break;
                }
            }
            else if(str1[i] != str2[j])
            {
                break;
            }
            i++;
        }
        if(str2[j] == '\0')
        {
            return (char *)&str1[i];
        }
        i++;
    }
    return NULL;
}
