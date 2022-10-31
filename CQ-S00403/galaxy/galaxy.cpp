#include<bits/stdc++.h>
//预计：15~40 
using namespace std;
const int N=5e5+2,M=5e5+2;
int q,t,n,m,x,y,low[N],cnt,tot,sum,top,f[N];
int st[N],dfn[N],hd[N],to[N],nxt[N],c[N],g[N];
map<int,int>pos[N];
void add(int x,int y){
	to[++cnt]=y;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
} 
void tarjan(int x){
	dfn[x]=low[x]=++tot;
	st[++top]=x;
	for(int i=hd[x];i;i=nxt[i]){
		if(!f[i]) continue;
		int y=to[i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(!c[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		sum++;
		int y=-1;
		do{
			y=st[top--];
			c[y]=sum;
		}while(x!=y); 
	}
} 
void pre(){
	tot=sum=top=0;
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(c,0,sizeof(c));
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		pos[i].clear();
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		f[pos[x][y]=cnt]=1;
		g[x]++;
	}
	scanf("%d",&q);
	while(q--){
	//	printf("f[pos[3][2]=%d]=%d\n",pos[3][2],f[pos[3][2]]);
		scanf("%d",&t);
		if(t==1){//摧毁边:边不能用 
			scanf("%d%d",&x,&y);
			g[x]--;
			f[pos[x][y]]=0;
		}else if(t==2){// 摧毁点:到达x的边不能用 
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				if(x!=i) {
					if(!pos[i][x]) continue;
					if(f[pos[i][x]])g[i]--;
					f[pos[i][x]]=0;
				}
			}
		}else if(t==3){
			scanf("%d%d",&x,&y);
			f[pos[x][y]]=1;
			g[x]++;
		}else{
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				if(x!=i) {
					if(!pos[i][x]) continue;
				//	if(i==3) printf("?");
					if(!f[pos[i][x]]){
				//		if(i==3) printf("?");
					//	cout<<i<<" ";
						g[i]++;
					}
				//	if(i==3) printf("? ");
					f[pos[i][x]]=1;
				}
			}
		}
	//	cout<<'\n';
		bool fg=0;
		for(int i=1;i<=n;i++){
		//	printf("g[%d]=%d\n",i,g[i]);
			if(g[i]!=1) {
				fg=1;
			//	break;
			}
		} 
		if(fg) {
			printf("NO\n");
			continue;
		}
		pre();
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				tarjan(i);
			}
		} 
//		cout<<"___"<<sum<<'\n';
		if(sum!=n) printf("YES\n");//只要图是联通（之前判边的时候判了）并且有环就ok了 
		else printf("NO\n");
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
