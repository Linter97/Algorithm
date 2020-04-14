#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	while (n != 1) {
		cout << n << " ";
		if (n % 2 == 1) n = n * 3 + 1;
		else n /= 2;
	}
	cout << n << "\n";
}
