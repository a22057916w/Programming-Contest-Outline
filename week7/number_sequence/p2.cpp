#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 40010;
int dig[maxn];
int count[maxn];
int tot[maxn];

int init() {

  // recording the digit for each number
  dig[0] = 1;
  for(int i = 1; i < maxn; i++)
    dig[i] = countDigit(i);

  // recording the total digits in every group
  count[0] = 0;
  for(int i = 1; i < maxn; i++)
    count[i] = count[i - 1] + dig[i];

  // recording the total digits from the firt group to a specific group
  tot[0] = 0;
  for(int i = 1; i < maxn; i++)
    tot[i] = tot[i - 1] + count[i];
}

int countDigit(int n) {
  return floor(log10(n) + 1);
}

int binary_search(int target) {

  int left = 1, right = maxn - 1;
  while(left <= right) {

    int middle = (right + left) >> 2;

    if(tot[middle] == target)
      return middle;
    else if(tot[middle] > target)
      right = middle;
    else
      left = middle + 1;
  }

  return left;
}

int main() {

  // initialing params dig, count, and tot
  init();

  freopen("10706.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
    int pos;
    cin >> pos;

    // perform binary search to get group where the target falls in;
    int g = binary_search(pos);
    int ans = tot[g] - tot[g - 1];
  }

}
