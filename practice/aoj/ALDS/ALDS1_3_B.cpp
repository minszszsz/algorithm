#include<iostream>
#include<queue>
#include<string>
#define R pair<string, long long>

using namespace std;

int main(){
  queue<R> Q;
  long long n, q, time;
  string name;
  cin >> n >> q;
  for(long long i=0;i<n;i++){
    cin >> name >> time;
    Q.push(R(name, time));
  }
  long long total=0;
  while(!Q.empty()){
    R r = Q.front();Q.pop();
    if(r.second <= q){
      total += r.second;
      cout << r.first << ' ' << total << endl;
    }
    else{
      total += q;
      Q.push(R(r.first, r.second - q));
    }
  }
}