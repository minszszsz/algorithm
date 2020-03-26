#include<iostream>

using namespace std;

int n, a[109];

void bubbleSort(){
  int cnt=0;
  for(int i=0;i<n;i++){
    for(int j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        cnt++;
        int tmp=a[j];
        a[j]=a[j-1];
        a[j-1]=tmp;
      }
    }
  }
  for(int i=0;i<n;i++)cout << a[i] << (i<n-1?' ': '\n');
  cout << cnt << endl;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  bubbleSort();
}