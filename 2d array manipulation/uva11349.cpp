#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tests;
  cin>>tests;
  int testId = 1;
  while(tests--){
    char Nchar, equalsign;
    int dimensionOfMatrix;
    cin>>Nchar>>equalsign>>dimensionOfMatrix;
    vector<vector<long long>> matrix (dimensionOfMatrix, vector<long long>(dimensionOfMatrix, 0));
    for(int i = 0; i < dimensionOfMatrix; i++) {
      for(int j = 0; j < dimensionOfMatrix; j++) {
        cin>>matrix[i][j];
      }
    }
    bool isSymmetric = true;
    for(int i = 0; i < dimensionOfMatrix; i++) {
      for(int j = 0; j < (dimensionOfMatrix+1)/2; j++) {
        if (matrix[i][j] != matrix[dimensionOfMatrix-1-i][dimensionOfMatrix-1-j] || matrix[i][j] < 0) {
          isSymmetric = false;
          i = j = dimensionOfMatrix;
        }
      }
    }
    if (isSymmetric) {
      cout<<"Test #"<<testId<<": Symmetric.\n";
    } else {
      cout<<"Test #"<<testId<<": Non-symmetric.\n";
    }
    testId++;
  }
  return 0;
}