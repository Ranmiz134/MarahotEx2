#include <stdio.h>
#include <limits.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define INF INT_MAX


//The function to read the matrix from the user
void getMatrix(int[SIZE][SIZE]);

//The function print the shortest path matrix
void printShortestPaths(int[SIZE][SIZE]);

//Dijkstra's algorithm
void dijkstra(int[][SIZE], int, int);

// Function to find the vertex with the minimum distance value
int minDistance(int[], int[]);

//The function check if there is a path from vertex i to vertex j, if there is return 1 (true), else return 0 (false)
int isPathExists(int mat[SIZE][SIZE], int i, int j);

int isPathExistsHelper(int mat[SIZE][SIZE], int i, int j, int visited[]);
