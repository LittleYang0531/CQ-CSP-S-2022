#include<bits/stdc++.h>
template<typename G>inline void read(G&x) {G f=1;x=0;char ch=getchar();while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();if(ch=='-') f=-1,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();x*=f;}
template<typename G>inline void write(G x) {if(x<0) putchar('-'),x=-x;if(x>=10) write(x/10);putchar('0'+x%10);}
using namespace std;
const int MAXN=1e3+5,MAXM=1e4+5;
int head[MAXN],nxt[MAXM],to[MAXM],siz[MAXN],niz[MAXN],cnt;
bool vis[MAXN][MAXN],got[MAXN][MAXN];
int f[MAXN],num;
void add(int u,int v) {
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,++siz[u],++niz[u];
}
void dfs(int p) {
	if(!f[p]) f[p]=1;
	else {
		if(f[p]!=2) ++num;
		f[p]=2;
		return;
	}
	for(int i=head[p];i;i=nxt[i]) {
		int tmp=to[i];
		if(vis[p][tmp]) continue;
		dfs(tmp);
		if(f[tmp]==2) {
			if(f[p]!=2) ++num;
			f[p]=2;
			return;
		}
	}
}
int n,m,q,u,v,op;
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;++i) {
		read(u),read(v);got[u][v]=1;
		add(u,v);
	}
	read(q);
	while(q--) {
		read(op);
		if(op==1) {
			read(u),read(v);
			vis[u][v]=1,--niz[u];
		}
		if(op==2) {
			read(u);
			for(int j=1;j<=n;++j) {
				if(!vis[j][u]&&got[j][u]) --niz[j];
				vis[j][u]=1;
			}
		}
		if(op==3) {
			read(u),read(v);
			vis[u][v]=0,++niz[u];
		}
		if(op==4) {
			read(u);
			for(int j=1;j<=n;++j) {
				if(vis[j][u]&&got[j][u]) ++niz[j];
				vis[j][u]=0;
			}
		}num=0;
		for(int j=1;j<=n;++j) {
			f[j]=0;
			if(niz[j]!=1) {
				puts("NO");
				goto end;
			}
		}
		for(int i=1;i<=n;++i) dfs(i);
		if(num==n) puts("YES");
		else puts("NO");
		end:;
	}
	return 0;
}

