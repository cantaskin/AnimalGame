#include "Animal.h"
#include <stdio.h>

int main()
{
    char *buffer = NULL;
    buffer = malloc(1000);
    while(print_main_menu() && readline(0, &buffer, 260))
    {
        if(atoi(buffer) == 1)
            while(!add_animal());
        else if(atoi(buffer) == 2)
           while(!uptade_animal());
        else 
            printf("Yanlis komut girdiniz. Lutfen tekrar deneyiniz\n");
    }
}   
