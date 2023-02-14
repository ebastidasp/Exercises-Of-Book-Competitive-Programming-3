#include <bits/stdc++.h>

using namespace std;

int main(){
  int tests;
  int testId = 1;
  cin>>tests;
  while(tests--){
    int Cookies, Remainder;
    cin>>Cookies>>Remainder;
    if (Cookies == Remainder) {
      cout<<"Case #"<<testId<<": 0\n";
    } else {
      vector <int> CookiesByGuest;
      for(int i = 1; i * i <= Cookies-Remainder; i++){
        if( ( (Cookies-Remainder) % i) == 0){
          if(count(CookiesByGuest.begin(), CookiesByGuest.end(), i) == 0)
            CookiesByGuest.push_back(i);
          if(count(CookiesByGuest.begin(), CookiesByGuest.end(), (Cookies-Remainder)/i) == 0)
            CookiesByGuest.push_back((Cookies-Remainder)/i);          
        }
      }
      sort(CookiesByGuest.begin(), CookiesByGuest.end());
      cout<<"Case #"<<testId<<":";
      for(int i = 0; i < CookiesByGuest.size(); i++){
        if(CookiesByGuest[i] > Remainder)
          cout<<" "<<CookiesByGuest[i];
      }
      cout<<'\n';
    }
    testId++;
  }

  return 0;
}