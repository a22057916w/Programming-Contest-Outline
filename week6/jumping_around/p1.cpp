#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ans[1510];

int main() {
  freopen("1621.in", "r" ,stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
    int a, b, c;
    cin >> a >> b >> c;

    int len = 0;
    int pos = 0;
    ans[len++] = 0;

    // first, we use all the three-stop tickets
    // second, we use the remaining one-stop and two-stop tickets
    // we have three different startegies for using the all three-stop tickets
    if(c % 3 == 0) {
      for(int i = 0; i < c / 3; i++)
        ans[len++] = (pos += 3);
      ans[len++] = ++pos;
      a--;

      for(int i = 0; i < c / 3; i++)
        ans[len++] = (pos -= 3);
      ans[len++] = ++pos;
      a--;

      for(int i = 0; i < c / 3; i++)
        ans[len++] = (pos += 3);
    }
    else if(c % 3 == 1) {
      for(int i = 0; i < c / 3 + 1; i++)
        ans[len++] = (pos += 3);
      ans[len++] = (pos -= 2);
      b--;

      for(int i = 0; i < c / 3; i++)
        ans[len++] = (pos -= 3);
      ans[len++] = ++pos;
      a--;

      for(int i = 0; i < c / 3; i++)
        ans[len++] = (pos += 3);
      ans[len++] = (pos += 2);
      b--;
    }
    else {
      for(int i = 0; i < c / 3 + 1; i++)
        ans[len++] = (pos += 3);
      ans[len++] = --pos;
      a--;

      for(int i = 0; i < c / 3; i++)
        ans[len++] = (pos -= 3);
      ans[len++] = --pos;
      a--;

      for(int i = 0; i < c / 3 + 1; i++)
        ans[len++] = (pos += 3);
    }

    // use all the one-stop tickets except for one to turn around
    while(a-- > 1)
      ans[len++] = ++pos;

    // now, we use half of the two-stop tickets and leave a one-stop ticket to turn around
    for(int i = 0; i < (b + 1) / 2; i++)
      ans[len++] = (pos+= 2);

    // there are two startegies to use the remaining two-stop tickets,
    // depending on wether the total two-stop tickets are even or odd
    if(b % 2)
      ans[len++] = --pos;
    else
      ans[len++] = ++pos;
    for(int i = b & 1; i < (b + 1) / 2; i++)
      ans[len++] = (pos -= 2);

    // print the route traversed
    for(int i = 0; i < len - 1; i++)
      cout << ans[i] << " ";
    cout << ans[len - 1] << endl;
  }

  return 0;
}
