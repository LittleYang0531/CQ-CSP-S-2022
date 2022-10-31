#include <bits/stdc++.h>
using namespace std;
bool lmg;
int read() {
	int x(0),f(0);
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int N=500005;
int n,m,q,cur,hed[N],from[N],to[N],nxt[N],use[N];
void add(int x,int y) {
	to[++cur]=y,from[cur]=x,use[cur]=1,nxt[cur]=hed[x],hed[x]=cur;
}
vector<int> g[N];
map<int,int> mp[N];
int t[N],tot;
bool oat;
signed main() {
//	cerr<<(&lmg-&oat)/1024.0/1024.0<<endl;
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i) {
		int x=read(),y=read();
		add(x,y);
		g[y].push_back(cur);
		mp[x][y]=cur;
		++t[x];
	}
	for(int i=1;i<=n;++i) if(t[i]==1) ++tot;
	q=read();
	while(q--) {
		int op=read(),u=read();
		if(op==1) {
			int v=read();
			int i=mp[u][v];
			if(i&&use[i]) {
				use[i]=0,--t[u];
				if(t[u]==1) ++tot;
				if(t[u]==0) --tot;
			}
		}
		if(op==2) {
			for(int i:g[u])
				if(use[i]) {
					use[i]=0,--t[from[i]];
					if(t[from[i]]==1) ++tot;
					if(t[from[i]]==0) --tot;
				}
		}
		if(op==3) {
			int v=read();
			int i=mp[u][v];
			if(i&&!use[i]) {
				use[i]=1,++t[u];
				if(t[u]==1) ++tot;
				if(t[u]==2) --tot;
			}
		}
		if(op==4) {
			for(int i:g[u]) 
				if(!use[i]) {
					use[i]=1,++t[from[i]];
					if(t[from[i]]==1) ++tot;
					if(t[from[i]]==2) --tot;
				}
		}
		if(tot==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2

NO
NO
YES
NO
YES
NO
NO
NO
YES
NO
NO
*/
