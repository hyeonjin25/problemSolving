#include<iostream>
using namespace std;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  string str;
  cin >> str;

  int cnt=0; //m개수
  string res = "";

  // max
  for(char c:str){
    if(c=='K'){ 
      res+="5";
      for(int i=0; i<cnt; i++){
        res += "0";
      }
      cnt=0;
      continue;
    }
    cnt++;
  }
  for(int i=0; i<cnt; i++){
    res += "1";
  }

  cout << res<<'\n';
  
  cnt=0;
  res = "";

   // min
  for(char c:str){
    if(c=='K'){ 
      if(cnt>0){
        res+="1";
        for(int i=0; i<cnt-1; i++){
          res += "0";
        }
        cnt=0;
      }
      res += "5";
      continue;
    }
    cnt++;
  }

  if(cnt>0){
    res+="1";
    for(int i=0; i<cnt-1; i++){
      res += "0";
    }
  }
  cout << res<<'\n';
}