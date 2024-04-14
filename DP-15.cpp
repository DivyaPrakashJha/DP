// Problem

// Given an integer array nums, return true if you can partition the array into two subsets 
// such that the sum of the elements in both subsets is equal or false otherwise.

// -> We have to partition the array into two subsets such that summation of the elements of the both the sets are equal
// i.e. Let S be the sum of all the elements in the initial array, S1 and S2 be the sum of elements of subset-1 and subset-2
// S1 + S2 = S
// Since S1 = S2
// Therefore S1 = S2 = S/2
// Hence if we obtain a single subset whose sum is equal to S/2 then we can say that the sum of the other subset will also be equal to S/2

#include<bits/stdc++.h>

using namespace std;

// Memoization
bool partitionEqualSubsetSum(int i, int target, vector<int>&v, vector<vector<int>>&dp){
    if (target == 0) return true;
    if (target < 0 or i < 0) return false;

    if (dp[i][target] != -1) return dp[i][target];

    // Pick
    if (partitionEqualSubsetSum(i-1, target - v[i], v, dp)) return true;

    // Non-Pick
    if (partitionEqualSubsetSum(i-1, target, v, dp)) return true;

    return dp[i][target] = false;
}

// Tabulation
bool partitionEqualSubsetSumTab(int target, vector<int>&v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(target+1, 0));

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
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i = 0; i < n; i++) cin>>v[i];

    int target = accumulate(v.begin(), v.end(), 0);

    if (target & 1) cout<<0;
    else{
        vector<vector<int>>dp(n, vector<int>(target/2 + 1, -1));
        cout<<partitionEqualSubsetSum(n-1, target/2, v, dp)<<endl;
        cout<<partitionEqualSubsetSumTab(target/2, v);
    }
}