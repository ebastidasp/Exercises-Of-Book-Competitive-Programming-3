#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, H, W;
  while (cin>>W) {
    cin>>H;
    cin>>N;
    if (!W && !H && ! N) return 0;
    vector <vector<bool>> spots (H, vector<bool>(W, false));
    while(N--) {
      int X[2], Y[2];
      cin>>X[0];
      cin>>Y[0];
      cin>>X[1];
      cin>>Y[1];
      if (X[1] < X[0]) {
        int aux = X[1];
        X[1] = X[0];
        X[0] = aux;
      }
      if (Y[1] < Y[0]) {
        int aux = Y[1];
        Y[1] = Y[0];
        Y[0] = aux;
      }
      for(int i = X[0]-1; i <= X[1]-1; i++) {
        for(int j = Y[0]-1; j <= Y[1]-1; j++) {
          spots[j][i] = true;
        }
      }
    }
    int numberOfEmptySpots = 0;
    for(int i = 0; i < W; i++) {
      for(int j = 0; j < H; j++) {
        if(!spots[j][i]) numberOfEmptySpots++;
      }
    }
    switch (numberOfEmptySpots) {
      case 0:
        cout<<"There is no empty spots."<<'\n';
        break;
      case 1:
        cout<<"There is one empty spot."<<'\n';
        break;
      default:
        cout<<"There are "<<numberOfEmptySpots<<" empty spots."<<'\n';
        break;
    }
  }
  return 0;
}
