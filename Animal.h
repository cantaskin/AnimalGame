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

//utilities.c

void	*my_memset(void *str, int letter, size_t n);
size_t	my_strlcpy(char *dest, const char *src, size_t size);
void	*my_calloc(size_t count, size_t size);
int	find_len(int nbr);
char	*my_itoa(int n);
void	my_putstr_fd(char *s, int fd);
int	my_atoi(const char *str);
int	count_words(const char *str, char c)

//utilities_two.c
int my_strlen(const char *ptr);
char *my_strlcat(char *dst, char *src, size_t dstsize);
char	*word_dup(const char *str, int start, int finish)
int energy_check(struct Animal *cpy);
char		**my_split(char const *s, char c);
char	*my_strdup(const char *str);
size_t readline(int fd, char **buffer, size_t maxlen);
int	my_strcmp(const char *s1, const char *s2);

//print.c

void print_to_file(int fd, struct Animal *new);
void print_to_file2(int fd, struct Animal *new);
void data_p1(struct Animal *cpy, int tmp_fd);
void data_p2(struct Animal *cpy, int tmp_fd);
void emo_and_data_print(struct Animal *cpy,const char *s1,const char *s2, int control);


//menu.c

int print_main_menu();
void multi_putstr(struct Animal **cpy, int fd);
int print_menu(struct Animal* animal);

//choices.c

int open_out(struct Animal *new);
void print_animal_names();
void uptade_name(struct Animal **new, int fd);
void foofd_animal_(struct Animal **ref,int fd);
void water_animal_(struct Animal **ref, int fd);
void play_animal_(struct Animal **ref, int fd);
void clean_animal_(struct Animal **ref,int fd);
void pet_animal_(struct Animal **ref, int fd);
void sleep_animal_(struct Animal **ref, int fd);
void price_animal_(struct Animal **ref, int fd);
void detail_animal(struct Animal **cpy, int fd);
int process_choice(struct Animal* animal, char *choice);
int choices(struct Animal *new);

//animal_core.c

struct Animal *animal_init();
int add_animal();
int uptade_animal();
#endif