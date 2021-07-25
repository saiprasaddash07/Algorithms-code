#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> res;

void dfsutil(vector<int> adj[],vector<int> &dis,vector<int> &low,vector<int> &vis,int &timer,int src,int parent){
    vis[src] = 1;
    dis[src] = low[src] = timer++;
    for(auto it : adj[src]){
        if(it==parent) continue;
        if(!vis[it]){
            dfsutil(adj,dis,low,vis,timer,it,src);
            low[src] = min(low[src],low[it]);
            if(low[it] > dis[src]){
                res.push_back({src,it});
            }
        }else{
            low[src] = min(low[src],dis[it]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(n,-1);
    vector<int> low(n,-1);
    vector<int> vis(n,0);
    int timer = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsutil(adj,dis,low,vis,timer,i,-1);
        }
    }
    for(auto x:res){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}