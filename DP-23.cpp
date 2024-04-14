// Problem

// Unbounded Knapsack

// You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
// You need to fill the knapsack with the items in such a way that you get the maximum profit. 
// You are allowed to take one item multiple times.

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

// Memoization
int maxProfit(int ind, int w, vector<int>&profit, vector<int>&weight, vector<vector<int>>&dp){
    if (w < 0) return -inf;
    if (ind < 0) return 0;
    
    if (dp[ind][w] != -1) return dp[ind][w];

    int pick = profit[ind] + maxProfit(ind, w-weight[ind], profit, weight, dp);
    int nonPick = maxProfit(ind-1, w, profit, weight, dp);

    return dp[ind][w] = max(pick, nonPick);
}

// Tabulation
int maxProfit(int n, int w, vector<int>&profit, vector<int>&weight){
    vector<vector<int>>dp(n+1, vector<int>(w+1, 0));

    for(int j = 0; j <= w; j++){
        if (j % weight[0] == 0) dp[0][j] = profit[0] * (j/weight[0]);
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= w; j++){
            if (j - weight[i] >= 0) dp[i][j] = max(profit[i] + dp[i][j-weight[i]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n-1][w];
}

int main(){
    int n, w;
    cin>>n>>w;

    vector<int>profit(n), weight(n);
    for(int i = 0; i < n; i++) cin>>profit[i];
    for(int i = 0; i < n; i++) cin>>weight[i];

    vector<vector<int>>dp(n+1, vector<int>(w+1, -1));
    cout<<maxProfit(n-1, w, profit, weight, dp)<<endl;
    cout<<maxProfit(n, w, profit, weight);
}

/* Sample Test Case
4 8
1 4 5 7
1 3 4 5

10 5
3 4 9 7 5 10 8 2 6 1 
10 8 6 3 1 9 5 7 4 2 
*/

// Output
// 11
// 25
