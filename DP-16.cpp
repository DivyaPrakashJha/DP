// Problem

// You are given an array 'arr' containing 'n' non-negative integers.
// Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.

// Note:
// 1. Each array element should belong to exactly one of the subsets.
// 2. Subsets need not always be contiguous.
// 3. Subset-sum is the sum of all the elements in that subset.

// -> Let the sums of the two subsets be S1 and S2 and the total sum of the original array be S
// => S1 + S2 = S
// => Therefore if we know that a subset with sum S1 is possible, the sum of the other subset will be S2 i.e. (S-S1) automatically
// Now, S1 - S2 = D assuming S1 >= S2 
// => D = S1 - (S-S1)
// => D = 2S1 - S
// As we have to minimize D, We will iterate from S/2 to S and check if it is possible to obtain S_i
// Then, D = 2S_j - S where S_j is the first possible subset sum in the range discussed above

// We will simply use the dp table that we made in DP-15 to check the above

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(auto &x: v) cin>>x;

    int sum = accumulate(v.begin(), v.end(), 0);
    vector<vector<int>>dp(n, vector<int>(sum+1, 0));

    dp[0][0] = 1;
    dp[0][v[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= sum; j++){
            if (j - v[i] >= 0) dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    // Iterating and Checking if sum S_i is possible
    
    int d = sum; // Considering the first Subset to be the entire array and the second subset to be empty

    for(int i = (sum+1)/2; i <= sum; i++){
        if (dp[n-1][i] == 1){
            d = 2*i - sum;
            break;
        }
    }

    cout<<d;
}