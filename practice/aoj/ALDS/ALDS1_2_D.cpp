#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int n, a[109], b[109], c[109];
int cnt=0;

void insertion_sort(int g){
  for(int i=g;i<g;i++){
    int v=c[i];
    int j=i-g;
    while(j>=0 && c[j]>v){
      c[j+g] = c[j];
      j-=g;
      cnt++;
    }
    c[j+g]=v;
  }
}


int main(){
  cin >> n;
}