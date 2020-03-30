#include<iostream>

using namespace std;

int n, q, a[29], b[209];

bool search(int rest, int idx){
  if(rest == 0)return true;
  else if(idx>=n || rest < 0)return false;
  else return search(rest - a[idx], idx+1) || search(rest, idx+1);
}

int main(){
  cin >>n;
  for(int i=0;i<n;i++)cin >> a[i];
  cin >> q;
  for(int i=0;i<q;i++)cin >> b[i];
  for(int i=0;i<q;i++){
    cout << (search(b[i], 0) ? "yes": "no") << endl;
  }
}