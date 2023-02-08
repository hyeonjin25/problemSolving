#include <bits/stdc++.h>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, n, m;
  cin >> T;
  while (T--)
  {
    vector<pair<int,int>> vec;
    cin >> n >> m;

    int temp;
    for (int i = 0; i < n; i++){
      cin >> temp;
      vec.push_back({temp,0}); // a와 b가 같으면 a가 못잡아먹으므로
    }
    for (int i = 0; i < m; i++){
      cin >> temp;
      vec.push_back({temp,1}); 
    }

    sort(vec.begin(),vec.end());

    int count=0;
    int res=0;
    for(auto v : vec){
      if(v.second==0){
        res+=count;
      }else{
        count++;
      }
    }

    cout << res << '\n';
  }
}