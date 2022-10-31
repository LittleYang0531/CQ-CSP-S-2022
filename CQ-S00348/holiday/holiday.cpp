#include<bits/stdc++.h>
using namespace std;
#define int long long

const int Maxn=2507;
const int Maxm=1e4+7;
int N,M,K,val[Maxn],f[Maxn][5],cnt,hed[Maxn],ans;
vector<int> num[Maxn];
bool Vis[Maxn];
struct node{
	int nxt,to;
}G[Maxm<<1];

inline int read(){
	int ret=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
	return f?-ret:ret;
}

void Addedge(int x,int y){
	G[++cnt].nxt=hed[x]; G[cnt].to=y; hed[x]=cnt;
}

void DFS(int x,int p,int dep,int id){
	for(int y,i=hed[x];i;i=G[i].nxt){
		if((y=G[i].to)==p) continue;
		if(dep<K) num[id].push_back(y),DFS(y,x,dep+1,id);
	}
}

void Solve(){
	for(int i=0;i<(int)num[1].size();++i) Vis[num[1][i]]=true;
	for(int i=0;i<(int)num[1].size();++i){
		int x=num[1][i],tmp=val[x]; 
		for(int j=0;j<(int)num[x].size();++j){
			int y=num[x][j]; 
			if(x==y) continue;
			tmp+=val[y];
			for(int k=0;k<(int)num[y].size();++k){
				int z=num[y][k];
				if(x==z||y==z) continue;
				tmp+=val[z];
				for(int d=0;d<(int)num[z].size();++d){
					int w=num[z][d];
					if(!Vis[w]||w==x||w==y||w==z) continue;
					ans=max(ans,tmp+val[w]);
				}
				tmp-=val[z];
			}
			tmp-=val[y];
		}
	}
	printf("%lld",ans);
}

signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	N=read(),M=read(),K=read();
	for(int i=2;i<=N;++i) val[i]=read();
	for(int x,y,i=1;i<=M;++i) 
		x=read(),y=read(),Addedge(x,y),Addedge(y,x);
	for(int i=1;i<=N;++i) DFS(i,0,-1,i);
	Solve();
	return 0;
}
