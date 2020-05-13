#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int post = 1;
vector<pair<int,int>> order;
void postorder(int v)
{
  order.push_back(make_pair(post,v));
  post += 1;
}

void explore(int i, vector<vector<int>> &adj, bool* visited)
{
  visited[i] = true;
  for(auto x : adj[i])
  {
    if(!visited[x])
    {
      explore(x,adj,visited);
    }
    //postorder(x);  
  }
  postorder(i);
}
void dfs(vector<vector<int>> &adj, size_t n)
{
  bool visited[n];
  for(int i =0; i<n;i++)
    visited[i] = false;

  for(auto it1 = 0;it1<adj.size();it1++)
  {
    if(!visited[it1])
      explore(it1,adj,visited);
   // postorder(it1);
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
  }
  dfs(adj,n);
  sort(order.begin(),order.end(), [] (pair<int,int> el1, pair<int,int> el2) -> bool { 
      return el1.first > el2.first;
      });
  for(auto i : order)
  {
    cout<<i.second + 1<<" ";
  } 

}
