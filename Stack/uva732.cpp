#include <bits/stdc++.h>

using namespace std;

vector<string> solution;

void stackThatGeneratesTargetWord (string originalWord, string targetWord, stack<char> result, int lastIndex, int startIndex, string stringResult, bool shouldAdd) {
  if(result.size() == 0)
    result.push('@');
  if(shouldAdd) {
    shouldAdd = false;
    result.push(originalWord.at(startIndex++));
    stringResult += "i";
    while(result.top() == targetWord.at(lastIndex)) {
      if(startIndex < targetWord.length()){
        stackThatGeneratesTargetWord(originalWord, targetWord, result, lastIndex, startIndex, stringResult, true);
      }
      result.pop();
      stringResult += "o";
      lastIndex++;
      if(lastIndex >= targetWord.length())
        break;
    }
  }
  while(lastIndex < targetWord.length() && startIndex < originalWord.length()) {
    while(result.top() != targetWord.at(lastIndex) ) {
      if(startIndex >= originalWord.length())
        break;
      result.push(originalWord.at(startIndex++));
      stringResult += "i";
      while(result.top() == targetWord.at(lastIndex)) {
        if(startIndex < targetWord.length()){
          stackThatGeneratesTargetWord(originalWord, targetWord, result, lastIndex, startIndex, stringResult, true);
        }
        result.pop();
        stringResult += "o";
        lastIndex++;
        if(lastIndex >= targetWord.length())
          break;
      }
      if (lastIndex >= targetWord.length())
        break;
    }
  }
  if(stringResult.length() == targetWord.length()*2)
    solution.push_back(stringResult);
}

int main(){
  cin.tie(NULL);
  string sourceWord, targetWord;
  string input;
  int i = 0;
  while(getline(cin, input)) {
    if(i == 0 && input.length() > 0){
      sourceWord = input;
    } else if(i == 1 && input.length() > 0) {
      targetWord = input;
    }
    if(input.length() > 0) {
      i++;
      i %= 2;
    }
    if (i == 0 && input.length() > 0) {
      string originalSourceWord = sourceWord;
      string originalTargetWord = targetWord;
      sort(sourceWord.begin(), sourceWord.end());
      sort(targetWord.begin(), targetWord.end());
      if(sourceWord != targetWord) {
        cout<<"[\n]\n";
      } else {
        solution.clear();
        cout<<"[\n";
        stackThatGeneratesTargetWord(originalSourceWord, originalTargetWord, stack<char>(), 0, 0, "", false);
        sort(solution.begin(), solution.end());
        for(int i = 0; i < solution.size(); i++) {
          for(int j = 0; j < solution[i].length(); j++){
            if(j == 0)
              cout<<solution[i].at(j);
            else
              cout<<" "<<solution[i].at(j);
          }
          cout<<'\n';
        }
        cout<<"]\n";
      }
    }
  }
  return 0;
}