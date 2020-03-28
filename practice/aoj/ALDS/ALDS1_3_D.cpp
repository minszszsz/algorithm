#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int main(){
  string s;
  stack<int> s1, s2;
  int total=0;
  cin >> s;
  for(int i=0;i<s.length();i++){
    if(s[i]=='\\')s1.push(i);
    else if(s[i]=='/'){

    }
  }
}