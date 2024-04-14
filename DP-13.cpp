// Problem

// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates.
// Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
// Initially, Alice is in the top-left position i.e. (O, O), and Bob is in the top-right place i.e. (O, 'C' - 1) in the grid. 
// Each of them can move from their current cell to the cells just below them. 
// When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. 
// If both stay in the same cell, only one of them will pick the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). 
// They will always stay inside the 'GRID'.
// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

#include<bits/stdc++.h>

using namespace std;

// Memoization
int maxChocolates(int i, int j1, int j2, int r, int c, vector<vector<int>>&v, vector<vector<vector<int>>>&dp){
    if (j1 < 0 or j2 < 0 or j1 >= c or j2 >= c) return 0;

    if (i == r-1){
        if (j1 == j2){
            return v[i][j1];
        }
        return v[i][j1] + v[i][j2];
    }

    if (dp[i][j1][j2] == -1){
        
        for(int k = -1; k <= 1; k++){
            for(int l = -1; l <= 1; l++){
                if (j1 == j2){
                    dp[i][j1][j2] = max(dp[i][j1][j2], v[i][j1] + maxChocolates(i+1, j1+k, j2+l, r, c, v, dp));
                }
                else{
                    dp[i][j1][j2] = max(dp[i][j1][j2], v[i][j1] + v[i][j2] + maxChocolates(i+1, j1+k, j2+l, r, c, v, dp));
                }
            }
        }
    }

    return dp[i][j1][j2];
}

// Tabulation
int maxChocolatesTab(int r, int c, vector<vector<int>>&v){
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // Base Case
    for(int k = 0; k < c; k++){
        for(int l = 0; l < c; l++){
            if (k == l) dp[r-1][k][l] = v[r-1][k];
            else dp[r-1][k][l] = v[r-1][k] + v[r-1][l];
        }
    }

    for(int i = r-2; i >= 0; i--){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < c; k++){
                
                int val = 0;
                for(int x = -1; x <= 1; x++){
                    for(int y = -1; y <= 1; y++){
                        if (j == k) val = v[i][j];
                        else val = v[i][j] + v[i][k];

                        if (j+x >= 0 and j+x < c and k+y >= 0 and k+y < c) val += dp[i+1][j+x][k+y];

                        dp[i][j][k] = max(dp[i][j][k], val);
                        val = 0;
                    }
                }
            }
        }
    }

    return dp[0][0][c-1];
}

int main(){
    int r, c;
    cin>>r>>c;

    vector<vector<int>>v(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>v[i][j];
        }
    }

    vector<vector<vector<int>>>dp(r+1, vector<vector<int>>(c+1, vector<int>(c+1, -1)));

    cout<<maxChocolates(0, c-1, 0, r, c, v, dp)<<endl;
    cout<<maxChocolatesTab(r, c, v);

}

/* Test Cases
5 7
1 0 0 0 0 0 1
2 0 0 0 0 3 0
2 0 9 0 0 0 0
0 3 0 5 4 0 0
1 0 2 3 0 0 6
*/

// Output
// 28