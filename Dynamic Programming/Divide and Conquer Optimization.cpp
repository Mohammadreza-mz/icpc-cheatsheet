// Divide and Conquer Optimization
// dp[i][j] = mink < j{dp[i - 1][k] + C[k][j]} A[i][j] ≤ A[i][j + 1] 
// A[i][j] — the smallest k that gives optimal answer, for example in dp[i][j] = dp[i - 1][k] + C[k][j]
// C[i][j] — some given cost function

int n , k , sum[N][N] , dp[K][N] ;
 
void calc(int ind,int l,int r,int opl,int opr)
{
	if(l>r) return;
	int m=(l+r)/2,op,res=1e9;
	for(int i=min(opr,m);i>=opl;i--)
	{
		int ret=dp[ind-1][i-1]+sum[m][m]+sum[i-1][i-1]-sum[i-1][m]-sum[m][i-1];
		if(res>=ret)
			res=ret,op=i;
	}
	dp[ind][m]=res;
	if(l==r)
		return;
	calc(ind,l,m-1,opl,op);
	calc(ind,m+1,r,op,opr);
}
