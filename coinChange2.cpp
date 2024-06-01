class Solution {
private:
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        //memoization
        //if(amount==0)return 1;
        if(ind==0){
            if(amount%coins[0]==0)return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int take=0;
        int notTake=f(ind-1,amount,coins,dp);
        if(coins[ind]<=amount)take=f(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=take+notTake;

    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //tabulation
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
            else dp[0][i]=0;
        }
        //for(int i=0;i<n;i++)dp[i][0]=0;
        for(int ind=1;ind<n;ind++){
            for(int j=0;j<=amount;j++){
                int take=0;
                int notTake=dp[ind-1][j];
                if(coins[ind]<=j)take=dp[ind][j-coins[ind]];
                dp[ind][j]=take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};
