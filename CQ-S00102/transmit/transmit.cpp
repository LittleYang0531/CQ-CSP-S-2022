#include<bits/stdc++.h>
#define ll long long
#define N 200000
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

inline int read(){
	int s=0;char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s;
}

inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

int n,Q,k;
int v[N+100];
vector<int> a[N+100];

struct node{int x,y,lca;}ask[N+100];

ll sum[N+100];
int dep[N+100],siz[N+100];
int f[N+100],son[N+100];
void dfs1(int x,int fa){
	siz[x]=1,dep[x]=dep[fa]+1,f[x]=fa;
	sum[x]=sum[fa]+v[x];
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];if(y==fa) continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y; 
	}
}
int dfn[N+100],cnt,top[N+100];
void dfs2(int x,int t){
	top[x]=t,dfn[x]=++cnt;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(y==f[x]||y==son[x]) continue;
		dfs2(y,y);
	}
}
int Lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}


int b[N+100][5];
void dfs(int x,int fa,int rt,int d){
	if(d>k) return;
	if(!b[rt][d]||v[x]<v[b[rt][d]]) b[rt][d]=x;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];if(y==fa) continue;
		dfs(y,x,rt,d+1);
	}
}


int stk1[N+100],top1;
int stk2[N+100],top2;
ll dp[N+100][5];

int main(){

	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);

	n=read(),Q=read(),k=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++) {
		int x=read(),y=read();
		a[x].push_back(y),a[y].push_back(x);
	}
	
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=Q;i++){
		int x=read(),y=read();
		ask[i]=(node){x,y,Lca(x,y)};
	}
	
	if(k==1){
		for(int i=1;i<=Q;i++){
			int x=ask[i].x,y=ask[i].y,lca=ask[i].lca;
			write(sum[x]+sum[y]-sum[lca]-sum[lca]+v[lca]),puts("");
		}
		return 0;
	}

//	if(n<=2000&&Q<=2000){
		for(int i=1;i<=n;i++) dfs(i,i,i,0);
		for(int t=1;t<=Q;t++){
			int x=ask[t].x,y=ask[t].y,lca=ask[t].lca;
			
			top1=top2=0;
			while(x!=lca) stk1[++top1]=x,x=f[x];
			stk1[++top1]=lca;
			while(y!=lca) stk2[++top2]=y,y=f[y];
			for(int i=top2;i>=1;i--)
				stk1[++top1]=stk2[i];
			
			for(int i=1;i<=top1;i++) 
				for(int j=0;j<=k;j++)
					dp[i][j]=inf;

			dp[top1][0]=v[stk1[top1]];
			for(int i=top1-1;i>=1;i--){
				int x=stk1[i];
				for(int j=i+1;j<=min(i+k,top1);j++){
					for(int l=0;l<=k;l++){
						for(int r=0;r<=k;r++){
							if(l+r+(j-i)>k) break;
							dp[i][l]=min(dp[i][l],dp[j][r]+v[b[x][l]]);
						}
					}
				}
			}
			write(dp[1][0]),puts("");
		}
		return 0;
//	}

	return 0;
}

