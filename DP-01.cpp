// Those who cannot remember the past are condemned to repeat it -- DP

// DP
// 1. Tabulation -> Bottom-Up
// 2. Memoization -> Top-Down

#include <bits/stdc++.h>

using namespace std;

#define int long long


vector<int>dp(10000, -1);

// // // Fibonacci Number

// // Memoization - We tend to store the value of subproblems in some map/table
// Overlapping sub-problems

int fibMemo(int n){
    if (n == 1) return 1;
    if (n == 0) return 0;

    if (dp[n] == -1){
        dp[n] = fibMemo(n-1) + fibMemo(n-2);
    }
    
    return dp[n];
}

// T.C = O(n)
// S.C = O(n) + O(n) -> DP Array + Recursion Stack Space 

// // Tabulation
int fibTab(int n){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// T.C = O(n)
// S.C = O(n) -> DP Array

signed main(){
    int n;
    cin>>n;

    // If we want to avoid global array, we can pass the dp array or vector by reference to the function
    // vector<int>dp(1000, -1);
    // OR
    // int dp[1000];
    // memset(dp, -1, sizeof(dp));

    cout<<fibMemo(n)<<endl;
    cout<<fibTab(n)<<endl;
}