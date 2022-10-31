#include<bits/stdc++.h>
#define N 500005
#define M 500005
using namespace std;
int n,m,q,h[N],cnt,vis[N],vs[N];
vector<int> v[N];
struct bb{
	int to,next;
}w[M];
bool bj[M];
void ad(int x,int y){
	w[++cnt].to=y;
	v[y].push_back(cnt);
	w[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x){
	int s=0;
	for(int i=h[x];i;i=w[i].next){
		if(bj[i])continue;
		s++;
	}
	vis[x]=3,vs[x]=1;
	if(s!=1){
		vs[x]=0;
		vis[x]=2;
		return ;
	}
	for(int i=h[x];i;i=w[i].next){
		if(bj[i])continue;
		int y=w[i].to;
		if(!vs[y])dfs(y);
		if(vis[y]==3||vis[y]==1)vis[x]=1;
		else vis[x]=2;
	}
	vs[x]=0;
	if(vis[x]==3)vis[x]=2;
}
void dl(int x,int tt){
	for(int i=h[x];i;i=w[i].next){
		int y=w[i].to;
		if(y==tt){
			bj[i]=1;
			break;
		}
	}
}
void dt(int x){
	for(auto i:v[x]){
		bj[i]=1;
	}
}
void al(int x,int tt){
	for(int i=h[x];i;i=w[i].next){
		int y=w[i].to;
		if(y==tt){
			bj[i]=0;
			break;
		}
	}
}
void at(int x){
	for(auto i:v[x]){
		bj[i]=0;
	}
}
bool check(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(i);
		if(vis[i]==2)return false;
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y);
	}
	scanf("%d",&q);
	while(q--){
		int t,x,y;
		scanf("%d%d",&t,&x);
		if(t==1){
			scanf("%d",&y);
			dl(x,y);
		}else if(t==2){
			dt(x);
		}else if(t==3){
			scanf("%d",&y);
			al(x,y);
		}else{
			at(x);
		}
		if(check()){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
