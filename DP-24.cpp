// Problem

// Rod Cutting Problem

// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. 
// Determine the maximum cost obtained by cutting the rod and selling its pieces.

// Note : 
// 1. The sizes will range from 1 to ‘N’ and will be integers.
// 2. The sum of the pieces cut should be equal to ‘N’.
// 3. Consider 1-based indexing. (i.e. index 0 represents price for rod of length 1)

// -> We can reduce this problem to unbounded knapsack problem where we can think of picking up lengths that sum up to N.

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

// Memoization
int maxCost(int ind, int length, vector<int>&v, vector<vector<int>>&dp){
    if (length < 0 or ind < 0) return -inf;
    if (length == 0) return 0;

    if (dp[ind][length] != -1) return dp[ind][length];

    int pick = v[ind] + maxCost(ind, length - (ind+1), v, dp);
    int nonPick = maxCost(ind-1, length, v, dp);

    return dp[ind][length] = max(pick, nonPick);
}

// Tabulation
int maxCost(vector<int>&v){
    int n = v.size();
    vector<vector<int>>dp(n, vector<int>(n+1, 0));

    for(int j = 0; j <= n; j++) dp[0][j] = v[0]*(j/1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            if (j-(i+1) >= 0) dp[i][j] = max(v[i] + dp[i][j-(i+1)], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n-1][n];
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];

    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    cout<<maxCost(n-1, n, v, dp)<<endl;
    cout<<maxCost(v);
}

/* Sample Test Cases
5
2 5 7 8 10

8
3 5 8 9 10 17 17 20
*/

// Output
// 12
// 24