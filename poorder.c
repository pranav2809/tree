#include <stdio.h>
#include <stdlib.h>
struct t1 {
    struct t1 *left;
    struct t1 *right;
    int data;
}*tt;
struct t1* fun(struct t1 *t)
{
    int l,r;
    t = (struct t1 *)malloc(sizeof(struct t1));
    printf("Data for this node:\n");
    scanf("%d",&(t->data));
    printf("Enter 1 for adding left child else 0\n");
    scanf("%d",&l);
    if(l)
        t->left=fun(t->left);
    else
        t->left = NULL;
    printf("Enter 1 for adding right child else 0\n");
    scanf("%d",&r);
    if(r)
        t->right=fun(t->right);
    else
        t->right = NULL;
    return t;
}
void postorder(struct t1 *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            postorder(t->left);

        if(t->right != NULL)
            postorder(t->right);

        printf("%d\n",t->data);
    }
}

void main()
{
    printf("~~~~~~~~~~~~~~~~~~~~~POST-ORDER METHOD~~~~~~~~~~~~~~~~~~~~~~``\n");
    tt=fun(tt);
    postorder(tt);
}
