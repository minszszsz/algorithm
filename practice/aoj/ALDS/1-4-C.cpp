#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool dic[30000000];

void init(){
  memset(dic, false, sizeof(dic));
}

int _hash(string s){
  int ret=0;
  for(int i=0;i<s.length();i++){
    ret *= 5;
    if(s[i]=='A')ret += 1;
    else if(s[i]=='C')ret += 2;
    else if(s[i]=='G')ret += 3;
    else if(s[i]=='T')ret += 4;
  }
  return ret;
}

void insert(string s){
  dic[_hash(s)] = true;
}

bool find(string s){
  return dic[_hash(s)];
}

int main(){
  init();
  int n;cin >> n;
  for(int i=0;i<n;i++){
    string com, s; cin >> com >> s;
    if(com == "insert")insert(s);
    else if(com == "find"){
      cout << (find(s)?"yes": "no") << endl;
    }
  }
}