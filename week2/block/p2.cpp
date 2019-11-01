#include <iostream>
#include <algorith>
#include <cstring>
using namespace std;

const int maxn = 210;

// box for storing the initial blocks,
// len for the length of consecutive color,
// col for the color of consecutive part
int box[maxn], len[maxn], col[maxn];

// pos for recording the length of differnet consecutive color interval
int pos;
int dp[maxn][maxn][maxn];

void init() {
  pos = 0;
  len[pos] = 1;
  col[pos] = box[0];

  int prev = box[0];
  for(int i = 0; i < n; i++) {
    if(box[i] == prev)
      len[pos]++;
    else {
      len[++pos] = 1;
      col[pos] = box[i];
      prev = box[i];
    }
  }

  memset(dp, -1, sizeof(dp));
}

int DP(int l, int r, int k) {

  //
  int ret = DP(l, r - 1, 0) + (len[r] + k) * (len[r] + k);

  for(int i = l; i < r; i--)
    if(col[i] == col[r])
      ret = max(ret, DP(i + 1, r - 1, 0) + DP(l, i, len[r] + k));

}

int main() {
  //freopen("10559.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {

    int n;
    for(int i = 0; i < n; i++)
      cin >> box[i];

    // initiating the params box, len, col, dp, and pos
    init();


  }

  return 0;
}
