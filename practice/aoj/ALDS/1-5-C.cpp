#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#define P pair<double, double>

using namespace std;

void printPoint(P point){
  printf("%.8lf %.8lf\n", point.first, point.second);
}

void recursive(P start, P end, int cnt){
  if(cnt == 0)return;
  double third_x = (end.first - start.first)/3.0;
  double third_y = (end.second - start.second)/3.0;
  double rotate_x = third_x/2.0 - third_y*sqrt(3)/2.0;
  double rotate_y = third_x*sqrt(3)/2.0 + third_y/2.0;
  P point1 = P(start.first + third_x, start.second + third_y);
  P point2 = P(start.first + third_x + rotate_x, start.second + third_y+rotate_y);
  P point3 = P(start.first + third_x*2, start.second + third_y*2);
  recursive(start, point1, cnt-1);
  printPoint(point1);
  recursive(point1, point2, cnt-1);
  printPoint(point2);
  recursive(point2, point3, cnt-1);
  printPoint(point3);
  recursive(point3, end, cnt-1);
}

int main(){
  int n; cin >> n;
  P start = P(0.0, 0.0);
  P end = P(100.0, 0.0);
  printPoint(start);
  recursive(P(0.0, 0.0), P(100.0, 0.0), n);
  printPoint(end);
}