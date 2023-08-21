#include <bits/stdc++.h>

using namespace std;

int main(){
  map<string, int> words;
  string aux = "a";
  int id = 1;
  while(aux != "aaaaaa"){
    bool isOrdered = true;
    for(int i = 0; i < aux.length()-1; i++){
      if(aux.at(i) >= aux.at(i+1)){
        isOrdered = false;
        break;
      }
    }
    if(isOrdered)
      words[aux] = id++;
    vector <int> indexes;
    for(int i = 0; i < aux.length(); i++){
      indexes.push_back(aux.at(i)-'a'+1);
    }
    for(int i = indexes.size()-1; i >= 0; i--){
      if(indexes[i] < 26){
        indexes[i]++;
        break;
      } else if (i > 0){
        indexes[i] = 1;
      } else {
        indexes[i] = 1;
        indexes.insert(indexes.begin(), 1, 1);
      }
    }
    aux = "";
    for(int i = 0; i < indexes.size(); i++){
      aux += char(indexes[i]+96);
    }
  }
  string input;
  while(getline(cin, input)){
    cout<<words[input]<<'\n';
  }
  return 0;
}
