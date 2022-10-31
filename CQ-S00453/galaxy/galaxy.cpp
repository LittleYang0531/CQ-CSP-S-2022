#include<bits/stdc++.h>
using namespace std;
inline void qr(int&x){
	bool f=(x=0);
	char c;
	while(c=getchar(),!isdigit(c)) f|=c=='-';
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	x=f?-x:x;
}
const int MAXN=5e5+5;
int to[MAXN],nxt[MAXN],hd[MAXN],del[MAXN],cnt;
int out[MAXN];
void ae(int u,int v){
	nxt[++cnt]=hd[v];
	hd[v]=cnt;
	to[cnt]=u;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m,q;
	qr(n),qr(m);
	int tot=0;
	for(int i=1;i<=m;++i){
		int u,v;
		qr(u),qr(v);
		ae(u,v);
		if(out[u]==1) --tot;
		++out[u];
		if(out[u]==1) ++tot;
	}
	qr(q);
	for(int i=1;i<=q;++i){
		int o,u;
		qr(o),qr(u);
		if(o==1){
			int v;
			qr(v); 
			if(out[u]==1) --tot;
			if(out[u]==2) ++tot;
			--out[u];
			for(int p=hd[v];p;p=nxt[p]){
				if(to[p]==u){
					del[p]=1;
					break;
				}
			}
		}
		if(o==3){
			int v;
			qr(v);
			if(out[u]==1) --tot;
			if(out[u]==0) ++tot;
			++out[u];
			for(int p=hd[v];p;p=nxt[p]){
				if(to[p]==u){
					del[p]=0;
					break;
				}
			}
		}
		if(o==2){
			for(int p=hd[u];p;p=nxt[p]){
				if(!del[p]){
					del[p]=1;
					const int&v=to[p];
					--out[v];
					if(out[v]==0) --tot;
					if(out[v]==1) ++tot;
				}
			}
		}
		if(o==4){
			for(int p=hd[u];p;p=nxt[p]){
				if(del[p]){
					del[p]=0;
					const int&v=to[p];
					++out[v];
					if(out[v]==2) --tot;
					if(out[v]==1) ++tot;
				}
			}
		}
		if(tot==n) puts("YES");
		else puts("NO");
	}
}
/*
期望 40pts
容易发现构成内向基环树森林的充要条件就是所有点的出度为1 
直接模拟即可。
不知道怎么优化。 
*/
//luogu:Stream_X
//coded by luogu-Stream_X
