#ifndef ANIMAL_H
# define ANIMAL_H
#define BUFFER_SIZE 1

//Mac veya Linuxta kullanacaksanız <unistd.h> kullanın, windowsta <io.h> çalışır.
# include <io.h> 
# include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>

struct Animal
{
    char *name;
    char *species;
    char *emotion;
    char *emotion_txt;
    int energy;
    int happiness;
};

int	ft_printf(const char *format, ...);
char	*get_next_line(int fd);

#endif