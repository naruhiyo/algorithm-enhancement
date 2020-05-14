#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
using mpint = mp::cpp_int;  // 多倍長整数（任意精度）

/*
 * 定数
 */
const long double PI = (acos(-1));
const long double EPS = 1e-10;
const long long INF = 1e18;

/*
 * データ変換 
 */
/* char -> int */
int ctoi(char c) { return (int)(c - '0'); }

/*
 * 数学的な計算
 */
/* 階乗 */
int factorial(int n) {
  int ret = 1;
  for (int i = 1; i < n + 1; ++i) {
    ret = ret * i;
  }
  return ret;
}

/* 最大公約数 */
template <typename T>
T gcd(T x, T y) { return x % y == 0 ? y : gcd(y, x % y); }

/* 最小公倍数 */
template <typename T>
T lcm(T a, T b) { return a * b / gcd(a, b); }

/* n個の整数の最小公倍数 */
template <typename T>
T lcm_n(vector<T> &numbers) {
  T l;
  l = numbers[0];
  for (int i = 1; i < numbers.size(); ++i) {
    l = lcm(l, numbers[i]);
  }
  return l;
}

/*
 * DP向け
 */
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

/*
 * グラフ
 */
class Graph {
 public:
  vector<vector<int>> G;
  vector<int> Trans;
  vector<int> inDeg;
  int numV;

  Graph(int numV) {
    this->numV = numV;
    inDeg.assign(numV, 0);
    Trans.assign(numV, 0);
    G.assign(numV, vector<int>());
  }

  int topologicalSort(int v, vector<int> &dp) {
    if (dp[v] != -1) {
      return dp[v];
    }

    int res = 0;

    for (auto to : G[v]) {
      chmax(res, topologicalSort(to, dp) + 1);
    }

    return dp[v] = res;
  }
};

void dfs(ll val, ll N, ll &count) {
  vector<bool> flag(3, false);

  for (auto s : to_string(val)) {
    if (s == '3') flag[0] = true;
    if (s == '5') flag[1] = true;
    if (s == '7') flag[2] = true;
  }

  if (val <= N) {
    if (flag[0] && flag[1] && flag[2]) {
      ++count;
    }

    dfs(10 * val + 3, N, count);
    dfs(10 * val + 5, N, count);
    dfs(10 * val + 7, N, count);
  }
}

int main() {
  ll N;
  cin >> N;

  ll count = 0;

  dfs(0, N, count);

  cout << count << endl;

  return 0;
}
