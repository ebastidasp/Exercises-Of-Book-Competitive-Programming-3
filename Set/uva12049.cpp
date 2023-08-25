#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    int n, m;
    cin>>n>>m;
    multiset<int> a, b;
    while(n--){
      int input;
      cin>>input;
      a.insert(input);
    }
    while(m--){
      int input;
      cin>>input;
      b.insert(input);
    }
    int same = 0;
    int before = -1;
    for(auto it = a.begin(); it != a.end(); it++){
      if(before != *it){
        if(b.find(*it) != b.end()){
          same += min(a.count(*it), b.count(*it));
        }
      }
      before = *it;
    }
    cout<<a.size() + b.size() - 2*same<<'\n';
  }
}