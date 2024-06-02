//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
private:
    int f(int ind1,int ind2,string&str1,string&str2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]= 1+f(ind1-1,ind2-1,str1,str2,dp);
        }
        if(str1[ind1]!=str2[ind2]){
            return dp[ind1][ind2]=max(f(ind1-1,ind2,str1,str2,dp),f(ind1,ind2-1,str1,str2,dp));
        }
        
    }
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return f(n-1,m-1,str1,str2,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends
