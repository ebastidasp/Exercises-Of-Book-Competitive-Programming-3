#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  while (cin>>N) {
    int maxLength = 0;
    cin.ignore();
    vector <string> filenames;
    while (N--) {
      string input;
      cin>>input;
      filenames.push_back(input);
      int inputLength = input.length();
      maxLength = max(maxLength, inputLength);
    }
    int numCols = floor((1.0*62)/(1.0*maxLength+2.0));
    int numRows = ceil(filenames.size()*1.0/(1.0*numCols));
    sort(filenames.begin(), filenames.end());
    for(int i = 0; i < 60; i++){
      cout<<"-";
    }
    cout<<'\n';
    for(int i = 0; i < numRows; i++) {
      for(int j = 0; j < numCols; j++) {
        if ((numRows*j + i) < filenames.size()) {
          cout<<filenames[numRows*j+i];
          for(int k = 0; k < maxLength-filenames[numRows*j+i].length(); k++) {
            cout<<" ";
          }
          if ((j < numCols - 1) && (numRows*(j+1)+i < filenames.size())) {
            cout<<"  ";
          }
        }
      }
      cout<<'\n';
    }
  }
}
