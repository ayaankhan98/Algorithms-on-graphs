#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 100000000

int dijkstra(vector<vector<pair<int,int>>> &adj, int s,int t)
{
  int n = adj.size();
  vector<int> dist(n,INF);
  vector<int> p(n);

  priority_queue<pair<int,int>, vector<pair<int,int>> , 
    greater<pair<int,int>>> pq;

  pq.push(make_pair(0,s));
  dist[s] = 0;

  while(!pq.empty())
  {
    int current_node = pq.top().second;
    int current_dist = pq.top().first;
    // cout<<current_node<<" "<<current_dist<<endl;
    pq.pop();

    for(pair<int,int> edge : adj[current_node])
    {
     // cout<<edge.first<<","<<edge.second<<endl;
      if (current_dist + edge.second < dist[edge.first])
      {
        dist[edge.first] = current_dist + edge.second;
        pq.push(make_pair(dist[edge.first],edge.first));
     //   cout<<"##"<<dist[edge.first]<<","<<edge.first<<endl; 
      }
    }
  }
  if(dist[t] != INF)
    return dist[t];
  return -1;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
  int u,v,w;
  while(m--)
  {
    cin>>u>>v>>w;
    adj[u-1].push_back(make_pair(v-1,w));
    //adj[v-1].push_back(make_pair(u-1,w));
  }
  int s,t;
  cin>>s>>t;
  cout<<dijkstra(adj,s-1,t-1);
  /*for(int i =0;i<adj.size();i++)
  {
    cout<<i<<" " ;
    for(auto v : adj[i])
      cout<<v.first<<"("<<v.second<<")";
    cout<<endl;
  }*/
}
