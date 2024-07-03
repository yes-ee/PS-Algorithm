#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <sstream>
#include <cmath>
#define endl "\n"

using namespace std;

struct TIME {
  string s1;
  string s2;
  double l;
};
TIME tmp[1001];
double Convert(string s1, string s2);
int mon_list[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  double p;
  cin >> n;
  if(n == 0){
    cout << 0;
    return 0;
  }
  for(int i = 1; i < n+1; i++){
    cin >> tmp[i].s1 >> tmp[i].s2 >> tmp[i].l;
  }
  double tn =  Convert(tmp[n].s1,tmp[n].s2);
  double up = 0, down = 0;
  for(int i = 1; i < n+1; i++){
    double ti = Convert(tmp[i].s1,tmp[i].s2);
    p = max(pow(0.5,(tn-ti)/365), pow(0.9,n-i));
    up += p * tmp[i].l;
    down += p;
  }
  double X = round(up/down);
  cout << X;
}

double Convert(string s1, string s2){
  double year = (s1[2] - '0') * 10 + (s1[3] - '0');
  double month = (s1[5] - '0') * 10 + (s1[6] - '0');
  double day = (s1[8] - '0') * 10 + (s1[9] - '0');
  day += year * 365;
  if (int(year) > 20) day++;
  for(int i = 1; i <= month-1; i++){
    if(i == 2 && int(year) == 20) day++;
    day += mon_list[i];
  }
  double hour = (s2[0] - '0') * 10 + (s2[1] - '0');
  double min = (s2[3] - '0') * 10 + (s2[4] - '0');
  double second = (s2[6] - '0') * 10 + (s2[7] - '0');
  double total = hour / 24 + min / (60*24) + second / (3600*24);
  day += total;
  return day;
}