#include <bits/stdc++.h>

using namespace std;

template<typename T>
double getAverage(std::vector<T> const& v) {
  if (v.empty()) {
    return 0;
  }
  return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

int main()
{
  int n;
  while(cin>>n){
    vector<int> values;
    for(int i = 0; i < n; i++){
      int input;
      cin>>input;
      values.push_back(input);
    }
    sort(values.begin(), values.end());
    int answer = 65000;
    int minSum = 65*1000*n;
    int numberOfValuesInArray = 0;
    int numberOfValuesOfA = 0;
    if (n % 2 == 1) {
      for(int i = values[n/2-1]-1; i <= values[n/2+1]+1; i++) {
        int sum = 0;
        for(int j = 0; j < values.size(); j++) {
          sum += abs(values[j]-i);
        }
        if(sum <= minSum) {
          if(minSum == sum) {
            numberOfValuesOfA++;
            answer = min(answer,i);
            int aux = upper_bound(values.begin(), values.end(), i)-lower_bound(values.begin(), values.end(), i);
            numberOfValuesInArray += aux;
          }
          else {
            minSum = sum;
            answer = i;
            numberOfValuesOfA = 1;
            numberOfValuesInArray = upper_bound(values.begin(), values.end(), i)-lower_bound(values.begin(), values.end(), i);
          }
        }
      }
    } else {
      for(int i = values[n/2-1]-1; i <= values[n/2]+1; i++) {
        int sum = 0;
        for(int j = 0; j < values.size(); j++) {
          sum += abs(values[j]-i);
        }
        if(sum <= minSum) {
          if(minSum == sum) {
            numberOfValuesOfA++;
            answer = min(answer,i);
            int aux = upper_bound(values.begin(), values.end(), i)-lower_bound(values.begin(), values.end(), i);
            numberOfValuesInArray += aux;
          }
          else {
            minSum = sum;
            answer = i;
            numberOfValuesOfA = 1;
            numberOfValuesInArray = upper_bound(values.begin(), values.end(), i)-lower_bound(values.begin(), values.end(), i);
          }
        }
      }
    }
    cout<<answer<<" "<<numberOfValuesInArray<<" "<<numberOfValuesOfA<<'\n';
  }
  return 0;
}
