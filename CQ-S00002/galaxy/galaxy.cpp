#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,m,q;
struct edge{
    int to,next;
    bool used;
}e[N];
int fir[N],np=0,c[N],r[N],yc[N],yr[N];
bool vis[N];
void add(int x,int y){
	e[++np].to=y;
	e[np].next=fir[x];
	e[np].used=1;
	fir[x]=np;
}
bool huan(int x){
	vis[x]=1;
	for(int i=fir[x];i;i=e[i].next){
		int j=e[i].to;
		if(r[j]==yr[j])e[i].used=1;
		if(!e[i].used||r[j]==0)continue;
		if(vis[j])return true;
		if(huan(j))return true;
	}
	return false;
}
bool judge(){
	for(int i=1;i<=n;i++){
		//printf("%d\n",i);
		int cnt=0;
		for(int j=fir[i];j;j=e[j].next){
			if(r[e[j].to]==yr[e[j].to])e[i].used=1;
		    if(e[i].used&&r[e[j].to])cnt++;
		}
		if(cnt!=1)return false;
		//printf("%d\n",i);
		memset(vis,0,sizeof(vis));
		if(!huan(i))return false;
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x;
		int y;
		scanf("%d%d",&x,&y);
		add(x,y); 
		c[x]++;
		r[y]++;
		yc[x]++;
		yr[y]++;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int t,u,v;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&u,&v);
			for(int i=fir[u];i;i=e[i].next){
				int j=e[i].to;
				if(j==v){
					e[i].used=0;
					break;
				}
			}
			c[u]--;
			r[v]--;
			if(judge())printf("YES\n");
			else printf("NO\n");
			continue;
		}
		if(t==2){
			scanf("%d",&u);
			//p[u]=0;
			r[u]=0;
			if(judge())printf("YES\n");
			else printf("NO\n");
			continue;
		}
		if(t==3){
			scanf("%d%d",&u,&v);
			for(int i=fir[u];i;i=e[i].next){
				int j=e[i].to;
				if(j==v){
					e[i].used=1;
					break;
				}
			}
			c[u]++;
			r[v]++;
			if(judge())printf("YES\n");
			else printf("NO\n");
			continue;
		}
		if(t==4){
			scanf("%d",&u);
			r[u]=yr[u];
			if(judge())printf("YES\n");
			else printf("NO\n");
			continue;
		}
	}
	return 0;
}
