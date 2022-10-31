//minimum cyclic shift using O(nlogn) suffix array
const int M=2e5+137,ML=18;
int n,lev,rnk[ML][M],ord[M];

bool cmp(int x, int y){
	if(rnk[lev][x] != rnk[lev][y])
		return rnk[lev][x] < rnk[lev][y];
	return rnk[lev][(x+(1<<lev))%n] < rnk[lev][(y+(1<<lev))%n];
}

int lcp(int i, int j){
	//lcp i,i+1,...n-1 and j,j+1,...,n-1
	if(j<i)
		swap(i,j);
	int ans=0;
	for(int k=ML-1;k>=0;k--){
		//for cyclic check ans<=n and use mod for i and j
		if((1<<k)+j <= n && rnk[k][i]==rnk[k][j]){
			ans+= (1<<k);
			i+= (1<<k);
			j+= (1<<k);
			if(j==n)
				return ans;
		}
	}
	return ans;
}

vector<int> radix[2][M];
string minimum_cyclic_shift(string s){
	//to make non cyclic: s+="$" $ is smaller than most of characters
	n= s.size();
	for(int i=0;i<n;i++)
		//-'$'
		radix[0][s[i]-'a'].pb(i);
		
	int cnt=0,tmp=0;
	//i<127
	for(int i=0;i<26;i++){
		for(int u:radix[0][i])
			rnk[0][u] = cnt, ord[tmp++]= u;
		
		cnt+= radix[0][i].size();
		radix[0][i].clear();
	}
	
	for(int j=1;j<ML;j++){
		lev=j-1;
		
		for(int i=0;i<n;i++)
			radix[0][rnk[lev][(i+(1<<lev))%n]].pb(i);
		for(int i=0;i<n;i++){
			for(int u:radix[0][i])
				radix[1][rnk[lev][u]].pb(u);
			radix[0][i].clear();
		}
		
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int u:radix[1][i])
				ord[cnt++]= u;
			radix[1][i].clear();
		}
		
		rnk[j][ord[0]]= 0;
		for(int i=1;i<n;i++){
			if(!cmp(ord[i-1],ord[i]))
				rnk[j][ord[i]] = rnk[j][ord[i-1]];
			else
				rnk[j][ord[i]] = i;
		}
	}
	
    string ans;
    ans.resize(n);
	for(int i=0;i<n;i++)
        ans[i]=s[(i+ord[0])%n];
    return ans;
}
