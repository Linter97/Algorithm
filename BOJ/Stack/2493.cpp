#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	stack<pii> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (!st.empty() && st.top().first <= x) st.pop();
		if (st.empty()) cout << "0 ";
		else cout << st.top().second << " ";
		st.push({ x, i });
	}
}
