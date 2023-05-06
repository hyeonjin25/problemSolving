#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;

  int cnt=0;
  for(int i=0; i<str.size(); i++){
    if(str[i]=='c'){
      if(str[i+1]=='='||str[i+1]=='-'){
        i++;
      }
    }
    if(str[i]=='d'){
      if(str[i+1]=='z'&&str[i+2]=='='){
        i+=2;
      }
      if(str[i+1]=='-'){
        i++;
      }
    }
    if(str[i]=='l'&&str[i+1]=='j')
      i++;
    
    if(str[i]=='n'&&str[i+1]=='j')
      i++;
    
    if(str[i]=='s'&&str[i+1]=='=')
      i++;
    
    if(str[i]=='z'&&str[i+1]=='=')
      i++;
    
    cnt++;
  }

  cout << cnt;
}