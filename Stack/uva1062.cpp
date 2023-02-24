#include <bits/stdc++.h>

using namespace std;

int main() {
  string input;
  int testId = 1;
  while(getline(cin, input) && input != "end") {
    stack<char> oneCharacterStack;
    vector<stack<char>> stacks;
    for(int i = 0; i < input.length(); i++){
      bool foundValidStack = false;
      for(int j = 0; j < stacks.size(); j++){
        if(stacks[j].top() >= input.at(i)) {
          stacks[j].push(input.at(i));
          foundValidStack = true;
          break;
        }
      }
      if(!foundValidStack) {
        stack <char> newStack;
        newStack.push(input.at(i));
        stacks.push_back(newStack);
      }
    }
    cout<<"Case "<<testId++<<": "<<stacks.size()<<'\n';
  }
}