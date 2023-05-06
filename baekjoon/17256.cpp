#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int ax, ay, az;
  int bx, by, bz;
  int cx, cy, cz;

  cin >> ax>>ay>>az>>cx>>cy>>cz;

  bx=cx-az;
  by=cy/ay;
  bz=cz-ax;

  cout << bx << ' '<<by<<' '<<bz;
}