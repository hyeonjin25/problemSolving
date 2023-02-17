#include <bits/stdc++.h>

using namespace std;

int mat[19][19];

// 한칸당 25칸씩 전부 확인하기 400*25 - 오른쪽, 아래, 대각선 오/왼

int pos(int x, int y){
  if(x<0||x>=19||y<0||y>=19) return -1;
  else return mat[x][y];
}

int func(int x, int y, int a){
  int count=0;
  for(int i=0; i<5; i++) {
    if (pos(x+i,y)==a) count++;
  }
  if(count==5) {
    if(pos(x-1,y)!=a&&pos(x+5,y)!=a) return a;
  }

  count=0;
  for(int i=0; i<5; i++) {
    if (pos(x,y+i)==a) count++;
  }
  if(count==5) {
    if(pos(x,y-1)!=a&&pos(x,y+5)!=a) return a;
  }

  count=0;
  for(int i=0; i<5; i++) {
    if (pos(x+i,y+i)==a) count++;
  }
  if(count==5) {
    if(pos(x-1,y-1)!=a&&pos(x+5,y+5)!=a) return a;
  }

  count=0;
  for(int i=0; i<5; i++) {
    if (pos(x-i,y+i)==a) count++;
  }
  if(count==5) {
    if(pos(x+1,y-1)!=a&&pos(x-5,y+5)!=a) return a;
  }

  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<19; i++)
    for(int j=0; j<19; j++)
      cin >> mat[i][j];

  for(int i=0; i<19; i++){
    for(int j=0; j<19; j++){
      if(mat[i][j]!=0) {
        if(func(i,j,mat[i][j])!=0) {
          cout << mat[i][j] << '\n' << i+1 << ' ' << j+1;
          return 0;
        }
      }
    }
  }
  
  cout << 0;
}