// // // Q. There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the
// 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.lf Frog jumps from 'ith to jth' stair,
// the energy lost in the jump is given by absolute value of ( HEIGHT [i-1] - HEIGHT [j-1] ). If the
// Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is
// to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

// Problem Link -  https://bit.ly/3JPcoOx

// Greedy won't work, we have to try all possible ways

#include<bits/stdc++.h>

using namespace std;

#define int long long

// // Using Recursion

int findMinimumEnergy(int n, vector<int>v){
    if (n == 0) return 0;

    int prev = findMinimumEnergy(n-1, v) + abs(v[n] - v[n-1]);
    int prev2 = INT_MAX;
    if (n > 1){
        prev2 = findMinimumEnergy(n-2, v) + abs(v[n] - v[n-2]);
    }

    return min(prev, prev2);
}

// It has overlapping sub-problems and the time complexity is exponential in nature


// // Using DP

// Memoization

int frogJump(int n, vector<int> &heights, vector<int>&dp)
{   
    if (n == 0) return 0;
    
    if (dp[n] == -1){
        int prev = frogJump(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
        int prev2 = INT_MAX;
        if (n > 1){
            prev2 = frogJump(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
        }
        
        dp[n] = min(prev, prev2);    
    }

    return dp[n];
}

int findMinimumEnergyD(int n, vector<int>&heights){
    vector<int>dp(n, -1);

    return frogJump(n-1, heights, dp);
    // dp[i] represents the minimum enery required to reach i from 0
}

// T.C - O(n)
// S.C - O(n) + O(n)

// Tabulation

int findMinEnergy(int n, vector<int>&heights){
    vector<int>dp(n, -1);

    dp[0] = 0;
    if (n > 1) dp[1] = abs(heights[0]-heights[1]);

    for(int i = 2; i < n; i++){
        int oneStep = dp[i-1] + abs(heights[i-1] - heights[i]);
        int twoSteps = dp[i-2] + abs(heights[i-2] - heights[i]);

        dp[i] = min(oneStep, twoSteps);
    }

    return dp[n-1];
}

// T.C. - O(n)
// S.C. - O(n)

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>heights(n);
        for(auto &x : heights) cin>>x;

        cout<<findMinimumEnergy(n-1, heights)<<endl; 
        cout<<findMinimumEnergyD(n, heights)<<endl;
        cout<<findMinEnergy(n, heights)<<endl<<endl;
    }
}


/* Test Cases
4
20
7 2 3 6 9 6 10 10 10 3 2 7 7 4 9 5 10 5 8 7 
29
7 2 8 3 3 5 8 2 2 2 7 7 6 9 1 2 8 1 7 4 9 7 2 1 5 7 6 3 1 
29
5 8 4 4 8 6 3 4 8 7 4 1 7 4 7 2 5 5 10 8 4 5 8 7 6 7 5 8 9 
28
8 4 2 10 10 7 10 10 8 1 10 5 4 4 2 10 10 5 1 2 7 4 2 4 10 10 10 1 
*/

// Output
// 28
// 44
// 26
// 51