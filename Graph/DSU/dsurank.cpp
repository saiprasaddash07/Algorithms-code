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

vector<int> parent(n); // parent[i] = i;
vector<int> rank(n,0);