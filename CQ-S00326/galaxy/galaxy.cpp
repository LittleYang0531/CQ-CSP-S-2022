#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int inf=0x3f3f3f3f;
const int N=1e3+10;
struct node{
	int w,to,next;
}edge[N<<1];
int head[N<<1],cnt=1;
void add(int u,int v/*,int w*/){
	edge[cnt].to=v;
	//edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int mp[N][N];
bool vis[N][N];
int n,m,q;
int out[N],in[N];
int dis[N][N];
bool check(){
	for(int i=1;i<=n;i++){
		if(out[i]!=1) return false;
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	if(m<1000){
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			out[u]++;add(u,v);
			mp[u][v]=1;vis[u][v]=1;dis[u][v]=1;
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			int a,b,c;
			scanf("%d",&a);
			if(a==1){
				scanf("%d%d",&b,&c);
				vis[b][c]=0;
				dis[b][c]=dis[0][0];
				out[b]--;
			}
			else if(a==2){
				scanf("%d",&b);
				for(int j=1;j<=n;j++){
					if(mp[j][b]&&vis[j][b]){
						vis[j][b]=0;
						out[j]--;
						dis[b][c]=dis[0][0];
					}
				}
			}
			else if(a==3){
				scanf("%d%d",&b,&c);
				out[b]++;
				vis[b][c]=1;
				dis[b][c]=1;
			}
			else{
				scanf("%d",&b);
				for(int j=1;j<=n;j++){
					if(mp[j][b]&&vis[j][b]){
						vis[j][b]=1;
						out[j]++;
						dis[b][c]=1;
					}
				}
			}
			if(check()){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	else{
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			out[u]++;add(u,v);
			mp[u][v]=1;vis[u][v]=1;dis[u][v]=1;
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			printf("NO\n");
		}
	}
	return 0;
}
