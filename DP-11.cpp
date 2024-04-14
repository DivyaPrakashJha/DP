// Problem

// You are given a triangular array/list 'TRIANGLE'. 
// Your task is to return the minimum path sum to reach from the top to the bottom row.
// The triangle array will have N rows and the i-th row, where O <= i < N will have i + 1 elements.
// You can move only to the adjacent number of row below each step.
// For example, if you are at index j in row i, then you can move to j or j + 1 index in row i + 1 in each step.

// We will start from the top as it is fixed, 
// f(i, j) indicates the minimum path sum from (i, j) to the last row

#include<bits/stdc++.h>

using namespace std;

#define inf INT_MAX

// Memoization
int minPath(int i, int j, int n, vector<vector<int>>&v, vector<vector<int>>&dp){
    if (i == n-1) return v[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = ( v[i][j] + min(minPath(i+1, j, n, v, dp), minPath(i+1, j+1, n, v, dp)) );
}

// Tabulation

int minPath(vector<vector<int>>&v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        dp[n-1][i] = v[n-1][i];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < i+1; j++){
            dp[i][j] = v[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    return dp[0][0];
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>>v;

    for(int i = 0; i < n; i++){
    	vector<int>x(i+1);
        for(int j = 0; j < i+1; j++) cin>>x[j];
        
        v.push_back(x);
    }
    
    vector<vector<int>>dp(n, vector<int>(n, -1));
	
    cout<<minPath(0, 0, n, v, dp)<<endl;
    cout<<minPath(v)<<endl;
}


/* Test Cases
4
2
3 4
6 5 7
4 1 8 3
*/