#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map> 
#include<iostream>
#include<algorithm>
#include<bitset>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define LL long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int dec(int x,int y){
	return x-y<0?x-y+mod:x-y; 
}
inline int qkpow(int a,int b){
	int res=1,base=a;
	while(b){
		if(b&1)res=1ll*res*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return res;
}
int n,q,lim,a[200005],dep[200005],top[200005],son[200005],fa[200005],sz[200005];
int seg[200005],rev[200005];
LL sum[200005];
vector<int>G[200005];
void dfs1(int u,int ff){
	fa[u]=ff;
	sz[u]=1;
	dep[u]=dep[ff]+1;
	sum[u]=sum[ff]+a[u]; 
	for(auto v:G[u]){
		if(v==ff)continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void dfs2(int u,int ff){
	if(son[u]){
		top[son[u]]=top[u];
		seg[son[u]]=++seg[0];
		rev[seg[0]]=son[u];
		dfs2(son[u],u);
	}
	for(auto v:G[u]){
		if(v==ff||v==son[u])continue;
		top[v]=v;
		seg[v]=++seg[0];
		rev[seg[0]]=v;
		dfs2(v,u);
	}
}
int LCA(int u,int v){
	if(u==v)return u;
	int fu=top[u],fv=top[v];
	while(fu!=fv){
		if(dep[fu]>dep[fv])u=fa[fu];
		else v=fa[fv];
		fu=top[u],fv=top[v];
	}
	if(dep[u]<dep[v])return u;
	return v;
}
#define pp pair<int,int>
const LL INF=-1e18;
const LL INF2=1e18;
struct Mat{
	LL a[2][2];
	void init(){
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				a[i][j]=INF;
	}
}s1[800005],s2[800005],Res;
Mat MUL(Mat A,Mat B){
	Mat C;
	C.init();
	for(int i=0;i<=1;i++)
		for(int k=0;k<=1;k++)
			if(A.a[i][k]!=INF)
				for(int j=0;j<=1;j++)
					C.a[i][j]=max(C.a[i][j],A.a[i][k]+B.a[k][j]);
	return C;
}
#define ls(p) p<<1
#define rs(p) p<<1|1
void build(int p,int l,int r){
	if(l==r){
		s1[p].a[0][0]=INF;
		s1[p].a[1][0]=a[rev[l]];
		s1[p].a[0][1]=s1[p].a[1][1]=0;
		s2[p]=s1[p];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	s1[p]=MUL(s1[ls(p)],s1[rs(p)]);
	s2[p]=MUL(s2[rs(p)],s2[ls(p)]);
}
void query1(int p,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		Res=MUL(Res,s1[p]);
		return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid)query1(ls(p),l,mid,L,R);
	if(mid+1<=R)query1(rs(p),mid+1,r,L,R);
}
void query2(int p,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		Res=MUL(Res,s2[p]);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid+1<=R)query2(rs(p),mid+1,r,L,R);
	if(L<=mid)query2(ls(p),l,mid,L,R);
}
vector<pp>buc1,buc2;
LL calc(int s,int t){
	Res.init();
	Res.a[0][1]=0;
	int u=s,v=t;
	int fu=top[u],fv=top[v];
	buc1.clear(),buc2.clear();
	while(fu!=fv){
		if(dep[fu]>dep[fv]){
			buc1.push_back(pp(seg[fu],seg[u])),u=fa[fu];
		}
		else {
			buc2.push_back(pp(seg[fv],seg[v])),v=fa[fv];
		}
		fu=top[u],fv=top[v];
	}
	if(dep[u]>dep[v]){
		buc1.push_back(pp(seg[v],seg[u]));
	}
	else {
		buc2.push_back(pp(seg[u],seg[v]));
	}
	reverse(buc2.begin(),buc2.end());
	for(int i=0;i<(int)buc1.size();i++){
		int l=buc1[i].first,r=buc1[i].second;
		if(l==seg[s]||l==seg[t])l++;
		if(r==seg[t]||r==seg[s])r--;
		if(l<=r)query2(1,1,n,l,r);
	} 
	for(int i=0;i<(int)buc2.size();i++){
		int l=buc2[i].first,r=buc2[i].second;
		if(l==seg[s]||l==seg[t])l++;
		if(r==seg[t]||r==seg[s])r--;
		if(l<=r)query1(1,1,n,l,r);
	} 
	return max(Res.a[0][0],Res.a[0][1]);
}
bool vis[200005];
vector<int>b1,b2;
LL dp[200005][2],excost[200005],excost2[200005];
bool cmp(int x,int y){
	return a[x]<a[y];
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),lim=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end(),cmp);
	seg[0]=seg[1]=1;
	rev[1]=1,top[1]=1;
	dfs1(1,0);
	dfs2(1,0);
	if(lim==2)
		build(1,1,seg[0]);
	else if(lim==3)
		for(int i=1;i<=n;i++)excost2[i]=a[G[i][0]];
	while(q--){
		int s,t;
		s=read(),t=read();
		if(lim==1){
			int lca=LCA(s,t);
			printf("%lld\n",sum[s]+sum[t]-sum[lca]-sum[fa[lca]]);
		}else if(lim==2){
			int lca=LCA(s,t);
			LL tot=sum[s]+sum[t]-sum[lca]-sum[fa[lca]];
			printf("%lld\n",tot-calc(s,t));
		}else if(n<=100000){
			int u=s,v=t;
			int lca=LCA(s,t);
			b1.clear(),b2.clear();
			while(u!=lca){
				b1.push_back(u);
				vis[u]=1;
				u=fa[u];
			}
			b1.push_back(lca);
			vis[lca]=1;
			while(v!=lca){
				b2.push_back(v);
				vis[v]=1;
				v=fa[v];
			}
			reverse(b2.begin(),b2.end());
			for(int i=0;i<(int)b2.size();i++)b1.push_back(b2[i]);
			int len=b1.size();
			for(int i=0;i<len;i++)dp[i][0]=dp[i][1]=INF2;
			dp[0][0]=a[b1[0]];
			for(int i=0;i<len;i++){
				excost[i]=INF2;
				int po=b1[i];
				for(int j=0;j<(int)G[po].size();j++){
					int to=G[po][j];
					if(i>=1&&to==b1[i-1])continue;
					if(i<len-1&&to==b1[i+1])continue;
					excost[i]=a[to];
					break;
				}
			}
			for(int i=0;i<len-1;i++){
				if(i+1<len){
					dp[i+1][0]=min(dp[i+1][0],dp[i][0]+a[b1[i+1]]);
					dp[i+1][1]=min(dp[i+1][1],dp[i][0]+excost[i+1]);	
					dp[i+1][0]=min(dp[i+1][0],dp[i][1]+a[b1[i+1]]);
					dp[i+1][1]=min(dp[i+1][1],dp[i][1]+excost[i+1]);	
				}
				if(i+2<len){
					dp[i+2][0]=min(dp[i+2][0],dp[i][0]+a[b1[i+2]]);
					dp[i+2][1]=min(dp[i+2][1],dp[i][0]+excost[i+2]);
					dp[i+2][0]=min(dp[i+2][0],dp[i][1]+a[b1[i+2]]);	
				}
				if(i+3<len)dp[i+3][0]=min(dp[i+3][0],dp[i][0]+a[b1[i+3]]);
			}
			printf("%lld\n",dp[len-1][0]); 
		}
	}
	return 0;
}
/*
939363946

10 10 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9

10 5
*/
