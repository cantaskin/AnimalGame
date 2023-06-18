#include "animal.h"

struct Animal *animal_init()
{
    struct Animal *new = malloc(sizeof(struct Animal));
    new->name = NULL;
    new->species = NULL;
    new->happiness = 60;
    new->energy = 60;
    new->emotion = NULL;
    new->emotion_txt = NULL;
    new->emotion = ft_strdup("mutlu");
    new->emotion_txt = ft_strdup(":)");
    return (new);

}

int add_animal()
{
    struct Animal *new = animal_init();
    char *tmp = NULL;
    char *buffer = NULL;
    buffer = malloc(1000);
    int fd , tmp_fd ,flag = 0;  // Otomatik boyutlandırma için başlangıç boyutu
    printf("Hayvan ismi giriniz\n");
     while (readline(0, &buffer, 260)) 
    {
        flag = 0;
        fd = open("evcil_veri.txt", O_RDWR);
            while(tmp = get_next_line(fd))
            {
                if(_strcmp(buffer,ft_split(tmp,',')[0]) && !new->name)
                {
                    flag = 1;
                    close(fd);
                    printf("Girdiginiz isim daha once başka bir hayvan için kullanilmistir. Baska bir isim giriniz.\n");
                    return 0;
                }
            }
        if(!flag)
        {
            if(!new->name)
            {
                new->name = ft_strdup(buffer);
                printf("Lutfen %s isimli hayvanin turunu giriniz.\n", new->name);
            }
            else if(!new->species)
            {
                new->species = ft_strdup(buffer);
                printf("%s isimde ve %s turunde hayvan olusturulmustur.\n", new->name, new->species);
            }
            else 
            {
                tmp_fd = open("duygu.txt", O_RDWR);
                while(get_next_line(tmp_fd));
                print_to_file(fd,new);
                print_to_file2(tmp_fd,new);
                close(tmp_fd);
                close(fd);
                return 1;
            }
        }
        close(fd);
    }
    free(new->name);
    free(new->species);
    free(new);
    free(buffer);
    free(tmp);
    return 1;
}



int uptade_animal()
{
    struct Animal *new = animal_init();
    char *tmp = NULL;
    char *buffer = NULL;
    buffer = malloc(1000);
    int fd , flag = 0; 
    print_animal_names();
    printf("Islem yapmak istediginiz hayvanin ismini giriniz.\n");
    while (readline(0, &buffer, 260)) 
    {
        flag = 0;
        fd = open("evcil_veri.txt", O_RDWR);
            while(tmp = get_next_line(fd))
            {
                if(_strcmp(buffer,ft_split(tmp,',')[0]))
                {
                    flag = 1;
                    new->name = ft_split(tmp,',')[0];
                    new->species = ft_split(tmp,',')[1];
                    new->happiness = ft_atoi(ft_split(tmp,',')[2]);
                    new->energy = ft_atoi(ft_split(tmp,',')[3]);
                    close(fd);
                }
            }
            if(!flag)
            {
                printf("Girdiginiz isimde bir hayvan bulunmamaktadir.\n");
                close(fd);
                free(tmp);
                free(buffer);
                //newı freele
                return 0;
            }
            else
                return !choices(new);
    }
}