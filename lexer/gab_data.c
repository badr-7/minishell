int    jump_sinq(char *str, int i)
{
    while(str[i] == 39)
        i++;
    return(i);
}

int    collect_s(char *str, int i)
{
    while(str[i] != 39)
        i++;
    return (i);
}

bool    sigq_count(char *str,int  i)
{
    int j;

    j = 0;
    while(str[i] &&  (ft_strchr(" \t\n|&()<>\"", str[i])))
    {
        if(str[i] == 39)
            j++;
        i++;
    }
    if(j % 4 == 0)
        return(true);
    else
        return(false);
}



void    ft_exand_utils(int *i, int *j, int *b, char *str)
{
    *j = *i;
    if(str[*j] == '$')
        (*j)--;
    if(str[(*b) + 1] == '$')
        (*b)++;
}

char    *expand(char *str, int j, t_env_node  *node)
{
    int i;
    int b;
    char *dest;
    
    dest = NULL;
    i = j;
    while (str[i] != '\0' && (ft_strchr(" \t\n|&()<>\"", str[i])))
    {
        b = j;
        if(str[i] == '$' || str[i + 1] == '\0' || str[i + 1] == '"' || str[i + 1] == ' ')
        {
            ft_exand_utils(&i, &j, &b, str);
            if ((node = env_find(glb_v.list, ft_substr(str, b + 1 , j - b), -1)))
                if (dest == NULL)
                    dest = node->content;
                else
                {
                    puts("2\n");
                    dest = ft_strjoin(dest, node->content);
                    
                }
            else
                if(!dest)
                    dest = ft_strdup("");
                else
                    continue ;
        }
        i++;
    }
    return(dest);
}
char    *sigle_q_handling(t_lexer *lexer , t_env_node  *node, int b)
{
    int     mode;
    char    *s;
    char    *dest;
    int     beg = 0;
    int     end = 0;
    
    
    mode = 0;
    if(sigq_count(lexer->str, b))
    {
        beg = jump_sinq(lexer->str, b);
        end = collect_s(lexer->str, beg);
        s = ft_substr(lexer->str, beg , end - beg);
        while(lexer->str[end] == 39)
            end++;
        printf("s = %s\nbeg = %d\nend = %d\n", s, beg, end);
    }
    while(lexer->str[b] && (ft_strchr(" \t\n|&()<>", lexer->str[b])))
    {
        mode = change_mode(mode, lexer->str[b]);
        printf("mode = %d\nstr[b] = %c\n",mode, lexer->str[b]);
        if(lexer->str[b] == '$' && mode == 0)
        {
           if ((node = env_find(glb_v.list,s + 1, -1)))
            {
                    free(s);
                    s = node->content;
                    lexer->str =+ end;
                    return(s);
            }
        }
        b++;
    }
    return(s);
}
t_token lex_var(t_lexer lexer, int i)
{
    char *dest;
    t_env_node  *node;
    int         j;
    int         b;

    dest = NULL;
    j = 0;
    if (lexer.prev_type.type == HERDOC)
        return (t_init(WORD, i, lexer.str));
    while (lexer.str[j] && lexer.str[j] == '"')
        j++;
    b = j;
    while (lexer.str[b] && b < i)
    {
        if(!(ft_strchr(" $\'\t\n|&()<>", lexer.str[b])))
            break;
        b++;
    }
    if (lexer.str[b] == 39)
       dest = sigle_q_handling(&lexer, node, b);
     printf("node = %s\n", dest);
    // if (b > j)
    //      dest = ft_substr(lexer.str, j , b - j);
    // printf("b = %d\nj = %d\ndest = %s\n", b, j,dest);
    if (lexer.str[b] == '$')
    {
        if(dest)
            dest = ft_strjoin(dest, expand(lexer.str, j, node));
        else
            dest = expand(lexer.str, j, node);
        if(dest)
            return (t_init(VAR, i , dest));
    }
    free(dest);
    return (t_init(WORD, i, lexer.str));
}