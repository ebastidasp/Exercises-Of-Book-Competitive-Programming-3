#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tests;
  cin>>tests;
  int testId = 1;
  while(tests--){
    int dimensionOfMatrix;
    cin>>dimensionOfMatrix;
    vector<vector<int>> matrix (dimensionOfMatrix, vector<int>(dimensionOfMatrix, 0));
    vector<vector<int>> transpose (dimensionOfMatrix, vector<int>(dimensionOfMatrix, 0));
    for(int i = 0; i < dimensionOfMatrix; i++) {
      int input;
      cin>>input;
      for(int j = 0; j < dimensionOfMatrix; j++) {
        int divider = pow(10,dimensionOfMatrix-j-1);
        matrix[i][j] = (input/divider % 10);
      }
    }
    int numberOfInstructions;
    cin>>numberOfInstructions;
    cin.get();
    while(numberOfInstructions--) {
      string instruction;
      getline(cin, instruction);
      int a, b;
      switch(instruction.at(0)) {
        case 'r':
          a = int(instruction.at(4)-'0');
          b = int(instruction.at(6)-'0');
          for(int i = 0 ; i < dimensionOfMatrix; i++) {
            int aux = matrix[a-1][i];
            matrix[a-1][i] = matrix[b-1][i];
            matrix[b-1][i] = aux;
          }
          break;
        case 'c':
          a = int(instruction.at(4)-'0');
          b = int(instruction.at(6)-'0');
          for(int i = 0 ; i < dimensionOfMatrix; i++) {
            int aux = matrix[i][a-1];
            matrix[i][a-1] = matrix[i][b-1];
            matrix[i][b-1] = aux;
          }
          break;
        case 'i':
          for(int i = 0; i < dimensionOfMatrix; i++) {
            for(int j = 0; j < dimensionOfMatrix; j++) {
              matrix[i][j] = (matrix[i][j]+1)%10;
            }
          }
          break;
        case 'd':
          for(int i = 0; i < dimensionOfMatrix; i++) {
            for(int j = 0; j < dimensionOfMatrix; j++) {
              matrix[i][j] = (matrix[i][j]-1+10)%10;
            }
          }
          break;
        case 't':
          for(int i = 0; i < dimensionOfMatrix; i++) {
            for(int j = 0; j < dimensionOfMatrix; j++) {
              transpose[j][i] = matrix[i][j];
            }
          }
          matrix = transpose;
          break;
        default:
          break;
      }
    }
    cout<<"Case #"<<testId<<"\n";
    for(int i = 0; i < dimensionOfMatrix; i++) {
      for(int j = 0; j < dimensionOfMatrix; j++) {
        cout<<matrix[i][j];
      }
      cout<<'\n';
    }
    cout<<'\n'; 
    testId++;
  }
  return 0;
}