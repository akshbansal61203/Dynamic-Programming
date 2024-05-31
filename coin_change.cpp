class Solution {
private:
//memoization
    int f(int ind,int amount,vector<vector<int>>&dp,vector<int>&coins){
        if(amount==0)return 0;
        if(ind==0&&amount>0){
            if(amount%coins[0]==0)return amount/coins[0];
            return 1e8;
        } 
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int take=1e8;
        int notTake=f(ind-1,amount,dp,coins);
        if(coins[ind]<=amount)take=1+f(ind,amount-coins[ind],dp,coins);
        return dp[ind][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      //tabulation
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e8;
        }
        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=amount;j++){
                int take=1e8;
                int notTake=dp[ind-1][j];
                if(coins[ind]<=j)take=1+dp[ind][j-coins[ind]];
                dp[ind][j]=min(take,notTake);
            }
        }
        if(dp[n-1][amount]==1e8)return -1;
        return dp[n-1][amount];
        
    }
};
