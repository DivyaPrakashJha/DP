// Problem

// Mr. X is a professional robber planning to rob houses along a street. 
// Each house has a certain amount Of money hidden. All houses along this street are arranged in a circle.
// That means the first house is the neighbor of the last one. 
// Meanwhile, adjacent houses have a security system connected, and it Will automatically contact the police 
// if two adjacent houses were broken into on the same night.
// You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. 
// Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.


// Observation

// The answer cannot contain the first and the last element at the same time
// Either it will have the first element, or the second element or none
// So we will remove the first element and get a value and then remove the last element and get a value
// The max of the above two values will be the answer

#include<bits/stdc++.h>

using namespace std;

// Memoization

int maxMoney(int n, vector<int>&v, vector<int>&dp){
    if (n == 0) return v[0];
    if (n < 0) return 0;

    if (dp[n] == -1){
        int pick = v[n] + maxMoney(n-2, v, dp);
        int nonPick = maxMoney(n-1, v, dp);

        dp[n] = max(pick, nonPick);
    }
    
    return dp[n];
}

int maxMoneyRob(vector<int>&v){
    int n = v.size();
    
    vector<int>dp(n, -1);

    return maxMoney(n-1, v, dp);
}

// Tabulation

int maxMoney(vector<int>&v){
    int n = v.size();

    vector<int>dp(n, -1);

    dp[0] = v[0];
    if (n > 1) dp[1] = max(v[0], v[1]);

    for(int i = 2; i < n; i++){
        int pick = v[i] + dp[i-2];
        int nonPick = dp[i-1];

        dp[i] = max(pick, nonPick);
    }

    return dp[n-1];
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);
        for(int i = 0; i < n; i++) cin>>v[i];

        if (n == 1) return v[0];

        vector<int>v1(v.begin()+1, v.end());
        vector<int>v2(v.begin(), v.end()-1);

        cout<<max(maxMoneyRob(v1), maxMoneyRob(v2))<<endl;
        cout<<max(maxMoney(v1), maxMoney(v2))<<endl;
        
    }
}

/* Test Cases
3
5
1 5 1 2 6
3
2 3 5
4
1 3 2 0
*/

// Output
// 11
// 5
// 3