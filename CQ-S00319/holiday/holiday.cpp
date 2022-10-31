#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=2510;
struct Gragh{
	int elast[N];
	int idx;
	struct path{
		int en,nex;
	}a[N*N];
	void add(int x,int y){
		a[++idx]=(path){y,elast[x]};
		elast[x]=idx;
	}
}G1,G2;
bool map[N][N];
int dist[N];
ll s[N];
int n,m,k;
void dfs1(int sta,int p,int tmp){
	if(tmp>k)
		return;
	G2.add(sta,p);
	map[sta][p]=1;
	for(int i=G1.elast[p];i;i=G1.a[i].nex){
		int q=G1.a[i].en;
		if(!map[sta][q])
			dfs1(sta,q,tmp+1);
	}
}
int id,p[10];
bool check(int x){
	for(int i=1;i<=id;i++)
		if(p[i]==x)
			return false;
	return true;
}
ll ANS;
void dfs2(int u){
	if(id==4){
		if(map[u][1]){
			ll res=0;
			for(int i=1;i<=4;i++)
				res+=s[p[i]];
			ANS=max(ANS,res);
		}
		return;
	}
	int y;
	for(int i=G2.elast[u];i;i=G2.a[i].nex){
		y=G2.a[i].en;
		if(check(y)&&y!=1){
			p[++id]=y;
			dfs2(y);
			--id;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++)
		scanf("%lld",s+i);
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		G1.add(x,y),G1.add(y,x);
	}
	for(int i=1;i<=n;i++)
		dfs1(i,i,0);
	dfs2(1);
	printf("%lld\n",ANS);
	return 0;
} 
