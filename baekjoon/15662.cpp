#include <bits/stdc++.h>
using namespace std;

// 1000*1000*8
// 오른쪽 : 2 - 6 맞닿음
// 왼쪽 : 6 - 2 맞닿음

int n; 
string sarr[1005];

string lround(string str){
  char temp = str[0];
  for(int i=0; i<7; i++){
    str[i] = str[i+1];
  }
  str[7] = temp;
  return str;
}

string rround(string str){
  char temp = str[7];
  for(int i=7; i>0; i--){
    str[i] = str[i-1];
  }
  str[0] = temp;
  return str;
}

void lcomp(int cur, int round, int a){
  if(cur==0) return;
  if(sarr[cur][6]!=sarr[cur-1][2]){
    lcomp(cur-1, round*(-1), a);
    if(cur==a) return;
    if(round=='1') sarr[cur]=rround(sarr[cur]);
    else sarr[cur]=lround(sarr[cur]);
  }
}

void rcomp(int cur, int round, int a){
  if(cur==n) return;
  if(sarr[cur][2]!=sarr[cur+1][6]){
    rcomp(cur+1, round*(-1), a);
    if(cur==a) return;
    if(round=='1') sarr[cur]=rround(sarr[cur]);
    else sarr[cur]=lround(sarr[cur]);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> sarr[i];
  }

  int nn;
  cin >>nn;

  int a,round;
  for(int i=0; i<nn; i++){
    cin >> a>>round;

    lcomp(a,round,a);
    rcomp(a,round,a);

    if(round=='1') sarr[a]=rround(sarr[a]);
    else sarr[a]=lround(sarr[a]);
  }

  int cnt=0;
  for(int i=1; i<=n; i++){
    if(sarr[i][0]=='1') cnt++;
  }

  for(int i=1; i<=n; i++){
    for(int j=0; j<8; j++){
      cout << sarr[i][j]<<' ';
    }
    cout << '\n';
  }

  // cout << cnt;
}