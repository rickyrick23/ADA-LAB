#include <stdio.h>
#include <limits.h>

#define MAX 20  // Maximum number of cities

int n;  // Number of cities
int dist[MAX][MAX];  // Distance matrix
int dp[MAX][(1 << MAX)];  // DP table for memoization

// A function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve TSP using dynamic programming and bitmasking
int tsp(int city, int mask) {
    if (mask == (1 << n) - 1) {  // If all cities have been visited
        return dist[city][0];  // Return the distance to the starting city
    }

    // If this state has been already computed, return the stored result
    if (dp[city][mask] != -1) {
        return dp[city][mask];
    }

    int ans = INT_MAX;  // Initialize the result to a large value

    // Try to visit each city that has not been visited yet
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if ((mask & (1 << nextCity)) == 0) {  // If the city has not been visited
            int newAns = dist[city][nextCity] + tsp(nextCity, mask | (1 << nextCity));
            ans = min(ans, newAns);  // Take the minimum result
        }
    }

    // Store the result in the DP table and return it
    dp[city][mask] = ans;
    return ans;
}

int main() {
    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize the DP table with -1 (meaning unvisited states)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from city 0 with an initial mask of 1 (city 0 is visited)
    int result = tsp(0, 1);

    // Output the result (minimum cost of visiting all cities)
    printf("The minimum cost of travelling all cities is: %d\n", result);

    return 0;
}
