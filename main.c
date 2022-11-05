
#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>

t_glb_v glb_v;

void	node_tree_clear(t_parser_node **tree)
{
	t_parser_node	*node;

	node = *tree;
	if (node)
	{
		node_tree_clear(&node->left);
		node_tree_clear(&node->right);
		free(node);
		*tree = NULL;
	}
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_strchr(accept, s[i]))
		i++;
	return (i);
}


void	print_node_argv(t_parser_node *node)
{
	char	**argv = node->av;

	while (argv && *argv)
		printf("%s\n", *argv++);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	t_parser_node	*tree;

	if(argc < 2 && !argv[1])
	{
		glb_v.list = create_env(envp);
		line = readline("$");
		while (line)
		{
			if (ft_strspn(line, " \n\t") < ft_strlen(line))
				add_history(line);
			tree = parse(line);
			print_node_argv(tree);
			node_tree_clear(&tree);
			free(line);
			line = readline("$");
		}
	}
	// sh_state_destroy();
}
