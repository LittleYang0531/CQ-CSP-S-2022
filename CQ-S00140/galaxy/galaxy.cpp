#include<bits/stdc++.h>
using namespace std;
int n,m,q,t,x,y,cnt,h[500001],f[1001][1001],ff[1001][1001],v[500001],w;
struct qx{
	int to,next;
}a[1000001];
void hb(int x,int y){
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x){
	if(v[x]){
		w=1;
		return;
	}
	if(w) return;
	v[x]=1;
	for(int i=h[x];i!=0;i=a[i].next){
		int y=a[i].to;
		if(!f[x][y]) continue;
		dfs(y);
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		hb(x,y);
		f[x][y]=1;
		ff[y][++ff[y][0]]=x;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&x,&y);
			f[x][y]=0;
		}else if(t==3){
			scanf("%d%d",&x,&y);
			f[x][y]=1;
		}else if(t==2){
			scanf("%d",&x);
			for(int i=1;i<=ff[x][0];i++){
				f[ff[x][i]][x]=0;
			}
		}else{
			scanf("%d",&x);
			for(int i=1;i<=ff[x][0];i++){
				f[ff[x][i]][x]=1;
			}
		}
		int pd=0;
		for(int i=1;i<=n;i++){
			w=0;
			for(int j=h[i];j!=0;j=a[j].next){
				int y=a[j].to;
				if(f[i][y]==1){
					w++;
				}
				if(w>1) break;
			}
			if(w!=1){
				printf("NO\n");
				pd=1;
				break;
			}
			memset(v,0,sizeof(v));
			w=0;
			dfs(i);
			if(!w){
				printf("NO\n");
				pd=1;
				break;
			}
		}
		if(!pd){
			printf("YES\n");
		}
	}
	return 0;
}
