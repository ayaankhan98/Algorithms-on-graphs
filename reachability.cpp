#include <iostream>
#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

int reach(vector<vector<int>> &adj, int x, int y, int n)
{
  //write your code here
  bool visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = false;

  stack<int> s;
  visited[x] = true;
  s.push(x);

  while (!s.empty())
  {
    int ele = s.top();
    if (ele == y)
      return 1;
    s.pop();
    for (auto i : adj[ele])
    {
      if (!visited[i])
      {
        visited[i] = true;
        s.push(i);
      }
    }
  }
  return 0;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1, n);
}
