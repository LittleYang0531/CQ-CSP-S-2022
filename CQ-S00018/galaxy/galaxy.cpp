#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
#define ll long long
struct G{
	int v,nex,fg=1;
}a[N];
int head[N]={0},tot=0;
void add(int u,int v){
	a[++tot].v=v;
	a[tot].nex=head[u];
	head[u]=tot;
	a[tot].fg=1;
}
int n,m,q;
int vis[N]={0};
int viss[N]={0};
int check(int x){
	int cnt=0;
	for(int i=head[x];i;i=a[i].nex){
		if(a[i].fg==1) cnt++;
	}
	return cnt;
}
int flag=0;
void dfs(int u){
	if(viss[u]>100||flag==1) {
		flag=1;
		return;
	}
	viss[u]++;
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].v;
		if(a[i].fg==-1) continue;
		dfs(v);
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
			scanf("%d%d",&x,&y);
		add(x,y);
	}
	memset(vis,0,sizeof vis);
	cin>>q;
	while(q--){
		int t,x,y;
		cin>>t;
		if(t==1){
			scanf("%d%d",&x,&y);
			for(int i=head[x];i;i=a[i].nex){
				int v=a[i].v;
				if(v==y){
					a[i].fg=-1;
					break; 
				}
			}
		}
		else if(t==2){
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				for(int j=head[i];j;j=a[j].nex){
					if(a[j].v==x){
						a[j].fg=-1;
						break;
					}
				}
			}
		}
		else if(t==3){
			scanf("%d%d",&x,&y);
			for(int i=head[x];i;i=a[i].nex){
				int v=a[i].v ;
				if(v==y){
					a[i].fg=1;
					vis[v]=0;
					break; 
				}
			}
		}
		else if(t==4){
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				for(int j=head[i];j;j=a[j].nex){
					if(a[j].v==x){
						a[j].fg=1;
						break;
					}
				}
			}
		}
		int f=1;
		memset(viss,0,sizeof viss);
		for(int i=1;i<=n;i++){
			flag=0;
			dfs(i);
			if(flag==1&&check(i)==1){
//				f=1;
			}
			else {
				f=0;
//				cout<<i<<":"<<flag<<","<<check(i);
			}
//				cout<<i<<":"<<flag<<","<<check(i);
		}
		if(f==1){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
}
