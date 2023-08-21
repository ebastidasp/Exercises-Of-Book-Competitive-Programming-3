#include <bits/stdc++.h>

using namespace std;

double value10(double d){
  return log10(d);
}

int main(){
  int numberOfWords = 0;
  double entropy, relEntropy;
  string inputLine;
  map<string, int> frequency;
  while(getline(cin, inputLine) && inputLine != "****END_OF_INPUT****"){
    string currWord = "";
    if(inputLine == "****END_OF_TEXT****"){
      double sum = 0.0;
      map<string, int>::iterator it;
      for (it = frequency.begin(); it != frequency.end(); it++){
        sum += it->second*(value10(numberOfWords)-value10(it->second));
      }
      frequency.clear();
      entropy = sum/numberOfWords;
      double eMax = value10(numberOfWords);
      cout<<fixed<<setprecision(1)<<numberOfWords<<" "<<entropy<<" "<<fixed<<setprecision(0)<<100*entropy/eMax<<'\n';
      numberOfWords = 0;
      entropy = relEntropy = 0.0;
    }
    else {
      inputLine += " ";
      for(int i = 0; i < inputLine.length(); i++){
        if(inputLine.at(i) != ',' && inputLine.at(i) != '.'  && inputLine.at(i) != ':' && inputLine.at(i) != ';' && inputLine.at(i) != '!' && inputLine.at(i) != '?' && inputLine.at(i) != '"' && inputLine.at(i) != '(' && inputLine.at(i) != ')' && inputLine.at(i) != ' '){
          if((inputLine.at(i) >= 65 && inputLine.at(i) <= 90) || (inputLine.at(i) >= 97 && inputLine.at(i) <= 122))
            currWord += tolower(inputLine.at(i));
          else
            currWord += inputLine.at(i);
        } else if(currWord != ""){
          frequency[currWord]++;
          numberOfWords++;
          currWord = "";
        }
      }
    }
  }
  return 0;
}
