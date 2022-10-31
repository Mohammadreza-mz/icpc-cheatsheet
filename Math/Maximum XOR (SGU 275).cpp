int n;
long long x, ans;
vector<long long> st;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		st.push_back(x);
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < st.size(); i++)
			for (int j = i + 1; j < st.size(); j++)
				if (__builtin_clzll(st[j]) == __builtin_clzll(st[i]))
					st[j] ^= st[i];
	sort(st.begin(), st.end());
	reverse(st.begin(), st.end());
	for (auto e: st)
		ans = max(ans, ans ^ e);
	cout << ans << endl;
	return 0;
}