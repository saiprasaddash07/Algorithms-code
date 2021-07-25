int find(int x,vector<int> &parent){
    if(parent[x]==x) return x;
    parent[x] = find(parent[x],parent);
    return parent[x];
}

void merge(int x,int y,vector<int> &parent,vector<int> &rank,int &count){
    int sa = find(x,parent);
    int sb = find(y,parent);
    if(sa==sb) return;
    if(rank[sa]==rank[sb]){
        parent[sa] = sb;
        rank[sb]++;
    }else if(rank[sa] < rank[sb]){
        parent[sa] = sb;
    }else{
        parent[sb] = sa;
    }
}

struct edge {
    int src,dest,weight;
};

struct mycomp{
    bool operator()(edge x,edge y){
        return x.weight <= y.weight;
    }
};

int xxxxxxxx(){
    vector<edge> arr(m);
    int k=0;
    for(int i=0;i<m;i++){
        int u = connections[i][0];
        int v = connections[i][1];
        int w = connections[i][2];
        arr[k].src = u;
        arr[k].dest = v;
        arr[k].weight = w;
        k++;
    }
    vector<int> parent(n+1,-1);
    vector<int> rank(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    sort(arr,arr+m,mycomp());
    int res = 0;
    k = 0;int i=0;
    vector<edge> result;
    while(k<n-1 && i<edge.size()){
        edge u = arr[i++];
        int x = find(u.src,parent);
        int y = find(u.dest,parent);
        if(x!=y){
            merge(x,y,parent,rank,count);
            result.push_back(u);
            k++;
        }
    }
}