#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
  ofstream o;
  o.open("output.txt");
  int population, instruction;
  int testId = 1;
  cin.tie(NULL);
  while(cin>>population>>instruction){
    if(!population && ! instruction)
      break;
    o<<"Case "<<testId++<<":\n";
    cin.get();
    deque<int> people;
    deque<int>::iterator it;
    for(int i = 0; i < min(population, 1000); i++){
      people.push_back(i+1);
    }
    while(instruction--){
      string input;
      getline(cin, input);
      char instruction;
      switch(input.at(0)){
        case 'N':
          o<<people.front()<<'\n';
          people.push_back(people.front());
          people.pop_front();
          break;
        case 'E':
          people.erase(remove(people.begin(),people.end(), stoi(input.substr(2, input.length()-2))),people.end());
          people.push_front(stoi(input.substr(2, input.length()-2)));
          break;
        default:
          break;
      }
    }
  }
  return 0;
}