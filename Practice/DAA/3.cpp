#include <bits/stdc++.h>
using namespace std;

int solve(int ind,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
    if(ind==0){
        if(wt[0]<=W) return val[0];
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = 0+solve(ind-1,W,wt,val,dp);
    int take = INT_MIN;
    if(wt[ind]<=W)
        take = val[ind]+solve(ind-1,W-wt[ind],wt,val,dp);
    return dp[ind][W] = max(take,notTake);
}

int knapsack(int n,int W,vector<int> &wt,vector<int> &val){
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return solve(n-1,W,wt,val,dp);
}

int tabulatedKnapsack(int n,int W,vector<int> &wt,vector<int> &val){
    vector<vector<int>> dp(n,vector<int>(W+1,0));

    for(int i=wt[0];i<=W;i++){
        dp[0][i] = val[0];
    }

    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int notTake = dp[i-1][w];
            int take = INT_MIN;
            if(wt[i]<=w){
                take = val[i]+dp[i-1][w-wt[i]];
            }

            dp[i][w] = max(notTake,take);
        }
    }

    return dp[n-1][W];
}


int main()
{
    int n, W;
    vector<int> wt, val;
    cin >> n >> W;

    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        wt.push_back(w);
        val.push_back(v);
    }

    cout<<knapsack(n,W,wt,val);
    cout<<"\nTabluated:\n";
    cout << tabulatedKnapsack(n, W, wt, val);
}