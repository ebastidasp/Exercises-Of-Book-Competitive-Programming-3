#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tests;
  cin>>tests;
  while(tests--){
    vector<vector<int>> matrix (3, vector<int>(3,0));
    vector<vector<int>> resultMatrix = {
      {0,0,0},
      {0,0,0},
      {0,0,0}
    };
    for(int i = 0; i < 3; i++) {
      int input;
      cin>>input;
      for(int j = 0; j < 3; j++) {
        matrix[i][j] = (input/int(pow(10, 3-j-1))) % 10;
      }
    }
    int maxIndex = -1;
    while(matrix != resultMatrix) {
      vector<vector<int>> auxMatrix = matrix;
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          if (i == 0 && j == 0) {
            auxMatrix[i][j] = (matrix[i+1][j] + matrix[i][j+1])%2;
          } else if (i == 1 && j == 0) {
            auxMatrix[i][j] = (matrix[i+1][j] + matrix[i][j+1]+matrix[i-1][j])%2; 
          } else if (i == 2 && j == 0) {
            auxMatrix[i][j] = (matrix[i-1][j] + matrix[i][j+1])%2; 
          } else if (i == 0 && j == 1) {
            auxMatrix[i][j] = (matrix[i][j+1] + matrix[i][j-1]+matrix[i+1][j])%2; 
          } else if (i == 0 && j == 2) {
            auxMatrix[i][j] = (matrix[i][j-1] + matrix[i+1][j])%2; 
          } else if (i == 1 && j == 1) {
            auxMatrix[i][j] = (matrix[i][j+1] + matrix[i][j-1]+matrix[i+1][j]+matrix[i-1][j])%2; 
          } else if (i == 1 && j == 2) {
            auxMatrix[i][j] = (matrix[i-1][j] + matrix[i][j-1]+matrix[i+1][j])%2; 
          } else if (i == 2 && j == 1) {
            auxMatrix[i][j] = (matrix[i][j+1] + matrix[i][j-1]+matrix[i-1][j])%2; 
          } else if (i == 2 && j == 2) {
            auxMatrix[i][j] = (matrix[i][j-1] + matrix[i-1][j])%2; 
          }
        }
      }
      matrix = auxMatrix;
      maxIndex++;
    }
    cout<<maxIndex<<'\n';
  }
  return 0;
}