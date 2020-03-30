#include<iostream>
#include<cstring>

using namespace std;

int n, a[2000009], b[2000009];

int main(){
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  int c[10009];
  memset(c, 0, sizeof(c));
  for(int i=0;i<n;i++)c[a[i]]++;
  for(int i=1;i<=10000;i++){
    c[i] += c[i-1];
  }
  for(int i=n-1;i>=0;i--){
    b[c[a[i]]-1] = a[i];
    c[a[i]]--;
  }
  for(int i=0;i<n;i++)cout << b[i] << (i<n-1?' ': '\n');
}