#include<iostream>

using namespace std;

int main(){
  int n;cin >> n;
  long long a=1, b=1, c;
  for(int i=0;i<n-1;i++){
    c = b;
    b = a;
    a = b + c;
  }
  cout << a << endl;
}