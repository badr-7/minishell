#include "lexer.h"
#include <stdlib.h>

t_glb_v glb_v;
#define NO_EXPANSION	((char *)-1)

void    put_str(char *s, int len)
{
    int i;

    i = 0;
    while(i < len)
        write(1, &s[i++], 1);
    write(1, "\n", 1);
}
// char    *exp_var(char **sp, t_env_node *node, char *expand)
// {
//     int		i;
//     char    *s;
//     char	*str;

//     i = 0;
//     s = *sp;
// 	if (s[i] == '$' && !ft_isalnum(s[i + 1]))
// 		 return (NO_EXPANSION);
// 	s++;
// 	i++;
// 	while (s[i] && (ft_isalnum(s[i]) || s[i]))
// 		i++;
//     str = ft_substr(s, 0, i);
// 	node = env_find(glb_v.list, str, i);
//     if(!node)
//         return (NO_EXPANSION);
// 	free(str);
// 	*sp = s + i;
// 	return(node->content);
// } 

int main(int ac, char **av, char *env[])
{
    t_lexer *lex ;
    t_token tok ;
    t_env_node  *node;
    char *s;
    char *expand;
    char *dest;

    // dest = ft_strdup("$USERd");
    expand = NO_EXPANSION;
    glb_v.list = create_env(env);
    // s = exp_var(&dest, node, expand);
    // if (s == NO_EXPANSION)
    //     return(0);
    // printf("%s\n", s);
    lex = lex_init("echo lalaUSER\"\"");
    // puts("2\n");
    // printf("lex.str = %s\n", lex->str);
     tok = get_token(*lex);
    // printf("%s\n", lex->str);
    while(tok.type != ERROR)
    {
        tok = get_next_token(lex);
        if(tok.type == VAR && tok.pos)
            put_str(tok.pos, ft_strlen(tok.pos));
        else
        put_str(tok.pos, tok.len);
    }
    return (0);
}

