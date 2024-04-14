// Problem

// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7

// Constraints:
// 1 <= 'n' <= 100
// 0 <= 'arr[i]' <= 1000
// 1 <= 'k' <= 1000

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

// Memoization
int countSubsetsWithSumK(int i, int target, vector<int>&v, vector<vector<int>>&dp){
    
    // Base Case
    if (target < 0) return 0;
    if (i == -1){
        if (target == 0) return 1;
        return 0;
    }
    
    // OR

    // if (i == 0){
    //     if (target == 0 and v[0] == 0) return 2;
    //     if (target == 0) return 1;
    //     if (target == v[0]) return 1;
    //     return 0;
    // }

    if (dp[i][target] != -1) return dp[i][target];

    // Pick
    int pick = countSubsetsWithSumK(i-1, target - v[i], v, dp);

    // Non Pick
    int nonPick = countSubsetsWithSumK(i-1, target, v, dp);

    return dp[i][target] = (pick + nonPick)%mod;
}

// Tabulation
int countSubsetsWithSumKTab(int target, vector<int>v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(target+1, 0));

    // Base Case
    if (v[0] <= target) dp[0][v[0]] = 1;
    if (v[0] == 0) dp[0][0] = 2;   
    else dp[0][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int pick = 0;
            if (j - v[i] >= 0) pick = dp[i-1][j - v[i]];
            int nonPick = dp[i-1][j];

            dp[i][j] = (pick + nonPick)%mod;
        }
    }

    return dp[n-1][target];
}

int main(){
    int n, k;
    cin>>n>>k;

    vector<int>v(n);
    for(auto &x: v) cin>>x;

    vector<vector<int>>dp(n, vector<int>(k+1, -1));

    cout<<countSubsetsWithSumK(n-1, k, v, dp)<<endl;
    cout<<countSubsetsWithSumKTab(k, v);
}

/* Sample Test Cases
15 7
2 2 1 7 3 3 1 7 9 6 7 4 2 7 5 

17 7
0 2 2 1 7 3 3 1 0 7 9 6 7 4 2 7 5 
*/

// Output
// 34
// 136