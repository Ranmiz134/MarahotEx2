//Ran Mizrahi 314809625
//my_mat.c

#include <stdio.h>
#include "my_mat.h"

// Function to read the matrix from the user
void getMatrix(int mat[SIZE][SIZE]) 
{
    int i, j;
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++) 
        {
            scanf("%d", &mat[i][j]);
            printf("V");
        }
    }
}

//Helper function check if there is a path from vertex i to vertex j
int isPathExistsHelper(int mat[SIZE][SIZE], int i, int j, int visited[]) 
{
    if (i == j) 
    {
        return FALSE;
    }
    visited[i] = TRUE;
    if (mat[i][j] != 0) 
    {
        return TRUE;
    }
    for (int k = 0; k < SIZE; k++) 
    {
        if (mat[i][k] != 0 && !visited[k]) 
        {
            if (isPathExistsHelper(mat, k, j, visited)) 
            {
                return 1;
            }
        }
    }

    //if no path found from i to j
    return FALSE;
}

//Function to check if there is a path from vertex i to vertex j
int isPathExists(int mat[SIZE][SIZE], int i, int j) 
{
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE) 
    {
        return FALSE; 
    }
    int visited[SIZE] = {0};

    return isPathExistsHelper(mat, i, j, visited);
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < SIZE; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

//Taken from the internet
//Implementation of Dijkstra's algorithm
void dijkstra(int graph[][SIZE], int src, int dest) {
    int dist[SIZE]; // The output array. dist[i] will hold the shortest distance from src to i
    int visited[SIZE]; // visited[i] will be 1 if vertex i is included in the shortest path tree or if the shortest distance from src to i is finalized
   // int parent[SIZE]; // parent array to store the shortest path tree

    // Initialize all distances as INFINITE and visited[] as 0
    for (int i = 0; i < SIZE; i++) {
        dist[i] = INF;
        visited[i] = 0;
        //parent[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < SIZE - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < SIZE; v++) {
            // Update dist[v] only if is not in visited, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances and paths
    if (dist[dest] == INF || dist[dest] == 0) {
        printf("-1\n"); // If there's no path from src to dest
    } else {
        printf("%d\n", dist[dest]);
    }
}


