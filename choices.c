#include "Animal.h"
int open_out(struct Animal *new)
{
    int fd;
    char *tmp = ft_strdup(new->name);
    printf("%s\n", ft_strlcat(tmp,"_evcil_cikti.txt",_strlen(tmp) + 18));
    fd = open(tmp, O_RDWR | O_CREAT, 0644);
    free(tmp);
    while(tmp = get_next_line(fd));
    free(tmp);
    return fd;

}
void print_animal_names()
{
    char *tmp = NULL; 
    int fd = 0;
    fd = open("evcil_veri.txt",O_RDWR);
    printf("Islem yapabileceginiz hayvanlarin isimleri :\n");
    while(tmp = get_next_line(fd))
    {
        printf("%s\n",ft_split(tmp,',')[0]);
    }
    close(fd);
}

void uptade_name(struct Animal **new, int fd)
{
    char *buffer = NULL;
    buffer = malloc(1000);
    printf("Yeni bir isim giriniz.\n");
    if (readline(0, &buffer, 260))
    {
        (new[0])->name = ft_strdup(buffer);
    }
    free(buffer);
    ft_putstr_fd("Ismi degistirildi.",fd);
}

void foofd_animal_(struct Animal **ref,int fd)
{
    printf("%s, isimli hayvan beslendi.", (ref[0])->name);
     ft_putstr_fd("Yemek verildi.",fd);
    (ref[0])->energy += 15;
    (ref[0])->happiness += 10;
}
//void remove_animal(struct Animal *ref);
void water_animal_(struct Animal **ref, int fd)
{
    printf("%s, isimli hayvana su verildi.", (ref[0])->name);
     ft_putstr_fd("Su içirildi.",fd);
    (ref[0])->energy += 5;
    (ref[0])->happiness += 5;
}
void play_animal_(struct Animal **ref, int fd)
{
    printf("%s, isimli hayvan oyun oynatildi.", (ref[0])->name);
     ft_putstr_fd("Oyun oynatildi.",fd);
    (ref[0])->energy -= 15;
    (ref[0])->happiness += 15;

}
void clean_animal_(struct Animal **ref,int fd)
{
    printf("%s, isimli hayvan temizlendi.", (ref[0])->name);
     ft_putstr_fd("Temizlendi.",fd);

    (ref[0])->energy -= 10;
    (ref[0])->happiness -= 5;
}
void pet_animal_(struct Animal **ref, int fd)
{
    printf("%s, isimli hayvan sevildi.", (ref[0])->name);
     ft_putstr_fd("Sevildi.",fd);
    (ref[0])->happiness += 5;
}
void sleep_animal_(struct Animal **ref, int fd)
{
    printf("%s, isimli hayvan uyutuldu.", (ref[0])->name);
    ft_putstr_fd("Uyutuldu.",fd);
    (ref[0])->energy += 5;
}
void price_animal_(struct Animal **ref, int fd)
{
    printf("%s, isimli hayvan ödüllendirildi.", (ref[0])->name);
    ft_putstr_fd("Odullendirildi.",fd);
    (ref[0])->happiness += 10;
}

void detail_animal(struct Animal **cpy, int fd)
{
    if((*cpy)->energy > 25 && (*cpy)->happiness > 50)
    {
        (*cpy)->emotion = ft_strdup("mutlu");
        (*cpy)->emotion_txt = ft_strdup(":)");
    }
    else if((*cpy)->energy < 20 && (*cpy)->happiness < 20)
    {
        (*cpy)->emotion = ft_strdup("uzgun");
        (*cpy)->emotion_txt = ft_strdup(":(");
    }
    else if((*cpy)->energy < 10 && (*cpy)->happiness < 10)
    {
        (*cpy)->emotion = ft_strdup("agliyor");
        (*cpy)->emotion_txt = ft_strdup(":')");
    }
    else if((*cpy)->energy < 5)
    {
        (*cpy)->emotion = ft_strdup("uyuyor");
        (*cpy)->emotion_txt = ft_strdup(":zz");
    }
    else if((*cpy)->energy < 20)
    {
        (*cpy)->emotion = ft_strdup("ac");
        (*cpy)->emotion_txt = ft_strdup(":-o");
    }
    else if((*cpy)->energy > 40 || (*cpy)->happiness < 30)
    {
        (*cpy)->emotion = ft_strdup("Oyun Istiyor");
        (*cpy)->emotion_txt = ft_strdup("<:o)");
    }
    printf("%s isimli hayvan kendini %s hissediyor. Enerji seviyesi : %d mutluluk seviyesi: %d \n", (*cpy)->name ,(*cpy)->emotion, (*cpy)->energy, (*cpy)->happiness);
    multi_putstr(cpy,fd);
    emo_and_data_print((*cpy),"duygu.txt","duygu_tmp.txt",0);
}

int process_choice(struct Animal* animal, char *choice) {
    int fd = -1;
    fd = open_out(animal);
    switch (atoi(choice)) {
        case 1:
            uptade_name(&animal, fd);
            break;
        case 2:
            emo_and_data_print(animal,"evcil_veri.txt","evcil_veri_tmp.txt",1);
            ft_putstr_fd("Hayvan silindi.\n",fd);
            return 1;
        case 3:
            foofd_animal_(&animal,fd);
            break;
        case 4:
            water_animal_(&animal,fd);
            break;
        case 5:
            play_animal_(&animal,fd);
            break;
        case 6:
            if (animal->happiness > 5)
                clean_animal_(&animal,fd);
            else
                printf("%s isimli hayvan mutlu degil. Onu mutlu edecek seyler yapin.\n", animal->name);
            break;
        case 7:
            pet_animal_(&animal,fd);
            break;
        case 8:
            if (animal->happiness > 5)
                sleep_animal_(&animal,fd);
            else
                printf("%s isimli hayvan mutlu degil. Onu mutlu edecek seyler yapin.\n", animal->name);
            break;
        case 9:
            price_animal_(&animal,fd);
            break;
        case 10:
            emo_and_data_print(animal,"evcil_veri.txt","evcil_veri_tmp.txt",0);
            return 0;
        default:
            printf("Yanlis tuslama yaptiniz.\n");
    }
    detail_animal(&animal,fd);
    return 1;
}
int choices(struct Animal *new)
{
    char *buffer = NULL;
    buffer = malloc(1000);
    while(print_menu(new) && readline(0, &buffer, 260))
    {
        if(!process_choice(new,buffer))
            return 0;
    }
         
}