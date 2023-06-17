#include "Animal.h"
#include <stdio.h>
void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s)
		while (s[index] != '\0')
			write(fd, &s[index++], 1);
}

int	ft_atoi(const char *str)
{
	long int	number;
	int			isaret;

	isaret = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isaret = -1;
		str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0') * isaret;
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
		str++;
	}
	return (number);
}

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static int _strlen(const char *ptr)
{
    int i = 0;
    while(ptr[i])
        i++;
    return i;
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}
int energy_check(struct Animal *cpy)
{
    if(!(cpy->energy > 5))
    {
        printf("Enerjiniz bitti lütfen uyuyunuz\n");
        return 0;
    }
    return 1;
}
char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= _strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == _strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


char	*ft_strdup(const char *str)
{
	char	*twin;
	size_t	i;

	twin = malloc(sizeof(char) * (_strlen(str) + 1));
	if (!twin)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		twin[i] = str[i];
		i++;
	}
	twin[i] = '\0';
	return (twin);
}
size_t readline(int fd, char **buffer, size_t maxlen) {
    size_t bytesRead = 0;
    size_t totalBytesRead = 0;
    char readChar;

    while (totalBytesRead < maxlen - 1) {
        bytesRead = read(fd, &readChar, 1);

        if (bytesRead == -1) {
            return -1; // Hata durumu
        } else if (bytesRead == 0) {
            break; // Dosya sonu
        } else {
            (*buffer)[totalBytesRead] = readChar;
            totalBytesRead++;

            if (readChar == '\n') {
                break; // Satır sonu
            }
        }
    }
    (*buffer)[totalBytesRead - 1] = '\0'; // Diziyi null karakteriyle sonlandırma

    return totalBytesRead;
}

int	_strcmp(char *s1, char *s2)
{
	size_t i;
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0' ) )
		i++;
	return (_strlen(s2) == i);
}

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
void print_to_file(int fd, struct Animal *new)
{
    write(fd,"\n",1);
    write(fd,new->name,_strlen(new->name));
    write(fd,",",1);
    write(fd,new->species,_strlen(new->species));
    write(fd,",60,60",6);
}
int add_animal()
{
    struct Animal *new = animal_init();
    char *tmp = NULL;
    char *buffer = NULL;
    buffer = malloc(1000);
    int fd , flag = 0;  // Otomatik boyutlandırma için başlangıç boyutu
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
                print_to_file(fd,new);
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

void change_txt(char *name, char *species, int happ, int energy)
{

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

void uptade_name(struct Animal **new)
{
    char *buffer = NULL;
    buffer = malloc(1000);
    printf("Yeni bir isim giriniz.\n");
    if (readline(0, &buffer, 260))
    {
        (new[0])->name = ft_strdup(buffer);
    }
    free(buffer);
}

void foofd_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvan beslendi.", (ref[0])->name);
    (ref[0])->energy += 15;
    (ref[0])->happiness += 10;
}
//void remove_animal(struct Animal *ref);
void water_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvana su verildi.", (ref[0])->name);
    (ref[0])->energy += 5;
    (ref[0])->happiness += 5;
}
void play_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvan oyun oynatıldı.", (ref[0])->name);
    (ref[0])->energy -= 15;
    (ref[0])->happiness += 15;

}
void clean_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvan temizlendi.", (ref[0])->name);
    (ref[0])->energy -= 10;
    (ref[0])->happiness -= 5;
}
void pet_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvan sevildi.", (ref[0])->name);
    (ref[0])->happiness += 5;
}
void sleep_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvan uyutuldu.", (ref[0])->name);
    (ref[0])->energy += 5;
}
void price_animal_(struct Animal **ref)
{
    printf("%s, isimli hayvan ödüllendirildi.", (ref[0])->name);
    (ref[0])->happiness += 10;
}
void emotions_print(struct Animal *cpy)
{
    int fd = open("duygu.txt",O_RDWR);
    char *tmp = NULL;
    while(tmp = get_next_line(fd))
    {
        if(_strcmp(cpy->name,ft_split(tmp,',')[0]))
        {
            write(fd,cpy->name,_strlen(cpy->name));
            write(fd,",",1);
            write(fd,cpy->emotion,_strlen(cpy->emotion));
            write(fd,cpy->emotion_txt,_strlen(cpy->emotion_txt));
        }
    }
    close(fd);
}
void detail_animal(struct Animal **cpy)
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
    emotions_print((*cpy));
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
            {
                while(1)
                {
                    printf("Lutfen yapmak istediginiz işlemi cümlenin basindaki numaralarla seciniz.\n",new->name);
                    printf("1-) %s isimli hayvanin ismini degistirin.\n",new->name);
                    printf("2-) %s isimli hayvani silin.\n",new->name);
                    printf("3-) %s isimli hayvani besleyin.\n",new->name);
                    printf("4-) %s isimli hayvana su verin.\n",new->name);
                    printf("5-) %s isimli hayvanla oyun oynayin.\n",new->name);
                    printf("6-) %s isimli hayvani temizle.\n",new->name);
                    printf("7-) %s isimli hayvani sev.\n",new->name);
                    printf("8-) %s isimli hayvani uyut.\n",new->name);
                    printf("9-) %s isimli hayvani odul ver.\n",new->name);
                    printf("10-) Başka bir hayvan seçin.\n");
                    scanf("%d",&flag);
                    if(flag == 1)
                    {
                        uptade_name(&new);
                    }
                    else if(flag == 2)
                    {
                        //delete_animal();
                        return 1;
                    }
                    else if(flag == 3)
                    {
                        if(energy_check(new))
                            foofd_animal_(&new);
                        else
                            break;
                    }
                    else if(flag == 4)
                    {
                        if(energy_check(new))
                            water_animal_(&new);
                        else
                            break;
                        
                    }
                    else if(flag == 5)
                    {
                        if(energy_check(new))
                            play_animal_(&new);
                        else
                            break;
                    }
                    else if(flag == 6)
                    {
                        if(energy_check(new) )
                        {
                            if((new->happiness > 5))
                                clean_animal_(&new);
                            else
                                printf("%s isimli hayvan mutlu değil. Onu mutlu edecek şeyler yapin.\n",new->name);
                        }
                        else
                            break;
                    }
                    else if(flag == 7)
                    {
                        if(energy_check(new))
                            pet_animal_(&new);
                        else
                            break;
                    }
                    else if(flag == 8)
                    {
                        if((new->happiness > 5))
                            sleep_animal_(&new);
                        else
                        printf("%s isimli hayvan mutlu değil. Onu mutlu edecek şeyler yapin.\n",new->name);
                        
                    }
                    else if(flag == 9)
                    {
                        if(energy_check(new))
                            price_animal_(&new);
                        else
                            break;
                    }
                    else if(flag == 10)
                    {
                        return 0;
                    }
                    else
                        printf("Yanlis tuslama yaptiniz.\n");
                    detail_animal(&new);
                    
                }
            }
    }
}
int main()
{
    int flag = 150;
    //struct Animal *a;
    
    while(1)
    {
        ft_printf("Lutfen yapmak istediginiz numarayi seciniz.\n");
        printf("1-) Yeni bir evcil hayvan olustur.\n");
        printf("2-) Varolan evcil hayvanlardan birini guncelle.\n");
        scanf("%d",&flag);
        if(flag == 1)
        {
            while(!add_animal());
        }
        else if(flag == 2)
        {
           while(!uptade_animal());
        } 
        else 
        {
            printf("Yanlis komut girdiniz. Lutfen tekrar deneyiniz\n");
        }
    }
}   
