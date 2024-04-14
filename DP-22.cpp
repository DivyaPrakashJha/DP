// Problem

// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
// You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. 
// Print 0, if a change isn't possible.

#include<bits/stdc++.h>

using namespace std;

// Memoization
int numWaysToMakeChange(int ind, int target, vector<int>&coins, vector<vector<int>>&dp){
    if (target < 0 or ind < 0) return 0;
    if (ind == 0 and target == 0) return 1;

    if (dp[ind][target] != -1) return dp[ind][target];

    // Pick
    int pick = numWaysToMakeChange(ind, target - coins[ind], coins, dp);

    // Non Pick
    int nonPick = numWaysToMakeChange(ind-1, target, coins, dp);

    return dp[ind][target] = pick + nonPick;
}

// Tabulation
int numWaysToMakeChange(int target, vector<int>&coins){
    int n = coins.size();

    vector<vector<int>>dp(n+1, vector<int>(target+1, 0));

    dp[0][0] = 1;
    for(int j = 0; j <= target; j++) 
        if (j%coins[0] == 0) dp[0][j] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            if (j - coins[i] >= 0) dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n-1][target];
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int>coins(n);
    for(auto &x : coins) cin>>x;

    vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
    cout<<numWaysToMakeChange(n-1, target, coins, dp)<<endl;
    cout<<numWaysToMakeChange(target, coins);
}

/* Sample Test Cases
4 5
1 2 3 4

3 4
1 2 3
*/

// Output
// 6
// 4

