//ex-gslist-1.c
#include <stdio.h>
#include <glib.h>

void print_llengh(GSList *list)
{
    printf("The list is now %u items long\n", g_slist_length(list));
}

int main(int argc, char *argv[])
{
    GSList *list = NULL;
    print_llengh(list);

    list = g_slist_append(list, "first");
    print_llengh(list);  

    list = g_slist_append(list, "second");
    print_llengh(list);  

    g_slist_free(list);

    return 0;
}
