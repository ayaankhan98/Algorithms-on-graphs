#include <iostream>
#include <vector>

using std::vector;
using std::pair;


int cc = 0;
void explore(vector<vector<int>> &adj, int v, bool* visited)
{
  visited[v] = true;
  for(auto x : adj[v])
  {
    if(!visited[x])
      explore(adj,x,visited);
  }
}

void DFS(vector<vector<int>> &adj, size_t n)
{
  bool visited[n];
  for(int i =0;i<n;i++)
    visited[i] = false;

  for(int i = 0 ;i < adj.size(); i++)
  {
    if (!visited[i])
    {
      explore(adj,i,visited);
      cc++;
    }
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  DFS(adj,n);
  std::cout<<cc;
}
