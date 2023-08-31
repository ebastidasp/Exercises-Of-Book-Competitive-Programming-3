#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin>>n && n){
    int N, M;
    cin>>N>>M;
    int x, y;
    while(n--){
      cin>>x>>y;
      if(x > N && y > M){
        cout<<"NE\n";
      } else if(x < N && y > M){
        cout<<"NO\n";
      } else if(x < N && y < M){
        cout<<"SO\n";
      } else if(x > N && y < M){
        cout<<"SE\n";
      } else {
        cout<<"divisa\n";
      }
    }
  }
}