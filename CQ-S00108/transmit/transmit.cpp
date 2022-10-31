#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool ST;
const int N=2e5+10;
int n,q,k,val[N];
int head[N],to[N<<1],nxt[N<<1],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
int ed;
int stk[N],tp;
int a[N],l;
void dfs(int u,int f){
	stk[++tp]=u;
	if(u==ed){l=tp;For(i,1,l)a[i]=stk[i];}
	go(u){
		int v=to[i];if(v!=f)dfs(v,u);
	}
	tp--;
}
int mn[N][3];
int f[N][3];
queue<int> Q;
int d[N];
void bfs(int *mn,int s){
	Q.push(s);memset(d,0x3f,sizeof d);
	For(i,0,k-1)mn[i]=1e18;
	d[s]=0,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		mn[d[u]]=min(mn[d[u]],val[u]);
		if(d[u]+1==k)continue;
		go(u){
			int v=to[i];if(d[v]>d[u]+1){
				d[v]=d[u]+1,Q.push(v);
			}
		}
	}For(i,1,k-1)mn[i]=min(mn[i],mn[i-1]);
}
const int LG=18;
int fa[LG][N],dep[N],sum[N];
void DFS(int u,int f){
	dep[u]=dep[f]+1,sum[u]=sum[f]+val[u];
	fa[0][u]=f;For(i,1,LG-1)fa[i][u]=fa[i-1][fa[i-1][u]];
	int x=u;For(i,0,k-1){
		mn[x][i]=min(mn[x][i],val[u]);
		x=fa[0][x];
	}
	go(u){int v=to[i];if(v!=f)DFS(v,u);}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	Rof(i,LG-1,0)if(dep[fa[i][x]]>=dep[y])x=fa[i][x];
	if(x==y)return x;
	Rof(i,LG-1,0)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int dis(int x,int y){
	int l=lca(x,y);
	return sum[x]+sum[y]-sum[l]-sum[fa[0][l]];
}
signed k1main(){
	while(q--){
		int u=read(),v=read();
		printf("%lld\n",dis(u,v));
	}
	return 0;
}
int tt[N],o;
void calc(int u,int f){
	For(j,1,k-1)mn[u][j]=min(mn[u][j],mn[f][j-1]);
	For(j,1,k-1)mn[u][j]=min(mn[u][j],mn[u][j-1]);
	go(u){
		int v=to[i];if(v!=f)calc(v,u);
	}
}
bool ED;
signed main(){
//	fprintf(stderr,"%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),k=read();
	For(i,1,n)val[i]=read();
	For(i,2,n){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	memset(mn,0x3f,sizeof mn);
	DFS(1,0);
	if(k==1)return k1main();
	For(i,1,n)For(j,1,k-1)mn[i][j]=min(mn[i][j],mn[i][j-1]);
	calc(1,0);
//	For(i,1,n)bfs(mn[i],i);
//	return 0;
	while(q--){
		int s=read(),t=read(),L=lca(s,t);
		l=0,o=0;while(s!=L)a[++l]=s,s=fa[0][s];
		a[++l]=s;while(t!=L)tt[++o]=t,t=fa[0][t];
		while(o)a[++l]=tt[o--];
//		ed=t,dfs(s,0);
//		For(i,1,l)printf("%d ",a[i]);puts("");
		For(i,1,l)For(j,0,k-1)f[i][j]=1e18;
		f[1][0]=val[a[1]];
		For(i,2,l){
			Rof(j,i-1,max(1ll,i-k)){
				For(k1,0,k-(i-j))For(k2,0,k-(i-j)-k1){
					assert(k1+k2+(i-j)<=k);
					f[i][k1]=min(f[i][k1],f[j][k2]);
				}
			}For(k1,0,k-1)f[i][k1]+=mn[a[i]][k1];
		}printf("%lld\n",f[l][0]);
//		For(i,1,l)For(k1,0,k-1)printf("f[%d][%d] = %lld\n",i,k1,f[i][k1]);
	}
	return 0;
}

