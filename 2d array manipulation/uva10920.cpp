#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long sz, p;
  while(cin>>sz) {
    cin>>p;
    if(!sz && !p) return 0;
    long long n = 1;
    while (p > (2*n-1)*(2*n-1)) {
      n++;
    }
    if(p == (2*n-1)*(2*n-1)) {
      cout <<"Line = "<<ceil(1.0*sz/2.0)+n-1<<", column = "<<ceil(1.0*sz/2.0)+n-1<<".\n";
    } else {
      long long minCoordinate = ceil(1.0*sz/2.0)-n+1, maxCoordinate = ceil(1.0*sz/2.0)+n-1;
      long long count = (2*n-1)*(2*n-1)+1;
      int x  = ceil(1.0*sz/2.0)+n, y = ceil(1.0*sz/2.0)+n-1;
      int dir = 0;
      while (count != p) {
        switch (dir) {
          case 0:
            if((x-1) < minCoordinate) {
              dir = 1;
              y--;
            } else {
              x--;
            }
            break;
          case 1:
            if((y-1) < minCoordinate) {
              dir = 2;
              x++;
            } else {
              y--;
            }
            break;
          case 2:
            if ((x+1) > maxCoordinate) {
              dir = 3;
              y++;
            } else {
              x++;
            }
            break;
          case 3:
            if((y+1) > maxCoordinate) {
              dir = 0;
              x--;
            } else {
              y++;
            }
            break;
          default:
            break;
        }
        count--;
      }
      cout<<"Line = "<<x<<", column = "<<y<<".\n";
    }
  }
  return 0;
}