# include "parser.h"
void	print_node_argv(char **argv)
{
	// char	**argv = node->argv;
	// t_rdr	*s = (t_rdr *)node->rdrlst;

	// printf("f = %d\n", s->type);
	while (argv && *argv)
		printf("%s\n", *argv++);
}
int main()
{
    t_cmd *list;
    t_wc_node   **wc_;
    char **av;
    t_lexer *lexer;
    t_rdr_node *rdr;

    // *wc_ = wc_ld_create("*");
    // list = ft_new_cmd("aaa", NULL);
    // list->next = ft_new_cmd("aaa", wc_);
    lexer = lex_init("<< as");
    rdr = collect_rdr(lexer, rdr);
    // av = av_creat(&list);
    // print_node_argv(av);
    // cmd_clear(&list);
    printf("%d\n", cmd_size(list));
}