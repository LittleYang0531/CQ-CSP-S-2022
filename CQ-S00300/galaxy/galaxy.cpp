#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace TYGAKIOI{
	struct edge{
		int nxt,to;
	}e[500010];
	int head[500010],cnt;
	int flag[1010][1010];
	int n,m,q;
	void add(int u,int v){
		e[++cnt]=(edge){head[u],v};
		head[u]=cnt;
	}
	int vis[500010];
	bool did(int u){
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(flag[u][v])
				continue;
			if(vis[v])
				return true;
			vis[v]=1;
			return did(v);
		}
		return false;
	}
	bool check(){
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=head[i];j;j=e[j].nxt){
				int v=e[j].to;
				if(flag[i][v])
					continue;
				sum++;
			}
			if(sum!=1)
				return false;
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			if(!did(i))
				return false;
		}
		return true;
	}
	int main(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			int t,tu,tv;
			scanf("%d",&t);
			if(t==1){
				scanf("%d%d",&tu,&tv);
				flag[tu][tv]=1;
			}
			else if(t==2){
				scanf("%d",&tu);
				for(int i=1;i<=n;i++)
					flag[i][tu]=1;
			}
			else if(t==3){
				scanf("%d%d",&tu,&tv);
				flag[tu][tv]=0;
			}
			else{
				scanf("%d",&tu);
				for(int i=1;i<=n;i++)
					flag[i][tu]=0;
			}
			if(check())
				printf("YES\n");
			else
				printf("NO\n");
		}
		return 0;
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	TYGAKIOI::main();
	return 0;
}
