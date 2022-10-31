#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,op,id[1005][1005],h[1005],cd[1005];
bool b[10005],fl[1005];
struct node{int v,ne;}e[10005];
void add(int u,int v){e[++k].v=v,e[k].ne=h[u],h[u]=k,id[u][v]=k,cd[u]++;}
void update(int x,int y){
	for(int i=1;i<=n;i++)if(id[i][x]!=0&&b[id[i][x]]!=y)b[id[i][x]]=y,cd[i]+=(y?-1:1);
}
bool dfs(int x){
	bool flag=0;fl[x]=1;
	for(int i=h[x];i;i=e[i].ne)if(!b[i])if(fl[e[i].v]||dfs(e[i].v)){flag=1;break;}
	return flag;
}
bool check(int x){
	return (cd[x]==1)&&dfs(x);
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),add(x,y);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&op),memset(fl,0,sizeof(fl));
		if(op==1)scanf("%d%d",&x,&y),b[id[x][y]]=1,cd[x]--;
		if(op==2)scanf("%d",&x),update(x,1);
		if(op==3)scanf("%d%d",&x,&y),b[id[x][y]]=0,cd[x]++;
		if(op==4)scanf("%d",&x),update(x,0);
		bool flag=1;
		for(int i=1;i<=n;i++)if(!check(i)){flag=0;break;}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}
