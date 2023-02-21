#include <bits/stdc++.h>

using namespace std;

vector<int> vec[105];
int vis[105];
queue<int> q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  int count = 0;
  q.push(1);
  vis[1] = 1;
  while (q.size())
  {
    auto cur = q.front();
    q.pop();
    for (auto e : vec[cur])
    {
      if (vis[e])
        continue;
      count++;
      q.push(e);
      vis[e] = 1;
    }
  }

  cout << count;
}