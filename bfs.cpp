#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> BFS(vector<vector<int>> &adj,int s, int n,vector<int> &dist)
{
  for(int i =0;i<n;i++)
    dist[i] = -1;
  dist[s] = 0;
  vector<int> p(n);
  p[s] = -1;
  queue<int> q;
  q.push(s);
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(auto x : adj[u])
    {
      if (dist[x] == -1)
      {
        q.push(x);
        dist[x] = dist[u]+1;
        p[x] = u;
      }
    }
  }
  return p;
}

int distance(vector<vector<int> > &adj, int s, int t) {
  int n = adj.size();
  vector<int> dist(n);
  vector<int> p = BFS(adj,s,n,dist);
  vector<int> path;
  if(dist[t] == -1)
    return -1;
  else
  {
    for(auto v = t ; v!= -1;v = p[v])
      path.push_back(v+1);

    return path.size()-1;
  }
  return -1;
}

int main() {
  //freopen("input.txt","r",stdin);
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  cout<<distance(adj, s, t);
}
