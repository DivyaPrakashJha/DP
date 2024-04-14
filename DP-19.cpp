// 0/1 Knapsack Problem

// Given N items where each item has some weight and profit associated with it and also given a bag with capacity W,
// [i.e., the bag can hold at most W weight in it]. 
// The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible. 

// Note: The constraint here is we can either put an item completely into the bag or cannot put it at all 
// [It is not possible to put a part of an item into the bag].

#include<bits/stdc++.h>

using namespace std;

// Recursive

int knapsack01R(int n, int w, vector<int>&weight, vector<int>&value){
    if (n == 0){
        if (weight[0] <= w){
            return value[0];
        }
        
        return 0;
    }
    
    int pick = 0;
    if (weight[n] <= w) pick = value[n] + knapsack01R(n-1, w-weight[n], weight, value);
    int nonPick = knapsack01R(n-1, w, weight, value);

    return max(pick, nonPick);
}

// Memoization

int knapsack01M(int n, int w, vector<int>&weight, vector<int>&value, vector<vector<int>>&dp){
    if (n == 0){
        if (weight[0] <= w){
            return value[0];
        }
        
        return 0;
    }
    
    if (dp[n][w] != -1) return dp[n][w];

    int pick = 0;
    if (weight[n] <= w) pick = value[n] + knapsack01M(n-1, w-weight[n], weight, value, dp);
    int nonPick = knapsack01M(n-1, w, weight, value, dp);
     
    return dp[n][w] = max(pick, nonPick);
}

// Tabulation

int knapsack01T(int n, int w, vector<int>&weight, vector<int>&value){
    vector<vector<int>>dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            if (weight[i] <= j){
                dp[i][j] = max(value[i] + dp[i-1][j-weight[i]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}

int main(){
    int n, w;
    cin>>n>>w;

    vector<int>weight(n), value(n);
    for(int i = 0; i < n; i++){
        cin>>value[i];
    }
    for(int i = 0; i < n; i++){
        cin>>weight[i];
    }


    cout<<knapsack01R(n-1, w, weight, value)<<endl;

    vector<vector<int>>dp(n, vector<int>(w+1, -1));
    cout<<knapsack01M(n-1, w, weight, value, dp)<<endl;

    cout<<knapsack01T(n, w, weight, value);
}