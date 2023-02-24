#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int n;

int b_search(int t){
  int st = 0, en=n-1;
  while(st<=en){
    int mid = (st+en)/2;
    if(v[mid]>t) en=mid-1;
    else if(v[mid]<t) st=mid+1;
    else return 1;
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >>n;
  for(int i=0; i<n;i++){
    int a; cin >>a;
    v.push_back(a);
  }
  sort(v.begin(),v.end());

  int m; cin >> m;
  for(int i=0; i<m;i++){
    int a; cin >>a;
    cout << b_search(a) << '\n';
  }
}