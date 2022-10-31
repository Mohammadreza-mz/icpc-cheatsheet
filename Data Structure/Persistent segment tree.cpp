// ask: find  a[l] +  a[l+1]  + a[l+2] +...+ a[r]  After the i th update query online
// update:  a[p]+= v

// ir = 0 which is its index in the initial segment tree Also you should have a NEXT_FREE_INDEX = 1 which is always the next free index for a node.
void build(int id = ir,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	L[id] = NEXT_FREE_INDEX ++;
	R[id] = NEXT_FREE_INDEX ++;
	build(L[id], l, mid);
	build(R[id], mid, r);
	s[id] = s[L[id]] + s[R[id]];
}

// Update function : (its return value, is the index of the interval in the new version of segment tree and id is the index of old one)
int upd(int p, int v,int id,int l = 0,int r = n){
	int ID =  NEXT_FREE_INDEX ++; // index of the node in new version of segment tree
	if(r - l < 2){
		s[ID] = (a[p] += v);
		return ID;
	}
	int mid = (l+r)/2;
	L[ID] = L[id], R[ID] = R[id]; // in case of not updating the interval of left child or right child
	if(p < mid)
		L[ID] = upd(p, v, L[ID], l, mid);
	else
		R[ID] = upd(p, v, R[ID], mid, r);
	return ID;
}

// (For the first query (with index 0) we should run root[0] = upd(p,  v,  ir)
// and for the rest of them, for j - th query se should run root[j] = upd(p,  v,  root[j - 1]) )
int sum(int x,int y,int id,int l = 0,int r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return sum(x, y, L[id], l, mid) +
	       sum(x, y, R[id], mid, r);
}

// (So, we should print the value of sum(x, y, root[i]) )