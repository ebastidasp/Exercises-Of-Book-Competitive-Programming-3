#include <bits/stdc++.h>

using namespace std;

int main()
{
  int cards;
  cin.tie(NULL);
  while(cin>>cards){
    if(cards == 0) return 0;
    map <string, string> cardNames;
    string card, pos;
    vector <string> orderedDeck (cards, "");
    int sumOfChars = 0;
    int originalNumberOfCards = cards;
    int currPos = -1;
    while(cards--){
      cin>>card;
      cin>>pos;
      for(int i = 1; i <= pos.length(); i++){
        while(orderedDeck[(currPos + i) % originalNumberOfCards] != "") currPos++; 
        if(i == pos.length()){
          orderedDeck[(currPos + i) % originalNumberOfCards] = card;
          currPos = (currPos + i) % originalNumberOfCards;
        } 
      }
    }
    for(int i = 0; i < orderedDeck.size()-1; i++){
      cout<<orderedDeck[i]<<" ";
    }
    cout<<orderedDeck[originalNumberOfCards-1]<<'\n';
  }
  return 0;
}
