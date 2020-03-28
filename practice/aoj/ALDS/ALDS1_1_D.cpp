#include<iostream>

using namespace std;

int main(){
  long long n, r[200009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> r[i];
  long long mx_prof = -1e9;
  long long mn=r[0];
  for(int i=1;i<n;i++){
    mx_prof = max(mx_prof, r[i] - mn);
    mn = min(mn, r[i]);
  }
  cout << mx_prof << endl;
}