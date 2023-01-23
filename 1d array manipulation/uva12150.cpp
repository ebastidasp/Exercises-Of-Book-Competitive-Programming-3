#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
  int N;
  ofstream o;
  o.open("output.txt");
  while(cin>>N){
    if(N == 0) return 0;
    vector<int> cars;
    vector<int> relPos;
    for(int i = 0; i < N; i++){
      int input;
      cin>>input;
      cars.push_back(input);
      cin>>input;
      relPos.push_back(input);
    }
    vector<int> carsInPositionOriginally(N, 0);
    for(int i = 0; i < N; i++){
      if ((i+relPos[i]) >= 0 && (i+relPos[i]) < N);
        carsInPositionOriginally[i+relPos[i]]++;
    }
    int pos = true;
    for(int i = 0; i < N; i++){
      if(carsInPositionOriginally[i] != 1){
        cout<<-1<<'\n';
        o<<-1<<'\n';
        pos = false;
        break;
      }
    }
    if (pos) {
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          if(j + relPos[j] == i){
            if(i == N - 1) cout<<cars[j];
            else cout<<cars[j]<<" ";
            if(i == N - 1) o<<cars[j];
            else o<<cars[j]<<" ";
            break;
          }
        }
      }
      cout<<'\n';
      o<<'\n';
    }
  }
  return 0;
}
