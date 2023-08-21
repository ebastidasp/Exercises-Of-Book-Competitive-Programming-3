#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  vector<int> numbersInInputString;
  while(cin>>n && n != EOF){
    numbersInInputString.push_back(n);
  }
  map<int,int> frequency;
  vector<int> orderIntegerAppears;
  for(int i = 0; i < numbersInInputString.size(); i++){
    if(!frequency[numbersInInputString[i]]){
      orderIntegerAppears.push_back(numbersInInputString[i]);
    }
    frequency[numbersInInputString[i]]++;
  }
  for(int i = 0; i < orderIntegerAppears.size(); i++){
    cout<<orderIntegerAppears[i]<<" "<<frequency[orderIntegerAppears[i]]<<'\n';
  }
  return 0;
}
