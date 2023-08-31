#include <bits/stdc++.h>

using namespace std;

int main(){
  map<int, string> is;
  is = {
    {1 , "one"},
    {2 , "two"},
    {3 , "three"},
    {4 , "four"},
    {5 , "five"},
    {6 , "six"},
    {7 , "seven"},
    {8 , "eight"},
    {9 , "nine"},
    {10, "ten"}
  };
  int n;
  cin>>n;
  while(n--){
    string input;
    cin>>input;
    for(auto it : is){
      if(it.second.length() == input.length()){
        int numDiff = 0;
        for(int i = 0; i < input.length(); i++){
          if(input.at(i) != it.second.at(i))
            numDiff++;
          if(numDiff > 1)
            break;
        }
        if(numDiff <= 1){
          cout<<it.first<<'\n';
          break;
        }
      }
    }
  }
}