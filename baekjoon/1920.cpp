#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n,m; cin >>n;
  for(int i=0; i<n;i++){
    int a; cin >>a;
    v.push_back(a);
  }
  sort(v.begin(),v.end());

  cin >> m;
  for(int i=0; i<m;i++){
    int a; cin >>a;
    cout << binary_search(v.begin(),v.end(),a) << '\n';
  }
}