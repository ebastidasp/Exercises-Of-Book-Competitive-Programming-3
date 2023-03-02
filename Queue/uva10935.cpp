#include <bits/stdc++.h>

using namespace std;

int main(){
  int numberOfCards;
  while(cin>>numberOfCards && numberOfCards){
    queue<int> cardDeck, cardsThrownAway;
    for(int i = 1; i <= numberOfCards; i++){
      cardDeck.push(i);
    }
    while(cardDeck.size() > 1){
      cardsThrownAway.push(cardDeck.front());
      cardDeck.pop();
      cardDeck.push(cardDeck.front());
      cardDeck.pop();
    }
    cout<<"Discarded cards:";
    while(!cardsThrownAway.empty()){
      cout<<" "<<cardsThrownAway.front();
      cardsThrownAway.pop();
      if(!cardsThrownAway.empty())
        cout<<",";
    }
    cout<<'\n';
    cout<<"Remaining card:";
    while(!cardDeck.empty()){
      cout<<" "<<cardDeck.front();
      cardDeck.pop();
    }
    cout<<'\n';
  }
  return 0;
}