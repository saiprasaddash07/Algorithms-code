int main(){
    vector<int> adj[n];
    int indegree[n];
    memset(indegree,0,sizeof(indegree));
    for(int i=0;i<arr.size();i++){
        int x=arr[i][0];
        int y=arr[i][1];
        adj[y].push_back(x);
        indegree[x]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    vector<int> res;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        res.push_back(x);
        for(auto y:adj[x]){
            if(--indegree[y]==0){
                q.push(y);
            }
        }
        cnt++;
    }
    if(cnt!=n){
        cout<<"Cycle";
        cout<<"\n";
        return -1;
    }
    for(auto x:res){
        cout<<x<<" ";
    }
    cout<<"\n";
}