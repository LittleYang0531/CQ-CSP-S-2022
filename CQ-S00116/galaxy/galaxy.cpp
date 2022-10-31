#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,t,u,v;
const int maxn=1000005;
int ey[maxn],enext[maxn],head[maxn];
bool w[maxn];
bool f=1;
bool check(){
	for(int i=1;i<=n;i++){
		int o=0;
		for(int j=head[i];j;j=enext[j]){
			if(w[j]==1){
				o++;
			}
		}
		if(o!=1) return 0;
	}
	return 1;
}
void DFS(int e,int p){
	if(e==v){
		f=0;
		return ;
	}
	for(int i=head[e];i;i=enext[i]){
		w[i]=p;
		DFS(ey[i],p); 
		if(f==1) w[i]=p^1;
		else return;
	}
	return;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		c++;
		enext[c]=head[x],head[x]=c,ey[c]=y,w[c]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&u,&v);
			f=1;
			DFS(u,0);
		}
		if(t==2){
			scanf("%d",&u);
			for(int i=head[u];i;i=enext[i]){
				w[i]=0;
			}
		}
		if(t==3){
			scanf("%d%d",&u,&v);
			f=1;
			DFS(u,1);
		}
		if(t==4){
			scanf("%d",&u);
			for(int i=head[u];i;i=enext[i]){
				w[i]=1;
			}
		}
		if(check()==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
