#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1000010;

int e;

struct Edge {
  int a, b;
  double weight;

  Edge(int i = 0, int j = 0, double w = 0):
    a(i), b(j), weight(w) {}

  bool operator<(const Edge &e) const {
    return weight < e.weight;
  }
} edge[maxn];

struct City {
  double x, y;
  int population;

  City(double _x = 0, double _y = 0, int p = 0):
    x(_x), y(_y), population(p) {}

} city[maxn];

int p[maxn];

void init(int n) {
  for(int i = 0; i < n; i++)
    cin >> city[i].x >> city[i].y >> city[i].population;

  e = 0;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
        double dist = sqrt(pow(city[i].x - city[j].x, 2) + pow(city[i].y - city[j].y, 2));
        edge[e++] = Edge(i, j, dist);
    }

    sort(edge, edge + e);

}

int main() {
  freopen("1494.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
      int n;
      cin >> n;

      init(n);

  }

  return 0;
}
