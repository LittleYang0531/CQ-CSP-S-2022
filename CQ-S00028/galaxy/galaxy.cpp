#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,ans,q;
struct node{
	int data,nxt;
}a[maxn];
int first[maxn],cnt,vis[maxn],du[maxn];
int v[1005][1005],p[1005][1005];
void add(int x,int y){
	a[++cnt].data=y;
	a[cnt].nxt=first[x];
	first[x]=cnt;
}
void dfs(int x,int fa){
	int flag=0;
	for(int i=first[x];i;i=a[i].nxt){
		if(vis[i]||a[i].data==fa)continue;
		int k=a[i].data;
		dfs(k,x);
		flag=1;
	}
	if(flag==0)ans=x;
}
int check(){
	for(int i=1;i<=n;i++)du[i]=0;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=first[i];j;j=a[j].nxt){
			if(vis[j])continue;
			flag++;
			du[a[j].data]++;
		}
		if(flag!=1)return 0;
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		if(du[i]!=0)pos++;
	}
	if(pos==n)return 1;
	else{
		for(int i=1;i<=n;i++){
			if(du[i]==0){
				dfs(i,0);
				for(int j=first[ans];j;j=a[j].nxt){
					int k=a[j].data;
					for(int s=first[k];s;s=a[s].nxt){
						int ps=a[s].data;
						if(ans==ps)return 1;
					}
				}
				return 0;
			}
		}
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x][y]=p[x][y]=1;//1:´æÔÚ 
		add(x,y);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int j=first[x];j;j=a[j].nxt){
				int k=a[j].data;
				if(k==y){
					v[x][y]=0;
					vis[j]=1;
					break;
				}
			}
		}
		if(t==2){
			int x;
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				for(int j=first[i];j;j=a[j].nxt){
					int k=a[j].data;
					if(vis[j])continue;
					if(k==x)vis[j]=1,v[i][x]=0;
				}
			}
		}
		if(t==3){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int j=first[x];j;j=a[j].nxt){
				int k=a[j].data;
				if(k==y){
					v[x][y]=1;
					vis[j]=0;
					break;
				}
			}
		}
		if(t==4){
			int x;
			scanf("%c",&x);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(v[i][j]==0&&p[i][j]==1){
						for(int k=first[i];k;k=a[k].nxt){
							int op=a[k].data;
							if(op==j){
								vis[k]=0;
								break;
							}
						}
						v[i][j]=1;
					}
				}
			}
		}
		if(i==10){
			for(int i=1;i<=n;i++){
				for(int j=first[i];j;j=a[j].nxt){
					int k=a[j].data;
					if(vis[j])continue;
				}
			}
		}
		if(check())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

