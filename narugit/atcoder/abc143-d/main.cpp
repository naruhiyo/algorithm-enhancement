#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
  ll N; //NC3 < N^3 = 8*10^9 > INT_MAX
  cin >> N;

  vector<int> L(N);

  for(auto& l : L){
    cin >> l;
  }

  sort(L.begin(), L.end());

  ll ans = 0;

  for(ll i = N-1; i > 1; --i){
    for(ll j = i-1; j > 0; --j){
      auto itr = lower_bound(L.begin(), L.end(), L[i] - L[j] + 1);
      ll index = distance(L.begin(), itr);
      if(j - index > 0){
        ans += j - index;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
