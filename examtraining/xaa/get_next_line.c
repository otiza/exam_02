#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i ;
	i=0;

	while(str[i])
		i++;
	return (i);
}

int check_ln(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\n')
	{
		if (str[i] == '\0')
			return(-1);
		i++;
	}
	return(i);
}

int ft_strcpy(char *dst,const char *src)
{
	int i;

	i=0;
	while(src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return(i);
}

int	ft_strcpy_b_zero(char *dst, const char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		dst[i] = '\0';
		i++;
	}
	return(i);
}

char *ft_strdup(char *str)
{
	int i;
	char *rslt;

	if (!(rslt = malloc(sizeof(str) * (ft_strlen(str)+1))))
		return(NULL);
	i = 0;
	while(str[i])
	{
		rslt[i] = str[i];
		i++;
	}
	rslt[i]='\0';
	return (rslt);
}

char *ft_strjoin(char *str1, char *str2)
{
	int i,j;
	char *rslt;

	if (!str1 || !str2)
		return(NULL);
	i = ft_strlen(str1);
	j = ft_strlen(str2);
	if(!(rslt = malloc(sizeof(char) * (i+j+1))))
		return(NULL);
	i = 0;
	j = 0;
	while ( str1[i])
	{
		rslt[j] =str1[i];
		j++;
		i++;
	}
	i = 0;
	while(str2[i])
	{
		rslt[j] = str2[i];
		j++;
		i++;
	}
	rslt [j] = '\0';
	return (rslt);
}

char * get_next_line(int fd)
{
	static char buff[BUFFER_SIZE] = {0};
	char *line;
	char *tofree;
	int i,k,rt;

	if(fd<0 || BUFFER_SIZE <= 0)
		return(NULL);
	if(!(line = ft_strdup("")))
		return(NULL);
	if (buff[0] == '\0')
		read (fd, buff, BUFFER_SIZE);

	i = 0;
	rt = 1;

	while(rt > 0)
	{
		if((i = check_ln(buff)) != -1)
		{
			tofree = line;
			k = ft_strlen(line);
			line = ft_strjoin(line,buff);
			free(tofree);
			line[k+i+1] = '\0';
			if (i == -1)
				buff[0] = '\0';
			ft_strcpy_b_zero(buff,&buff[i+1]);
			if(*line == '\0')
			{
				free(line);
				return(NULL);
			}
			return(line);
		}
		else
		{
			tofree= line;
			line = ft_strjoin(line,buff);
			free(tofree);
			rt = read(fd,buff,BUFFER_SIZE);
		}
	}
	free(line);
	return(NULL);
}
