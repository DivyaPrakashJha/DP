// Problem

// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums 
// and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Constraints
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

// -> Approach-1

// We firstly assign + to every element of the array.
// Then this problem will be reduced to pick(assign -) and nonPick(leave it as +) format
// Solved Below

// -> Approach-2

// Since we have to assign some elements + sign and some elements - sign
// We can think of it as dividing the array into two subsets (one on which we assign + and the other on which we assign -)
// Thus S1 - S2 = Target
// Refer DP-18

#include<bits/stdc++.h>

using namespace std;

// Memoization
int numWays(int i, int target, vector<int>&v, vector<vector<int>>&dp){
    if (target < 0) return 0;
    if (i == -1){
        if (target == 0) return 1;
        return 0;
    }

    if (dp[i][target] != -1) return dp[i][target];

    // Assign negative (Pick)
    int neg = numWays(i-1, target - 2*v[i], v, dp); 
    // We did -2*v[i] as in target the the number is already counted as +ive,
    // So, firstly we eliminated the effect of already counted +ive number, and then we subtracted the number from the target 

    // Leave it as positive (Non Pick)
    int pos = numWays(i-1, target, v, dp);

    return dp[i][target] = neg + pos;
}

// Tabulation
int numWaysTab(int target, vector<int>&v){
    int n = v.size();
    
    vector<vector<int>>dp(n, vector<int>(target+1, 0));

    // Base Case
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if (2*v[0] <= target) dp[0][2*v[0]] = 1;
    if (v[0] == 0) dp[0][0] = 2;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int neg = 0;
            if (j - 2*v[i] >= 0) neg = dp[i-1][j-2*v[i]];
            int pos = dp[i-1][j];

            dp[i][j] = neg + pos;
        }
    }
    return dp[n-1][target];
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int>v(n);
    for(auto &x : v) cin>>x;

    // Assigning + to every element
    int sum = accumulate(v.begin(), v.end(), 0);

    target = sum - target;
    // Pick some numbers such that they form the target

    if (target < 0) cout<<0;
    else{
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        cout<<numWays(n-1, target, v, dp)<<endl;
        cout<<numWaysTab(target, v);
    }
}

/* Sample Test Cases
5 3
1 1 1 1 1

5 4
1 2 4 2 1
*/

// Output
// 5
// 4
