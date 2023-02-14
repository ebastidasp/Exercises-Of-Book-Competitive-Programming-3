#include <bits/stdc++.h>

using namespace std;

int main()
{
  string input;
  while (getline(cin, input) && input != "#") {
    if (next_permutation(input.begin(), input.end())) {
      cout<<input<<'\n';
    } else {
      cout<<"No Successor\n";
    }
  }
  return 0;
}
