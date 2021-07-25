#include <bits/stdc++.h>
using namespace std;

int n = 4;
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0},
};

//If all cities have been visited
int VISITEDALL = (1<<n) - 1;

int dp[1<<n][n];

int tspdp(int mask,int pos){
    if(mask == VISITEDALL){
        return dist[pos][0];
    }
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        if((mask & (1<<i)) == 0){
            int temp = dist[pos][i] + tspdp( mask | (1<<i), i);
            res = min(res,temp);
        }
    }
    return (dp[mask][pos] = res);
}

int main(){
    int y = tspdp(1,0);
    memset(dp,-1,sizeof(dp));
    cout<<y<<"\n";
    return 0;
}