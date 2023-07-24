#include <bits/stdc++.h>
using namespace std;

// 10! * 10

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;

  sort(str.begin(), str.end());

  int cnt = 0;
  do{
    int flag=1;
    for(int i=1; i<str.size(); i++){
      if(str[i-1]==str[i]) flag=0;
    }
    if(flag) cnt++;
  }while(next_permutation(str.begin(),str.end()));

  cout << cnt;
}