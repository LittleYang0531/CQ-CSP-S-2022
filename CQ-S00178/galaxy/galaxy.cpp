#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
struct node{
	int to,next,to1;
}a[N];
int n,m,idx=0;
int q,pre[N];
void add(int u,int v){
	a[++idx]={v,pre[u],v};
	pre[u]=idx;
}
bool f[N];
bool dfs(int s,int b){
	for(int i=pre[s];i;i=a[i].next){
		if(a[i].to==b)
		return true;
		else if(a[i].to!=-1)
		if(dfs(a[i].to,b)) return true;
	}
	return false;
}
bool cmp(){
	for(int i = 1;i<=n;i++){
		if(f[i]) return false;
		int v=0;
		for(int j = pre[i];j;j=a[j].next){
			if(a[j].to!=-1)
			v++;
			if(v>1) return false;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = pre[i];j;j=a[j].next){
			int to=a[j].to;
			if(to!=-1){
				if(!dfs(to,i)){
					return false;
				}
				break;
			}
		}
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int u,v;
			scanf("%d%d",&u,&v);
			for(int i = pre[u];i;i=a[i].next){
				if(a[i].to==v){
					a[i].to=-1;
					break;
				}
			}
		}else if(t==2){
			int u;
			scanf("%d",&u);
			f[u]=true;	
		}else if(t==3){
			int u,v;
			scanf("%d%d",&u,&v);
			for(int i = pre[u];i;i=a[i].next){
				if(a[i].to1==v){
					a[i].to=a[i].to1;
					break;
				}
			}
		}else{
			int u;
			scanf("%d",&u);
			f[u]=false;
		}
		int cnt=0,flag=0;
		for(int i = 1;i <=n&&!flag;i++){
			for(int j = pre[i];j;j=a[j].next){
				if(a[j].next<0)continue;
				cnt++;
				if(cnt>1){
					flag=1;
					printf("NO\n");
					break;
				}
			}
		}
		if(!f)printf("YES\n");
	}
	return 0;
}
