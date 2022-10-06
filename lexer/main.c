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
int main()
{
    t_lexer *lex ;
    t_token tok ;
    char    **env;


    // glb_v.list = create_env(env);
    *lex = lex_init("echo *_*x* jdsk");
    // tok = get_token(lex);
    while(tok.type != ERROR)
    {
        tok = get_next_token(lex);
        put_str(tok.pos, tok.len);
    }
    return (0);
}