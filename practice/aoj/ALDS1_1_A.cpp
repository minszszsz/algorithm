#include<iostream>

using namespace std;
int n, a[109];

void printCards(){
  for(int i=0;i<n;i++)cout << a[i] << (i<n-1?' ': '\n');
}

void insertSort(){
  for(int i=1;i<n;i++){
    int key = a[i];
    int j=i-1;
    while(j>=0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    printCards();
  }
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  insertSort();
}