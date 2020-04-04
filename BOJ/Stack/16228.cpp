#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string a[101], b[101];
string op = "+-()<>";
int t, tt;
void make_infix(string s) {
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (op.find(s[i]) != string::npos) {
			if (temp != "") {
				a[t++] = temp;
				temp = "";
			}
			a[t++] = s[i];
			if (s[i] == '>' || s[i] == '<') i++;
		}
		else temp += s[i];
	}
	if (temp != "") a[t++] = temp;
}
void infix_to_postfix() {
	stack<string> st;
	for (int i = 0; i < t; i++) {
		if (a[i] == "(") st.push(a[i]);
		else if (a[i] == ")") {
			while (st.top() != "(") {
				b[tt++] = st.top();
				st.pop();
			}
			st.pop();
		}
		else if (op.find(a[i]) != string::npos) {
			if (st.empty()) st.push(a[i]);
			else if (a[i] == "+" || a[i] == "-") {
				while (!st.empty() && (st.top() == "<" || st.top() == ">" || st.top() == "+" || st.top() == "-")) {
					b[tt++] = st.top();
					st.pop();
				}
				st.push(a[i]);
			}
			else if (a[i] == "<" || a[i] == ">") {
				while (!st.empty() && (st.top() == "<" || st.top() == ">") ) {
					b[tt++] = st.top();
					st.pop();
				}
				st.push(a[i]);
			}
		}
		else b[tt++] = a[i];
	}
	while (!st.empty()) b[tt++] = st.top(), st.pop();
}
int compute() {
	stack<string> st;
	for (int i = 0; i < tt; i++) {
		if (op.find(b[i]) != string::npos) {
			int x = stoi(st.top());
			st.pop();
			int y = stoi(st.top());
			st.pop();
			if (b[i] == "+") st.push(to_string(y + x));
			else if (b[i] == "-") st.push(to_string(y - x));
			else if (b[i] == "<") st.push(to_string(min(x, y)));
			else st.push(to_string(max(x, y)));
		}
		else st.push(b[i]);
	}
	return stoi(st.top());
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	make_infix(s);
	infix_to_postfix();
	cout << compute() << "\n";
}
