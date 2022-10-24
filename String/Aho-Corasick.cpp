const int M=2e5+137;//M is total length of strings
int nxt[26][M], cnt=1, last[M], label[M], f[M];
//ind is string number
void add(string &s, int ind){
	int x=1;
	for(char c: s){
		if(!nxt[c-'a'][x])
			nxt[c-'a'][x] = ++cnt;
		x= nxt[c-'a'][x];
	}
	label[x]= ind;
}
 
void bfs(){
	queue<int> q;
	last[1]=1;
	f[1]=1;
	
	for(int c=0;c<26;c++){
		if(!nxt[c][1])
			nxt[c][1] = 1;
		else{
			f[nxt[c][1]]= 1;
			q.push(nxt[c][1]);
		}
	}
	
	while(q.size()){
		int v = q.front();
		q.pop();
		if(label[f[v]])
			last[v]= f[v];
		else
			last[v]= last[f[v]];
		for(int c=0;c<26;c++){
			if(!nxt[c][v])
				nxt[c][v] = nxt[c][f[v]];
			else{
				f[nxt[c][v]]= nxt[c][f[v]];
				q.push(nxt[c][v]);
			}
		}
	}
}