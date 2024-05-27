//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        for(int j=0;j<N;j++)dp[0][j]=Matrix[0][j];
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                int up=Matrix[i][j]+dp[i-1][j];
                int lf=Matrix[i][j],ri=Matrix[i][j];
                if(j>0)lf+=dp[i-1][j-1];
                else lf=-1e9;
                if(j+1<N)ri+=dp[i-1][j+1];
                else ri=-1e9;
                dp[i][j]=max(up,max(lf,ri));
            }
        }int maxi=-1e9;
        for(int j=0;j<N;j++){
            maxi=max(maxi,dp[N-1][j]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
