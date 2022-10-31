#include<bits/stdc++.h> 
using namespace std;
const int N=5e5;
int Head[N+5],V[N*2+5],Nxt[N*2+5],tot;
void add(int u,int v){
	Nxt[++tot]=Head[u];Head[u]=tot;
	V[tot]=v;return;
}
int b[N+5];//被完全摧毁不可到达
map<int,int>a[N+5];//a->x->b
int vis[N+5];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m;scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;scanf("%d %d",&u,&v);
		add(u,v);
	}
	int q;scanf("%d",&q);
	while(q--){
		int t;scanf("%d",&t);
		if(t==1){
			int u,v;scanf("%d %d",&u,&v);
			a[u][v]=1;
		}
		else if(t==2){
			int u;scanf("%d",&u);
			b[u]=1;
		}
		else if(t==3){
			int u,v;scanf("%d %d",&u,&v);
			a[u][v]=0;
		}
		else if(t==4)
		{
			int u;scanf("%d",&u);
			b[u]=0;
		}
		memset(vis,0,sizeof(vis));
		int u=1,cnt=1,fg=0;vis[1]=1;
		while(1)
		{
			int nv=0;
			for(int i=Head[u];i;i=Nxt[i])
			{
				int v=V[i];
				if(a[u][v]||b[v])continue;
				
				if(vis[v])
				{
					if(v==1&&cnt==n)fg=1;
					else fg=-1;
				}
				if(fg)break;
				
				nv=v;vis[v]=1;cnt++;
			}
			if(fg)break;
			if(!nv)fg=-1;
			if(fg)break;
			u=nv;cnt++;
		}
		if(fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}
