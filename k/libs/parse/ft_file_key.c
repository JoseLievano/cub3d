#include "ft_parse.h"

static bool ft_is_space(char c)
{
	if (c == 32 || (c >= 7 && c <= 15))
		return (true);
	return (false);
}

static bool ft_compare_key(char *key, char *str)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(key);
	if (len <= 0)
		return (false);
	while (i < len)
	{
		if (key[i] != str[i])
			return (false);
		i++;
	}
	if (!ft_is_space(str[i]))
		return (false);
	return (true);
}

int ft_get_unique_key(char *key, t_dll *content)
{
	int i;
	int hits;
	t_dll *local_c;
	char *c_str;

	i = 0;
	hits = 0;
	local_c = content;
	while (local_c)
	{
		c_str = (char *) local_c->content;
		if (ft_compare_key(key, c_str))
		{
			hits++;
			i = (int) local_c->index;
		}
		local_c = local_c->next;
	}
	if (hits == 1)
		return i;
	return -1;
}

char *ft_remove_key(char *key, char *content)
{
	size_t c_len;
	size_t k_len;
	size_t i;
	char *new_str;

	i = 0;
	c_len = ft_strlen(content);
	k_len = ft_strlen(key);
	new_str = (char *) malloc(sizeof(char) * c_len);
	while (i < c_len)
	{
		new_str[i] = '\0';
		i++;
	}
	c_len = 0;
	while (content[k_len])
	{
		if (!ft_is_space(content[k_len]))
		{
			new_str[c_len] = content[k_len];
			c_len++;
		}
		k_len++;
	}
	return (new_str);
}

char *ft_get_key_content(char *key, t_dll *f_c)
{
	char *fl_path;
	int i;

	fl_path = NULL;
	i = ft_get_unique_key(key, f_c);
	if (i < 0)
		return fl_path;
	fl_path = ft_remove_key(key, (char *) t_dll_get_node_index(f_c, i)->content);
	return (fl_path);
}
