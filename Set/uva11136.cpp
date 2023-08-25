#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n && n != 0){
    multiset<long long, greater<long long>> bills;
    long long sum = 0;
    while(n--){
      long long input;
      cin >> input;
      while(input--){
        long long bill;
        cin >> bill;
        bills.insert(bill);
      }
      sum += *( bills.begin() ) - *prev( bills.end() );
      bills.erase(bills.find(*( bills.begin() )));
      bills.erase(bills.find(*prev( bills.end() )));
    }
    cout<<sum<<'\n';
  }
  return 0;
}