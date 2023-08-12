#include <bits/stdc++.h>
using namespace std;

/**
 * task: given N elements [0...N-1] where each has some weight w[i]
 * and profit p[i], put the items into a bag with capacity W such that
 * the sum of profits associated with them is the maximum possible.
*/
int knapsack_1(int N, int W, vector<int>& w, vector<int>& p) {
  int dp[N + 1][W + 1]; // time = space = O(N * W)

  for(int i = 0; i <= N; ++i) {
    for(int j = 0; j <= W; ++j) {
      if(i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = dp[i - 1][j]; // don't take this element

      if(j >= w[i - 1]) { // don't go out of the bounds
        dp[i][j] = std::max( // try to take this element
          dp[i][j],
          dp[i - 1][j - w[i - 1]] + p[i - 1]
        );
      }
    }
  }

  return /* ans */ dp[N][W];
}

/**
 * task: given an array of length N, check if is possible to
 * select some elements from the array which sum up to T
 * (don't need to output the selected elements)
*/
bool knapsack_2(int N, int T, vector<int>& elements) {
  bool dp[N + 1][T + 1]; memset(dp, 0, sizeof dp);
  dp[0][0] = 1;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j <= T; ++j) {
      if(dp[i][j]) {
        dp[i + 1][j] = 1;

        if(j + elements[i] <= T) { // don't go out of the bounds
          dp[i + 1][j + elements[i]] = 1;
        }
      }
    }
  }

  return dp[N][T];
}
