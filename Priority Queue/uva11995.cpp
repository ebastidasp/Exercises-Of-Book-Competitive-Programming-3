#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
  ofstream o;
  o.open("o2.txt");
  int n;
  while(cin>>n){
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;
    bool canBeQueue = true, canBeStack = true, canBePQ = true;
    int numPosDataStructures = 3;
    while(n--){
      int operation, number;
      cin>>operation>>number;
      if(operation == 1){
        q.push(number);
        s.push(number);
        pq.push(number);
      } else {
        if(q.size()){
          if(q.front() != number && canBeQueue){
            canBeQueue = false;
            numPosDataStructures--;
          } else {
            q.pop();
          }
        } else {
          if(numPosDataStructures) numPosDataStructures--;
          canBeQueue = false;
        }
        if(s.size()){
          if(s.top() != number && canBeStack){
            canBeStack = false;
            numPosDataStructures--;
          } else {
            s.pop();
          }
        } else {
          if(numPosDataStructures) numPosDataStructures--;
          canBeStack = false;
        }
        if(pq.size()){
          if(pq.top() != number && canBePQ){
            canBePQ = false;
            numPosDataStructures--;
          } else {
            pq.pop();
          }
        } else {
          if(numPosDataStructures) numPosDataStructures--;
          canBePQ = false;
        }
      }
    }
    if(numPosDataStructures == 0){
      o<<"impossible\n";
    } else if(numPosDataStructures > 1){
      o<<"not sure\n";
    } else {
      if(canBeQueue && !canBeStack && !canBePQ){
        o<<"queue\n";
      } else if(!canBeQueue && canBeStack && !canBePQ){
        o<<"stack\n";
      } else if(!canBeQueue && !canBeStack && canBePQ){
        o<<"priority queue\n";
      }
    }
  }
}