#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
inline int read(){
	char ch=' ';int x=0,f=1;
	while((ch<'0'||ch>'9')&&ch!='-'){ch=getchar();}
	if(ch=='-'){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f; 
}
const int N=2e5+5,inf=9e18;
int n,q,k;
int v[N],s[N];
vector<int>e[N];
int dep[N],bz[N][18];
void dfs(int d,int fa){
	s[d]=s[fa]+v[d];
	dep[d]=dep[fa]+1;
	bz[d][0]=fa;
	for(int to:e[d]){
		if(to==fa){
			continue;
		}
		dfs(to,d);
	}
}
void pre(){
	rep(j,1,17){
		rep(i,1,n){
			bz[i][j]=bz[bz[i][j-1]][j-1];
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	int len=dep[x]-dep[y];
	rep(i,0,17){
		if(len&(1<<i)){
			x=bz[x][i];
		}
	}
	if(x==y){
		return x;
	}
	per(i,17,0){
		if(bz[x][i]!=bz[y][i]){
			x=bz[x][i],y=bz[y][i];
		}
	}
	return bz[x][0];
}
void solve1(){
	rep(i,1,q){
		int x=read(),y=read();
		int Lca=lca(x,y);
		cout<<s[x]+s[y]-s[Lca]-s[bz[Lca][0]]<<endl; 
	}
}
int f[2005],h[2005];
void solve2(){
	rep(p,1,q){
		vector<int>v1,v2;
		int x=read(),y=read();
		int Lca=lca(x,y);
		while(x!=Lca){
			v1.push_back(x);
			x=bz[x][0];
		}
		v1.push_back(Lca);
		while(y!=Lca){
			v2.push_back(y);
			y=bz[y][0];
		}
		per(j,(int)v2.size()-1,0){
			v1.push_back(v2[j]);
		}
		rep(i,2,(int)v1.size()-3){
			h[i]=inf;
			for(int to:e[v1[i]]){
				if(to==v1[i-1]||to==v1[i+1]){
					continue;
				}
				h[i]=min(h[i],v[to]);
			}
		}
		memset(f,0,sizeof(f));
		f[0]=v[v1[0]];
		rep(i,1,(int)v1.size()-1){
//			cout<<v1[i]<<'!'; 
			f[i]=inf;
			rep(j,max(0ll,i-k),i-1){
				f[i]=min(f[i],f[j]+v[v1[i]]);
			}
			if(i>=4&&k==3){
				f[i]=min(f[i],f[i-4]+h[i-2]+v[v1[i]]);
			}
		}
		cout<<f[(int)v1.size()-1]<<endl;
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout); 
	n=read(),q=read(),k=read();
	rep(i,1,n){
		v[i]=read();
	}
	rep(i,2,n){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	pre();
	if(k==1){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
