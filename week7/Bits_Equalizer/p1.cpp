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

    // recording the number of '1' and '?' in s as s1 and que
    // recording the number of '1' in t as t1
    int s1 = 0, t1 = 0, que = 0;
    // recording the number of pair (1, 0) and (0, 1) as one_zero and zero_one
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

    // if the number of '1' in s is more than that in t, then there is no solution
    if(s1 > t1)
      printf("Case %d: -1\n", cas++);
    // performing the exchanges of pairs between all (1, 0), (0, 1),
    // then turn the question mark into the corelated sign and exchange the pairs again,
    // therefore, all (1, 0) must count and also the question mark
    else
      printf("Case %d: %d\n", cas++, max(one_zero, zero_one) + que);
  }

  return 0;
}
