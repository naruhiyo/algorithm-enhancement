#include <bits/stdc++.h>
#define repeat(i, n) for(ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  double a, b, x;
  const long double PI = acos(-1);
  cin >> a >> b >> x;
  long double result = 0.0;
  long double S = x/a;

  if (S >= a*b/2) {
    long double h = (a*b - S) * 2 / a;
    result = atan2(h, a) / (2 * PI) * 360;
  } else {
    long double w = 2 * S / b;
    result = atan2(b, w) / (2 * PI) * 360;
  }

  cout << fixed << setprecision(10) << result << endl;
  return 0;
}
