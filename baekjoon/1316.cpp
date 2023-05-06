#include<bits/stdc++.h>
using namespace std;

int arr[200];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int T;
  string str;
  cin >> T;
  int cnt=0;

  while(T--){
    cin >> str;

    fill(arr,arr+200,0);

    int flag=0;
    for(int i=0; i<str.size(); i++){
      if(arr[str[i]]==1&&str[i-1]!=str[i]) {
        flag=1;
        break;
      }
      arr[str[i]]=1;
    }

    if(flag==0) {
      cnt++;
    }
  }

  cout << cnt;
}