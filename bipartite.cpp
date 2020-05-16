#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool explore(vector<vector<int>> &adj, int v, int c, vector<bool>& visited, vector<int> &color)
{
  visited[v] = true;
  color[v] = c;

  for(auto x : adj[v])
  {
    if(!visited[x])
    {
      if (explore(adj,x,c^1,visited,color) == false)
        return false;
    }
    else
    {
      if (color[v] == color[x])
        return false;
    }
  }
  return true;
}

int bipartite(vector<vector<int> > &adj) {

  int n = adj.size();
  vector<bool> visited(n);
  vector<int> color(n);
  for(int i=0;i<n;i++)
    visited[i] = false;
  
  color[0] = 1;

  for(auto it=0;it!=adj.size();it++)
  {
    if(!visited[it])
      if(!explore(adj,it,color[it]^1,visited,color))
        return 0;
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
