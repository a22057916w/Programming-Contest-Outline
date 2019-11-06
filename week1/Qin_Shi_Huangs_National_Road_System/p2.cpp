#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1010;
// recording the number of edges
int e;
// recording the imformation of edges
struct Edge {
  int a, b;
  double weight;

  Edge(int i = 0, int j = 0, double w = 0):
    a(i), b(j), weight(w) {}

  bool operator<(const Edge &e) const {
    return weight < e.weight;
  }
} edge[maxn * maxn];

vector<Edge> tree[maxn];
// recording the city status
struct City {
  double x, y;
  double p;
  void read() {
    cin >> x >> y >> p;
  }
} city[maxn];

// recording the parents for each node(city)
int p[maxn];

int visited[maxn];
double maxEdge[maxn][maxn];

void init(int n) {
  for(int i = 0; i < n; i++)
    city[i].read();

  // intiializing the params "edge" and "e"
  e = 0;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
        double dist = sqrt(pow(city[i].x - city[j].x, 2) + pow(city[i].y - city[j].y, 2));
        edge[e++] = Edge(i, j, dist);
    }
  // ordering the sequence from smaller(edge's weight) to bigger for the use of "kruscal" algorithm
  sort(edge, edge + e);
  // set each node's parent as itself
  for(int i = 0; i < n; i++) {
    p[i] = i;
    tree[i].clear();
    visited[i] = false;
  }
}

// find node x's parents
int find(int x) {
  return x == p[x] ? x : (p[x] = find(p[x]));
}
// joint a and b, leb b's parents be a's
void joint(int a, int b) {
  p[find(a)] = find(b);
}

double kruscal(int n) {
  double sum = 0;

  for(int i = 0, j = 0; i < n - 1 && j < e; i++, j++) {
    // check if the node a and b on a edge have the same parents
    // if so, they are in the same tree, then continue to the next edge
    while(find(edge[j].a) == find(edge[j].b)) {
      j++;
    }
    // let b's parents be a's so that a and b are now connected, in the same tree
    joint(edge[j].a, edge[j].b);
    // once the edge has been connected, we can count the weight of edge
    sum += edge[j].weight;
    tree[edge[j].a].push_back(Edge(edge[j].a, edge[j].b, edge[j].weight));
    tree[edge[j].b].push_back(Edge(edge[j].b, edge[j].a, edge[j].weight));
  }
  return sum;
}

void dfs(int u, int n) {
  // traverse the MST by DFS like,
  // node 0 to 1 -> node 1 to 2 and node 1 back to 0
  // then find the maximun edge of node 1 between node 0 and 2
  visited[u] = true;
  for(int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i].b;
    if(visited[v])
      continue;

    double cost = tree[u][i].weight;
    maxEdge[u][v] = maxEdge[v][u] = cost;

    for(int j = 0; j < n; j++) {
      if(visited[j])
        maxEdge[j][v]= maxEdge[v][j] = max(maxEdge[j][u], cost);
    }
    dfs(v, n);
  }
}

int main() {
  freopen("1494.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
      int n;
      cin >> n;
      // intiializing params for cities and kruscal algorithm
      init(n);

      double mstCost = kruscal(n);
      // perform dfs to find the maximun wieght for a node to the adjcent nodes on MST
      dfs(0, n);

      // find out the maximun ration and print out the answer
      double ans = 0;
      for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
          ans = max(ans, (city[i].p + city[j].p) / (mstCost - maxEdge[i][j]));
      printf("%.2lf\n", ans);
  }

  return 0;
}
