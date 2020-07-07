#include <bits/stdc++.h>

#include <boost/multiprecision/cpp_int.hpp>

// increment
#define rep_n(_1, _2, _3, NAME, ...) NAME
#define rep_2(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define rep_3(i, initial, n) \
  for (int(i) = (int)(initial); (i) < (int)(n); ++(i))
#define rep(...) rep_n(__VA_ARGS__, rep_3, rep_2, rep_1)(__VA_ARGS__)
// decrement
#define rep_r_n(_1, _2, _3, NAME, ...) NAME
#define rep_r_2(i, n) for (int(i) = (int)(n); (i) > 0; (i)--)
#define rep_r_3(i, initial, n) \
  for (int(i) = (int)(initial); (i) > (int)(n); (i)--)
#define rep_r(...) rep_r_n(__VA_ARGS__, rep_r_3, rep_r_2)(__VA_ARGS__)
// define type definition
using namespace std;
typedef long long ll;
using mpint = boost::multiprecision::cpp_int;  // 多倍長整数（任意精度）
typedef pair<int, int> P;

// define construct variable
const double EPS = numeric_limits<double>::epsilon();
// 10^9 + 7
const ll MOD = ll(1e9) + 7;
const ll INF = ll(1e10);
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
const double PI = acos(-1);

// define methods
// 最大公約数
ll gcd(const ll a, const ll b) { return b ? gcd(b, a % b) : a; }
// 最小公倍数
ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }
// char -> int
int ctoi(char c) { return (int)(c - '0'); }
// 素因数分解
vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> p;
  for (ll i = 2; i * i <= n; i++) {
    if ((n % i) != 0) continue;
    pair<ll, ll> a = make_pair(i, 0);
    while ((n % i) == 0) {
      n /= i;
      a.second += 1;
    }
    p.push_back(a);
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
  if (u < 0) {
    u += MOD;
  }
  return u;
}
// 順列
ll permutation(const ll n, const ll m) {
  ll result = 1;
  for (ll i = n; i > n - m; i--) {
    result = (result * i) % MOD;
  }
  return result;
}

// 繰り返し n 乗法
ll repeat_square(const ll n, const ll x) {
  if (x == 0) return 1;
  ll res = repeat_square(n, x / 2);
  res = res * res % MOD;
  if ((x % 2) == 1) res = res * n % MOD;
  return res;
}
// 組み合わせ nCm
ll combination(ll n, ll m) {
  ll p = permutation(n, m);
  ll div = 1;
  for (ll i = 2; i <= m; i++) {
    div = (div * i) % MOD;
  }
  return (p * modinv(div)) % MOD;
}

// アルファベットの取得
string get_alphabet(ll n) {
  n--;
  return string(1, 'a' + (n % 26));
}

int main() {
  string S, T;
  cin >> S >> T;

  if (S == T) {
    cout << "Yes" << endl;
    return 0;
  }
  // map<string, int> a, b;
  // rep(i, S.length()) a[S.substr(i, 1)]++;
  // rep(i, T.length()) b[T.substr(i, 1)]++;

  // vector<string> n;
  // for(auto itr: a) {
  //   int x = b[itr.first];
  //   if (itr.second == x) {
  //     a[itr.first] = -1;
  //     b[itr.first] = -1;
  //     continue;
  //   }

  //   n.push_back(itr.first);
  // }

  // rep(i, n.size()) {
  //   int c = a[n[i]];
  //   bool ok = false;
  //   for(auto it: b) {
  //     if (it.second == c) {
  //       ok = true;
  //       break;
  //     }
  //   }
  //   if (!ok) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  // }

  // cout << "Yes" << endl;

  vector<int> sv(S.length());
  vector<int> tv(T.length());
  map<char, int> smap;
  map<char, int> tmap;

  for (int i = 0; i < S.length(); ++i) {
    if (smap.count(S[i]) == 0) {
      smap[S[i]] = smap.size();
    }

    sv[i] = smap[S[i]];
  }

  for (int i = 0; i < T.length(); ++i) {
    if (tmap.count(T[i]) == 0) {
      tmap[T[i]] = tmap.size();
    }

    tv[i] = tmap[T[i]];
  }

  cout << (sv == tv ? "Yes" : "No") << endl;
  return 0;
}
