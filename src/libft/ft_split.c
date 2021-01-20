/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:10:48 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/20 11:50:25 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_split_nwords(char *str)
{
	int n_words;
	int i;

	i = 0;
	n_words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			n_words++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' 
				&& str[i] != '\n' && str[i] != '\0')
				i++;
		}
		i++;
	}
	return (n_words);
}

static char **ft_split_fill(char *str, int n_words)
{
	char **keywords;
	int i;
	int start;
	int j;

	i = 0;
	j = 0;
	keywords = malloc(sizeof(char *) * n_words);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			start = i;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				i++;
			keywords[j] = ft_substr(str, start, (i - start));
			j++;
		}
		i++;
	}
	return (keywords);
}

char **ft_split(char *str)
{
	int n_words;
	int i;
	char **keywords;

	n_words = ft_split_nwords(str);
	keywords = ft_split_fill(str, n_words);
	return (keywords);
}