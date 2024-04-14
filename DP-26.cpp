// Problem 

// Print Longest Commmon Subsequence

// We will use the dp table used in the previous question

#include<bits/stdc++.h>

using namespace std;

void printLCS(string s, string t){
    int n = s.length(), m = t.length();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Printing the DP table from which we will derive our subsequence
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // Printing the LCS
    int sz = dp[n][m];
    cout<<"Length : "<<sz<<endl;
    char str[sz];

    int i = n, j = m, cur = sz-1;

    while(i > 0 and j > 0){
        if (s[i-1] == t[j-1]){
            str[cur] = s[i-1];
            cur--;
            i--;
            j--;
        }
        else{
            if (dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }

    for(auto it : str) cout<<it;
} 

int main(){
    string s, t;
    cin>>s>>t;

    printLCS(s, t);
}