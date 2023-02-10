#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling) {
    int res=0;
    
    for(string& s:babbling){
        int fail=0;
        int n=s.size();
        
        int i=0;
        while(i<n){
            if(n-i>2 && s[i]=='a'){
                if(s[i+1]=='y'&& s[i+2]=='a') i+=3;
                else{fail=1; break;}
            }
            else if(n-i>1 && s[i]=='y'){
                if(s[i+1]=='e') i+=2;
                else{fail=1; break;}
            }
            else if(n-i>2 && s[i]=='w'){
                if(s[i+1]=='o'&& s[i+2]=='o') i+=3;
                else{fail=1; break;}
            }
            else if(n-i>1 && s[i]=='m'){
                if(s[i+1]=='a') i+=2;
                else{fail=1; break;}
            }
            else {fail=1; break;}
        }
        if(!fail) res++;
    }
    
    return res;
}
