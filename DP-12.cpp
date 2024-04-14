// Problem

// You have been given an N*M matrix filled with integer numbers, 
// find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. 
// So from a particular cell (row, col), we can move in three directions i.e. down, down left diagonal, down right diagonal

#include<bits/stdc++.h>

using namespace std;

// Memoization
int maxSum(int n, int m, vector<vector<int>>&v, vector<vector<int>>&dp){
    if (m < 0 or m >= v[0].size()) return -1e8;
    if (n == 0) return dp[n][m] = v[0][m];

    if (dp[n][m] != -1) return dp[n][m];

    int top = maxSum(n-1, m, v, dp);
    int topLeft =  maxSum(n-1, m-1, v, dp);
    int topRight = maxSum(n-1, m+1, v, dp);
    
    return dp[n][m] = ( v[n][m] + max( {top, topLeft, topRight} ) );  
}

int maxSumM(vector<vector<int>>&v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>>dp(n, vector<int>(m, -1));

    int mx = -1e8;
    for(int i = 0; i < m; i++){
        mx = max(mx, maxSum(n-1, i, v, dp));
    }

    return mx;
}


// Tabulation
int maxSum(vector<vector<int>>&v){
    int n = v.size();
    int m = v[0].size();

    
    vector<vector<int>>dp(n, vector<int>(m, 0));

    for(int j = 0; j < m; j++){
        dp[0][j] = v[0][j];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = v[i][j];

            int x = dp[i-1][j], y = -1e8, z = -1e8;
            if (j-1 >= 0) y = dp[i-1][j-1];
            if (j+1 < m) z = dp[i-1][j+1];

            dp[i][j] += max({x, y, z});
        }
    }

    int mx = -1e8;
    for(int j = 0; j < m; j++){
        mx = max(mx, dp[n-1][j]);
    }

    return mx;
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

        cout<<maxSumM(v)<<endl;
        cout<<maxSum(v)<<endl;
    }
}

/* Sample Test Case
2
3 3
1 2 3
9 8 7
4 5 6
4 6
10 10 2 -13 20 4
1 -9 -81 30 2 5
0 10 4 -79 2 -10
1 -5 2 20 -11 4
*/

// Output
// 17
// 74