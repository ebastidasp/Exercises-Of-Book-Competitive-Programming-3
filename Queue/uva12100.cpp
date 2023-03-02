#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv){
  int tests;
  cin.tie(NULL);
  cin>>tests;
  while(tests--){
    int size, position;
    cin>>size>>position;
    queue<int> printQueue;
    vector<int> vectorQueue;
    for(int i = 0; i < size; i++){
      int input;
      cin>>input;
      printQueue.push(input);
      vectorQueue.push_back(input);
    }
    sort(vectorQueue.begin(), vectorQueue.end(), greater<int>());
    int currPosition = 0;
    int time = 0;
    while(position >= 0){
      if(printQueue.front() != vectorQueue[0]){
        printQueue.push(printQueue.front());
        printQueue.pop();
        if(position == 0)
          position = printQueue.size() - 1;
        else
          position--;
      } else {
        time++;
        position--;
        vectorQueue.erase(vectorQueue.begin());
        printQueue.pop();
      }
    }
    cout<<time<<'\n';
  }
  return 0;
}