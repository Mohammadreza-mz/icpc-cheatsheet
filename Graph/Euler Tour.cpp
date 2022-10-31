//Directed Euler Tour­O( E )  
void visit (Graph& g, int a , vector<int>& path) {   
	while (!g[a].empty()){    
		int b = g[a].back().dst;     
		g[a].pop_back();     
		visit (g, b, path);   
	}   
	path.push_back (a); 
} 
bool eulerPath (Graph g, int s , vector<int> &path) {  
	int n = g.size(), m = 0;   
	vector<int> deg (n);   
	REP (u , n) {     
		m += g[u].size();     
  FOR (e , g[u]) --deg[e->dst]; //  in-deg     
  deg[u] += g[u].size();      // out-deg   
}   
int k = n - count (ALL (deg), 0);   
if (k == 0 || (k == 2 && deg[s] == 1)) {     
	path.clear();     
	visit (g, s , path);     
	reverse (ALL (path));     
	return path.size () == m + 1;  
}   
return false; 
} 
//Undirected Euler Tour­O( E )  
void visit(const Graph &g, vector< vector<int> > &adj, int s, vector<int> &path) {
	FOR (e , g[s]) 
	if (adj[e->src][e->dst]) {     
		--adj[e->src][e->dst];    
		--adj[e->dst][e->src];     
		visit(g, adj, e->dst , path);  
	}   
	path.push_back(s);
} 
bool eulerPath (const Graph &g, int s , vector<int> &path)
{   
	int n = g.size(); 
	int odd = 0, m = 0;
	REP (i, n) {
		if (g[i].size() % 2 == 1) 
			++odd;
		m += g[i].size();   
	}   
	m/= 2;   
	if (odd == 0 || (odd == 2 && g[s].size() % 2 == 0)) 
	{    
		vector< vector<int> > adj (n , vector<int> (n));   

		REP (u , n) FOR (e , g[u]) ++adj[e->src][e->dst];    
		path.clear ();     
		visit (g, adj, s, path);     
		reverse (ALL (path));    
		return path.size() == m + 1;  
	}  
	return false;
} 