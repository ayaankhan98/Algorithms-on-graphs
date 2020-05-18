#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

// the idea is to perform the V-1 iterations of Bellaman Ford Algorithm
// after successful V-1 iterations you will have the shortest path in 
// the dist array given that there is no negative cycle in the graph
// but if the graph contains the negative cycle then at the V-th iteraion
// of Bellaman ford algorithm will further improve the distances in the
// dist array because of that negative cycle

bool negative_cycle(vector<vector<pair<int,int>> > &adj) {

  int n = adj.size();
  vector<int> dist(n,INF);
  dist[0] = 0;
  bool is_cycle = false;
  for(int t = 0 ; t < n ; t++) {
    for(int i = 0; i < n ; i++) {
      for ( auto x : adj[i] ) {
        if ( dist[x.first] > dist[i] + x.second ) {
          dist[x.first] = dist[i] + x.second;
          if (t == n-1)
            is_cycle = true;
        }
      }
    }
  }
  return is_cycle;
}


int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
  int u,v,w;
  while(m--) {
    cin>>u>>v>>w;
    adj[u-1].push_back(make_pair(v-1,w));
  }
  if(negative_cycle(adj))
    cout<<"1";
  else
    cout<<0;
}
