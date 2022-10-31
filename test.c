# include "parser.h"

int main()
{
    t_cmd *list;
    t_wc_node   **wc_;

    *wc_ = wc_ld_create("*");
    list = ft_new_cmd("aaa", wc_);

    cmd_clear(&list);
    printf("%d\n", cmd_size(list));
}