#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define D printf("Here: %d\n", __LINE__);
#else
#define D
#endif


#define datatype int

typedef struct tree
{
    datatype key;
    struct tree *left, *right, *parent;
} tree;

void btUpView(tree *);

void insert(tree **root,int key, tree *pt) {
    if(!(*root))
    {
// дерево пустое или дошли до нужного места
        *root=(tree *)calloc(1,sizeof(tree));
        (*root)->key=key;
        (*root)->parent=pt;
// c calloc строчка ниже не нужа
        (*root)->left=(*root)->right= NULL;
    }
    else if( key < (*root)->key)
        insert( &((*root)->left) ,key,*root);
    else
        insert( &((*root)->right),key,*root);
}

int main(int argc, char ** argv)
{
/*
        10
      /   \
     5     15
    / \   /  \
   3   7 13   18
  /   /
 1   6
*/
//10 5 15 3 7 13 18 1 6 0
    int index;
    tree *t = NULL;
    scanf("%d",&index);
    while(index)
    {
        insert(&t,index,NULL);
        scanf("%d",&index);
    }
    btUpView(t);   //для  7-2 задачи

    return 0;
}

