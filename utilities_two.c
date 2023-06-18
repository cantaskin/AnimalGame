#include "Animal.h"

int my_strlen(const char *ptr)
{
    int i = 0;
    while(ptr[i])
        i++;
    return i;
}

char *my_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = my_strlen(dst);
	src_len = my_strlen(src);
	if (dstsize == 0)
		return (src);
	if (dstsize < dst_len)
		return (src);
	else
	{
		i = dst_len;
		while (src[j] && (dst_len + j) < dstsize)
			dst[i++] = src[j++];
		if ((dst_len + j) == dstsize && dst_len < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (dst);
	}
}
char	*word_dup(const char *str, int start, int finish)
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
        my_printf("Enerjiniz bitti lütfen uyuyunuz\n");
        return 0;
    }
    return 1;
}
char		**my_split(char const *s, char c)
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
	while (i <= my_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == my_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


char	*my_strdup(const char *str)
{
	char	*twin;
	size_t	i;

	twin = malloc(sizeof(char) * (my_strlen(str) + 1));
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

int	my_strcmp(const char *s1, const char *s2)
{
	size_t i;
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0' ) )
		i++;
	return (my_strlen(s2) == i);
}