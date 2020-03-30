#include<iostream>

using namespace std;

int main(){
  int n, q, a[100009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  cin >> q;
  int cnt =0, x;
  for(int i=0;i<q;i++){
    cin >> x;
    for(int j=0;j<n;j++){
      if(a[j] == x){
        cnt++;
        break;
      }
    }
  }
  cout << cnt << endl;
}