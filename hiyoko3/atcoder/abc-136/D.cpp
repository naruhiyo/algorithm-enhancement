#include <bits/stdc++.h>
#define repeat(i, n) for(int (i) = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const double EPS = numeric_limits<double>::epsilon();
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
	string S;
	cin >> S;
	vector<int> result(S.length(), 0);

	repeat(i, S.length()) {
		int pos = 1;
		string a = S.substr(i, 1);
		if (a == "L") continue;

		for(int j = i+1; j < S.length(); j++) {
			string b = S.substr(j, 1);
			if (b == "L") break;
			pos++;
		}
		// cout << "pos: " << pos << ", result idx: " << ((pos % 2) == 0 ? i+pos : i+pos-1) << endl;
		if ((pos % 2) == 0) result[i+pos] += 1;
		else result[i+pos-1] += 1;
	}


	for(int i = S.length() - 1; i >= 0; i--) {
		int pos = 1;
		string a = S.substr(i, 1);
		if (a == "R") continue;

		for(int j = i-1; j >= 0; j--) {
			string b = S.substr(j, 1);
			if (b == "R") break;
			pos++;
		}
		// cout << "pos: " << pos << ", result idx: " << ((pos % 2) == 0 ? i-pos : i-pos-1) << endl;
		if ((pos % 2) == 0) result[i-pos] += 1;
		else result[i-pos+1] += 1;
	}

	repeat(i, S.length()) {
		cout << result[i] << endl;
	}
	return 0;
}
