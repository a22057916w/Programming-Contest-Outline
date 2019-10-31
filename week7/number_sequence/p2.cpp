#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdint>
using namespace std;

const int maxn = 40010;
int64_t dig[maxn];
int64_t count[maxn];
int64_t tot[maxn];

int64_t countDigit(int n) {
  return floor(log10(n) + 1);
}

void init() {

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


// customized binary_search
int64_t binary_search(int target) {

  int64_t left = 1, right = maxn - 1;
  while(left < right) {

    int64_t middle = (right + left) >> 1;

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
    int64_t pos;
    cin >> pos;

    // perform binary search to get group where the target falls in;
    int64_t g = binary_search(pos);
    // the k digits(target) in group g
    int64_t k = pos - tot[g - 1];

    // to record the target number and the remaining digits and
    // to calculate the increasing sum of digits when perform loop
    int num, remain;
    int64_t sum = 0;

    // sum up the digits from No.1 to No.g to find the target number
    for(int i = 1; i <= g; i++) {
      sum += dig[i];
      if(sum >= k) {
        remain = sum - k;
        num = i;
        break;
      }
    }

    // perform convertion of integer-to-string using c++11 <sstream> and <string> libs,
    // then print the answer
    ostringstream ss;
    ss << num;
    cout << ss.str()[(dig[num] - 1) - remain] << endl;
  }

}
