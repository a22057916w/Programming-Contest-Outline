#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000010;
int a[maxn], cnt[maxn];

void init_sequence(int n, int m) {
  a[1] = 1; a[2] = 2; a[3] = 3;
  for(int i = 4; i <= n; i++)
    a[i] = ((a[i - 1] + a[i - 2] + a[i - 3]) % m) + 1;

  memset(cnt, 0, sizeof(cnt));
}

int main() {
  freopen("11536.in", "r", stdin);

  int testcase, cas = 1;
  cin >> testcase;

  while(testcase--) {
    int n, m, k;
    cin >> n >> m >> k;

    init_sequence(n, m);

    // using the "sliding window method" to calculate the min-sub-array
    // params front and rear as indexes for manipulating the array
    int front = 1, rear = 0;
    // c for recording the numbers of 1 to k
    int c = 0;

    // front...rear represents the interval [front, rear]
    // front moves right to contract
    // rear moves right to expand
    int ans = 1E9;
    while(true) {
      // moving "front" right if the numbers(from 1 to k) all lie in the interval [front, rear]
      if(c == k) {
        cnt[a[front]]--;
        // check if there is missing a number from 1 to k
        if(cnt[a[front]] == 0 && a[front] <= k)
          c--;
        front++;
        if(c == k)
          ans = min(ans, rear - front + 1);
      }
      // moving "rear" right if there is missing a number from 1 to k in the interval [front, rear]
      else {
        rear++;
        if(rear > n)
          break;

        cnt[a[rear]]++;
        // check if the condition is reached, that at least has one number from 1 to k
        if(cnt[a[rear]] == 1 && a[rear] <= k)
          c++;
        if(c == k)
          ans = min(ans, rear - front + 1);
      }
    }

    // print out the answer
    cout << "Case " << cas++ << ": ";
    if(ans != 1E9)
      cout << ans << endl;
    else
      cout << "sequence nai" << endl;
  }

  return 0;
}
