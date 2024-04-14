// Problem

// You are present at point 'A' which is the top-left cell of an M X N matrix, 
// your destination is point 'B', which is the bottom-right cell of the same matrix. 
// Your task is to find the total number of unique paths from point 'A' to point 'B'.
// In other words, you will be given the dimensions of the matrix as integers 'M' and 'N', 
// your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX[M - 1][N - 1].
// To traverse in the matrix, you can either move Right or Down at each step. 
// For example in a given point MATRIX[i][j] you can move to either MATRIX[i + 1][j] or MATRIX[i][j+1]

#include<bits/stdc++.h>

using namespace std;

// T.C. of recursion will be 2^(nm)

// Memoization
int numberOfPaths(int n, int m, vector<vector<int>>&dp){
    if (n == 0 and m == 0) return 1;
    if (n < 0 or m < 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];

    int ways = numberOfPaths(n-1, m, dp) + numberOfPaths(n, m-1, dp);
    return dp[n][m] = ways; 
}

// T.C. - O(nm)

// Tabulation

int numPaths(int n, int m){
    vector<vector<int>>dp(n, vector<int>(m, 0));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (i-1 >= 0){
                dp[i][j] += dp[i-1][j];
            }
            if (j-1 >= 0){
                dp[i][j] += dp[i][j-1];
            }
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

        vector<vector<int>>dp(n, vector<int>(m, -1));
        cout<<numberOfPaths(n-1, m-1, dp)<<endl;
        cout<<numPaths(n, m)<<endl;
    }
}

/* Test Cases
10
3 2
5 4
5 7
4 4
3 5
4 6
7 3
2 5
1 5
3 3
*/

// Output
// 3
// 35
// 210
// 20
// 15
// 56
// 28
// 5
// 1
// 6