#include<iostream>
#include<stack>
#include<string>

using namespace std;

long long str_to_int(string str){
  long long ret=0;
  for(int i=0;i<str.length();i++){
    ret *= 10;
    ret += str[i] - '0';
  }
  return ret;
}

int main(){
  stack<long long> s;
  string tmp;
  while(cin >> tmp){
    if(tmp == "+"){
      long long sm=0;
      sm += s.top();s.pop();
      sm += s.top();s.pop();
      s.push(sm);
    }
    else if(tmp == "-"){
      long long sm=0;
      sm -= s.top();s.pop();
      sm += s.top();s.pop();
      s.push(sm);
    }
    else if(tmp == "*"){
      long long mu=1;
      mu *= s.top();s.pop();
      mu *= s.top();s.pop();
      s.push(mu);
    }
    else{
      s.push(str_to_int(tmp));
    }
  }
  cout << s.top() << endl;
}
