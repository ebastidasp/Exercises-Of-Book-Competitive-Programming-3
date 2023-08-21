#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    int numberOfSnowflakes;
    cin>>numberOfSnowflakes;
    if(numberOfSnowflakes){
      vector<int> listOfSnowFlakes;
      map<int, int> lastSeen;
      int maxLength = 0;
      int currLength = 0;
      int prevIndex = 0;
      while(numberOfSnowflakes--){
        int snowflakeId;
        cin>>snowflakeId;
        listOfSnowFlakes.push_back(snowflakeId);
        if(lastSeen.find(snowflakeId) != lastSeen.end()){
          prevIndex = max(prevIndex, lastSeen[snowflakeId]);
          currLength = listOfSnowFlakes.size() - 1 - prevIndex;
        } else {
          currLength++;
        }
        maxLength = max(maxLength, currLength);
        lastSeen[snowflakeId] = listOfSnowFlakes.size() - 1;
      }
      cout<<maxLength<<'\n';
    } else {
      cout<<0<<'\n';
    }
  }
}