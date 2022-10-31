const ll N = 2e5 + 5, LOG = 20;
int n, m, up[N][LOG], h[N], st[N], en[N], timer, par[N];
vector <int> adj[N];
void dfs(int v, int p = 0) {
	dp[v] = 1;
	st[v] = timer++;
	h[v] = h[p] + 1;
	up[v][0] = p;
	for (int i = 1; i < LOG; i++)
		if(up[v][i - 1] != -1)
			up[v][i] = up[up[v][i - 1]][i - 1];
	for (auto u : adj[v]) {
		if(u == p)	continue;
		par[u] = v;
		dfs(u, v);
	}
	en[v] = timer++;
}
bool check(int v, int u) {
	return (st[v] <= st[u]) && (en[u] <= en[v]);
}
int get(int v, int len) {
	for (int i = LOG - 1; ~i; i--) {
		if(len & (1 << i))
			v = up[v][i];
	}
	return v;
}
int lca(int v, int u) {
	if(h[v] < h[u])	swap(v, u);
	for (int i = LOG - 1; ~i; i--)
		if(h[up[v][i]] >= h[u])
			v = up[v][i];
	if(v == u)	return v;
	for (int i = LOG - 1; ~i; i--)
		if(up[v][i] != up[u][i])
			v = up[v][i], u = up[u][i];
	return up[u][0];
}
int path(int v, int p) {
	for (int i = LOG - 1; ~i; i--)
		if(!check(up[v][i], p))
			v = up[v][i];
	return v;
}
vector <int> seg[N << 2];
void build(int id = 1, int b = 0, int e = n) {
	if(e - b == 1) {
		seg[id].push_back(h[num[b]]);
		return;
	}
	int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
	build(lc, b, mid);
	build(rc, mid, e);
	seg[id] = seg[lc];
	for (int i = 0; i < seg[rc].size(); i++)
		seg[id].push_back(seg[rc][i]);
	sort(seg[id].begin(), seg[id].end());
	return;
}
int main() {
	h[0] = -1;
	dfs(0);
}