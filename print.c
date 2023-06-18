#include "Animal.h"
void print_to_file(int fd, struct Animal *new)
{
    write(fd,"\n",1);
    write(fd,new->name,_strlen(new->name));
    write(fd,",",1);
    write(fd,new->species,_strlen(new->species));
    write(fd,",60,60",6);
}
void print_to_file2(int fd, struct Animal *new)
{
    write(fd,"\n",1);
    write(fd,new->name,_strlen(new->name));
    write(fd,",",1);
    write(fd,"mutlu,:)",8);
}
void data_p1(struct Animal *cpy, int tmp_fd)
{
    write(tmp_fd, cpy->name, _strlen(cpy->name));
    write(tmp_fd, ",", 1);
    write(tmp_fd, cpy->emotion, _strlen(cpy->emotion));
    write(tmp_fd, ",", 1);
    write(tmp_fd, cpy->emotion_txt,  _strlen(cpy->emotion_txt));
}
void data_p2(struct Animal *cpy, int tmp_fd)
{
    write(tmp_fd, cpy->name, _strlen(cpy->name));
    write(tmp_fd, ",", 1);
    write(tmp_fd, cpy->species, _strlen(cpy->species));
    write(tmp_fd, ",", 1);
    write(tmp_fd, ft_itoa(cpy->happiness),  _strlen(ft_itoa(cpy->happiness)));
    write(tmp_fd, ",", 1);
    write(tmp_fd, ft_itoa(cpy->energy), _strlen(ft_itoa(cpy->energy)));
    write(tmp_fd, "\n", 1); 
}
void emo_and_data_print(struct Animal *cpy,const char *s1,const char *s2, int control)
{
    int fd = open(s1, O_RDWR);
    int tmp_fd = open(s2, O_RDWR | O_CREAT, 0644);
    char *tmp = NULL;
    int flag = 0;

    while (tmp = get_next_line(fd))
    {

        if (_strcmp(cpy->name, ft_split(tmp, ',')[0]))
        {
            flag = 1;
            if(control == 1)
            {
                write(1,"\0",1);
                write(1,"\n",1);
            }
            else if(_strcmp(s1,"duygu.txt"))
                data_p1(cpy,tmp_fd);
            else    
                data_p2(cpy,tmp_fd);
        }
        else
            write(tmp_fd, tmp, _strlen(tmp));
    }
  /* if(!flag && !_strcmp(s1,"duygu.txt"))
    {
        write(1,"\n",1);
        data_p2(cpy,tmp_fd);
    }
    else if(!flag && !_strcmp(s1,"duygu.txt"))
*/
    close(fd);
    close(tmp_fd);
    remove(s1);
    rename(s2, s1);
}