#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	bool SF=false;int XF=0;char CH=getchar();
	for(;CH<'0'||CH>'9';CH=getchar()) if(CH=='-') SF=true;
	for(;CH>='0'&&CH<='9';CH=getchar()) XF=(XF<<3)+(XF<<1)+(CH-'0');
	if(SF) XF=-XF; return XF;
}
inline LL readl(){
	bool SF=false;LL XF=0;char CH=getchar();
	for(;CH<'0'||CH>'9';CH=getchar()) if(CH=='-') SF=true;
	for(;CH>='0'&&CH<='9';CH=getchar()) XF=(XF<<3)+(XF<<1)+(CH-'0');
	if(SF) XF=-XF; return XF;
}
int N,Q,K;
LL n[200005];
struct E{
	int v,nxt;
}e[200005];
int cnt,head[200005];
inline void adde(int u,int v){
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int fa[200005][18];
LL dis[200005];
int d[200005];
inline void dfs(int now,int FA){
	fa[now][0]=FA;
	dis[now]=dis[FA]+n[now];
	for(int i=head[now];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==FA) continue;
		d[v]=d[now]+1;
		dfs(v,now);
	}
}
inline int lca(int u,int v){
	if(u==v) return v;
	if(d[u]>d[v]){
		swap(u,v);
	}
	if(d[u]!=d[v]){
		for(int i=17;i>=0;i--){
			if(d[fa[v][i]]>d[u]){
				v=fa[v][i];
			}
		}
		v=fa[v][0];
	}
	if(u==v) return u;
	for(int i=17;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	N=read();
	Q=read();
	K=read();
	for(int i=1;i<=N;i++){
		n[i]=readl();
	}
	int aa,bb;
	for(int i=1;i<N;i++){
		aa=read();
		bb=read();
		adde(aa,bb);
		adde(bb,aa);
	}
	dfs(1,0);
	for(int i=1;i<=17;i++){
		for(int j=2;j<=N;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	if(K==1){
		int s,t,ll;
		for(int i=1;i<=Q;i++)
		{
			s=read();
			t=read();
			ll=lca(s,t);
			printf("%lld\n",dis[s]+dis[t]-dis[ll]-dis[fa[ll][0]]);
		}
	}
	return 0;
}
