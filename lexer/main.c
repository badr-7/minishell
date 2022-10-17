#include "lexer.h"
#include <stdlib.h>

t_glb_v glb_v;

void    put_str(char *s, int len)
{
    int i;

    i = 0;
    while(i < len)
        write(1, &s[i++], 1);
    write(1, "\n", 1);
}
int main(int ac, char **av, char *env[])
{
    t_lexer *lex ;
    t_token tok ;


    glb_v.list = create_env(env);
    lex = lex_init("cat $USER$USER$USER");
    // puts("2\n");
    // printf("lex.str = %s\n", lex->str);
    //  tok = get_token(lex);
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

