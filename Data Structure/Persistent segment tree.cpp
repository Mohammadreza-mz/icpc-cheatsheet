int n, cnt=0;
ll sum[M], le[M], ri[M], root[M];
void build(int id, int b, int e){
	sum[id]=0;
	if(e-b==1)
		return;
	int m=(b+e)/2;
	le[id]= ++cnt;
	build(le[id], b,m);
	ri[id]= ++cnt;
	build(le[id], m,e);
}

int g(int id, int b, int e, int l, int r){
	if(l<=b && e<=r) return sum[id];
	if(e<=l || r<=b) return 0;
	int m= (b+e)/2;
	return g(le[id], b,m, l,r) + g(ri[id], m,e ,l,r);
}

int upd(int id, int b, int e, int x, int y){
	if(e-b==1){
		sum[++cnt]= y;
		return cnt;
	}
	int m=(b+e)/2, tmp= ++cnt;
	le[tmp]= le[id],ri[tmp]= ri[id];
	if(x<m)
		le[tmp]= upd(le[id], b,m ,x,y);
	else
		ri[tmp]= upd(ri[id], m,e ,x,y);
		
	sum[tmp]= sum[le[tmp]]	+ sum[ri[tmp]];
	return tmp;
}

int main(){
	root[0]= ++cnt;
	build(root[0], 0, n);
	for(int i=0;i<q;i++){
		root[i] = root[i - 1];
		//do ith upd query:
		root[i] = upd(root[i], 0 , n, pos, val);
	}
}