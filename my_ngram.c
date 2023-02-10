#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_cmp(char* p1, char p2)
{
    for(int i = 0; p1[i]; i++)
    {
        if(p1[i] == p2)
        {
            return 1;
        }
    }
    return 0;
}

void my_c(char* p1)
{

    char* sort_str = malloc(sizeof(char)* strlen(p1));
    int g = 0;
    
    int x[128] = {0};
    
    for(int i = 0; p1[i]; i++)
    {
        if(!my_cmp(sort_str, p1[i]))
        {
            sort_str[g] = p1[i];
            g++;
        }
    }
    for(int d = 0; sort_str[d]; d++)
    {
        for(int i = 0; p1[i]; i++)
        {
            if(sort_str[d] == p1[i])
            {
                x[(int)p1[i]]++;
            }
        }
    }
    for(int i = 0; i < 128; i++)
    {
        if(x[i] > 0)
        {
            printf("%c:%d\n", i , x[i]);
        }
    }
}

int len(char** p1)
{
    int length = 0;
    for(int i = 0;p1[i]; i++)
    {
        length += strlen(p1[i]);
    }
    return length;
}

int main(int ac, char** av)
{
    char* str1 = malloc(sizeof(char)* len(av));
    int count = 0;

    for(int i = 1; i < ac ; i++)
    {
        for(int x = 0; av[i][x]; x++)
        {
            str1[count] = av[i][x];
            count++;
        }
    }
    my_c(str1);

    return 0;
}