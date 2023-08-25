#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while(cin >> n >> m && (n || m)){
    set<int> a, b;
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
    int sum = 0;
    for(auto it = a.begin(); it != a.end(); it++){
      if(b.find(*it) != b.end()){
        sum++;
      }
    }
    cout<<sum<<'\n';
  }
}