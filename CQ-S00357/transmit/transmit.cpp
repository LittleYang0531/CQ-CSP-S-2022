#include<stdio.h>
#define LL long long
const int N=2e5+5,M=4e5+5;
int n,k,head[N],cnt=1,a[N],time[N];
struct dy{
	int v,next;
}edge[M];
void add(int u,int v){
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void dfs(int u,int dad){
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=dad)
		{
			time[v]=time[u]+1;
			dfs(v,u);
		}
	}
}
LL my_min(LL x,LL y){
	return x<y?x:y;
}
int my_max(int x,int y){
	return x>y?x:y;
}
int lj[N],ci=1,ljj[N],cii=1;
int getf(int x,int y){
	int ans=0;lj[0]=a[x];ljj[0]=a[y];ci=1;cii=1;
	if(time[x]>time[y])
	{
		while(time[x]>time[y])
			for(int i=head[x];i&&time[x]>time[y];i=edge[i].next)
				if(time[x]>time[edge[i].v]){x=edge[i].v;ans++;lj[ci++]=a[x];break;}
	}
	if(time[x]<time[y])
	{
		while(time[x]<time[y])
			for(int i=head[y];i&&time[x]<time[y];i=edge[i].next)
				if(time[y]>time[edge[i].v]){y=edge[i].v;ans++;ljj[cii++]=a[y];break;}
	}
	while(x!=y)
	{
		for(int i=head[x];i;i=edge[i].next)if(time[x]>time[edge[i].v]){x=edge[i].v;lj[ci++]=a[x];break;}
		for(int i=head[y];i;i=edge[i].next)if(time[y]>time[edge[i].v]){y=edge[i].v;ljj[cii++]=a[y];break;}
		ans+=2;
	}
	return ans;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int w;scanf("%d%d%d",&n,&w,&k);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,1);
	while(w--)
	{
		int u,v;scanf("%d%d",&u,&v);
		int t=getf(u,v);
		if(t==1)	printf("%lld\n",(LL)( ((LL)a[u])+((LL)a[v]) ));
		else
		{
			if(t>k)	t=k;
			LL dp[N]={};int cd=ci+cii-1;
			for(int i=0;i<ci;i++)	{dp[i]=lj[i];lj[i]=0;}
			for(int i=0;i<cii-1;i++)	{dp[ci+cii-2-i]=ljj[i];ljj[i]=0;}ljj[cii-1]=0;ci=0;cii=0;
			for(int i=0;i<cd;i++)
			{
				LL tm=1e18;
				for(int j=my_max(i-t,0);j<i;j++)	tm=my_min(tm,dp[j]);
				if(tm!=1e18)	dp[i]+=tm;
			}
			printf("%lld\n",dp[cd-1]);
		}
	}
	return 0;
}
