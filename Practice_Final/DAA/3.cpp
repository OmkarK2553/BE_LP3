#include <bits/stdc++.h>
using namespace std;

int solve(int ind,vector<int> &wt,vector<int> &val,int W,vector<vector<int>> &dp){
    if(ind==0){
        if(wt[0]<=W) return val[0];
        return 0;
    }

    int notTake = 0+solve(ind-1,wt,val,W,dp);
    int take = INT_MIN;
    if(wt[ind]<=W){
        take = val[ind]+solve(ind-1,wt,val,W-wt[ind],dp);
    }
    return dp[ind][W] = max(notTake,take);
}

int knapsack(int n,vector<int> &wt,vector<int> &val,int W){
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return solve(n-1,wt,val,W,dp);
}

int tabknapsack(int n,vector<int> &wt,vector<int> &val,int W){
    vector<vector<int>> dp(n,vector<int>(W+1,0));

    for(int i=wt[0];i<=W;i++){
        dp[0][i] = val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int notTake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            }
            dp[ind][w] = max(notTake, take);
        }
    }
    return dp[n-1][W];
}

int main()
{
    int n,W;
    cin>>n>>W;

    vector<int> wt,val;

    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        wt.push_back(w);
        val.push_back(v);
    }

    cout << knapsack(n, wt, val, W) << "\n";
    cout << tabknapsack(n, wt, val, W) << "\n";
}