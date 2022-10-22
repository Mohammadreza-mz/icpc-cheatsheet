const ll INF=(ll)1e18+10,M=2e5+137,T= 4;
const ll bas[]= {31, 53, 727, 727};
const ll mod[]= {(ll)1e9+7, (ll)1e9+9, (ll)1e9+7, (ll)1e9+9};
ll pw[T][M],hs[T][M],n;
ll substr(int t, int l, int r){
	return (hs[t][r] -(hs[t][l-1]* pw[t][r-l+1]%mod[t]) + mod[t])%mod[t];
}
string s;
int lcp(int x, int y){
	int l= 1, r=n, m;
	if(s[x-1] != s[y-1])
		return 0;
	
	bool is=1;
	while(l<r){
		m=(l+r+1)/2;
		is=1;
		for(int i=0;i<T;i++){
			if(substr(i, x,x+m-1) != substr(i, y,y+m-1))
				is=0;
		}
		if(is)
			l=m;
		else
			r= m-1;
	}
	return l;
}

bool cmp(int x, int y){
	int l= lcp(x,y);
	if(l==n)
		return 0;
	return s[x-1+l]<s[y-1+l];
}
void minimum_cyclic_shift(){
	n= s.size();
	s= s+s;
	for(int i=0;i<T;i++)
		pw[i][0]= 1;
		
	//hs[0][0]= hs[1][0]= 0;
	for(int i=1;i<=2*n;i++){
		for(int j=0;j<T;j++){
			pw[j][i]= pw[j][i-1]*bas[j]%mod[j];
			hs[j][i]= (hs[j][i-1]*bas[j]+(s[i-1]-'a'+1)) %mod[j];
		}
	}	
	int mi=1;
	for(int i=2;i<=n;i++){
		if(cmp(i,mi))
			mi=i;
	}
	for(int i=mi-1;i<mi-1+n;i++)
		cout<<s[i];
}
