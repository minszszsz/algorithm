#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define P pair<int, int>

using namespace std;

int n, d[109];
vector<int> G[109];
bool check[109];


int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    int u, k, v;
    cin >> u >> k;
    for(int i=0;i<k;i++){
      cin >> v;
      G[u].push_back(v);
    }
  }
  memset(check, false, sizeof(check));
  memset(d, -1, sizeof(d));
  queue<P> Q;
  Q.push(P(1, 0));
  check[1]=true;
  while(!Q.empty()){
    P p = Q.front();Q.pop();
    int n=p.first, dis = p.second;
    d[n] = dis;
    for(int i=0;i<G[n].size();i++){
      if(!check[G[n][i]]){
        check[G[n][i]]=true;
        Q.push(P(G[n][i], dis + 1));
      }
    }
  }
  for(int i=1;i<=n;i++)cout << i << ' ' << d[i] << endl;
}