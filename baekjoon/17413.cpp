#include <bits/stdc++.h>

using namespace std;

string str;
vector<char> vec;
stack<char> S;

int main()
{
  getline(cin,str);

  int flag=0;
  int st,end;
  for(int i=0; i<str.size(); i++){
    if(str[i]==' '||str[i]=='<'){
      while(S.size()){
        char c = S.top(); S.pop();
        vec.push_back(c);
      }
      vec.push_back(str[i]);
      if(str[i]=='<') flag=1;
      continue;
    }
    if(flag==1) vec.push_back(str[i]);
    else S.push(str[i]);    
 
    if(str[i]=='>') flag=0;
  }

  while(S.size()){
    char c = S.top(); S.pop();
    vec.push_back(c);
  }

  for(char c:vec){
    cout << c;
  }
}