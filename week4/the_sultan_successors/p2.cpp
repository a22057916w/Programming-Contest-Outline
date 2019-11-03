#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int chessboard[10][10];
int queen_pos[10];
int score;

bool conflict(int c, int r) {
  for(int i = 1; i < c; i++) {
    // check the horizontal (row) direction
    if(queen_pos[i] == r)
      return true;
    // check the diagonal direction
    if(abs(c - i) == abs(queen_pos[i] - r))
      return true;
  }

  return false;
}

void DFS(int c) {
  // sum up the total scores and end the revursive function,
  // if the chessboard has been browsed through the last column (that is beyond 8-th column)
  if(c == 9) {
    int sum = 0;
    for(int i = 1; i <= 8; i++)
      sum += chessboard[i][queen_pos[i]];
    score = max(score, sum);
    return;
  }
  // perform backtracking with for loop, checking the place one-by-one (from 1 to 8 per column)
  // then moving column by DFS method
  for(int r = 1; r <= 8; r++)
    if(!conflict(c, r)) {
      queen_pos[c] = r;
      DFS(c + 1);
    }
}


int main() {
  freopen("167.in", "r", stdin);

  int testcase;
  cin >> testcase;

  while(testcase--) {
    for(int i = 1; i <= 8; i++)
      for(int j = 1; j <= 8; j++)
        cin >> chessboard[i][j];

      // perform dfs and backtracking
      score = 0;
      DFS(1);

      // print out the answer in a given format
      printf("%5d\n", score);
  }
}
