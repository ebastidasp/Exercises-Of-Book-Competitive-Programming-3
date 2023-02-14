#include <bits/stdc++.h>

using namespace std;

string to_lower(string s) {
	for (int i = 0; i < s.length(); i++)
    if (s[i] >= 'A'&&s[i] <= 'Z')
      s[i] += 'a' - 'A';
	return s;
}

string to_upper(string s) {
	for (int i = 0; i < s.length(); i++)
    if (s[i] >= 'a'&&s[i] <= 'z')
      s[i] -= 'a' - 'A';
	return s;
}


bool cmp(pair<string, bool>& a,
  pair<string, bool>& b)
{
  return a.first < b.first;
}

int main()
{
  string s;
  map <string, bool> wordsToIgnore;
  vector <string> titles;
  map <string, bool> mapWordsInTitles;
  while (getline(cin, s) && s != "::") {
    wordsToIgnore[to_lower(s)] = true;
  }
  while (getline(cin, s) && s != "::") {
    titles.push_back(to_lower(s));
    stringstream ss(titles[titles.size()-1]);
    string Buf;
    while (ss >> Buf) {
      if (!wordsToIgnore[Buf])
        mapWordsInTitles[Buf] = true;
    }
  }
  vector<pair<string, bool> > wordsInTitles;
  for (auto& it : mapWordsInTitles) {
    wordsInTitles.push_back(it);
  }
  sort(wordsInTitles.begin(), wordsInTitles.end(), cmp);
  for(int i = 0; i < wordsInTitles.size(); i++) {
    for(int j = 0; j < titles.size(); j++) {
      vector <string> wordsInSpecificTitle;
      stringstream ss2(titles[j]);
      string Buf2;
      while (ss2 >> Buf2) {
        wordsInSpecificTitle.push_back(Buf2);
      }
      map <string, int> firstIndexOfWord;
      for(int k = 0; k < wordsInSpecificTitle.size(); k++) {
        if(wordsInSpecificTitle[k] == wordsInTitles[i].first) {
          for(int l = firstIndexOfWord[wordsInSpecificTitle[k]]; l <= titles[j].length()-wordsInSpecificTitle[k].length(); l++) {
            if (titles[j].substr(l, wordsInSpecificTitle[k].length()) == wordsInSpecificTitle[k]) {
              if (l + wordsInSpecificTitle[k].length() < titles[j].length()) {
                if (titles[j].at(l+wordsInSpecificTitle[k].length()) == ' ' && l == 0) {
                  cout<<to_upper(titles[j].substr(l, wordsInSpecificTitle[k].length())) + titles[j].substr(wordsInSpecificTitle[k].length(), titles[j].length()-wordsInSpecificTitle[k].length());
                  firstIndexOfWord[wordsInSpecificTitle[k]] = l + wordsInSpecificTitle[k].length();
                  break;
                } else if (titles[j].at(l+wordsInSpecificTitle[k].length()) == ' ' && titles[j].at(l-1) == ' ') {
                  cout<<titles[j].substr(0, l) + to_upper(titles[j].substr(l, wordsInSpecificTitle[k].length())) + titles[j].substr(l+wordsInSpecificTitle[k].length(), titles[j].length()-l-wordsInSpecificTitle[k].length());
                  firstIndexOfWord[wordsInSpecificTitle[k]] = l + wordsInSpecificTitle[k].length();
                  break;
                }
              } else if (l + wordsInSpecificTitle[k].length() == titles[j].length()) {
                if (l == 0) { 
                  cout<<to_upper(titles[j].substr(l, wordsInSpecificTitle[k].length()));
                  firstIndexOfWord[wordsInSpecificTitle[k]] = l + wordsInSpecificTitle[k].length();
                  break;
                } else if (titles[j].at(l-1) == ' ') {
                  cout<<titles[j].substr(0, l) + to_upper(titles[j].substr(l, wordsInSpecificTitle[k].length()));
                  firstIndexOfWord[wordsInSpecificTitle[k]] = l + wordsInSpecificTitle[k].length();
                  break;
                }           
              }
            }
          }
          cout<<'\n';
        }
      }
    }
  }

  return 0;
}
