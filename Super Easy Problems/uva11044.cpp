#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    double r, c;
    cin>>r>>c;
    int answer = ceil((r-2)/3.0)*ceil((c-2)/3.0);
    cout<<answer<<'\n';
  }
}