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
tree * findBrother(tree *, int );


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

 /*   int origin;
    scanf("%d", &origin);
    tree * tmp = findBrother(t,origin);
    printf("%d\n", tmp==NULL?0:tmp->key);*/

    return 0;
}


tree * findBrother(tree *root, int key)
{

    int was_in_bottom;

    tree * it = root;
    tree * left_edge = root;
    tree * right_edge = root;

    while(NULL != left_edge && NULL != left_edge->left)
    {
        left_edge = left_edge->left;
    }

    while(NULL != right_edge && NULL != right_edge->right)
    {
        right_edge = right_edge->right;
    }
    it = left_edge;
    while(it != right_edge)
    {
        if(NULL == it || NULL == it->parent)
        {
            continue;
        }
        else
        {
            if(it->key == key)
            {
                if (it == it->parent->left)
                {
                    return it->parent->right;
                }
                else
                {
                    return it->parent->left;
                }
            }
        }

#ifdef DEBUG
    printf("it: %d\n", it->key);
#endif
        if(it == it->parent->left && it->parent->right != NULL) // от левого идём к правому если он есть
        {
            it = it->parent->right;
            was_in_bottom = 0;
        }
        else if (NULL != it->left && !was_in_bottom) //если уже на правом, смотрим, можно ли спуститься вниз
        {
            it = it->left;
        }
        else if(NULL != it->parent) //иначе идём вверх
        {
            it=it->parent;
            was_in_bottom = 1;
        }
    }
    return NULL;
}

void btUpView(tree *root)
{
    tree * it;
    tree * left_edge = root;


    while(NULL != left_edge && NULL != left_edge->left)
    {
        left_edge = left_edge->left;
    }

    it = left_edge;
    while(it != root)
    {
        printf("%d ", it->key);
        it = root;
        while( it->left != left_edge )
        {
            it = it->left;
        }
        left_edge = it;
    }



    it = root;
    while(NULL != it)
    {
        printf("%d ", it->key);
        it = it->right;
    }

    printf("\n");
}

