#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tests;
  cin.tie(NULL);
  cin>>tests;
  while(tests--){
    map <char, int> valueOfChars;
    int numberOfChars;
    cin>>numberOfChars;
    while(numberOfChars--){
      char inputChar;
      int inputValue;
      cin>>inputChar;
      cin>>inputValue;
      valueOfChars[inputChar] = inputValue;
    }
    int lines;
    cin>>lines;
    vector <string> inputLines;
    cin.ignore();
    while(lines--){
      string aux;
      getline(cin, aux);
      inputLines.push_back(aux);
    }
    int value = 0;
    for(int i = 0; i < inputLines.size(); i++){
      for(int j = 0; j < inputLines[i].length(); j++){
        if(valueOfChars[inputLines[i].at(j)]) {
          value += valueOfChars[inputLines[i].at(j)];
        }
      }
    }
    cout <<  fixed;
    cout <<  setprecision(2);

    cout<<1.0*value/100<<'$'<<'\n';
  }
  return 0;
}
