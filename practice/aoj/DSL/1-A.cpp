#include<iostream>
#include<vector>

using namespace std;

int n, q;
int parent[10009], root[10009];

void init(int n){
  for(int i=0;i<n;i++){
    parent[i] = i;
    root[i] = i;
  }
}

int find_root(int x){
  if(root[x] == x)return x;
  else return root[x] = find_root(root[x]);
}

void unite(int x, int y){
  if(find_root(x) == find_root(y))return;
  root[find_root(y)] = find_root(x);
};

bool same(int x, int y){
  return find_root(x) == find_root(y);
};

int main(){
  cin >> n >> q;
  init(n);
  for(int i=0;i<q;i++){
    int com, x, y;
    cin >> com >> x >> y;
    if(com == 0){
      unite(x, y);
    }
    else if(com == 1){
      cout << (same(x, y)?'1': '0') << endl;
    }
  }
}
