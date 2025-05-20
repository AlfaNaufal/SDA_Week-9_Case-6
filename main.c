#include <stdio.h>
#include <conio.h>
#include "header.h"

int main() {
    
    Isi_Tree Tree, Tree2;
    CreateSampleTree(Tree);
    CreateSampleTree(Tree2);
    int max = nbElmt(Tree);
    int menu;
    char cari;

    do{
        mainMenu();
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\nPreOrder Traversal:\n");
                PreOrder(Tree);
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 2:
                printf("\nInOrder Traversal:\n");
                InOrder(Tree);
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 3:
                printf("\nPostOrder Traversal:\n");
                PostOrder(Tree);
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 4:
                printf("\nLevel Order Traversal:\n");
                Level_order(Tree, max);
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 5:
                printf("\nPrint Tree:\n");
                PrintTree(Tree);
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 6:
                printf("Masukkan node yang ingin dicari: ");
                scanf(" %c", &cari);
                if (Search(Tree, cari)) {
                    printf("Node '%c' ditemukan di tree.\n", cari);
                } else {
                    printf("Node '%c' TIDAK ditemukan.\n", cari);
                }
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 7:
                printf("Jumlah daun dalam tree: %d\n", nbDaun(Tree));
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 8:
                printf("Masukkan node yang ingin dicari levelnya: ");
                scanf(" %c", &cari);
                {
                    int lvl = Level(Tree, cari);
                    if (lvl != -1)
                    printf("Level node '%c' adalah %d\n", cari, lvl);
                else
                printf("Node tidak ditemukan.\n");
                }
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 9:
                printf("Kedalaman tree: %d\n", Depth(Tree));
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
                break;
            case 10:
                printf("Perbandingan tree :\n");
                if (CompareTree(Tree, Tree2)){
                    printf("tree Sama\n");
                }else{
                    printf("tree Tidak Sama\n");
                }
                break;
                printf("\n\nKlik apapun untuk kembali.\n");
                getch();
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }        

    }while (menu != 0);

    return 0;
}