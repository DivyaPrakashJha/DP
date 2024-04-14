// Problem

// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

#include<bits/stdc++.h>

using namespace std;

// Memoization

bool subsetSumEqualsK(int i, int target, vector<int>&v, vector<vector<int>>&dp){
    if (target == 0) return 1;
    if (i < 0 or target < 0) return 0;

    if (dp[i][target] != -1) return dp[i][target];

    // Pick
    if (subsetSumEqualsK(i-1, target-v[i], v, dp)) return dp[i][target] = 1;

    // Non Pick
    if (subsetSumEqualsK(i-1, target, v, dp)) return dp[i][target] = 1; 

    return dp[i][target] = 0;
}

// Tabulation

bool subsetSumEqualsKTab(vector<int>&v, int target){
    int n = v.size();

    vector<vector<bool>>dp(n, vector<bool>(target+1, 0));

    // Base Case
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if (v[0] <= target) dp[0][v[0]] = 1;

    // Filling the table
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            if (j - v[i] >= 0) dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n-1][target];
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int>v(n);
    for(int i = 0; i < n; i++) cin>>v[i];

    vector<vector<int>>dp(n, vector<int>(target+1, -1));

    cout<<subsetSumEqualsK(n-1, target, v, dp)<<endl;
    cout<<subsetSumEqualsKTab(v, target);

}

/* Sample Test Cases
10 172
8 59 58 79 44 7 65 69 60 51

10 114
5 8 48 82 82 54 5 90 37 89 

10 109
68 41 9 52 54 45 13 13 58 1 

10 19
60 15 13 10 7 29 47 48 90 70
*/

// Output
// 1
// 0
// 1
// 0
