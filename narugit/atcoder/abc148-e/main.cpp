#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
using mpint = mp::cpp_int; // 多倍長整数（任意精度）

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
int factorial(int n){ int ret = 1; for(int i = 1; i < n + 1; ++i) { ret = ret * i; } return ret; }

/* 最大公約数 */
template <typename T>T gcd(T x, T y){ return x % y == 0 ? y : gcd(y, x % y); }

/* 最小公倍数 */
template <typename T>T lcm(T a, T b) { return a * b / gcd(a, b); }

/* n個の整数の最小公倍数 */
template <typename T>T lcm_n(vector<T> &numbers) { T l; l = numbers[0]; for(int i = 1; i < numbers.size(); ++i) { l = lcm(l, numbers[i]); } return l; }

/*
 * DP向け
 */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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

int main(){
  mpint N;
  cin >> N;

  if( N % 2 == 0){
    mpint ans = 0;
    mpint d = 1;
    for(int i = 1; i <= 18; ++i){
      d *= 10;
      ans += N/d;
    }
    d = 5;
    mpint e = 2;
    for(int i = 1; i <= 90; ++i){
      d *= 5;
      e *= 2;
      ans += N/d/2 - N/(d*e);
    }
    cout << ans << endl;
  } else{
    cout << 0 << endl;
  }

  return 0;
}
