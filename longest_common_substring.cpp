class Solution {
public:
    int dp[1001][1001];
    bool solve(int l,int r,string&s){
        if(l>=r)return 1;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]=solve(l+1,r-1,s);
        }
        return dp[l][r]=false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int startInd=0;
        int maxLength=INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        startInd=i;
                    }
                }
            }
        }
        return s.substr(startInd,maxLength);
    }
};
