#include<bits/stdc++.h>
//stO stO stO Orz Orz Orz¿¼Éñ£¨»®µô£©CCF±£ÓÓ 
using namespace std;
#define il inline
#define ll unsigned long long
#define N 200010
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
}a[N];
int n,QAQ,k,h[N],tot;
ll v[N],mn;
bool vis[N];
il void lj(int l,int r){
	tot++;
	a[tot].to=r;
	a[tot].nxt=h[l];
	h[l]=tot;
}
void dfs(int x,int cnt,const int T,ll ans,ll pd,int pdzb,int pdwz){
	if(x==T){
		mn=min(mn,ans+v[x]);
		return;
	}
	if(ans>=mn){
		return;
	}
	if(v[x]<pd){
		pd=v[x];
		pdzb=cnt;
		pdwz=x;
	}
	if(cnt>k){
		ans+=v[pdwz];
		cnt=cnt-pdzb+1;
		pd=0;
		pd=~pd;
		pdzb=cnt;
		pdwz=x;
	}
	for(int i=h[x];i!=0;i=a[i].nxt){
		int ot=a[i].to;
		if(!vis[ot]){
			vis[ot]=1;
			dfs(ot,cnt+1,T,ans,pd,pdzb,pdwz);
			vis[ot]=0;
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),QAQ=read(),k=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++){
		int l=read(),r=read();
		lj(l,r);
		lj(r,l);
	}
	while(QAQ--){
		int l=read(),r=read();
		mn=0;
		mn=~mn;
		vis[l]=1;
		dfs(l,1,r,v[l],mn,1,0);
		vis[l]=0;
		printf("%lld ",mn);
	}
	return 0;
}
