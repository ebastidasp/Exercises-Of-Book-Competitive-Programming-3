#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<vector<int>> blockSpaces (n+2, vector<int>(n+2, -1));
  for(int i = 0; i < n; i++) {
    blockSpaces[i][0] = i;
  }
  char input [25];
  gets(input);
  while(gets(input)) {
    int a, b, posA, posB, lastB, columnA, columnB;
    char instruction [4];
    char secondInstruction[4];
    sscanf(input, "%s %d %s %d", instruction, &a, secondInstruction, &b);
    switch (input[0]) {
      case 'm':
        switch (secondInstruction[1]) {
          case 'n':
            for(int i = 0; i < n; i++) {
              for(int j = 0; j < n; j++) {
                if(blockSpaces[i][j] == a) {
                  columnA = i;
                }
                if(blockSpaces[i][j] == b) {
                  columnB = i;
                }
              }
            }
            if(columnA != columnB) {
              for(int i = 0; i < n; i++) {
                if(blockSpaces[columnB][i] == b) {
                  posB = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnB][i] != -1)){
                    blockSpaces[blockSpaces[columnB][i]][0] = blockSpaces[columnB][i];
                    blockSpaces[columnB][i] = -1;
                    i++; 
                  }
                }
              }
              for(int i = 0; i < n; i++){
                if(blockSpaces[columnA][i] == a) {
                  posA = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnA][i] != -1)){
                    blockSpaces[blockSpaces[columnA][i]][0] = blockSpaces[columnA][i];
                    blockSpaces[columnA][i] = -1;
                    i++; 
                  }                  
                }
              }
              blockSpaces[columnB][posB+1] = a;
              blockSpaces[columnA][posA] = -1;
            }
            break;
          case 'v':
            for(int i = 0; i < n; i++) {
              for(int j = 0; j < n; j++) {
                if(blockSpaces[i][j] == a) {
                  columnA = i;
                }
                if(blockSpaces[i][j] == b) {
                  columnB = i;
                }
              }
            }
            if(columnA != columnB) {
              for(int i = 0; i < n; i++) {
                if(blockSpaces[columnB][i] == b) {
                  lastB = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnB][i] != -1)){
                    lastB = i;
                    i++; 
                  }
                }
              }
              for(int i = 0; i < n; i++){
                if(blockSpaces[columnA][i] == a) {
                  posA = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnA][i] != -1)){
                    blockSpaces[blockSpaces[columnA][i]][0] = blockSpaces[columnA][i];
                    blockSpaces[columnA][i] = -1;
                    i++; 
                  }                  
                }
              }
              blockSpaces[columnB][lastB+1] = a;
              blockSpaces[columnA][posA] = -1;
            }
            break;
          default:
            break;
        }
        break;
      case 'p':
        switch(secondInstruction[1]) {
          case 'n':
            for(int i = 0; i < n; i++) {
              for(int j = 0; j < n; j++) {
                if(blockSpaces[i][j] == a) {
                  columnA = i;
                }
                if(blockSpaces[i][j] == b) {
                  columnB = i;
                }
              }
            }
            if(columnA != columnB) {
              for(int i = 0; i < n; i++) {
                if(blockSpaces[columnB][i] == b) {
                  posB = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnB][i] != -1)){
                    blockSpaces[blockSpaces[columnB][i]][0] = blockSpaces[columnB][i];
                    blockSpaces[columnB][i] = -1;
                    i++; 
                  }
                }
              }
              vector<int> overA;
              for(int i = 0; i < n; i++){
                if(blockSpaces[columnA][i] == a) {
                  overA.push_back(a);
                  posA = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnA][i] != -1)){
                    overA.push_back(blockSpaces[columnA][i]);
                    i++; 
                  }                  
                }
              }
              for(int i = 0; i < overA.size(); i++) {
                blockSpaces[columnB][posB+1+i] = overA[i];
                blockSpaces[columnA][posA+i] = -1;
              }
            }
            break;
          case 'v':
            for(int i = 0; i < n; i++) {
              for(int j = 0; j < n; j++) {
                if(blockSpaces[i][j] == a) {
                  columnA = i;
                }
                if(blockSpaces[i][j] == b) {
                  columnB = i;
                }
              }
            }
            if(columnA != columnB) {
              for(int i = 0; i < n; i++) {
                if(blockSpaces[columnB][i] == b) {
                  lastB = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnB][i] != -1)){
                    lastB = i;
                    i++; 
                  }
                }
              }
              vector<int> overA;
              for(int i = 0; i < n; i++){
                if(blockSpaces[columnA][i] == a) {
                  overA.push_back(a);
                  posA = i;
                  i++;
                  while((i <= n-1) && (blockSpaces[columnA][i] != -1)){
                    overA.push_back(blockSpaces[columnA][i]);
                    i++; 
                  }                  
                }
              }
              for(int i = 0; i < overA.size(); i++) {
                blockSpaces[columnB][lastB+1+i] = overA[i];
                blockSpaces[columnA][posA+i] = -1;
              }
            }
            break;
          default:
            break;
        }
        break;
      case 'q':
        for(int i = 0; i < n; i++) {
          cout<<i<<":";
          for(int j = 0; j < n; j++) {
            if(blockSpaces[i][j] == -1) break;
            cout<<" "<<blockSpaces[i][j];
          }
          cout<<'\n';
        }
        return 0;
      default:
        break;
    }
  }
  return 0;
}
