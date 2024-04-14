// Problem

// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns.
// Each point in the grid has some cost associated with it.
// Find a path from top left i.e. [0, 0] to the bottom right i.e. [N - 1, M - 1] 
// which minimizes the sum of the cost of all the numbers along the path. 
// You need to tell the minimum sum of that path.
// Note:You can only move down or right at any point in time .

#include <bits/stdc++.h>

using namespace std;

#define inf 1e9

// Memoization

int minSum(int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp){
    if (n == 0 and m == 0) return grid[0][0];
    if (n < 0 or m < 0) return inf;

    if (dp[n][m] != -1) return dp[n][m];

    int mn = grid[n][m] + min(minSum(n-1, m, grid, dp), minSum(n, m-1, grid, dp));
    return dp[n][m] = mn;
}

// Tabulation

int minSum(int n, int m, vector<vector<int>>&grid){
    vector<vector<int>>dp(n, vector<int>(m, -1));

    dp[0][0] = grid[0][0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (i == 0 and j == 0) continue;

            dp[i][j] = grid[i][j];
            
            int x = inf, y = inf;
            if (i-1 >= 0) x = dp[i-1][j];
            if (j-1 >= 0) y = dp[i][j-1];

            dp[i][j] += min(x, y); 
        }
    }

    return dp[n-1][m-1];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        vector<vector<int>>grid(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>grid[i][j];
            }
        }

        vector<vector<int>>dp(n, vector<int>(m, -1));

        cout<<minSum(n-1, m-1, grid, dp)<<endl;
        cout<<minSum(n, m, grid)<<endl;
    }
}

/* Test Cases
2
6 6
6 1 11 15 3 9 
10 18 12 19 12 2 
20 8 17 8 11 5 
19 1 19 15 3 8 
13 10 20 9 7 5 
10 6 17 9 12 13 
3 6
6 20 9 16 8 11 
18 1 12 17 12 11 
19 17 18 13 16 17 
*/

// Output
// 78
// 94