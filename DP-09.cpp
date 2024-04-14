// Problem

// Given a 'N' * 'M' maze with obstacles, 
// count and return the number of paths to reach the right-bottom cell from the top-left cell. 
// A cell in the given maze has a value -1 if it is a blockage or dead-end, else O. 
// From a given cell, we are allowed to move to cells (i+l, j) and (i, j+l) only. 
// Since the answer can be large, print it modulo 1e9 + 7.

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

// Memoization

int numPaths(int n, int m, vector<vector<int>>&v, vector<vector<int>>&dp){
    if (n == 0 and m == 0) return 1;
    if (n < 0 or m < 0) return 0;
    if (v[n][m] == -1) return 0;

    if (dp[n][m] != -1) return dp[n][m];

    int ways = numPaths(n-1, m, v, dp) % mod  + numPaths(n, m-1, v, dp) % mod;
    return dp[n][m] = ways % mod;
}

// Tabulation

int numPaths(int n, int m, vector<vector<int>>&v){
    vector<vector<int>>dp(n, vector<int>(m, 0));

    dp[0][0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (v[i][j] == -1) continue;
            
            if (i-1 >= 0) dp[i][j] += dp[i-1][j] % mod;
            if (j-1 >= 0) dp[i][j] += dp[i][j-1] % mod;
        }
    }

    return dp[n-1][m-1] % mod;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        vector<vector<int>>v(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>v[i][j];
            }
        }

        vector<vector<int>>dp(n, vector<int>(m, -1));
        cout<<numPaths(n-1, m-1, v, dp)<<endl;
        cout<<numPaths(n, m, v)<<endl;
    }
}

/* Test Cases
2
14 12
0 0 0 0 0 0 0 0 -1 0 -1 0 
0 0 -1 0 0 0 0 -1 -1 0 0 0 
0 -1 -1 0 0 -1 0 -1 0 0 0 -1 
-1 0 -1 0 0 -1 0 0 -1 0 -1 -1 
0 -1 0 0 0 0 0 0 -1 0 0 0 
-1 -1 0 0 0 0 -1 -1 -1 -1 0 0 
0 0 0 -1 -1 0 0 -1 0 0 0 0 
0 -1 -1 -1 0 0 0 -1 0 0 0 -1 
-1 0 0 -1 -1 -1 0 0 0 0 0 0 
0 0 -1 0 0 -1 -1 0 0 -1 -1 -1 
-1 0 0 -1 0 0 0 -1 0 0 0 0 
-1 0 0 0 0 -1 -1 0 -1 0 0 0 
0 0 0 -1 0 0 -1 0 0 0 0 0 
0 0 0 0 -1 0 0 0 0 0 0 0 
2 2
0 -1
-1 0
*/

// Output
// 440
// 0