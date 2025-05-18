#include <stdio.h>
#include "header.h"

int main() {
    
    Isi_Tree tree;
    CreateSampleTree(tree);

    // Contoh penggunaan traversal
    printf("PreOrder Traversal:\n");
    PreOrder(tree);

    printf("\nInOrder Traversal:\n");
    InOrder(tree);

    printf("\nPostOrder Traversal:\n");
    PostOrder(tree);

    printf("\nLevelOrder Traversal:\n");
    Level_order(tree, 10);

    return 0;
}