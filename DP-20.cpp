// Problem
// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. 
// You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;

// Memoization
int minCoins(int i, int target, vector<int>&v, vector<vector<int>>&dp){
    if (i == -1 or target < 0) return inf;
    if (target == 0) return 0;

    if (dp[i][target] != -1) return dp[i][target];
    
    // Pick
    int pick = 1 + minCoins(i, target - v[i], v, dp);
    // Non Pick
    int nonPick = minCoins(i-1, target, v, dp);

    return dp[i][target] = min(pick, nonPick);
}

// Tabulation
int minCoinsTab(int target, vector<int>&v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(target+1, inf));

    // Base Case
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int j = 1; j <= target; j++)
        if (j % v[0] == 0) dp[0][j] = j/v[0];

    // Filling the Table

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            int pick = inf;
            if (j - v[i] >= 0) pick = 1 + dp[i][j-v[i]];
            int nonPick = dp[i-1][j];

            dp[i][j] = min(pick, nonPick);
        }
    }

    return dp[n-1][target];
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int>v(n);
    for(int &x: v) cin>>x;

    vector<vector<int>>dp(n, vector<int>(target+1, -1));

    cout<<minCoins(n-1, target, v, dp)<<endl;
    cout<<minCoinsTab(target, v);
}

/* Sample Test Case
4 10
4 1 2 6 

6 10
13 17 20 19 1 8 
*/

// Output
// 2
// 3