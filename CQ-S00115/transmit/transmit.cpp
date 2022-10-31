#include<bits/stdc++.h>
template<typename G>inline void read(G&x) {G f=1;x=0;char ch=getchar();while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();if(ch=='-') f=-1,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();x*=f;}
template<typename G>inline void write(G x) {if(x<0) putchar('-'),x=-x;if(x>=10) write(x/10);putchar('0'+x%10);}
using namespace std;
#define int long long
const int MAXN=2e5+5;
int head[MAXN],nxt[MAXN*2],to[MAXN*2],cnt,size[MAXN];
int top[MAXN],son[MAXN],siz[MAXN],fa[MAXN],dep[MAXN];
int g[MAXN],f[MAXN],sm[MAXN],ans,a[MAXN];
void add(int u,int v) {
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
	nxt[++cnt]=head[v],head[v]=cnt,to[cnt]=u;
}
void dfs(int p,int las) {
	fa[p]=las,siz[p]=1,dep[p]=dep[las]+1,sm[p]=sm[las]+a[p];
	for(int i=head[p];i;i=nxt[i]) {
		int tmp=to[i];
		if(tmp!=las) {
			dfs(tmp,p);
			siz[p]+=siz[tmp];
		}
	}
}
void bfs(int p,int tp) {
	top[p]=tp,++size[top[p]];
	for(int i=head[p];i;i=nxt[i]) {
		int tmp=to[i];
		if(tmp!=fa[p]&&siz[tmp]>siz[son[p]]) son[p]=tmp;
	}
	if(son[p]) bfs(son[p],tp);
	for(int i=head[p];i;i=nxt[i]) {
		int tmp=to[i];
		if(tmp!=fa[p]&&tmp!=son[p]) {
			bfs(tmp,tmp);
		}
	}
}
int LCA(int x,int y) {
	while(top[x]!=top[y]) {
//		cout<<x<<" "<<y<<" "<<top[x]<<" "<<fa[top[x]]<<" "<<top[y]<<" "<<fa[top[y]]<<" "<<dep[x]<<" "<<dep[y]<<endl;
		while(dep[top[x]]>=dep[top[y]]&&top[x]!=top[y]) {
			x=fa[top[x]];
		}
		while(dep[top[y]]>=dep[top[x]]&&top[x]!=top[y]) {
			y=fa[top[y]];
		}
	}
	if(dep[x]<dep[y]) return x;
	return y;
}
int n,q,h,u,v;
stack<int> stk;
signed main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n),read(q),read(h);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<n;++i) {
		read(u),read(v);add(u,v);
	}
	dfs(1,0),bfs(1,1);
	while(q--) {
		read(u),read(v);
		int lca=LCA(u,v),tot=0;cout<<u<<' '<<v<<" "<<lca<<endl;
		ans=sm[u]+sm[v]-sm[lca];
		if(h==1) {
			printf("%lld\n",ans);
			continue;
		}
		while(u!=lca) {
			u=fa[u];
			g[++tot]=u;
		}
		g[++tot]=lca;
		while(fa[v]!=lca) {
			v=fa[v];
			stk.push(v);
		}
		while(!stk.empty()) {
			g[++tot]=stk.top();
			stk.pop();
		}
		for(int i=1;i<=tot;++i) {
			int sum=0;f[i]=f[i-1];
			for(int j=i-1;j>=max(1ll,i-h+2-(i==h));--j) {
				sum+=a[g[j]];
				f[i]=max(f[i],f[j-1]+sum);
			}
		}
		for(int i=tot-1;i>=max(1ll,tot-h+1);--i) f[tot]=max(f[tot],f[i]);
		printf("%lld\n",ans-f[tot]);
	}
	return 0;
}
//#include<bits/stdc++.h>
//template<typename G>inline void read(G&x) {G f=1;x=0;char ch=getchar();while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();if(ch=='-') f=-1,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();x*=f;}
//template<typename G>inline void write(G x) {if(x<0) putchar('-'),x=-x;if(x>=10) write(x/10);putchar('0'+x%10);}
//using namespace std;
//const int MAXN=2e5+5;
//int head[MAXN],nxt[MAXN*2],to[MAXN*2],cnt,size[MAXN];
//int top[MAXN],son[MAXN],siz[MAXN],fa[MAXN],dep[MAXN];
//int ql[MAXN],qr[MAXN],f[MAXN][3][3],cot,g[MAXN];
//vector<int> qs[MAXN],V,c;
//void add(int u,int v) {
//	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
//	nxt[++cnt]=head[v],head[v]=cnt,to[cnt]=u;
//}
//void dfs(int p,int las) {
//	fa[p]=las,siz[p]=1,dep[p]=dep[las]+1;
//	for(int i=head[p];i;i=nxt[i]) {
//		int tmp=to[i];
//		if(tmp!=las) {
//			dfs(tmp,p);
//			siz[p]+=siz[tmp];
//		}
//	}
//}
//void bfs(int p,int tp) {
//	top[p]=tp,++size[top[p]];
//	for(int i=head[p];i;i=nxt[i]) {
//		int tmp=to[i];
//		if(tmp!=fa[i]&&siz[tmp]>siz[son[p]]) son[p]=tmp;
//	}
//	if(son[p]) bfs(son[p],tp);
//	else c.emplace_back(p);
//	for(int i=head[p];i;i=nxt[i]) {
//		int tmp=to[i];
//		if(tmp!=fa[p]) {
//			bfs(tmp,tmp);
//		}
//	}
//}
//int LCA(int x,int y) {
//	if(dep[x]<dep[y]) swap(x,y);
//	while(top[x]!=top[y]) {
//		while(dep[x]>dep[y]&&top[x]!=top[y]) {
//			x=fa[top[x]];
//		}
//		while(dep[y]<dep[x]&&top[x]!=top[y]) {
//			y=fa[top[y]];
//		}
//	}
//	if(dep[x]<dep[y]) return x;
//	return y;
//}
//int n,q,h,a[MAXN],u,v;
//int main() {
////	freopen("transmit.in","r",stdin);
////	freopen("transmit.out","w",stdout);
//	read(n),read(q),read(h);
//	for(int i=1;i<=n;++i) read(a[i]);
//	for(int i=1;i<n;++i) {
//		read(u),read(v);add(u,v);
//	}
//	dfs(1,0),bfs(1,1);
//	for(auto i:V) {
//		int sqn=sqrt(size[top[i]]),tot=0,now=i;last=top[now];
//		while(top[now]==last) {
//			++tot;c.emplace_back(a[now]);
//			if(tot==sqn) {
//				++cot,--tot;
//				for(int j=0;j<=2;++j) {
//					for(int k=0;k<=2;--k) {
//						for(int t=0;t<j;++t) {
//							f[cot][j][k]+=c[t];
//						}
//						for(int t=0;t<k;++t) {
//							f[cot][j][k]+=c[tot-t];
//						}
//						for(int t=j+1;t<tot-k;++t) {
//							for(int l=t-1;l<t;++l) g[t]=max(g[l])
//							g[t]=
//						}
//					}
//				}
//				tot=0,c.clear();
//			}
//			last=top[now];
//			now=fa[now];
//		}
//		if(!c.empty()) {
//		}
//	}
//	while(q--) {
//		
//	}
//	return 0;
//}

