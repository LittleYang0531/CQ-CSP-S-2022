#include<bits/stdc++.h>
using namespace std;
const int N=2505;
const int M=10005;
int n,m,k;
long long a[N];
struct edge{
	int to,nxt,w;
}e[2*M]; 
int cnt,head[N];
void add(int u,int v,int w){
	cnt++;
	e[cnt].w=w;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int vis[N];
long long ans=0;
void dfs(int x,int step,long long sum,int k1){
//	cout<<x<<" "<<step<<" "<<sum<<endl;
	if(step>4){
//		cout<<endl;
//		if(x==1){
		ans=max(ans,sum);
//		}
		return ;
	}
	for(int i=head[x];i;i=e[i].nxt){
		if(step==5){
			if(k1<k)dfs(e[i].to,step,sum,k1+1);
			if(e[i].to==1)dfs(e[i].to,step+1,sum+a[e[i].to],0);	
		}
		else if(vis[e[i].to]==0){
			vis[e[i].to]=1;
//			cout<<e[i].to<<" ";
			if(k1<k)dfs(e[i].to,step,sum,k1+1);
			dfs(e[i].to,step+1,sum+a[e[i].to],0);	
			vis[e[i].to]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,1);
	}
	vis[1]=1;
	dfs(1,1,0,0);
	printf("%lld",ans);
	return 0;
}
