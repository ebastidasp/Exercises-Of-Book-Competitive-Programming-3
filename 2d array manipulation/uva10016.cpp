#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tests;
  cin>>tests;
  cin.tie(NULL);
  while(tests--){
    int n;
    cin>>n;
    vector<vector<int>> squaretron (n, vector<int>(n, 0));
    vector<vector<int>> auxSquaretron (n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin>> squaretron[i][j];
      }
    }
    auxSquaretron = squaretron;
    int numberOfRings = ceil(1.0*n/2);
    for(int i = 0; i < numberOfRings; i++){
      int t;
      cin>>t;
      for(int j = 0; j < t; j++) {
        int c;
        cin>>c;
        switch (c) {
          case 1:
            for(int k = i; k <= (n-1)/2; k++) {
              for(int l = i; l < n-i; l++) {
                if(k == 0 + i || k == n - 1 - i || l == 0 + i || l == n - 1 - i) {
                  int aux = squaretron[k][l];
                  squaretron[k][l] = squaretron[n-1-k][l];
                  squaretron[n-1-k][l] = aux;
                }
              }
            }
            auxSquaretron = squaretron;
            break;
          case 2:
            for(int k = i; k < n-i; k++) {
              for(int l = i; l <= (n-1)/2; l++) {
                if(k == 0 + i || k == n - 1 - i || l == 0 + i || l == n - 1 - i) {
                  int aux = squaretron[k][l];
                  squaretron[k][l] = squaretron[k][n-1-l];
                  squaretron[k][n-1-l] = aux;
                }
              }
            }
            auxSquaretron = squaretron;
            break;
          case 3:
            for(int k = i; k < n-i; k++) {
                for(int l = i; l < n-i; l++) {
                  if(k == 0 + i || k == n - 1 - i || l == 0 + i || l == n - 1 - i) {
                    auxSquaretron[k][l] = squaretron[l][k];
                  }
                }
            }
            squaretron = auxSquaretron;
            break;
          case 4:
            for(int k = i; k < n-i; k++) {
                for(int l = i; l < n-i; l++) {
                  if(k == 0 + i || k == n - 1 - i || l == 0 + i || l == n - 1 - i) {
                    auxSquaretron[n-1-l][n-1-k] = squaretron[k][l];
                  }
                }
            }
            squaretron = auxSquaretron;
            break;
          default:
            break;
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if (j == n-1) {
          cout<<squaretron[i][j];
        } else {
          cout<<squaretron[i][j]<<" ";
        }
      }
      cout<<'\n';
    }
  }
  return 0;
}
