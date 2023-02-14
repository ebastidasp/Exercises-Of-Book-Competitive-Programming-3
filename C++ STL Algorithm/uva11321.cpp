#include <bits/stdc++.h>

using namespace std;

int m;

bool sortNumbers (const int & a, const int & b) {
  if (a % m == b % m) {
    if (((a%2)+2)%2 != ((b%2)+2)%2)
      return ((a%2)+2)%2 > ((b%2)+2)%2;
    if (a%2 == 0 && b%2 == 0)
      return a < b;
    return a > b;
  }
  return a%m < b%m;
}

int main(){
  int n;
  while(cin>>n>>m){
    if(n == 0 && m == 0){
      cout<<"0 0\n";
      return 0;
    }
    int orn = n;
    vector<int> numbers;
    while(n--){
      int input;
      cin>>input;
      numbers.push_back(input);
    }
    sort(numbers.begin(), numbers.end(), sortNumbers);
    cout<<orn<<" "<<m<<'\n';
    for(int i = 0; i < numbers.size(); i++) {
      cout<<numbers[i]<<'\n';
    }
  }

  return 0;
}