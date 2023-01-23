#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin.tie(NULL);
  while(cin>>N){
    vector<int> numbers;
    int inputNumber;
    int orN = N;
    vector <int> differences;
    vector <bool> hasDiff (N, true);
    while(N--){
      cin>>inputNumber;
      numbers.push_back(inputNumber);
    }
    for(int i = 0; i < numbers.size() - 1; i++){
      hasDiff[abs(numbers[i] - numbers[i+1])] = false;
    }
    bool isJollyJumper = true;
    for(int i = 1; i < orN; i++){
      if(hasDiff[i]) {
        isJollyJumper = false;
        break;
      }
    }
    if(isJollyJumper){
      cout<<"Jolly"<<'\n';
    } else {
      cout<<"Not jolly"<<'\n';
    }
  }  
  return 0;
}
