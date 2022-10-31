
vector<edge> g[maxn];
int h[maxn], dst[maxn], prevv[maxn ], preve[maxn];
inline void add_edge(int f, int t, int cap, int cost)
{
	g[f].emplace_back(t, cap, cost, g[t].size());
	g[t].emplace_back(f, 0, -cost, g[f].size() - 1);
}
 
int mcmf(int s, int t , int maxFlow)
{
	int res = 0;
	int c = INT_MAX;
	memset(h, 0, sizeof(h));
 	int f = 0;
	while (f < maxFlow) {
		priority_queue<ii, vector<ii>, greater<ii> > que;
		fill(dst, dst + n , inf);
		dst[s] = 0;
		que.push(mp(0, s));
		while (!que.empty()) {
			ii p = que.top(); que.pop();
			int v = p.second;
			if (dst[v] < p.first) continue;
			fore(i , 0 , g[v].size() - 1) {
				edge &e = g[v][i];
				int nd = dst[v] + e.cost + h[v] - h[e.to];
				if (e.cap > 0 && dst[e.to] > nd){
					dst[e.to] = nd;
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(mp(dst[e.to], e.to));
				}
			}
		}
 
		if (dst[t] == inf) return c;
		fore(i, 0 , n - 1) h[i] += dst[i];
 
		int d = inf;
		for(int v = t; v != s; v = prevv[v])
			d = min(d, g[prevv[v]][preve[v]].cap);
		f += d;
		res += d * h[t];
		c = min(c, res);
		if (res >= 0) break;
		
		for(int v = t; v != s; v = prevv[v]){
			edge &e = g[prevv[v]][preve[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
	}
 
	return c;
}
