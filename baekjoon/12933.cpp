#include <bits/stdc++.h>
using namespace std;

int arr[100]; //quack -> 아스키 매핑
int count=0;

int w[5]={'q'-'0','u'-'0','a'-'0','c'-'0','k'-'0'};

int now=0; // 현재 울고있는 오리 수
int big=0; // 한번에 가장 많이 운 오리 수
int main()
{
  string str; cin >> str;

  for(int i=0; i<str.size();i++){
    int idx=str[i]-'0';
    arr[idx]++;
    for(int j=0; j<4; j++){
      if(arr[w[j]]<arr[w[j+1]]){
        cout << -1; return 0;
      }
    }
    if(idx==w[0]) now++;
    if(idx==w[4]) now--;
    big=max(big,now);
  }

  for(int i=0; i<4; i++){
    if(arr[w[i]]!=arr[w[i+1]]){
      cout << -1; return 0;
    }
  }

  cout << big;
}