// // Understanding it it's a DP problem

// ->Try all possible ways and
// * Count the total number of ways
// * Figure out the best way 
// * Find min or max


// // Way to Solve

// 1) Try to represent the problem in terms of index
// 2) Do all possible stuffs on the indices according to the problem statement
// 3) if the question says: 
    // count all ways -> sum of all stuffs
    // find minimum -> min(of all stuffs)


// // Problem

// You have been given a number of stairs. Initially, you are at the 0th stair. 
// You need to reach the nth stair. Each time you can either climb one step or two steps.
// You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.


#include<bits/stdc++.h>

using namespace std;

#define int long long

// Using recursion
int countDistinctWaysToClimb(int n){ // Going backward 
    if (n == 1) return 1; // 1->0
    if (n == 2) return 2; // 2->1->0 and 2->0

    return countDistinctWaysToClimb(n-1) + countDistinctWaysToClimb(n-2);
}

// Using DP 

// Memoization

vector<int>dp(100000, -1);

int countDistinctWaysToClimbD(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (dp[n] == -1){
        dp[n] = countDistinctWaysToClimbD(n-1) + countDistinctWaysToClimbD(n-2);
    }

    return dp[n];
}

// Tabulation

int countWays(int n){
    vector<int>dp(n+1, -1);

    dp[0] = dp[1] = 1; 

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

signed main(){
    int n;
    cin>>n;

    // cout<<countDistinctWaysToClimb(n)<<endl;
    cout<<countDistinctWaysToClimbD(n)<<endl;
    cout<<countWays(n)<<endl;
}