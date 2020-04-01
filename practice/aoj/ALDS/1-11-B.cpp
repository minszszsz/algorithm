#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

bool check[109];
int d[109], f[109];
int n, t=0;
vector<int> G[109];

void dfs(int n){
  check[n] = true;
  d[n] = ++t;
  for(int i=0;i<G[n].size();i++){
    if(!check[G[n][i]])dfs(G[n][i]);
  }
  f[n] = ++t;
}

int main(){
  memset(check, false, sizeof(check));
  cin >> n;
  for(int i=0;i<n;i++){
    int u, k, v;
    cin >> u >> k;
    for(int i=0;i<k;i++){
      cin >> v;
      G[u].push_back(v);
      sort(G[u].begin(), G[u].end());
    }
  }
  for(int i=1;i<=n;i++){
    if(!check[i])dfs(i);
  }
  for(int i=1;i<=n;i++)cout << i << ' ' <<  d[i] << ' ' << f[i] << endl;
}