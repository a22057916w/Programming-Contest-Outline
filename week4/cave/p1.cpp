#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000005;
int f[maxn], c[maxn], h[maxn];

int main() {
  freopen("1442.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
      int n;
      cin >> n;
      for(int i = 0; i < n; i++)
        cin >> f[i];
      for(int i = 0; i < n; i++)
        cin >> c[i];

      int ans = 0, level = c[0];
      // sweeping the cave twice and recording the storable height of oil
      // first, left to right
      for(int i = 0; i < n; i++) {
        if(f[i] > level)
          level = f[i];
        if(c[i] < level)
          level = c[i];
        h[i] = level;
      }
      // second, right to left
      level = c[n - 1];
      for(int i = n - 1; i >= 0; i--) {
        if(f[i] > level)
          level = f[i];
        if(c[i] < level)
          level = c[i];
        ans += min(h[i], level) - f[i];
      }

      // print out the answer
      cout << ans << endl;
  }

  return 0;
}
