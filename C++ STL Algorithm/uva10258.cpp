#include <bits/stdc++.h>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

class Problem {
  public:
    int problem;
    int time;
    char result;
    Problem (int _problem, int _time, char _result) {
      problem = _problem;
      time = _time;
      result = _result;
    }
};

bool sortProblems(const Problem &a,
  const Problem &b)
{
  if (a.problem != b.problem) 
    return a.problem < b.problem;
  if (a.time != b.time)
    return a.time < b.time;
  return a.result < b.result;
}

class Contestant {
  public:
    int id;
    int numberOfProblemsSolved;
    int penaltyTime;
    vector <Problem> problemsSolved;
    bool hasSubmission;
    Contestant (int _id) {
      id = _id;
      numberOfProblemsSolved = 0;
      penaltyTime = 0;
      hasSubmission = false;
    }
};

bool sortContests(const Contestant &a,
  const Contestant &b)
{
  if (a.numberOfProblemsSolved != b.numberOfProblemsSolved) 
    return a.numberOfProblemsSolved > b.numberOfProblemsSolved;
  if (a.penaltyTime != b.penaltyTime)
    return a.penaltyTime < b.penaltyTime;
  if (a.hasSubmission != b.hasSubmission) {
    int aH = (int) a.hasSubmission, bH = (int) b.hasSubmission;
    return aH > bH;
  }
  return a.id < b.id;
}

int main()
{
  int n;
  cin>>n;
  cin.ignore();
  cin.tie(NULL);
  string emptyString;
  getline(cin, emptyString);
  while(n--) {
    string submission;
    vector <Contestant> contestants;
    for(int i = 0; i < 100; i++) {
      Contestant newContestant (i+1);
      contestants.push_back(newContestant);
    }
    while (getline(cin, submission) && submission.length() > 0){
      vector <string> inputSubmission = split(submission, ' ');
      contestants[stoi(inputSubmission[0])-1].hasSubmission = true;
      if(inputSubmission[3] == "C" || inputSubmission[3] == "I") {
        Problem problemSolved (stoi(inputSubmission[1]), stoi(inputSubmission[2]), inputSubmission[3].at(0));
        contestants[stoi(inputSubmission[0])-1].problemsSolved.push_back(problemSolved);
      }
    }
    for(int i = 0; i < contestants.size(); i++) {
      if(contestants[i].problemsSolved.size() > 0) {
        sort(contestants[i].problemsSolved.begin(), contestants[i].problemsSolved.end(), sortProblems);
        int currProblem = contestants[i].problemsSolved[0].problem;
        for(int j = 0; j < contestants[i].problemsSolved.size(); j++){
          if (contestants[i].problemsSolved[j].result == 'C' && currProblem == contestants[i].problemsSolved[j].problem) {
            bool changed = false;
            contestants[i].numberOfProblemsSolved++;
            contestants[i].penaltyTime += contestants[i].problemsSolved[j].time;
            for(int k = j+1; k < contestants[i].problemsSolved.size(); k++) {
              if(contestants[i].problemsSolved[j].problem != contestants[i].problemsSolved[k].problem){
                currProblem = contestants[i].problemsSolved[k].problem;
                changed = true;
                break;
              }
            }
            if (!changed) {
              currProblem = 101;
            }
          } else {
            if (currProblem == contestants[i].problemsSolved[j].problem) {
              for (int k = j+1; k < contestants[i].problemsSolved.size(); k++){
                if(contestants[i].problemsSolved[k].problem == contestants[i].problemsSolved[j].problem && contestants[i].problemsSolved[k].result == 'C'){
                  contestants[i].penaltyTime += 20;
                  break;
                } else if (contestants[i].problemsSolved[k].problem != currProblem) {
                  currProblem = contestants[i].problemsSolved[k].problem;
                  break;
                }
              }
            }
          }
        }
      }
    }
    sort(contestants.begin(), contestants.end(), sortContests);
    for(int i = 0; i < contestants.size(); i++) {
      if(!contestants[i].hasSubmission)
        break;
      cout<<contestants[i].id<<" "<<contestants[i].numberOfProblemsSolved<<" "<<contestants[i].penaltyTime<<'\n';
    }
    if(n) cout<<'\n';
  }
  return 0;
}
