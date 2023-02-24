#include <bits/stdc++.h>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

int main(){
  string input;
  int line = 0;
  vector<string> cards;
  while(getline(cin, input) && input != "#") {
    if (line == 0)
      cards.clear();
    vector <string> aux = split(input, ' ');
    cards.insert(cards.end(), aux.begin(), aux.end());
    line++;
    line = line % 2;
    if(line == 0) {
      vector<stack<string>> cardPiles;
      for(int i = 0; i < cards.size(); i++){
        stack<string> auxStack;
        auxStack.push(cards[i]);
        cardPiles.push_back(auxStack);
      }
      bool isThereAPossibleMove = true;
      while(isThereAPossibleMove) {
        isThereAPossibleMove = false;
        for(int i = 1; i < cardPiles.size(); i++) {
          if(cardPiles[i].size() > 0){
            int numberOfPilesBefore = 0;
            int oneBefore = -1;
            for(int j = i-1; j >= 0; j--){
              if(cardPiles[j].size() > 0) {
                numberOfPilesBefore++;
                if(numberOfPilesBefore == 1) {
                  if(cardPiles[j].top().at(0) == cardPiles[i].top().at(0) || cardPiles[j].top().at(1) == cardPiles[i].top().at(1)) {
                    oneBefore = j;
                  }
                }
                else if (numberOfPilesBefore == 3) {
                  if(cardPiles[j].top().at(0) == cardPiles[i].top().at(0) || cardPiles[j].top().at(1) == cardPiles[i].top().at(1)) {
                    cardPiles[j].push(cardPiles[i].top());
                    cardPiles[i].pop();
                    oneBefore = -1;
                    isThereAPossibleMove = true;
                  }
                }
                if (numberOfPilesBefore >= 3) {
                  break;
                }
              }
            }
            if(oneBefore != -1) {
              cardPiles[oneBefore].push(cardPiles[i].top());
              cardPiles[i].pop();
              isThereAPossibleMove = true;
            }
            if(isThereAPossibleMove)
              break;
          }
        }
      }
      int counter = 0;
      for(int i = 0; i < cardPiles.size(); i++) {
        if(cardPiles[i].size() > 0) {
          counter++;
        }
      }
      if (counter > 1)
        cout<<counter<<" piles remaining:";
      else
        cout<<counter<<" pile remaining:";
      for(int i = 0; i < cardPiles.size(); i++) {
        if(cardPiles[i].size() > 0) {
          cout<<" "<<cardPiles[i].size();
        }
      }
      cout<<'\n';
    }
  }
  return 0;
}