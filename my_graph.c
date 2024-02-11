//Ran Mizrahi 314809625
//my_graph.c

#include <stdio.h>
#include "my_mat.h"

int main() {
    char choice;
    int i, j, tf;
    int mat[SIZE][SIZE];
    //int graph[MAX_SIZE][MAX_SIZE];

    do {
        scanf(" %c", &choice);

        switch (choice) { 
            case 'A':
                getMatrix(mat);
                printf("done");
                break;
            case 'B':
                scanf("%d %d", &i, &j);
                //int arr[SIZE];
                tf = isPathExists(mat, i, j);
                if (tf == 1)
                {
                    printf("True\n");
                }
                else
                {
                    printf("False\n");
                }
                break;
            case 'C':
                scanf("%d %d", &i, &j);
                dijkstra(mat, i, j);
                break;
            case 'D':
                return 0;
            default:
                break;
        }
    } while (TRUE); //Infinite loop until the user chooses to exit

    return 0;
}