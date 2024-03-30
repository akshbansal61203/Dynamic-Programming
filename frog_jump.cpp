#include <bits/stdc++.h> 
int f(int n,vector<int>&dp,vector<int> &heights){
    if(n==0)return 0;
    int left=f(n-1)+abs(heights[n]-heights[n-1]);
    if(n-2>=0){
        int right=f(n-2)+abs(heights[n]-heights[n-2]);
        return min(right,left);
    }
    return left;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
   return f(n-1);
}
