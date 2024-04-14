// Problem

// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. 
// Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ 
// and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. 

// Since the answer may be too large, return it modulo ‘10^9 + 7’.

// If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:
// 1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
// 2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2.
// Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.


// -> Since S1 + S2 = S (Total Sum of the original array)
// and S1 - S2 = D
// => S1 - (S-S1) = D
// => 2S1 - S = D
// => S1 = (D+S)/2

// Hence, this problem reduces to finding the number of subsets whose sum of elements is equal to (D+S)/2. Refer DP -17

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

// Memoization
int countSubsets(int i, int target, vector<int>&v, vector<vector<int>>&dp){
    if (target < 0) return 0;
    if (i < 0){
        if (target == 0) return 1;
        return 0;
    }

    if (dp[i][target] != -1) return dp[i][target];

    // Pick
    int pick = countSubsets(i-1, target - v[i], v, dp);

    // Non-Pick
    int nonPick = countSubsets(i-1, target, v, dp);

    return dp[i][target] = (pick + nonPick)%mod;
}

// Tabulation
int countSubsetsTab(int target, vector<int>&v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(target+1, 0));

    // Base Case
    dp[0][0] = 1;
    if (v[0] <= target) dp[0][v[0]] = 1;

    // Filling the table
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            if (j - v[i] >= 0) dp[i][j] = (dp[i-1][j - v[i]] + dp[i-1][j])%mod;
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n-1][target];
}

int main(){
    int n, d;
    cin>>n>>d;

    vector<int>v(n);
    for(auto &x: v) cin>>x;

    int target = (d + accumulate(v.begin(), v.end(), 0) );
    if (target%2) cout<<0;
    else{
        target/=2;

        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        cout<<countSubsets(n-1, target, v, dp)<<endl;
        cout<<countSubsetsTab(target, v);
    }
    
}

/* Sample Test Cases
11 48
13 3 11 3 13 12 13 13 10 4 2

10 11
9 14 7 2 11 9 8 8 1 10

12 9
6 3 8 7 4 10 4 7 7 4 7 4
*/

// Outputs
// 0
// 26
// 127