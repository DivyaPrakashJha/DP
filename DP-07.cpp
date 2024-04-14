// Problem

// Ninja is planing this 'N' days-long training schedule. 
// Each day, he can perform any one Of these three activities. (Running. Fighting Practice or Learning New Moves)
// Each activity has some merit points on each day. 
// As Ninja has to improve all his skills, he can't do the same activity in two consecutive days. 
// Can you help Ninja find out the maximum merit points Ninja can earn?
// You are given a 2D array of size 'POINTS' with the points corresponding to each day and activity. 
// Your task is to calculate the maximum number of merit points that Ninja can earn.


// Tasks : 0, 1, 2 (Running, Fighting, Learning)
// Days : 0, 1, . . ., n-1


#include<bits/stdc++.h>

using namespace std;

// Using recursion

int maxPoints(int day, int taskP, vector<vector<int>>&v){  // Current day, Task Performed on the next day
    if (day == 0){
        int mx = 0;
        for(int i = 0; i <= 2; i++){
            if (i != taskP){
                mx = max(mx, v[day][i]);
            }
        }

        return mx;
    }

    int mx = 0;
    for(int i = 0; i <= 2; i++){
        if (i != taskP){
            int points = v[day][i] + maxPoints(day-1, i, v);
            mx = max(mx, points);
        }
    }

    return mx;
}

// Using Memoization

int maxPointsM(int d, int t, vector<vector<int>>&v, vector<vector<int>>&dp){
    if (d == 0){
        int mx = 0;
        for(int i = 0; i < 3; i++){
            if (i != t){
                mx = max(mx, v[d][i]);
            }
        }

        return mx;
    }

    if (t != -1 and dp[d][t] != -1) return dp[d][t];

    int mx = 0;
    for(int i = 0; i < 3; i++){
        if (i != t){
            int points = v[d][i] + maxPointsM(d-1, i, v, dp);
            mx = max(mx, points);
        }
    }
    
    if (t == -1) return mx;
    return dp[d][t] = mx;
}

int maxPointsNinja(vector<vector<int>>&v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(3, -1));

    return maxPointsM(n-1, -1, v, dp);
}

// Tabulation

int maxPointsT(vector<vector<int>>&v){
    int n = v.size();

    vector<vector<int>>dp(n, vector<int>(3, -1));

    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);

    for(int d = 1; d < n; d++){
        for(int t = 0; t < 3; t++){
            int mx = 0;
            for(int i = 0; i < 3; i++){
                if (i != t){
                    mx = max(mx, v[d][i] + dp[d-1][i]);
                }
            }

            dp[d][t] = mx;
        }
    }
    
    // On the last day we find the maximum possible such that we are not going to perform any other task on the next day
    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<int>>v(n, vector<int>(3));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cin>>v[i][j];
            }
        }

        cout<<maxPoints(n-1, -1, v)<<endl; // -1 indicates that no task is performed
        cout<<maxPointsNinja(v)<<endl;
        cout<<maxPointsT(v)<<endl;
    }
}

/* Test Cases
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
*/

// Output
// 11
// 210