#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  freopen("12545.in", "r", stdin);

  int testcase,cas = 1;
  cin >> testcase;

  while(testcase--) {
    string s, t;
    cin >> s >> t;

    int s1 = 0, t1 = 0, que = 0;
    int one_zero = 0;
    int zero_one = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '1')
        s1++;
      if(t[i] == '1')
        t1++;
      if(s[i] == '?')
        que++;
      if(s[i] == '1' && t[i] == '0')
        one_zero++;
      if(s[i] == '0' && t[i] == '1')
        zero_one++;
    }

    if(s1 > t1)
      printf("Case %d: -1\n", cas++);
    else
      printf("Case %d: %d\n", cas++, max(one_zero, zero_one) + que);
  }

  return 0;
}
