#include<iostream>
#include<map>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  char al[5] = {'M','O','B','I','S'};

  map<char,int> m;
  string str;
  cin >> str;

  for(auto s:str){
    m[s]=1;
  }

  for(auto a:al){
    if(m.find(a)==m.end()){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}