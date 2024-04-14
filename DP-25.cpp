// Problem

// Length of Longest Common Subsequence

#include<bits/stdc++.h>

using namespace std;

// Memoization
// dp[i][j] represents the lcs of s[0..i] and t[0..j]

int lengthLCS(string s, string t, int sInd, int tInd, vector<vector<int>>&dp){
    if (sInd < 0 or tInd < 0) return 0;

    if (dp[sInd][tInd] != -1) return dp[sInd][tInd];
    
    // Equal
    if (s[sInd] == t[tInd]) return dp[sInd][tInd] = 1 + lengthLCS(s, t, sInd-1, tInd-1, dp);
    
    // Not Equal
    return dp[sInd][tInd] = max(lengthLCS(s, t, sInd-1, tInd, dp), lengthLCS(s, t, sInd, tInd-1, dp));
}

// Tabulation
int lengthLCS_Tab(string s, string t){
    // We will shift the indexes 1 place forward in order to contain the base cases
    int n = s.length(), m = t.length();

    vector<vector<int>>dp(n+2, vector<int>(m+2, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }

    return dp[n][m];
}

int main(){
    string s, t;
    cin>>s>>t;

    vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
    cout<<lengthLCS(s, t, s.length()-1, t.length()-1, dp)<<endl;
    cout<<lengthLCS_Tab(s, t);
}