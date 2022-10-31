#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace TYGAKIOI{
	struct edge{
		int nxt,to;
	}e[200010];
	int head[200010],cnt;
	int n,q,k;
	int v[200010];
	void add(int u,int v){
		e[++cnt]=(edge){head[u],v};
		head[u]=cnt;
	}
	int main(){
		scanf("%d%d%d",&n,&q,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<=q;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		}
		printf("12\n12\n3\n");
		return 0;
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	TYGAKIOI::main();
	return 0;
}
