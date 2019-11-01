#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pair_ii;

#define maxn 10010
int num[maxn];

void exchange(int l, int r) {
  // r - l is always an even number
  for(int i = l, j = (l + r) / 2 + 1; j <= r; i++, j++)
    swap(num[i], num[j]);
}

int main() {
  freopen("1611.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
      cin >> num[i];

    // recording the two cargos that being exchanged and the number of movement
    vector<pair<int, int> > rec;

    // place the i-th number to num[i], like selection sort
    for(int i = 1; i <= n; i++) {
        // first, find the number i and store in pos params
        int pos;
        for(int j = i; j <= n; j++)
          if(num[j] == i) {
            pos = j;
            break;
          }

        // second, perform the cargo exchange.

        // do nothing if i is already in the position
        if(pos == i)
          continue;

        // peform one exchange if n lies in [i, i - 1 + 2 * (pos - i)]
        if((i - 1) + 2 * (pos - i) <= n) {
          rec.push_back(pair_ii(i, (i - 1) + 2 * (pos - i)));
          exchange(i, (i - 1) + 2 * (pos - i));
        }
        // peform two exchanges with two strategies,
        // depending on wether (pos - i) is even or odd
        // and minus i to do the one-exchage movement
        else {
            if((pos - i + 1) % 2) {
              rec.push_back(pair_ii(i + 1, pos));
              exchange(i + 1, pos);
            }
            else {
              rec.push_back(pair_ii(i, pos));
              exchange(i, pos);
            }
            i--;
        }
    }

    // print out the answer
    cout << rec.size() << endl;
    for(int i = 0; i < rec.size(); i++)
      cout << rec[i].first << " " << rec[i].second << endl;
  }

  return 0;
}
