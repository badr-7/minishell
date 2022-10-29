
#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>

void	print_node_argv(t_node *node)
{
	char	**argv = node->argv;

	while (argv && *argv)
		printf("%s\n", *argv++);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	t_parser_node	*tree;

	if (sh_state_init(argc, argv, envp))
		return (1);
	line = readline("$");
	while (line)
	{
		if (ft_strspn(line, " \n\t") < ft_strlen(line))
			add_history(line);
		tree = parse_input(line);
		print_node_argv(tree);
		node_tree_clear(&tree);
		free(line);
		line = readline("$");
	}
	sh_state_destroy();
}
