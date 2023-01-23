#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tests;
  cin>>tests;
  while(tests--){
    vector<vector<int>> pyramid;
    for(int i = 0; i < 9; i++) {
      vector<int> aux (i+1, 0);
      pyramid.push_back(aux);
    }
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j <= i; j++) {
        int input;
        cin>>input;
        pyramid[2*i][2*j] = input;
      }
    }
    for(int i = 8; i >= 2; i -= 2) {
      for(int j = 0; j < i; j += 2) {
        pyramid[i][j+1] = (pyramid[i-2][j] - pyramid[i][j] - pyramid[i][j+2])/2;
        pyramid[i-1][j] = pyramid[i][j] + pyramid[i][j+1];
        pyramid[i-1][j+1] = pyramid[i][j+1] + pyramid[i][j+2];
      }
    }
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < i+1; j++) {
        if(j == i)
          cout<<pyramid[i][j];
        else 
          cout<<pyramid[i][j]<<" ";
      }
      cout<<'\n';
    }
  }
  return 0;
}