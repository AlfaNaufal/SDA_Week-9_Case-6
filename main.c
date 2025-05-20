#include <stdio.h>
#include "header.h"

int main() {
    
    Isi_Tree Tree;
    CreateSampleTree(Tree);
    int menu;
    char cari;

    // Contoh penggunaan traversal
    printf("PreOrder Traversal:\n");
    PreOrder(Tree);

    printf("\nInOrder Traversal:\n");
    InOrder(Tree);

    printf("\nPostOrder Traversal:\n");
    PostOrder(Tree);

    printf("\nLevelOrder Traversal:\n");
    Level_order(Tree, 10);


    return 0;
}