// // // Q. DP3 Follow Up
// Instead of i->i+1, i->i+2
// The frog can now jump : i->i+1, i->i+2, i->i+3, .... , i->i+k
// With subsequent loss of energy = abs(height(i) - height(i+k))

#include<bits/stdc++.h>

using namespace std;


// Memoization

int frogJumpK(int n, int k, vector<int>&heights, vector<int>&dp){
    if (n == 0) return 0;

    if (dp[n] == -1){
        int mn = INT_MAX;
        for(int i = n-1; i >= 0 and i >= n-k; i--){
            mn = min(mn, frogJumpK(i, k, heights, dp) + abs(heights[n]-heights[i]));
        }
        dp[n] = mn;
    }

    return dp[n];
}

int findMinimumEnergy(int n, int k, vector<int>&heights){
    vector<int>dp(n, -1);
    return frogJumpK(n-1, k, heights, dp);
}

// Tabulation

int findMinEnergy(int n, int k, vector<int>&heights){
    vector<int>dp(n, -1);

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int mn = INT_MAX;
        for(int j = i-1; j >= 0 and j >= i-k; j--){
            mn = min(mn, dp[j] + abs(heights[j] - heights[i]));
        }

        dp[i] = mn;
    }

    return dp[n-1];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int>heights(n);
        for(auto &it : heights) cin>>it;

        cout<<findMinimumEnergy(n, k, heights)<<endl;
        cout<<findMinEnergy(n, k, heights)<<endl<<endl;
    }
}

/* Test Cases
4
20 3
7 2 3 6 9 6 10 10 10 3 2 7 7 4 9 5 10 5 8 7 
29 2
7 2 8 3 3 5 8 2 2 2 7 7 6 9 1 2 8 1 7 4 9 7 2 1 5 7 6 3 1 
29 5
5 8 4 4 8 6 3 4 8 7 4 1 7 4 7 2 5 5 10 8 4 5 8 7 6 7 5 8 9 
28 6
8 4 2 10 10 7 10 10 8 1 10 5 4 4 2 10 10 5 1 2 7 4 2 4 10 10 10 1 
*/

// Output
// 12
// 44
// 4
// 7