#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#define P pair<char, char>

using namespace std;
int n;
P p[109], q[109], r[109];

void printArray(P a[]){
  for(int i=0;i<n;i++){
    cout << a[i].first << a[i].second << (i<n-1?' ': '\n');
  }
}

void bubbleSort(){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>=i+1;j--){
      if(q[j].second < q[j-1].second){
        swap(q[j], q[j-1]);
      }
    }
  }
}

void selectionSort(){
  for(int i=0;i<n;i++){
    int mni = i;
    for(int j=i;j<n;j++){
      if(r[j].second <r[mni].second){
        mni=j;
      }
    }
    if(mni!=i)swap(r[i], r[mni]);
  }
}

int main(){
  cin >> n;
  string s;
  for(int i=0;i<n;i++){
    cin >> s;
    p[i] = P(s[0], s[1]);
  }
  copy(p, p+n, q);
  copy(p, p+n, r);
  bubbleSort();
  printArray(q);
  cout << "Stable" << endl;
  selectionSort();
  printArray(r);
  bool check_stable=true;
  for(int i=0;i<n;i++){
    if(q[i] != r[i])check_stable=false;
  }
  cout << (check_stable?"Stable": "Not stable") << endl;
}