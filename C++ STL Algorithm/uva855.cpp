#include <bits/stdc++.h>

using namespace std;

int main()
{
  int numTestCases;
  cin>>numTestCases;
  while(numTestCases--) {
    int street, avenue, friends;
    cin>>street>>avenue>>friends;
    vector <int> streetOfFriend, avenueOfFriend;
    while(friends--){
      int input;
      cin>>input;
      streetOfFriend.push_back(input);
      cin>>input;
      avenueOfFriend.push_back(input);
    }
    sort(streetOfFriend.begin(), streetOfFriend.end());
    sort(avenueOfFriend.begin(), avenueOfFriend.end());
    cout<<"(Street: "<<streetOfFriend[(streetOfFriend.size()-1)/2]<<", Avenue: "<<avenueOfFriend[(streetOfFriend.size()-1)/2]<<")\n";
  }
  return 0;
}
