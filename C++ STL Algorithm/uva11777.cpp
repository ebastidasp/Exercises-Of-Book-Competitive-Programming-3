#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCases;
  cin>>testCases;
  int testId = 1;
  while(testCases--) {
    int Term1, Term2, Final, Attendance, Ctest1, Ctest2, Ctest3;
    cin>>Term1>>Term2>>Final>>Attendance>>Ctest1>>Ctest2>>Ctest3;
    double avg;
    if (Ctest1 <= Ctest2 && Ctest1 <= Ctest3) {
      avg = (Ctest2 + Ctest3) / 2.0;
    } else if (Ctest2 <= Ctest1 && Ctest2 <= Ctest3) {
      avg = (Ctest1 + Ctest3) / 2.0;
    } else {
      avg = (Ctest1 + Ctest2) / 2.0;
    }
    double finalGrade = Term1+Term2+Final+Attendance+avg;
    if (finalGrade >= 90) {
      cout<<"Case "<<testId<<": A\n";
    } else if (finalGrade >= 80) {
      cout<<"Case "<<testId<<": B\n";
    } else if (finalGrade >= 70) {
      cout<<"Case "<<testId<<": C\n";
    } else if (finalGrade >= 60) {
      cout<<"Case "<<testId<<": D\n";
    } else {
      cout<<"Case "<<testId<<": F\n";
    }
    testId++;
  }
  return 0;
}