//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int ind,int n,int price[],vector<vector<int>>&dp){
       if(n==0)return 0;
        if(ind==0){
            if(1<=n)return n*price[ind];
            return -1e9;
        }
        if(dp[ind][n]!=-1)return dp[ind][n];
        int notTake=f(ind-1,n,price,dp);
        int take=-1e9;
        if(n>=ind+1)take=price[ind]+f(ind,n-ind-1,price,dp);
        return dp[ind][n]=max(take,notTake);
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
