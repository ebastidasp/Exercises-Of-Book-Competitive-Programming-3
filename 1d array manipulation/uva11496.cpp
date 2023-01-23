#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin.tie(NULL);
  while(cin>>N){
    if(N == 0) return 0;
    vector<int> H;
    while(N--){
      int input;
      cin>>input;
      H.push_back(input);
    }
    int peaks = 0;
    for(int i = 0; i < H.size(); i++){
      if(((H[i] > H[(i+1) % H.size()]) && (H[i] > H[(i-1+H.size()) % H.size()])) || ((H[i] < H[(i+1) % H.size()]) && (H[i] < H[(i-1+H.size()) % H.size()])))
        peaks++;
    }
    cout<<peaks<<'\n';
  }
  return 0;
}
