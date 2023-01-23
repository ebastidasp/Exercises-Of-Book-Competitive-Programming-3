#include <bits/stdc++.h>

using namespace std;

int main()
{ 
  int n, m;
  cin.tie(NULL);
  while(cin>>n>>m, n) {
    cin.ignore();
    vector<vector<char>> bigPolyomino(n, vector<char>(n, ' ')), smallPolyommino(m, vector<char>(m, ' '));
    for(int i = 0; i < n; i++) {
      string input;
      cin>>input;
      for(int j = 0; j < input.length(); j++)
        bigPolyomino[i][j] = input.at(j);
      for(int j = input.length(); j < n; j++)
        bigPolyomino[i][j] = '.';
    }
    for(int i = 0; i < m; i++) {
      string input;
      cin>>input;
      for(int j = 0; j < input.length(); j++)
        smallPolyommino[i][j] = input.at(j);
      for(int j = input.length(); j < m; j++)
        smallPolyommino[i][j] = '.';
    }
    bool bigPolHasAtLeast1Ast = false;
    for(int i = 0; i < bigPolyomino.size(); i++) {
      for(int j = 0; j < bigPolyomino[0].size(); j++) {
        if(bigPolyomino[i][j] == '*') {
          bigPolHasAtLeast1Ast = true;
          break;
        }
      }
      if (bigPolHasAtLeast1Ast) break;
    }
    if (bigPolHasAtLeast1Ast) {
      bool hasAtLeast1Ast = false;
      for(int i = 0; i < smallPolyommino.size(); i++) {
        for(int j = 0; j < smallPolyommino[0].size(); j++) {
          if(smallPolyommino[i][j] == '*') {
            hasAtLeast1Ast = true;
            break;
          }
        }
        if (hasAtLeast1Ast) break;
      }
      if (hasAtLeast1Ast) {
        bool hasMinDimension = false;
        while (!hasMinDimension) {
          for(int i = 0; i < smallPolyommino.size(); i++) {
            bool hasAst = false;
            for(int j = 0; j < m; j++) {
              if(smallPolyommino[i][j] == '*') {
                hasAst = true;
                break;
              }
            }
            if (!hasAst) {
              smallPolyommino.erase(smallPolyommino.begin()+i);
              break;
            } else {
              hasMinDimension = true;
              break;
            }
          }
        }
        hasMinDimension = false;
        while(!hasMinDimension) {
          for(int i = smallPolyommino.size()-1; i >= 0; i--) {
            bool hasAst = false;
            for(int j = 0; j < m; j++) {
              if(smallPolyommino[i][j] == '*') {
                hasAst = true;
                break;
              }
            }
            if (!hasAst) {
              smallPolyommino.erase(smallPolyommino.begin()+i);
              break;
            } else {
              hasMinDimension = true;
              break;
            }
          } 
        }
        hasMinDimension = false;
        while (!hasMinDimension) {
          for(int i = 0; i < smallPolyommino[0].size(); i++) {
            bool hasAst = false;
            for(int j = 0; j < smallPolyommino.size(); j++) {
              if (smallPolyommino[j][i] == '*') {
                hasAst = true;
                break;
              }
            }
            if (!hasAst) {
              for(int j = 0; j < smallPolyommino.size(); j++) {
                smallPolyommino[j].erase(smallPolyommino[j].begin()+i);
              }
              break;
            } else {
              hasMinDimension = true;
              break;
            }
          }
        }
        hasMinDimension = false;
        while(!hasMinDimension) {
          for(int i = smallPolyommino[0].size()-1; i >= 0; i--) {
            bool hasAst = false;
            for(int j = 0; j < smallPolyommino.size(); j++) {
              if (smallPolyommino[j][i] == '*') {
                hasAst = true;
                break;
              }
            }
            if (!hasAst) {
              for(int j = 0; j < smallPolyommino.size(); j++) {
                smallPolyommino[j].erase(smallPolyommino[j].begin()+i);
              }
              break;
            } else {
              hasMinDimension = true;
              break;
            }
          }
        }
      }
      bool canBeFormed = false;
      for(int j = 0; j <= bigPolyomino.size()-smallPolyommino.size(); j++) {
        for (int k = 0; k <= bigPolyomino.size()-smallPolyommino[0].size(); k++) {
          for(int l = 0; l <= bigPolyomino.size()-smallPolyommino.size(); l++) {
            for(int o = 0; o <= bigPolyomino.size()-smallPolyommino[0].size(); o++) {
              vector<vector<char>> combinationOf2SmallPolyommino (n, vector<char>(n, '.'));
              for(int p = j; p < smallPolyommino.size()+j; p++) {
                for(int q = k; q < smallPolyommino[0].size()+k; q++) {
                  if (smallPolyommino[p-j][q-k] == '*') {
                    combinationOf2SmallPolyommino[p][q] = '*';
                  }
                }
              }
              for(int p = l; p < smallPolyommino.size()+l; p++) {
                for(int q = o; q < smallPolyommino[0].size()+o; q++) {
                  if (smallPolyommino[p-l][q-o] == '*' && combinationOf2SmallPolyommino[p][q] == '.') {
                    combinationOf2SmallPolyommino[p][q] = '*';
                  }
                }
              }
              if(combinationOf2SmallPolyommino == bigPolyomino) {
                canBeFormed = true;
                break;
              }
            }
            if (canBeFormed) break;
          }
          if (canBeFormed) break;
        }
        if (canBeFormed) break;
      }
      if(canBeFormed) {
        cout<<"1\n";
      }
      else {
        cout<<"0\n";
      }
    } else {
      cout<<"0\n";
    }
  }
  return 0;
}