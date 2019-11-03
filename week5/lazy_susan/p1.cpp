#include <iostream>
using namespace std;

const int maxn = 505;
int a[maxn];

int main() {
  freopen("1620.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> a[i];

    // if n and 逆序數 are both odd
    // then the outcome is impossible
    int cnt = 0; // 存逆序數
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        if(a[i] > a[j])
          cnt++;

    if(cnt % 2 && n % 2)
      cout << "impossible" << endl;
    else
      cout << "possible" << endl;
  }
  return 0;
}
