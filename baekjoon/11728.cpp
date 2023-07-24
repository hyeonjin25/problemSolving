#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m,temp;
  cin >> n >> m;

  for(int i=0; i<n; i++) cin >>temp, v.push_back(temp);
  for(int i=0; i<m; i++) cin >>temp, v.push_back(temp);

  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++) cout << v[i] << ' ';
}