#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);

int     main()
{
    int		fd;
	char	*line;
	int		i;


	i = 0;
	fd = open("main.c", O_RDONLY);

	line = get_next_line(fd);
    printf("\nFirst line: %s\n", line);
    free(line);

    printf("second gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

    printf("third gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

        printf("fourth gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

        printf("fifth gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

            printf("6 gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

    printf("7 gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

        printf("8 gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

    printf("9 gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

     printf("10 gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);


    printf("11 gnl here");
    line = get_next_line(fd);
    printf("\nSecond line: %s\n", line);
    free(line);

    system("leaks a.out");
    while(1) ;

	return (0);
}
