const long long N = 2e5 + 2, K = 50 + 2, inf = 1e18;
double dp[N][K], sum[N], prefix[N], rev[N], x;
int n, k;
inline double cost(int l, int r, int k) {
	return dp[l - 1][k - 1] + (prefix[r] - prefix[l - 1]) - ((rev[r] - rev[l - 1]) * sum[l - 1]);
}
void solve(int l, int r, int k, int optl, int optr) {
	if(l > r)	return;
	int mid = (l + r) / 2, idx = optl;
	dp[mid][k] = cost(optl, mid, k);
	for (int i = optl + 1; i <= min(mid, optr); i++)
    	if(dp[mid][k] > cost(i, mid, k))
        	dp[mid][k] = cost(i, mid, k), idx = i;
	solve(l, mid - 1, k, optl, idx);
    solve(mid + 1, r, k, idx, optr);
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum[i + 1] = sum[i] + x, rev[i + 1] = rev[i] + (1.0 / x), prefix[i + 1] = prefix[i] + (sum[i + 1] / x), dp[i + 1][0] = inf;
	}
	for (int i = 1; i <= k; i++)	
        solve(i, n, i, i, n);
	cout << setprecision(6) << dp[n][k] << "\n";
}