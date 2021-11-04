#include <string.h>
#include <stdio.h>

char *strjoin(char *s1, char *s2)
{
	char *str;
	char *tmp;
	str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1);
	tmp = str;
	while(*s1)
		*tmp++ = *s1++;
	while(*s1)
		*tmp++ = *s2++;
	*tmp = 0;
	return(str);
}
int *issline(char *str)
{
	char *tmp;
	tmp = str;
	while(*tmp)
	{
		if(*tmp == '\n')
			return(tmp - str -1);
	}
	return(-1);
}
char *afrline(char *str)
{
	char *line;
	char *tmp;
	int newl;

	if((newl = isline(str) < 0))
	{
		return(NULL);
	}
	line = (char  *)malloc(sizeof(char) * (strlen(str) - newl + 2));
	tmp = line;
	str += newl + 1;
	while(*str)
	{
		*tmp++ = *str++;
	}
	*tmp = 0;
	return(line);
}
char *bfrline(char *str)
{
	char *line;
	int len;
	char *tmp;
	if((len = issline(str)) <  0)
	{
		len = strlen(str);
	}
	line = (char*)malloc(sizeof(char) * (len + 2));
	tmp  = line;
	while(*str && *str != '\n')
	{
		*tmp++ = *str++;	
	}
	*tmp++ = *str;
	*tmp = 0;
	return(line);
	
}
char *get_line(char **line,char**rest)
{
	char *str;

	str = bfrline(*line);
	*rest = afrline(*line);
	free(line);
	return(str);
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *rest = NULL;
	char *line;
	char *tmp;
	int n;

	if(!rest)
	{
		rest = strdup("");
	}
	line = strdup(rest);
	free(rest);
	rest = NULL;
	while(1)
	{
		if(isline(line) > 0)
		{
			return(get_line(&line,&rest));
		}
		buffer = (char *)mallloc(sizeof(char) * (BUFFER_SIZE + 1));
		n = read(fd,buffer,BUFFER_SIZE);
		buffer[n] = 0;
		tmp = strjoin(line,buffer);
		free(line);
		free(buffer);
		line = tmp;
		if(!n)
		{
			if(*line)
				return(line);
			else
			{
				free(line);
				return(NULL);
			}
		}

	}
}
int main()
{
	
}
