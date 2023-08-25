#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;
  while (T--)
  {
    int B, SG, SB;
    cin>>B>>SG>>SB;
    multiset<int, greater<int>> sgL, sbL;
    int input;
    while(SG--){
      cin>>input;
      sgL.insert(input);
    }
    while(SB--){
      cin>>input;
      sbL.insert(input);
    }
    vector<int> sgLToInsert, sbLToInsert;
    while(sgL.size() > 0 && sbL.size() > 0){
      multiset<int, greater<int>>::iterator it1 = sgL.begin();
      multiset<int, greater<int>>::iterator it2 = sbL.begin();
      for(int i = 0; (i < B) && (sgL.size() > 0 && sbL.size() > 0); i++){
        if (*it1 > *it2) {
          sbL.erase( sbL.find ( *it2 ) );
          sgLToInsert.push_back( *it1 - *it2 );
          sgL.erase( sgL.find( *it1 ) );
        } else if (*it1 < *it2) {
          sgL.erase( sgL.find ( *it1 ) );
          sbLToInsert.push_back( *it2 - *it1 );
          sbL.erase( sbL.find( *it2 ) );
        } else {
          sgL.erase( sgL.find ( *it1 ) );
          sbL.erase( sbL.find ( *it2 ) );
        }
        it1 = sgL.begin();
        it2 = sbL.begin();
      }
      if(sgLToInsert.size() > 0){
        for(auto it : sgLToInsert){
          sgL.insert( it );
        }
        sgLToInsert.clear();
      }
      if(sbLToInsert.size() > 0){
        for(auto it : sbLToInsert){
          sbL.insert( it );
        }
        sbLToInsert.clear();
      }
    }
    if(sgL.size() > 0){
      cout<<"green wins\n";
      for(auto it : sgL){
        cout<<it<<'\n';
      }
    }
    else if(sbL.size() > 0){
      cout<<"blue wins\n";
      for(auto it : sbL){
        cout<<it<<'\n';
      }
    }
    else {
      cout<<"green and blue died\n";
    }
    if(T) cout<<'\n';
  }
}