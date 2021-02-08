/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:36:37 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/08 20:27:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static	int		ft_word(char const *str, int i, int *nbword, int c)
{
	*nbword += 1;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static	void	ft_free(char **tab, int n)
{
	int	i;

	i = 0;
	while (i > n)
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

static	int		ft_add_word(char **tab, char const *str, int *nbword, int c)
{
	int		wlen;
	int		j;
	char	*tmp;
	int		sv;

	wlen = 0;
	sv = 0;
	while (str[wlen] != c && str[wlen] != '\0')
		wlen++;
	if (!(tmp = (char *)malloc((wlen + 1) * sizeof(char))))
	{
		ft_free(tab, *nbword);
		*nbword = 0;
		return (ft_strlen(str));
	}
	tmp[wlen] = '\0';
	j = 0;
	while (sv < wlen)
	{
		tmp[j] = str[sv++];
		j++;
	}
	tab[*nbword] = tmp;
	*nbword += 1;
	return (wlen);
}

static	void	reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char			**ft_split(char const *str, char c)
{
	int		i;
	char	**tab;
	int		number_words;

	reset(&i, &number_words);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		if (str[i] != c)
			i = ft_word(str, i, &number_words, c);
		else
			i++;
	if (!(tab = (char **)malloc((number_words + 1) * sizeof(char *))))
		return (NULL);
	tab[number_words] = 0;
	reset(&i, &number_words);
	while (str[i] != '\0')
		if (str[i] != c)
			i += ft_add_word(tab, str + i, &number_words, c);
		else
			i++;
	if (!number_words && !tab)
		return (NULL);
	return (tab);
}