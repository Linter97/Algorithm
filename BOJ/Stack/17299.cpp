#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[1000001], NGF[1000001], cnt[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	stack<pii> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && st.top().second <= cnt[a[i]]) st.pop();
		if (st.empty()) NGF[i] = -1;
		else NGF[i] = st.top().first;
		st.push({ a[i], cnt[a[i]]});
	}
	for (int i = 0; i < n; i++)cout << NGF[i] << " ";
	cout << "\n";
}
