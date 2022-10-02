#include "env.h"

int main(int ac, char *av[], char *env[])
{
    t_env_node  *list;
    list = create_env(env);

    // while (list)
	// {
        // env_find(list,"USER", 4);
		printf("%s\n",  env_find(list,"VSCODE_GIT_ASKPASS_MAIN", -1)->content);
		list = list->next;
	// }
	return (0);
}
