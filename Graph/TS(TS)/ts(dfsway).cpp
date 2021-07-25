int main(){
    void TSutil(vector<int> adj[],vector<int> &vis, stack<int> &st,int src) {
        vis[src] = 1; 
        
        for(auto x : adj[src]) {
            if(!vis[x]) {
                TSutil(adj,vis,st,x);
            }
        }
        st.push(src); 
    }
	vector<int> TS(int N, vector<int> adj[]) {
	    stack<int> st; 
	    vector<int> vis(N, 0); 
	    for(int i = 0;i<N;i++) {
	        if(!vis[i]) {
	            TSutil(adj,vis,st,i); 
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo;    
	}
}

int check(int V, vector <int> &res, vector<int> adj[]) { // Check if the func returns well , i.e , there is no cycle
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}