#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

int main() {
  int result = 0, N;
	cin >> N;

	// initialize
	vector<int> L(N);
	for(int i = 0; i < N; i++) {
		cin >> L[i];
	}
	// sort
	sort(L.begin(), L.end());

  ll ans = 0;
  for(ll i = N - 1; i >= 0; i--) {
    for(ll j = i - 1; j >= 0; j--) {
			// 二部探索で L[i]+L[j] 以上のパターンを走査
      auto itr = lower_bound(L.begin(), L.end(), L[i] + L[j]);
			// 要件を満たさない Indexを取得
      ll ngIndex = distance(itr, L.end());
			// ngIndex の値は 要件を満たさないパターン数を表しているので、L[i]までのパターン数から差し引く
      result += (N - 1 - i) - ngIndex;
    }
  }

	cout << result << endl;
}
