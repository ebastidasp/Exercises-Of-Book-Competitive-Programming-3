#include <bits/stdc++.h>

using namespace std;

class oneTimeTask {
  public:
    int start, end;
    oneTimeTask (int _start, int _end) {
      start = _start;
      end = _end;
    }
};

class repeatingTasks {
  public:
    int start, end, interval;
    repeatingTasks (int _start, int _end, int _interval) {
      start = _start;
      end = _end;
      interval = _interval;
    }
};

int main(){
  int n, m;
  while(cin>>n>>m) {
    if (n == 0 && m == 0)
      return 0;
    vector <oneTimeTask> otTasks;
    vector <repeatingTasks> rTasks;
    while(n--){
      int start, end;
      cin>>start>>end;
      oneTimeTask newTimeTask(start, end);
      otTasks.push_back(newTimeTask);
    }
    while(m--){
      int start, end, interval;
      cin>>start>>end>>interval;
      repeatingTasks newRepeatingTask(start, end, interval);
      rTasks.push_back(newRepeatingTask);
    }
    bitset <1000001> isMinuteFree (0);
    bool isThereConflict = false;
    for (int i = 0; i < otTasks.size(); i++) {
      for(int j = otTasks[i].start; j < otTasks[i].end; j++) {
        if(isMinuteFree[j] == 1) {
          isThereConflict = true;
          break;
        }
        isMinuteFree[j] = 1;
      }
      if(isThereConflict)
        break;
    }
    if (!isThereConflict) {
      for(int i = 0; i < rTasks.size(); i++){
        int startPoint = rTasks[i].start;
        for(int j = startPoint; j <= 1000000; j += rTasks[i].interval) {
          for(int k = j; (k < j + rTasks[i].end - startPoint) && k <= 1000000; k++) {
            if(isMinuteFree[k] == 1) {
              isThereConflict = true;
              break;
            }
            isMinuteFree[k] = 1;
          }
          if(isThereConflict)
            break;
        }
        if(isThereConflict)
          break;
      }
    }
    if (isThereConflict)
      cout<<"CONFLICT\n";
    else
      cout<<"NO CONFLICT\n";
  }
  return 0;
}