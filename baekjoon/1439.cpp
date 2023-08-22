#include<bits/stdc++.h>
using namespace std;

int arr[105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;
  cnt[str[0]]++;

  for(int i=1; i<str.size(); i++){
    if(str[i] == str[i-1]) continue;
    cnt[str[i]]++;
  }

  cout << min(cnt['0'],cnt['1']);
}