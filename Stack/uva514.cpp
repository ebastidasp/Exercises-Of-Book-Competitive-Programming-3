#include <bits/stdc++.h>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

int main(){
  int N;
  cin.tie(NULL);
  while(cin>>N && N) {
    string input;
    cin.get();
    while(getline(cin, input) && input != "0") {
      vector<string> numbers = split(input, ' ');
      vector<int> start;
      for(int i = 0; i < N; i++) {
        start.push_back(i+1);
      }
      stack <int> result;
      int lastIndex = 0;
      int pushIndex = 0;
      result.push(0);
      while(lastIndex >= 0 && lastIndex < N) {
        while(result.top() != stoi(numbers[lastIndex])){
          result.push(start[pushIndex++]);
          if(pushIndex >= N && result.top() != stoi(numbers[lastIndex])) {
            lastIndex = -1;
            break;
          }
        }
        if(lastIndex >= 0 && lastIndex < N) {
          if (result.top() == stoi(numbers[lastIndex])) {
            result.pop();
            lastIndex++;
          }
        }
      }
      if (lastIndex != -1)
        cout<<"Yes\n";
      else
        cout<<"No\n";
    }
    cout<<'\n';
  }
  return 0;
}