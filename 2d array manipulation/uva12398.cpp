#include <bits/stdc++.h>

using namespace std;

int main()
{
  string input;
  int testId = 1;
  while(getline(cin,input)) {
    vector<char> inputString;
    for (int i = 0; i < input.length(); i++) {
      inputString.push_back(input.at(i));
    }
    vector<vector<int>> matrix = {{0,0,0},{0,0,0},{0,0,0}};
    for(int i = inputString.size()-1; i >= 0; i--) {
      switch(inputString[i]) {
        case 'a':
          matrix[0][0] = (matrix[0][0]+1)%10;
          matrix[1][0] = (matrix[1][0]+1)%10;
          matrix[0][1] = (matrix[0][1]+1)%10;
          break;
        case 'b':
          matrix[0][1] = (matrix[0][1]+1)%10;
          matrix[0][0] = (matrix[0][0]+1)%10;
          matrix[0][2] = (matrix[0][2]+1)%10;
          matrix[1][1] = (matrix[1][1]+1)%10;
          break;
        case 'c':
          matrix[0][2] = (matrix[0][2]+1)%10;
          matrix[0][1] = (matrix[0][1]+1)%10;
          matrix[1][2] = (matrix[1][2]+1)%10;
          break;
        case 'd':
          matrix[1][0] = (matrix[1][0]+1)%10;
          matrix[0][0] = (matrix[0][0]+1)%10; 
          matrix[1][1] = (matrix[1][1]+1)%10;
          matrix[2][0] = (matrix[2][0]+1)%10;
          break;
        case 'e':
          matrix[1][1] = (matrix[1][1]+1)%10;
          matrix[1][0] = (matrix[1][0]+1)%10;
          matrix[1][2] = (matrix[1][2]+1)%10;
          matrix[0][1] = (matrix[0][1]+1)%10;
          matrix[2][1] = (matrix[2][1]+1)%10;
          break;
        case 'f':
          matrix[1][2] = (matrix[1][2]+1)%10;
          matrix[1][1] = (matrix[1][1]+1)%10;
          matrix[0][2] = (matrix[0][2]+1)%10;
          matrix[2][2] = (matrix[2][2]+1)%10;
          break;
        case 'g':
          matrix[2][0] = (matrix[2][0]+1)%10;
          matrix[2][1] = (matrix[2][1]+1)%10;
          matrix[1][0] = (matrix[1][0]+1)%10;
          break;
        case 'h':
          matrix[2][1] = (matrix[2][1]+1)%10;
          matrix[2][0] = (matrix[2][0]+1)%10;
          matrix[2][2] = (matrix[2][2]+1)%10;
          matrix[1][1] = (matrix[1][1]+1)%10; 
          break;
        case 'i':
          matrix[2][2] = (matrix[2][2]+1)%10;
          matrix[1][2] = (matrix[1][2]+1)%10;
          matrix[2][1] = (matrix[2][1]+1)%10;
          break;
        default:
          break;
      }
    }
    cout<<"Case #"<<testId<<":\n";
    for(int i = 0; i < 3; i++) {
      cout<<matrix[i][0];
      for(int j = 1; j < 3; j++) {
        cout<<" "<<matrix[i][j];
      }
      cout<<'\n';
    }
    testId++;
  }
  return 0;
}