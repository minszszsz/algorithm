#include<iostream>

using namespace std;

long long n,k,w[100009], mn=10000, mx=0, sm=0;

bool check(int p){
  if(k*p<sm || p<mx)return false;
  long long rest=0, cnt=1;
  for(int i=0;i<n;i++){
    if(rest + w[i] > p){
      cnt++;
      rest = w[i];
    }
    else rest += w[i];
  }
  if(cnt>k)return false;
  return true;
}

int main(){
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> w[i];
    mn = min(w[i], mn);
    mx = max(w[i], mx);
    sm += w[i];
  };
  long long left=mn, right=1e9;
  while(left<right){
    long long md = (left + right)/2;
    if(check(md))right=md;
    else left=md+1;
  }
  cout << left << endl;
}