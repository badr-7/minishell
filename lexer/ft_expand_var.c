/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:47 by mel-hous          #+#    #+#             */
/*   Updated: 2022/10/27 10:05:35 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#define NO_EXPANSION	((char *)-1)

// char *exit_status(char **s)
// {
//     if(!ft_strncmp(*s,"$?", 2))
//         return(NULL);
//     return (NO_EXPANSION);
// }
 
char *str_add(char *full, char c, char *s)
{
    char *dest;

    dest = NULL;
    if (s == NO_EXPANSION)
        return(full);
    if (!s)
    {
        // if(c == 39 )
        //     return(full);
        char    *str;
        str = malloc(sizeof(char) * 2);
        str[0] = c;
        str[1] = '\0';
        dest = ft_strjoin(full, str);
        return (dest);
    }
    else
        dest = ft_strjoin(full, s);
    free(full);
    free(s);
    return(dest);
}


char    *exp_var(char **sp, char *expand)
{
    char	*s;
	size_t	i;
	char	*value;

	s = *sp;
	if (s[0] != '$' || (!ft_isalpha(s[1]) && s[1] != '_'))
		return (NO_EXPANSION);
	s++;
	i = 1;
	while (ft_isalnum(s[i]) || s[i] == '_')
		i++;
	*sp = s + i;
	value = env_find2(glb_v.list,s, i);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
} 


t_token lex_var(t_lexer lexer, int len)
{
    int i;
    int mode;
    char    *s;
    char    **str;
    char    *expnd;
    char    *full;
    int     a;
    
    a = 0;
    
    // puts("1\n");
    full = ft_strdup("");
    s = ft_substr(lexer.str, 0, len+1);
    // printf("------------s = %s\n", s);
    str = ft_split(s, '"');
    mode = 0;
    i = 0;
    free(s);
    while(*str)
    {
        s = *str;
        while(full && *s)
        {
            mode = change_mode2(mode, *s);
            expnd = NO_EXPANSION;
            if(mode != 1)
                if(*s == '$')
                {
                    // expnd = exit_status(*s);
                    // if (expnd == NO_EXPANSION)
                    expnd = exp_var(&s, expnd);
                    a = 1;
                }
            if (expnd == NO_EXPANSION)
                full = str_add(full, *s++, NULL);
            else
                full = str_add(full,0 , expnd);
        }
        str++;
    }
    if (full)
        return(t_init(VAR, len, full));
    return(t_init(WORD, len, lexer.str));
}