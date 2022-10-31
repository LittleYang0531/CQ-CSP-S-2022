#include<bits/stdc++.h>
//stO stO stO Orz Orz Orz¿¼Éñ£¨»®µô£©CCF±£ÓÓ 
using namespace std;
#define il inline
#define ll unsigned long long
#define N 2505
#define M 10010
il ll read(){
	ll x=0;
	bool w=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch==45) w=0;
		ch=getchar();
	}while(ch>47&&ch<58){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return (w)?(x):(-x);
}
struct edge{
	int to,nxt;
}a[M];
int n,m,k,h[N],tot;
ll b[N],mx;
bool vis[N],bis[N];
il void lj(int l,int r){
	tot++;
	a[tot].to=r;
	a[tot].nxt=h[l];
	h[l]=tot;
}
void dfs(int x,int cnt,ll ans){
	if(cnt==5){
		if(x!=1) return;
		mx=max(mx,ans);
		return;
	}
	for(int i=h[x];i!=0;i=a[i].nxt){
		int to=a[i].to;
		if((cnt==4&&to==1)||!vis[to]){
			vis[to]=1;
			dfs(to,cnt+1,ans+b[to]);
			vis[to]=0;
		}
	}
}
void jt(const int X,int x,int cnt){
	if(cnt>k){
		return;
	}
//	cout<<x<<" ";
	if(!bis[x]){
		bis[x]=1;
		lj(X,x);
		lj(x,X);
	}
	for(int i=h[x];i!=0;i=a[i].nxt){
		if(!vis[a[i].to]){
			vis[a[i].to]=1;
			jt(X,a[i].to,cnt+1);
			vis[a[i].to]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;i++) b[i]=read();
	while(m--){
		int l=read(),r=read();
		lj(l,r);
		lj(r,l);
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			memset(bis,0,sizeof(bis));
			bis[i]=1;
			for(int j=h[i];j!=0;j=a[j].nxt){
				bis[a[j].to]=1;
			}
			vis[i]=1;
			jt(i,i,-1);
			vis[i]=0;
		}
	}
	vis[1]=1;
	dfs(1,0,0);
	printf("%lld",mx);
	return 0;
}
