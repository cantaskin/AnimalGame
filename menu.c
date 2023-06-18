#include "Animal.h"

int print_main_menu()
{
    ft_printf("Lutfen yapmak istediginiz numarayi seciniz.\n");
    printf("1-) Yeni bir evcil hayvan olustur.\n");
    printf("2-) Varolan evcil hayvanlardan birini guncelle.\n");
    return 1;
}

void multi_putstr(struct Animal **cpy, int fd)
{
    ft_putstr_fd(" Kendini ",fd);
    ft_putstr_fd((*cpy)->emotion,fd);
    ft_putstr_fd(" hissediyor. ",fd);
    ft_putstr_fd((*cpy)->emotion_txt,fd);
    ft_putstr_fd(". ",fd);
    ft_putstr_fd(" Enerji seviyesi : ",fd);
    ft_putstr_fd(ft_itoa((*cpy)->energy),fd);
    ft_putstr_fd(" Mutluluk seviyesi : ",fd);
    ft_putstr_fd(ft_itoa((*cpy)->happiness),fd);
    ft_putstr_fd("\n",fd);
}


int print_menu(struct Animal* animal) {
    printf("Lutfen yapmak istediginiz islemi cumlenin basindaki numaralarla seciniz.\n");
    printf("1-) %s isimli hayvanin ismini degistirin.\n", animal->name);
    printf("2-) %s isimli hayvani silin.\n", animal->name);
    printf("3-) %s isimli hayvani besleyin.\n", animal->name);
    printf("4-) %s isimli hayvana su verin.\n", animal->name);
    printf("5-) %s isimli hayvanla oyun oynayin.\n", animal->name);
    printf("6-) %s isimli hayvani temizle.\n", animal->name);
    printf("7-) %s isimli hayvani sev.\n", animal->name);
    printf("8-) %s isimli hayvani uyut.\n", animal->name);
    printf("9-) %s isimli hayvani odul ver.\n", animal->name);
    printf("10-) Baska bir hayvan secin.\n");
    return 1;
}