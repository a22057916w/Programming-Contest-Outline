#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

const int maxn = 40010;
long long int dig[maxn];
long long int count[maxn];
long long int tot[maxn];

long long int countDigit(int n) {
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



long long int binary_search(int target) {

  long long int left = 1, right = maxn - 1;
  while(left < right) {

    long long int middle = (right + left) >> 1;

    if(tot[middle] == target)
      return middle;
    else if(tot[middle] > target)
      right = middle;
    else
      left = middle + 1;
    //cout << left << " " << middle << " " << right << endl;
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
    long long int pos;
    cin >> pos;

    // perform binary search to get group where the target falls in;
    long long int g = binary_search(pos);
    // the k digits(target) in group g
    long long int k = pos - tot[g - 1];
    // the total digits in group g
    long long int tg_ditgits = count[g];
    //cout << g << " " << k << " " << tg_ditgits << endl;
    // find the target number
    int num, remain;
    long long int sum = 0;
    for(int i = 1; i <= g; i++) {
      sum += dig[i];
      if(sum >= k) {
        remain = sum - k;
        num = i;
        break;
      }
    }
    //cout << num << " " << remain << endl;
    ostringstream ss;
    ss << num;
    cout << ss.str()[(dig[num] - 1) - remain] << endl;
  }

}
