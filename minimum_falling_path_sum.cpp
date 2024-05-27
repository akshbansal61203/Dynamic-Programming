class Solution {
public:
    int f(vector<vector<int>>&dp,vector<vector<int>>&matrix,int i,int j){
        if(i<0||j>=matrix.size())return 1e9;
        if(i==0)return matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int up=matrix[i][j]+f(dp,matrix,i-1,j);
        int lf=matrix[i][j]+f(dp,matrix,i-1,j-1);
        int ri=matrix[i][j]+f(dp,matrix,i-1,j+1);
        return dp[i][j]=min(up,min(lf,ri));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++)dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int lf=0;int ri=0;
                if(j>0)lf=matrix[i][j]+dp[i-1][j-1];
                else lf=1e9;
                if(j+1<n)ri=matrix[i][j]+dp[i-1][j+1];
                else ri=1e9;
                dp[i][j]=min(up,min(lf,ri));
            }
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};
