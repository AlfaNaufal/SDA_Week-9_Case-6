#include <stdio.h>
#include "header.h"
#include "boolean.h"

void Create_tree(Isi_Tree X, int Jml_Node){
    for (int i = 1; i < Jml_Node; i++) {
        X[i].info = '\0';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }
}

void CreateSampleTree(Isi_Tree X) {

    Create_tree(X, jml_maks);

    X[1].info = 'A';
    X[1].ps_fs = 2;
    X[1].ps_nb = 0;
    X[1].ps_pr = 0;

    X[2].info = 'B';
    X[2].ps_fs = 4;
    X[2].ps_nb = 3;
    X[2].ps_pr = 1;

    X[3].info = 'C';
    X[3].ps_fs = 6;
    X[3].ps_nb = 0;
    X[3].ps_pr = 1;

    X[4].info = 'D';
    X[4].ps_fs = 0;
    X[4].ps_nb = 5;
    X[4].ps_pr = 2;

    X[5].info = 'E';
    X[5].ps_fs = 8;
    X[5].ps_nb = 0;
    X[5].ps_pr = 2;

    X[6].info = 'F';
    X[6].ps_fs = 0;
    X[6].ps_nb = 7;
    X[6].ps_pr = 3;

    X[7].info = 'G';
    X[7].ps_fs = 0;
    X[7].ps_nb = 9;
    X[7].ps_pr = 3;
    
    X[9].info = 'H';
    X[9].ps_fs = 0;
    X[9].ps_nb = 0;
    X[9].ps_pr = 3;

    X[8].info = 'I';
    X[8].ps_fs = 0;
    X[8].ps_nb = 10;
    X[8].ps_pr = 5;

    X[10].info = 'J';
    X[10].ps_fs = 0;
    X[10].ps_nb = 0;
    X[10].ps_pr = 5;
}

// void Create_tree(Isi_Tree X, int Jml_Node){
//     int i;
//     infotype data;
//     fo(i, n){
//         printf("Masukkan data node ke-%d: ", i);
//         scanf(" %c", &data);  
//         X[i].info = data;
//         X[i].ps_fs = nil;
//         X[i].ps_nb = nil;
//         X[i].ps_pr = nil;
//     }

    // fo(i, n){
    //     int child;
    //     printf("Masukkan child pertama dari %c (0 jika tidak ada): ", X[i].info);
    //     scanf("%d", &child);
    //     if(child != 0){
    //         X[i].ps_fs = child;
    //         X[child].ps_pr = i;

    //         int sibling = child;
    //         while(1){
    //             int next_sibling;
    //             printf("Masukkan next sibling dari %c (0 jika tidak ada): ", X[sibling].info);
    //             scanf("%d", &next_sibling);
    //             if(next_sibling == 0)
    //                 break;
    //             X[sibling].ps_nb = next_sibling;
    //             X[next_sibling].ps_pr = i;
    //             sibling = next_sibling;
    //         }
    //     }
    // }
// }

boolean IsEmpty (Isi_Tree P){
    return P[1].info == '\0';
}

/***** Traversal *****/
void PreOrder (Isi_Tree P){
    int current;
    boolean isResmi;

    current = 1;
    isResmi = true;

    printf("%c\n", P[current].info);

    // do{
    while(current != 0){

        if(P[current].ps_fs != 0 && isResmi){
            current = P[current].ps_fs;
            printf("%c\n", P[current].info);
        }else if(P[current].ps_nb != 0){
            current = P[current].ps_nb;
            printf("%c\n", P[current].info);
            isResmi = true;
        }else{
            current = P[current].ps_pr;
            isResmi = false;
        }
    }
        // }while(P[current].ps_pr != 0);

}

void InOrder (Isi_Tree P){

    int current;
    boolean isResmi;

    current = 1;
    isResmi = true;

    while(current != 0 ){
        if(P[current].ps_fs != 0 && isResmi){
            current = P[current].ps_fs;
        }else{
            // printf("%c\n", P[current].info);

            if(isResmi){
                printf("%c\n", P[current].info);
            }
            
            if(current == P[P[current].ps_pr].info){
                printf("%c\n", P[P[current].ps_pr].info);
            }
            
            if(P[current].ps_nb != 0){
                printf("%c\n", P[P[current].ps_pr].info);
                current = P[current].ps_nb;
                isResmi = true;
            }else{
                current = P[current].ps_pr;
                isResmi = false;
            }
        }
    }


}


