#include <bits/stdc++.h>

using namespace std;

pair<int,int> w[30]; // 숫자들의 위치 저장 (1~25)
int in[30];
int col[10]; // 세로줄 (1~5)
int row[10]; // 가로줄
int crs[5]; // 0:왼쪽 아래로 대각선, 1:오른쪽 위로 대각선

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int temp;
  for(int i=1; i<=5;i++) 
    for(int j=1; j<=5;j++){
      cin >> temp;
      w[temp]={i,j};
    }

  for(int i=0;i<25;i++)
    cin >> in[i];

  for(int i=0; i<25; i++){
    pair<int,int> cur=w[in[i]]; // 현재 위치
    col[cur.first]++;
    row[cur.second]++;
    if(cur.first==cur.second) crs[0]++;
    if(cur.first+cur.second==6) crs[1]++;

    int line=0;
    for(int j=1; j<=5;j++){
      if(col[j]==5) line++;
      if(row[j]==5) line++;
    }
    for(int j=0; j<=1;j++){
      if(crs[j]==5) line++;
    }
    
    if(line>2){
      cout << i+1;
      return 0;
    }
  }
}