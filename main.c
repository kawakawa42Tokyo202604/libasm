/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Codex                                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:47:11 by Codex             #+#    #+#             */
/*   Updated: 2026/10/23 19:47:50 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
static void	test_read(void);
static void	test_memory(void);

int	main(void)
{
	char		buf[16];
	const char	*text;

	text = "Hello";
	printf("strlen:    %zu\n", strlen(text));
	printf("ft_strlen: %zu\n", ft_strlen(text));
	printf("strcpy:    %s\n", strcpy(buf, text));
	printf("ft_strcpy: %s\n", ft_strcpy(buf, text));
	printf("strcmp:    %d\n", strcmp("abc", "abd"));
	printf("ft_strcmp: %d\n", ft_strcmp("abc", "abd"));
	printf("write:     ");
	fflush(stdout);
	printf(" (%zd bytes)\n", write(STDOUT_FILENO, text, 5));
	printf("ft_write:  ");
	fflush(stdout);
	printf(" (%zd bytes)\n", ft_write(STDOUT_FILENO, text, 5));
	test_read();
	test_memory();
	return (0);
}

/* main.c の先頭10文字を比較 */
static void	test_read(void)
{
	int		fd;
	char	buf[11];
	ssize_t	count;

	fd = open("main.c", O_RDONLY);
	if (fd == -1)
	{
		perror("main.c");
		return ;
	}
	memset(buf, 0, sizeof(buf));
	count = read(fd, buf, 10);
	printf("read:      %s (%zd bytes)\n", buf, count);
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		perror("lseek");
		close(fd);
		return ;
	}
	memset(buf, 0, sizeof(buf));
	count = ft_read(fd, buf, 10);
	printf("ft_read:   %s (%zd bytes)\n", buf, count);
	close(fd);
}

/* 確保した文字列と整数を表示 */
static void	test_memory(void)
{
	char	*real_str;
	char	*my_str;
	int		*real_num;
	int		*my_num;

	real_str = strdup("Hello");
	my_str = ft_strdup("Hello");
	real_num = calloc(1, sizeof(int));
	my_num = ft_calloc(1, sizeof(int));
	if (!real_str || !my_str || !real_num || !my_num)
		fprintf(stderr, "Memory allocation failed\n");
	else
	{
		printf("strdup:    %s\n", real_str);
		printf("ft_strdup: %s\n", my_str);
		printf("calloc:    %d\n", real_num[0]);
		printf("ft_calloc: %d\n", my_num[0]);
	}
	free(real_str);
	free(my_str);
	free(real_num);
	free(my_num);
}
