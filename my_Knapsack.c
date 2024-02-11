//Ran Mizrahi 314809625
//my_Knapsack.c

#include <stdio.h>
#include <string.h>

#define NUM_ITEMS 5
#define MAX_ITEM 20
#define CAPACITY 20


void getItems(char[][MAX_ITEM], int[], int[]);

int knapSack (int[], int[] , int[]);

int max(int, int);

void fillSelected(int[][CAPACITY + 1], int[], int[], int[]);

void fillResult(int[], char[][MAX_ITEM], char[][MAX_ITEM]);


int main() {
    char items[NUM_ITEMS][MAX_ITEM];
    char result[NUM_ITEMS][MAX_ITEM];
    int weights[NUM_ITEMS], values[NUM_ITEMS];
    int selected_bool[NUM_ITEMS] = {0};
    int i, max_value;

    getItems(items, weights, values);
    max_value = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d\n", max_value);

    fillResult(selected_bool, result, items);

    printf("Selected items:");
    for (i = 0; i < NUM_ITEMS; i++) 
    {
        printf(" %s", result[i]);
    }

    return 0;
}

/**
 * This function prompts the user to input details for a list of items including their names, weights, and values.
 * It populates the provided arrays with the inputted data.
 * 
 * @param items An array of strings to store the names of the items.
 *              Each string should be of length MAX_ITEM or greater.
 * @param weights An array of integers to store the weights of the items.
 *                It must have enough space to hold NUM_ITEMS elements.
 * @param values An array of integers to store the values of the items.
 *               It must have enough space to hold NUM_ITEMS elements.
 * 
 * @return void
 */
void getItems(char items[][MAX_ITEM], int weights[], int values[]) {
    int i;

    // Input weights and values for each item
    for (i = 0; i < NUM_ITEMS; i++) 
    {
        scanf("%s", items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
}

/**
 * Returns the maximum of two integers.
 * 
 * @param a An integer representing the first value.
 * @param b An integer representing the second value.
 * 
 * @return The maximum of the two integers: 'a' if it is greater than 'b', otherwise 'b'.
 */
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

/**
 * Solves the 0/1 knapsack problem given item weights, values, and a capacity constraint.
 * It returns the maximum value that can be obtained by selecting a subset of the items.
 * 
 * @param weights An array of integers representing the weights of the items.
 *                It must have enough space to hold NUM_ITEMS elements.
 * @param values An array of integers representing the values of the items.
 *               It must have enough space to hold NUM_ITEMS elements.
 * @param selected_bool An array of integers representing whether each item is selected (1) or not selected (0).
 *                      It must have enough space to hold NUM_ITEMS elements.
 * 
 * @return The maximum value that can be obtained by selecting a subset of the items.
 */
int knapSack (int weights[], int values[] , int selected_bool[]) {
    int arr[NUM_ITEMS + 1][CAPACITY + 1];
    int i, w;

    // Build table arr[][] in bottom up manner
    for (i = 0; i <= NUM_ITEMS; i++) 
    {
        for (w = 0; w <= CAPACITY; w++) 
        {
            if (i == 0 || w == 0)
            {
                arr[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                arr[i][w] = max(values[i - 1] + arr[i - 1][w - weights[i - 1]], arr[i - 1][w]);
            }
            else
            {
                arr[i][w] = arr[i - 1][w];
            }
        }
    }
    fillSelected(arr, selected_bool, weights, values);

    return arr[NUM_ITEMS][CAPACITY];
}

/**
 * Fills the selected_bool array to indicate which items are selected based on the dynamic programming table.
 * 
 * @param arr A 2D array representing the dynamic programming table.
 *            It contains the maximum values achievable with varying item selections and capacities.
 * @param selected_bool An array of integers representing whether each item is selected (1) or not selected (0).
 *                      It must have enough space to hold NUM_ITEMS elements.
 * @param weights An array of integers representing the weights of the items.
 *                It must have enough space to hold NUM_ITEMS elements.
 * @param values An array of integers representing the values of the items.
 *               It must have enough space to hold NUM_ITEMS elements.
 * 
 * @return void
 */
void fillSelected(int arr[][CAPACITY + 1], int selected_bool[], int weights[], int values[])
{
    int res = arr[NUM_ITEMS][CAPACITY];
    int w = CAPACITY;
    for (int i = NUM_ITEMS; i > 0 && res > 0; i--) 
    {
        if (res != arr[i - 1][w]) 
        {
            selected_bool[i - 1] = 1;
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }
}

/**
 * Fills the result array with the names of selected items based on the selected_bool array.
 * 
 * @param selected_bool An array of integers indicating whether each item is selected (1) or not selected (0).
 *                      It must have enough space to hold NUM_ITEMS elements.
 * @param result An array of strings to store the names of the selected items.
 *               Each string should be of length MAX_ITEM or greater.
 * @param items An array of strings representing the names of all available items.
 *              It must have enough space to hold NUM_ITEMS elements.
 * 
 * @return void
 */
void fillResult(int selected_bool[], char result[][MAX_ITEM], char items[][MAX_ITEM])
{
    int i, j = 0;
    for (i = 0; i < NUM_ITEMS; i++)
    {
        if (selected_bool[i] == 1)
        {
            strcpy(result[j], items[i]);
            j++;
        }
    }
}