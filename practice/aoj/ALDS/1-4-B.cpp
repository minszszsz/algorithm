#include<iostream>

using namespace std;

int n, a[100009];

bool binary_search(int x){
  int lb=-1, ub=n;
  while(lb+1<ub){
    int md = (lb+ub)/2;
    if(a[md]<=x)lb=md;
    else ub=md;
  }
  return a[lb]==x;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  int q;cin >> q;
  int cnt=0;
  for(int i=0;i<q;i++){
    int x;cin >> x;
    if(binary_search(x))cnt++;
  }
  cout <<cnt << endl;
}