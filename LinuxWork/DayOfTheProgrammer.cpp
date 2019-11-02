#include <bits/stdc++.h>
#include <string>

using namespace std;

bool LeapYear( int year) {
  if (year % 400 == 0) return true;
  if ((year % 4 == 0)&& (year % 100 >0)) return true;
  return false;

}

string solve(int year){
    // Complete this function
  
  string yearString; 
  ostringstream convert;
  convert << year;
  yearString = convert.str();
  string leapYear = "12.09."+yearString;
  string commonYear = "13.09." + yearString ;
  string year1918 = "26.09." + yearString;
  if  (year == 1918) return year1918;
  if (LeapYear(year)) return leapYear;
  return commonYear;

}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
