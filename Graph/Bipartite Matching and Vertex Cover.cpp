//Bipartite Matching is O(M * N)
#define M 128
#define N 128
bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int n, m;
bool bpm( int u )
{
    for( int v = 0; v < n; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;
		
        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
vector<int> vertex_cover()
{
	// Comment : Vertices on the left side (n side) are labeled like this : m+i where i is the index
	set<int> s, t, um; // um = UnMarked
	vector<int> vc;
	for(int i = 0; i < m; i++)
		if(matchL[i]==-1)
			s.insert(i), um.insert(i);
	while( um.size() )
	{
		int v = *(um.begin());
		for(int i = 0; i < n; i++)
			if( graph[v][i] && matchL[v]!=i)
			{
				t.insert(i);
				if( s.find(matchR[i]) == s.end())
					s.insert(matchR[i]), um.insert(matchR[i]);
			}
		um.erase(v);
	}
	for(int i = 0; i < m; i++)
		if( s.find(i) == s.end() )
			vc.push_back(i);
	for(set<int>::iterator i = t.begin(); i != t.end(); i++)
		vc.push_back((*i) + m);
	return vc;
}
int main()
{
    // Read input and populate graph[][]
    // Set m, n
    memset( matchL, -1, sizeof( matchL ) );
    memset( matchR, -1, sizeof( matchR ) );
    int cnt = 0;
    for( int i = 0; i < m; i++ )
    {
        memset( seen, 0, sizeof( seen ) );
        if( bpm( i ) ) cnt++;
    }
    vector<int> vc = vertex_cover();
    // cnt contains the number of happy pigeons
    // matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
    // matchR[j] contains the pigeon in hole j or -1 if hole j is empty
    // vc contains the Vertex Cover
    return 0;
}