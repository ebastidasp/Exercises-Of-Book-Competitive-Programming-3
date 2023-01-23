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
    vector<vector<int>> blockSpaces (n, vector<int>(n, 0));
    vector<vector<int>> blockSpaces2 (n, vector<int>(n, 0));
    vector <int> front, right;
    for(int i = 0; i < n; i++) {
      int input;
      cin>>input;
      front.push_back(input);
    }
    for(int i = 0; i < n; i++) {
      int input;
      cin>>input;
      right.push_back(input);
    }
    int min = 0;
    vector<int> available (n, 0);
    for(int i = 0; i < n; i++){
      int val = front[i];
      int minvalue = 1000000000;
      int index = -1;
      for(int j = 0; j < n; j++){
        if(right[j] >= val && right[j] < minvalue && available[j] < right[j]) {
          index = j;
          minvalue = right[j];
        }
      }
      if(index != -1) {
        blockSpaces[n-index-1][i] = val;
        available[index] = max(val, available[index]);
      } else {
        for(int j = 0; j < n; j++){
          if(right[j] >= val && right[j] < minvalue) {
            index = j;
            minvalue = right[j];
          }
        }
        blockSpaces[n-index-1][i] = val;
        available[index] = max(val, available[index]);
      }
    }
    for(int i = 0; i < n; i++){
      int val = right[n-i-1];
      int maxN = 0;
      for(int j = 0; j < n; j++){
        if(blockSpaces[i][j] > maxN) {
          maxN = blockSpaces[i][j];
        }
      }
      if(maxN < val) {
        int minvalue = 1000000000;
        int index;
        for(int j = 0; j < n; j++) {
          if(front[j] >= val && front[j] < minvalue) {
            index = j;
            minvalue = front[j];
          }
        }
        blockSpaces[i][index] = val;
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        min += blockSpaces[i][j];
      }
    }
    int maxBlocks = 0;
    for(int i = 0; i < n; i++){
      int val = front[i];
      for(int j = 0; j < n; j++){
        if(front[i] <= right[n-j-1]) {
          blockSpaces2[n-j-1][i] = front[i];
        } else {
          blockSpaces2[n-j-1][i] = right[n-j-1];
        }
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        maxBlocks += blockSpaces2[i][j];
      }
    }
    cout<<"Matty needs at least "<<min<<" blocks, and can add at most "<<maxBlocks-min<<" extra blocks."<<'\n';
  }
  return 0;
}