void PostOrder (Isi_Tree P){

    int current;
    boolean isResmi;

    current = 1;
    isResmi = true;

    while(current != 0){
        if(P[current].ps_fs != 0 && isResmi){
            current = P[current].ps_fs;
            isResmi = true;
        }else{
            printf("%c\n", P[current].info);
            if(P[current].ps_nb != 0){
                current = P[current].ps_nb;
                isResmi = true;
            }else{
                current = P[current].ps_pr;
                isResmi = false;
            }
        }
    }
}

void Level_order(Isi_Tree X, int Maks_node){

    if (IsEmpty(X)) return;

    int max_depth = 0;
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0') {
            int current_depth = Level(X, X[i].info);
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
    }

    for (int depth = 0; depth <= max_depth; depth++) {
        for (int i = 1; i <= Maks_node; i++) {
            if (X[i].info != '\0' && Level(X, X[i].info) == depth) {
                printf("%c\n", X[i].info);
            }
        }
    }

}


void PrintTree (Isi_Tree P){

    int max = nbElmt(P);
    for (int i = 1; i <= max; i++) {
        if (P[i].info != '\0') {
            printf("--> index ke-%d \n", i);
            printf("info array ke %d          :  %c\n", i, P[i].info);
            printf("first son array ke %d     :  %d\n", i,  P[i].ps_fs);
            printf("next brother array ke %d  :  %d\n", i,  P[i].ps_nb);
            printf("parent array ke %d        :  %d\n", i,  P[i].ps_pr);
            printf("\n\n");
        }
    }
}
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */


/***** Search *****/
boolean Search (Isi_Tree P, infotype X){
    int current = 1;
    boolean found = false; 
    
    while(P[current].info != '\0' && !found){
        if (P[current].info == X){
            found = true;
        }else{
            current++;	
        }
    }
    
    return found;
}


/***** Fungsi Lain *****/


int nbElmt (Isi_Tree P){
    int current = 1;
    
    while(P[current].info != '\0'){
        current++;
    }
    
    return current;
    
}
/* Mengirimkan banyak elemen (node) di pohon non biner P */


int nbDaun (Isi_Tree P){
    int nDaun = 0, current = 1;
    boolean isResmi = true;

    while(current != 0){
        if(P[current].ps_fs != 0 && isResmi){
            current = P[current].ps_fs;
        }else{
            if(P[current].ps_fs == 0){ nDaun++;}
            if(P[current].ps_nb != 0){
                current = P[current].ps_nb;
                isResmi = true;
            }else{
                current = P[current].ps_pr;
                isResmi = false;
            }
        }
    }

    return nDaun;

}
/* Mengirimkan banyak daun (node) pohon non biner P */


int Level (Isi_Tree P, infotype X){
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int parent = P[i].ps_pr;
            while (parent != 0) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1; // jika X tidak ditemukan
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */


int Depth (Isi_Tree P){
    int max_depth = 0, max_node = nbElmt(P);

    for (int i = 1; i <= max_node; i++) {
        if (P[i].info != '\0') {
            int depth = 0;
            int current = i;
            while (P[current].ps_pr != 0) {
                depth++;
                current = P[current].ps_pr;
            }
            if (depth > max_depth)
                max_depth = depth;
        }
    }

    return max_depth;
}
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */


int Max (infotype Data1, infotype Data2){
    return (Data1 > Data2) ? Data1 : Data2;
}
/* Mengirimkan Nilai terbesar dari dua data */

boolean CompareTree(Isi_Tree T1, Isi_Tree T2) {
    for (int i = 1; i <= jml_maks; i++) {
        if (T1[i].info != T2[i].info ||
            T1[i].ps_fs != T2[i].ps_fs ||
            T1[i].ps_nb != T2[i].ps_nb ||
            T1[i].ps_pr != T2[i].ps_pr) {
            return false;
        }
    }
    return true;
}


void mainMenu(){
        printf("\n=== MENU NON-BINARY TREE ===\n");
        printf("1. PreOrder Traversal\n");
        printf("2. InOrder Traversal\n");
        printf("3. PostOrder Traversal\n");
        printf("4. Level Order Traversal\n");
        printf("5. Print Tree\n");
        printf("6. Search Node\n");
        printf("7. Jumlah Daun\n");
        printf("8. Level Node\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Bandingkan Dua Tree (Belum tersedia)\n");
        printf("0. Exit\n");
        printf("Pilih menu: ");
}