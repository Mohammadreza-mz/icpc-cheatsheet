const ll M=2e5+137,T= 4;
const ll bas[]= {31, 53, 727, 727};
const ll mod[]= {(ll)1e9+7, (ll)1e9+9, (ll)1e9+7, (ll)1e9+9};
ll pw[T][M],hs[T][M],n;
ll substr(int t, int l, int r){
	return (hs[t][r] -(hs[t][l-1]* pw[t][r-l+1]%mod[t]) + mod[t])%mod[t];
}
string s;

bool cmp(int l1, int l2, int sz){
	for(int i=0;i<T;i++)
		if(substr(i, l1,l1+sz-1) != substr(i, l2,l2+sz-1))
			return 0;
	return 1;
}

int lcp(int x, int y){
	int l= 1, r=n, m;
	if(s[x-1] != s[y-1])
		return 0;
	
	bool is=1;
	while(l<r){
		m=(l+r+1)/2;
		is= cmp(x,y,m);
		if(is)
			l=m;
		else
			r= m-1;
	}
	return l;
}

bool lcp_cmp(int x, int y){
	int l= lcp(x,y);
	if(l==n)
		return 0;
	return s[x-1+l]<s[y-1+l];
}

void calc_hash(string &str){
	for(int i=0;i<T;i++)
		pw[i][0]= 1;
		
	//hs[0][0]= hs[1][0]= 0;
	for(int i=1;i<=str.size();i++){
		for(int j=0;j<T;j++){
			pw[j][i]= pw[j][i-1]*bas[j]%mod[j];
			hs[j][i]= (hs[j][i-1]*bas[j]+(str[i-1]-'a'+1)) %mod[j];
		}
	}
}

void minimum_cyclic_shift(){
	n= s.size();
	s= s+s;
	calc_hash(s);
	int mi=1;
	for(int i=2;i<=n;i++){
		if(lcp_cmp(i,mi))
			mi=i;
	}
	for(int i=mi-1;i<mi-1+n;i++)
		cout<<s[i];
}
