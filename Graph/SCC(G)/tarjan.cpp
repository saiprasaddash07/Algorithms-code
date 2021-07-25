#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void sccutil(vector<int> adj[],int src,int disc[],int low[],stack<int> &s,bool inStack[],int &timer){
    disc[src] = low[src] = timer++;
    s.push(src);
    inStack[src] = true;
    for(auto x : adj[src]){
        if(disc[x] == -1){
            sccutil(adj,x,disc,low,s,inStack,timer);
            low[src] = min(low[src],low[x]);
        }else if(inStack[x]){
            low[src] = min(low[src],disc[x]);
        }
    }
    if(low[src] == disc[src]){
        vector<int> v;
        while(s.top() != src){
            int w = s.top();
            s.pop();
            v.push_back(w);
            inStack[w] = false;
        }
        int w = s.top();
        s.pop();
        v.push_back(w);
        inStack[w] = false;
        res.push_back(v);
    }
}

void sccdfs(vector<int> adj[],int v){
    int disc[v],low[v];
    bool inStack[v];
    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    memset(inStack,0,sizeof(inStack));
    stack<int> s;
    int timer = 0;
    for(int i=0;i<v;i++){
        if(disc[i]==-1){
            sccutil(adj,i,disc,low,s,inStack,timer);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
    sccdfs(adj,n);
    for(auto v : res){
        for(auto y : v){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}