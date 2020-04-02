#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include<iomanip>
#include<map>

#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

map<ll, ll> prime_factors(ll n) {
    map<ll, ll> res;
    if(n == 1) { // n=1 の素因数分解は n^1
        res[n] = 1;
        return res;
    }
    for(ll i = 2; i*i <= n; ++i) {
        while(n % i == 0) {
            ++res[i]; // 素数i^{res[i]}
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main(){
  ll a, b;
  cin >> a >> b;

  if(a == 1 && b == 1) {
    cout << 1 << endl;
    return 0;
  }

  map<ll, ll> p_a = prime_factors(a);
  map<ll, ll> p_b = prime_factors(b);

  vector<ll> d_a, d_b;

  for(auto itr = p_a.begin(), end = p_a.end(); itr != end; ++itr) {
    d_a.push_back(itr->first);
  }

  for(auto itr = p_b.begin(), end = p_b.end(); itr != end; ++itr) {
    d_b.push_back(itr->first);
  }

  ll j = 0;
  ll ans = 1;
  for(ll i = 0; i < d_a.size(); ++i){
    if(d_a[i] == d_b[j]) {
        ++ans;
    }
    while(d_b[j] < d_a[i] && j < d_b.size()){
      ++j;
      if(d_a[i] == d_b[j]) {
        ++ans;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
