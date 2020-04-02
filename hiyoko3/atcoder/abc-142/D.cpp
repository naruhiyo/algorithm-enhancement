#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

// increment
#define rep_n(_1, _2, _3, NAME, ...) NAME
#define rep_2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep_3(i, initial, n) for (int i = (int)(initial); i < (int)(n); ++i)
#define repeat(...) rep_n(__VA_ARGS__, rep_3, rep_2, rep_1)(__VA_ARGS__)
// decrement
#define rep_r_n(_1, _2, _3, NAME, ...) NAME
#define rep_r_2(i, n) for (int i = (int)(n); i > 0; i--)
#define rep_r_3(i, initial, n) for (int i = (int)(initial); i > (int)(n); i--)
#define repeat_r(...) rep_r_n(__VA_ARGS__, rep_r_3, rep_r_2)(__VA_ARGS__)
// define variable
using namespace std;
typedef long long ll;
using mpint = boost::multiprecision::cpp_int; // 多倍長整数（任意精度）
typedef pair<int, int> P;
const double EPS = numeric_limits<double>::epsilon();
// 最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// 最小公倍数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// char -> int
int ctoi(char c) { return (int)(c - '0'); }
// 素因数分解
vector<ll> prime_factorize(ll n) {
	// それぞれの乗数が欲しければ vector< pair<ll, ll> > にする
	// vector< pair<ll, ll> > p
	// l35-36. p.push_back(make_pair(i, 0))
	// l36. p[i].second += 1;
	// l40. p.push_back(make_pair(n, 0))
	vector<ll> l;
	for(ll i = 2; i*i <= n; i++) {
		if ((n % i) != 0) continue;
		while((n % i) == 0) { n /= i; }
		l.push_back(i);
	}

	if (n != 1) l.push_back(n);
	return l;
}

int main() {
	ll A, B;
	cin >> A >> B;
 
	ll d = gcd(A, B);
	
	vector<ll> p = prime_factorize(d);
	
	cout << (p.size() + 1) << endl;
	return 0;
}