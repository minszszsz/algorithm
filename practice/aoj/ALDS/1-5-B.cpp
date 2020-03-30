#include<iostream>
#include<vector>

const int SENTINENTAL=1e9+7;

using namespace std;

int cnt=0;
int n;
int A[500009];

void merge(int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int>L, R;
  for(int i=0;i<n1;i++)L.push_back(A[left+i]);
  for(int i=0;i<n2;i++)R.push_back(A[mid+i]);
  L.push_back(SENTINENTAL);
  R.push_back(SENTINENTAL);
  int i=0, j=0;
  for(int k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j])A[k]=L[i++];
    else A[k]=R[j++];
  }
}

void mergeSort(int left, int right){
  if(left+1<right){
    int mid=(left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(){
  cin >> n;
  int tmp;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  mergeSort(0, n);
  for(int i=0;i<n;i++)cout << A[i] << (i<n-1?' ': '\n');
  cout << cnt << endl;
}