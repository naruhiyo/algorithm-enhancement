#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

// increment
#define rep_n(_1, _2, _3, NAME, ...) NAME
#define rep_2(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define rep_3(i, initial, n) for (int(i) = (int)(initial); (i) < (int)(n); ++(i))
#define rep(...) rep_n(__VA_ARGS__, rep_3, rep_2, rep_1)(__VA_ARGS__)
// decrement
#define rep_r_n(_1, _2, _3, NAME, ...) NAME
#define rep_r_2(i, n) for (int(i) = (int)(n); (i) > 0; (i)--)
#define rep_r_3(i, initial, n) for (int(i) = (int)(initial); (i) > (int)(n); (i)--)
#define rep_r(...) rep_r_n(__VA_ARGS__, rep_r_3, rep_r_2)(__VA_ARGS__)
// define type definition
using namespace std;
typedef long long ll;
using mpint = boost::multiprecision::cpp_int; // 多倍長整数（任意精度）
typedef pair<int, int> P;

// define construct variable
const double EPS = numeric_limits<double>::epsilon();
// 10^9 + 7
const ll MOD = ll(1e9)+7;
const ll INF = ll(1e10);
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

// define methods
// 最大公約数
ll gcd(const ll a, const ll b) { return b ? gcd(b, a % b) : a; }
// 最小公倍数
ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }
// char -> int
int ctoi(char c) { return (int)(c - '0'); }
// 素因数分解
vector< pair<ll, ll> > prime_factorize(ll n) {
  vector< pair<ll, ll> > p;
  for (ll i = 2; i * i <= n; i++) {
    if ((n % i) != 0) continue;
    p.push_back(make_pair(i, 0));
    while ((n % i) == 0) {
      n /= i;
      p[i].second += 1;
    }
    p.push_back(make_pair(n, 0));
  }

  if (n != 1) p.push_back(make_pair(n, 1));
  return p;
}
// 組み合わせの整合性を保つ（後ほど解析する）
ll modinv(ll a) {
	ll b = MOD, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= MOD;
	if (u < 0) { u += MOD; }
	return u;
}
// 順列
ll permutation(const ll n, const ll m) {
	ll result = 1;
	for (ll i = n; i > n - m; i--) { result = (result * i) % MOD; }
	return result;
}

// 繰り返し n 乗法
ll repeat_square(const ll n, const ll x) {
	if (x == 0) return 1;
	ll res = repeat_square(n, x/2);
	res = res * res % MOD;
	if ((x % 2) == 1) res = res * n % MOD;
  return res;
}
// 組み合わせ
ll combination(const ll n, const ll a) {
	ll x = 1, y = 1;
  for(ll i = 0; i < a; i++){
    x = x * (n-i) % MOD;
    y = y * (i+1) % MOD;
  }
  return x * repeat_square(y, MOD-2) % MOD;
}

ll result = 0;
ll n;
ll d[] = {3,5,7};
void calc(int digit, ll val, int pos) {
	if (digit < 1) {
		// cout << "digit: " << digit << ", val: " << val << ", pos: " << pos << ", result: " << result << endl;
		if (val <= n) {
			string s = to_string(val);
			bool ok3 = false, ok5 = false, ok7 = false;
			rep (i, s.length()) {
				if (s[i] == '3') ok3 = true;
				else if (s[i] == '5') ok5 = true;
				else if (s[i] == '7') ok7 = true;
			}
			if (ok3 && ok5 && ok7) result += 1;
			// cout << ok3 << ok5 << ok7 << "digit: " << digit << ", val: " << val << ", pos: " << pos << endl;
		}
		return;
	}

	ll temp = 1;
	rep(i, digit-1) { temp *= 10; }

	rep(i, 3) {
		val += temp * d[i];
		calc(digit-1, val, i+1);
		val -= temp * d[i];
	}
	
	return;
}

int main() {
	cin >> n;

	int x = 3;
	ll m = n;
	while(m > 100) {
		calc(x, 0, 0);

		m /= 10;
		x++;
	}

	cout << result << endl;
  return 0;
}
