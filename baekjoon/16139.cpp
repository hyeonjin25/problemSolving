#include <bits/stdc++.h>
using namespace std;

int arr[200005][50];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;

  for(int i=0; i<str.size(); i++){
    for(int j=0; j<26; j++){
      if(i!=0) {
        arr[i][j] = arr[i-1][j];
      }

      if(str[i]-'a'==j) arr[i][j]++;
    }
  }

  int T;
  char c;
  int l,r;
  cin >> T;
  
  while(T--){
    cin >> c >> l >> r;

    int rr = arr[r][c-'a'];
    if(l == 0) {
      cout << rr << '\n';
      continue;
    }
    int ll = arr[l-1][c-'a'];
    cout << rr-ll << '\n';
  }
}