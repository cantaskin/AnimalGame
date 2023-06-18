#include "Animal.h"

int print_main_menu()
{
    my_printf("Lutfen yapmak istediginiz numarayi seciniz.\n");
    my_printf("1-) Yeni bir evcil hayvan olustur.\n");
    my_printf("2-) Varolan evcil hayvanlardan birini guncelle.\n");
    return 1;
}

void multi_putstr(struct Animal **cpy, int fd)
{
    my_putstr_fd(" Kendini ",fd);
    my_putstr_fd((*cpy)->emotion,fd);
    my_putstr_fd(" hissediyor. ",fd);
    my_putstr_fd((*cpy)->emotion_txt,fd);
    my_putstr_fd(". ",fd);
    my_putstr_fd(" Enerji seviyesi : ",fd);
    my_putstr_fd(my_itoa((*cpy)->energy),fd);
    my_putstr_fd(" Mutluluk seviyesi : ",fd);
    my_putstr_fd(my_itoa((*cpy)->happiness),fd);
    my_putstr_fd("\n",fd);
}


int print_menu(struct Animal* animal) {
    my_printf("Lutfen yapmak istediginiz islemi cumlenin basindaki numaralarla seciniz.\n");
    my_printf("1-) %s isimli hayvanin ismini degistirin.\n", animal->name);
    my_printf("2-) %s isimli hayvani silin.\n", animal->name);
    my_printf("3-) %s isimli hayvani besleyin.\n", animal->name);
    my_printf("4-) %s isimli hayvana su verin.\n", animal->name);
    my_printf("5-) %s isimli hayvanla oyun oynayin.\n", animal->name);
    my_printf("6-) %s isimli hayvani temizle.\n", animal->name);
    my_printf("7-) %s isimli hayvani sev.\n", animal->name);
    my_printf("8-) %s isimli hayvani uyut.\n", animal->name);
    my_printf("9-) %s isimli hayvani odul ver.\n", animal->name);
    my_printf("10-) Baska bir hayvan secin.\n");
    return 1;
}