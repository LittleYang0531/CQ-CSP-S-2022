#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2505,M=2e4+5;
int lst[N],to[M],nxt[M],ec;
inline void ae(int x,int y){
	to[++ec]=y,nxt[ec]=lst[x],lst[x]=ec;	
}
int n,m,k;
ll a[N];
int dis[N][N];
void bfs(int s,int *dis){
	static int q[N],ql,qr;
	for(int i=1;i<=n;i++)dis[i]=102;
	dis[s]=0,q[ql=qr=1]=s;
	while(ql<=qr){
		int x=q[ql++];
		for(int i=lst[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				q[++qr]=y;
			}
		}
	}
}
int mx1[N],mx2[N],mx3[N];
pair<int,int> get(int i,int j){
	int a,b;
	if(mx1[i]==j)a=mx2[i],b=mx3[i];
	else if(mx2[i]==j)a=mx1[i],b=mx3[i];
	else a=mx1[i],b=mx2[i];
	return make_pair(a,b);	
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);k++;
	for(int i=2;i<=n;i++)scanf("%lld",a+i);
	a[0]=-4e18;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ae(x,y),ae(y,x);	
	}
	for(int i=1;i<=n;i++){
		bfs(i,dis[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j||dis[1][j]>k||dis[i][j]>k)continue;
			if(a[j]>a[mx1[i]])mx3[i]=mx2[i],mx2[i]=mx1[i],mx1[i]=j;
			else if(a[j]>a[mx2[i]])mx3[i]=mx2[i],mx2[i]=j;
			else if(a[j]>a[mx3[i]])mx3[i]=j;
		}
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]>k)continue;
			ll val=a[i]+a[j];
			pair<int,int> p=get(i,j);
			pair<int,int> q=get(j,i);
			if(p.first!=q.first){
				val+=a[p.first]+a[q.first];	
			}else{
				val+=a[p.first]+max(a[p.second],a[q.second]);	
			}
			ans=max(ans,val);
		}
	}
	cout<<ans<<endl;
	return 0;
}
