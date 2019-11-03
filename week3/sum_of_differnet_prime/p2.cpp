#include <iostream>
using namespace std;

const int maxn = 1120;
bool visit[maxn + 10] = {false};
int prime[maxn + 10];
int prime_cnt = 0;

int dp[maxn + 10][15] = {0};

void init_prime_table() {
  for(int i = 2; i <= maxn; i++)
    if(!visit[i]) {
      prime[prime_cnt++] = i;
      for(int j = i * i; j <= maxn; j += i)
        visit[j] = true;
    }
}

int main() {

  init_prime_table();

  // peeform DP
  dp[0][0] = 1;
  for(int i = 0; i < prime_cnt; i++)
    for(int j = maxn; j >= prime[i]; j--)
      for(int k = 1; k < 15; k++)
        dp[j][k] += dp[j - prime[i]][k - 1];

  freopen("1213.in", "r", stdin);

  // read the inputs and print the answer
  int n, k;
  while(cin >> n >> k) {
    cout << dp[n][k] << endl;
  }

  return 0;
}
