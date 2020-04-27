#include <iostream>
#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

int number_of_components(vector<vector<int>> &adj, int n)
{
  int res = 0;
  //write your code here
  bool visited[n];
  for (int i = 0; i > n; i++)
    visited[i] = false;

  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      res++;
      visited[i] = true;
      st.push(i);
    }

    while (!st.empty())
    {
      int ele = st.top();
      st.pop();
      for (auto x : adj[ele])
      {
        if (!visited[x])
        {
          visited[x] = true;
          st.push(x);
        }
      }
    }
  }
  return res;
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
  std::cout << number_of_components(adj, n);
}
