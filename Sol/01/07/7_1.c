#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;//datatype 
    struct tree *left, *right;
    struct tree *parent; // необязательное поле
} tree;


void preorder(tree *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->key);
    if(root->left)//! NULL
        preorder(root->left);
    if(root->right)//! NULL
        preorder(root->right);
}

void inorder(tree *root) {
    if(root == NULL)
        return;
    if(root->left)    
        inorder(root->left);
    printf("%d ",root->key);
    if(root->right)
        inorder(root->right);
}

void postorder(tree *root)
{
    if(root == NULL)
        return;
    if(root->left)
        postorder(root->left);
    if(root->right)
        postorder(root->right);
    printf("%d ",root->key);
}


//Вычисляем высоту дерева
int heightTree(tree* p)
{
    if (p == NULL)
        return 0;
    else
    {
        /* вычисляем высоту каждого поддерева */
        int lheight = heightTree(p->left);
        int rheight = heightTree(p->right);
 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
//Печатаем все узлы на уровне level
void printCurrentLevel(tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        //если поменять местами то будет обход справа на лево
        printCurrentLevel(root->left,  level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
//функция печати
void printBFS(tree* root)
{
    int h = heightTree(root);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

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

int main(void)
{
    tree *tr = NULL;
    insert(&tr,10,NULL);
    insert(&tr,5, NULL);
    insert(&tr,15,NULL);
    insert(&tr,3, NULL);
    insert(&tr,7 ,NULL);  
    insert(&tr,18,NULL);  
    insert(&tr,1, NULL);    
    insert(&tr,6 ,NULL);
    printf("BFS (Breadth First Traversal)\n");    
    printBFS(tr);
    printf("\nInorder\n");    
    inorder(tr);  
    return 0;
}
