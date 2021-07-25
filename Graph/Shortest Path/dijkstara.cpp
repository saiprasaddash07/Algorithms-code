#include<bits/stdc++.h>
using namespace std;

void setmethod(){
    vector<pair<int,int> > adj[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back({b,wt});
		adj[b].push_back({a,wt});
	}

    int source;
    cin>>source;

    set<pair<int,int>> s; // {dist from the source , vertex}
    s.insert({0,source});

    vector<int> dist(N+1,1e7);
    dist[source]=0;

    while(!s.empty()){
        auto it=s.begin();
        auto x= (*it);
        s.erase(it);
        int v= x.second;
        for(auto u:adj[v]){
            int a=u.first;
            int w=u.second;
            if(dist[v]+w < dist[a]){
                if(dist[a]!=1e7){
                    s.erase(s.find({dist[a],a}));
                }
                dist[a]=dist[v]+w;
                s.insert({dist[a],a});
            }
        }
    }
}

void pqmethod(){
    vector<pair<int,int> > adj[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back({b,wt});
		adj[b].push_back({a,wt});
	}

    int source;
    cin>>source;

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> dist(n+1,INT_MAX);

    pq.push({0,source});
    dist[src] = 0;

    while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		for( auto it : adj[prev]){
			int next = it.first;
			int nextDist = it.second;
			if( dist[next] > dist[prev] + nextDist){
				dist[next] = dist[prev] + nextDist;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}