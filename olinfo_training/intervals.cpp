#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int N;
vector<pair<int, int>> A;

void solve() {
  unordered_multiset<int> s;
  int ans = 0;
  for(int i = 0; i < (int)A.size(); ++i) {
    auto it = s.find(A[i].first);
    if(it != s.end())
      s.erase(it);
    else
      ans += 1;
    s.insert(A[i].second);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  sort(all(A));

  solve();
}
