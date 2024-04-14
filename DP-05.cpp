// // // Q. Maximum Sum of Non-Adjacent Elements
// You are given an array/list of 'N integers. You are supposed to return the maximum sum of the
// subsequence with the constraint that no two elements are adjacent in the given array/list.

// Problem Link - https://bit.ly/3q5rlUY

// We try out all the possible subsequences and then find the maximum sum among them

// For subsequences, we can either pick an element or not pick the element

#include<bits/stdc++.h>

using namespace std;

// Memoization

int maxSum(int n, vector<int>&nums, vector<int>&dp){
    if (n == 0) return nums[0];
    if (n < 0) return 0;

    if (dp[n] == -1){
        // Pick
        int pick = nums[n] + maxSum(n-2, nums, dp); // If we pick the current element, then we cannot pick the prev so n-2

        // NonPick
        int nonPick = maxSum(n-1, nums, dp); // If we don't pick the current element, then we can pick the prev so n-1

        dp[n] = max(pick, nonPick);
    }

    return dp[n];
}


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    vector<int>dp(n, -1);
    return maxSum(n-1, nums, dp);
}

// T.C. - O(n)
// S.C. - O(n) + O(n)

// Tabulation

int maxSum(vector<int>&nums){
    int n = nums.size();

    vector<int>dp(n, -1);

    dp[0] = nums[0];
    if (n > 1) dp[1] = max(nums[0], nums[1]);
    
    for(int i = 2; i < n; i++){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

// T.C. - O(n)
// S.C. - O(n)

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);
        for(auto &it : v){
            cin>>it;
        }

        cout<<maximumNonAdjacentSum(v)<<endl;
        cout<<maxSum(v)<<endl;
    } 
}

/* Test Cases
4
4
9 9 8 2
4
8 5 8 8
4
5 8 7 2
4
3 10 10 7
*/

// Output
// 17
// 16
// 12
// 17