#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,cnt,head[500005];
bool vis[500005],flag;
struct edge{
	int next,to,o;
}e[500005];
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].o=0;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool Fv[500005];
void dfs(int x){
	if(flag) return;
	for(int j=head[x];j;j=e[j].next){
		if(e[j].o) continue;
		if(Fv[j]){
			flag=1;
			return;
		}
		Fv[j]=1;
		dfs(e[j].to);
		Fv[j]=0;
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int t,u,v;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&u,&v);
			for(int j=head[u];j;j=e[j].next){
				if(e[j].to==v) e[j].o=1;
			}
		}else if(t==2){
			scanf("%d",&v);
			for(int j=1;j<=cnt;j++){
				if(e[j].to==v) e[j].o=1;
			}
		}else if(t==3){
			scanf("%d%d",&u,&v);
			for(int j=head[u];j;j=e[j].next){
				if(e[j].to==v) e[j].o=0;
			}
		}else if(t==4){
			scanf("%d",&u);
			for(int j=head[u];j;j=e[j].next){
				e[j].o=0;
			}
		}
		bool F=1;
		for(int j=1;j<=n;j++){
			int sum=0;
			for(int i=head[j];i;i=e[i].next){
				if(e[i].o) continue;
				sum++;
			}
			if(sum!=1){
				F=0;
				break;
			}
		}
		if(!F){
			printf("NO\n");
			continue; 
		}
		for(int i=1;i<=n;i++){
			flag=0;
			memset(Fv,0,sizeof(Fv)); 
			for(int j=head[u];j;j=e[j].next){
				if(e[j].o) continue;
				Fv[j]=1;
				dfs(e[j].to);
				Fv[j]=0;
			}
			if(!flag){
				F=0;
				break;
			}
		}
		if(!F){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}
