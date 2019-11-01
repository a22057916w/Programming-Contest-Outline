#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 210;

// box for storing the initial blocks,
// len for the length of consecutive color,
// col for the color of consecutive part
int box[maxn], len[maxn], col[maxn];

// pos for recording the length of differnet consecutive color interval
int pos;

// dp(i, j) stands for the maximum score in the interval [i, j]
// an additional condition k in dp(i, j, k) stands for moving right k-th index
// to get an maximum score on dp[i][j][k]
int dp[maxn][maxn][maxn];

void init(int n) {
  pos = 0;
  len[pos] = 1;
  col[pos] = box[0];

  int prev = box[0];
  for(int i = 1; i < n; i++) {
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

  // terminal condition
  if(l > r)
    return 0;

  // return the score if it's calculated and determined
  if(dp[l][r][k] != - 1)
    return dp[l][r][k];

  // find the maximum socre of interval [l, r - 1] plus the score of interval [r, k]
  // because three might be the same color in the interval [r, k] after merge
  int ret = DP(l, r - 1, 0) + (len[r] + k) * (len[r] + k);

  // there might be the same color in the interval [l, r] after merge,
  // therefore, we need to find the interval with maximum socre that lies in the interval [l, r]
  for(int i = l; i < r; i++)
    if(col[i] == col[r])
      ret = max(ret, DP(i + 1, r - 1, 0) + DP(l, i, len[r] + k));
  dp[l][r][k] = ret;

  return ret;
}

int main() {
  freopen("10559.in", "r", stdin);

  int testcase, cas = 1;
  cin >> testcase;

  while(testcase--) {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
      cin >> box[i];

    // initiating the params box, len, col, dp, and pos
    init(n);

    // perform the DP and print the maximum score
    cout << "Case " << cas++ << ": " << DP(0, pos, 0) << endl;
  }

  return 0;
}
