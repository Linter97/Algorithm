#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int m[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin >> a;
	a = 1000 - a;
	int i = 0, res = 0;
	while (a) {
		if (a / m[i] != 0) {
			res += a / m[i];
			a %= m[i];
		}
		i++;
	}
	cout << res << "\n";
}
