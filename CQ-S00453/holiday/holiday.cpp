#include<bits/stdc++.h>
using namespace std;
template<class T>inline void qr(T&x){
	bool f=(x=0);
	char c;
	while(c=getchar(),!isdigit(c)) f|=c=='-';
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	x=f?-x:x;
}
const int MAXN=2505;
#define ll long long
vector<int>G[MAXN];
int dis[MAXN][MAXN];
ll s[MAXN];
queue<pair<int,int> >q;
void bfs(int S){
	q.push({S,-1});
	dis[S][S]=0;
	while(q.size()){
		int x=q.front().first,t=q.front().second;
		q.pop();
		for(int&y:G[x]){
			if(dis[S][y]==-1){
				dis[S][y]=t+1;
				q.push({y,t+1});
			}
		}
	}
}
inline int max(const int&x,const int&y){return x>y?x:y;}
ll pos[MAXN][MAXN],pre[MAXN][MAXN],suf[MAXN][MAXN],cpre[MAXN][MAXN],csuf[MAXN][MAXN];
int ipre[MAXN][MAXN],isuf[MAXN][MAXN];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(dis,-1,sizeof dis);
	memset(pos,-1,sizeof pos);
	int n,m,k;
	qr(n),qr(m),qr(k);
	for(int i=2;i<=n;++i) qr(s[i]);
	for(int i=1;i<=m;++i){
		int u,v;
		qr(u),qr(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i) bfs(i);
	for(int i=2;i<=n;++i){
		if(dis[1][i]<=k){
			for(int j=2;j<=n;++j){
				if(j==i) continue;
				if(dis[i][j]>k) continue;
				pos[j][i]=max(pos[j][i],s[i]+s[j]);
			}
		}
	}
	for(int i=2;i<=n;++i){
		pre[i][1]=cpre[i][1]=-1;
		for(int j=2;j<=n;++j){
			if(pos[i][j]>=pre[i][j-1]){
				pre[i][j]=pos[i][j];
				ipre[i][j]=j;
				cpre[i][j]=pre[i][j-1];
			}
			else{
				pre[i][j]=pre[i][j-1];
				ipre[i][j]=ipre[i][j-1];
				cpre[i][j]=max(cpre[i][j-1],pos[i][j]);
			}
		}
		suf[i][n+1]=csuf[i][n+1]=-1;
		for(int j=n;j>=2;--j){
			if(pos[i][j]>=suf[i][j+1]){
				suf[i][j]=pos[i][j];
				isuf[i][j]=j;
				csuf[i][j]=suf[i][j+1];
			}
			else{
				suf[i][j]=suf[i][j+1];
				isuf[i][j]=isuf[i][j+1];
				csuf[i][j]=max(csuf[i][j-1],pos[i][j]);
			}
		}
	}
	ll ans=0;
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			if(i==j) continue;
			if(dis[i][j]>k) continue;
			if(pre[i][j-1]==-1&&suf[i][j+1]==-1) continue;
			if(pre[j][i-1]==-1&&suf[j][i+1]==-1) continue;
			ll l=max(pre[i][j-1],suf[i][j+1]);
			ll r=max(pre[j][i-1],suf[j][i+1]);
			ll cl=(l==pre[i][j-1]?max(cpre[i][j-1],suf[i][j+1]):max(csuf[i][j+1],pre[i][j-1]));
			ll cr=(r==pre[j][i-1]?max(cpre[j][i-1],suf[j][i+1]):max(csuf[j][i+1],pre[j][i-1]));
			int il=(l==pre[i][j-1]?ipre[i][j-1]:isuf[i][j+1]);
			int ir=(r==pre[j][i-1]?ipre[j][i-1]:isuf[j][i+1]); 
			if(l==cl||r==cr||il!=ir) ans=max(ans,l+r);
			else ans=max(ans,max(l+cr,r+cl));
		}
	}
	cout<<ans;
}
/*
期望 100pts
懒得写了。 
*/
//written by luogu-Stream_X
//coded by luogu-Stream_X
