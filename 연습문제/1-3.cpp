#include <bits/stdc++.h>

using namespace std;

//제곱 수 판별
//o(sqlt(n))
int func3(int n){
  for(int i=0; i<n;i++){
    if(i*i==n)return 1;
  }
  return 0;
}

int main(){

}