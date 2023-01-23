#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin.tie(NULL);
  int id = 1;
  while(cin>>N){
    if(N < 0) return 0;
    vector<int> problemsCreated, problemsNeeded;
    for(int i = 0; i < 12; i++){
      int input;
      cin>>input;
      problemsCreated.push_back(input);
    }
    for(int i = 0; i < 12; i++){
      int input;
      cin>>input;
      problemsNeeded.push_back(input);
    }
    int sum = N;
    cout<<"Case "<<id<<":"<<'\n';
    for(int i = 0; i < 12; i++) {
      if(sum >= problemsNeeded[i]) {
        cout<<"No problem! :D"<<'\n';
        sum += problemsCreated[i] - problemsNeeded[i];
      }
      else {
        cout<<"No problem. :("<<'\n';
        sum += problemsCreated[i];
      }
    }
    id++;
  }
  return 0;
}
