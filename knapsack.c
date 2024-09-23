#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to implement 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n+1][W+1];

    // Build the DP table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or zero capacity
            } else if (weights[i-1] <= w) {
                // Either include the item or exclude it
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];  // Exclude the item
            }
        }
    }

    // The value at dp[n][W] is the maximum value that can be attained
    return dp[n][W];
}

int main() {
    int n, W;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    // Input the weight and value of each item
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the knapsack function
    int maxValue = knapsack(W, weights, values, n);

    // Output the maximum value that can be attained
    printf("The maximum value that can be attained is: %d\n", maxValue);

    return 0;
}
