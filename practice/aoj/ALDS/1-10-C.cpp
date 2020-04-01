#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int dp[1501][1501];

int LCS(string x, string y){
  memset(dp, 0, sizeof(dp));
  if(x[0] == y[0])dp[0][0] = 1;
  for(int i=1;i<x.length();i++){
    dp[i][0] = dp[i-1][0];
    if(x[i] == y[0])dp[i][0] = 1;
  }
  for(int i=1;i<y.length();i++){
    dp[0][i] = dp[0][i-1];
    if(y[i] == x[0])dp[0][i] = 1;
  }
  for(int i=1;i<x.length();i++){
    for(int j=1;j<y.length();j++){
      if(x[i] == y[j])dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[x.length()-1][y.length()-1];
}

int main(){
  int q;cin >> q;
  for(int i=0;i<q;i++){
    string x, y;
    cin >> x >> y;
    cout << LCS(x, y) << endl;
  }
}