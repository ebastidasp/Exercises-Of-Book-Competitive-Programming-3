#include <bits/stdc++.h>

using namespace std;

int main()
{
  string input;
  while (cin>>input) {
    vector<string> possiblePasswords;
    int maxMinDistanceBetweenConsecutiveLetters = 0;
    int index = 0;
    possiblePasswords.push_back(input);
    string auxPrev = possiblePasswords[0], auxNext = possiblePasswords[0];
    for(int i = 1; i <= 10; i++) {
      prev_permutation(auxPrev.begin(), auxPrev.end());
      next_permutation(auxNext.begin(), auxNext.end());
      possiblePasswords.push_back(auxPrev);
      possiblePasswords.push_back(auxNext);
    }
    sort(possiblePasswords.begin(), possiblePasswords.end(), greater<string>());
    for(int i = 0; i < possiblePasswords.size(); i++) {
      int localMin = 28;
      for(int j = 1; j < possiblePasswords[i].length(); j++){
        localMin = min(localMin, abs(possiblePasswords[i].at(j)-possiblePasswords[i].at(j-1)));
      }
      if (localMin >= maxMinDistanceBetweenConsecutiveLetters) {
        index = i;
      }
      maxMinDistanceBetweenConsecutiveLetters = max(maxMinDistanceBetweenConsecutiveLetters, localMin);
    }
    cout<<possiblePasswords[index]<<maxMinDistanceBetweenConsecutiveLetters<<'\n';
  }
  return 0;
}
