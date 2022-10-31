#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char ch=getchar();
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
ll n,m,q,a[100005],b[100005],dp_a[100005][20],dp_b[100005][20],lo[100005],f_b[100005][20],f_a[100005][20],fa[100005][20],za[100005][20];
void make_st(){
	for(ll i=2;i<=1e5;i++){
		lo[i]=lo[i>>1]+1;
	}
	for(ll i=1;i<=n;i++){
		dp_a[i][0]=a[i];
		f_a[i][0]=a[i];
		if(a[i]<=0)
			fa[i][0]=a[i];
		else
			fa[i][0]=-1e10;
		if(a[i]>=0)
			za[i][0]=a[i];
		else
			za[i][0]=1e10;
	}
	for(ll j=1;j<=19;j++){
		for(ll i=1;i<=n&&i+(1<<j)-1<=n;i++){
			dp_a[i][j]=max(dp_a[i][j-1],dp_a[i+(1<<(j-1))][j-1]);
			f_a[i][j]=min(f_a[i][j-1],f_a[i+(1<<(j-1))][j-1]);
			fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
			za[i][j]=min(za[i][j-1],za[i+(1<<(j-1))][j-1]);
		}
	}
	for(ll i=1;i<=m;i++){
		dp_b[i][0]=b[i];
		f_b[i][0]=b[i];
	}
	for(ll j=1;j<=19;j++){
		for(ll i=1;i<=m&&i+(1<<j)-1<=m;i++){
			dp_b[i][j]=min(dp_b[i][j-1],dp_b[i+(1<<(j-1))][j-1]);
			f_b[i][j]=max(f_b[i][j-1],f_b[i+(1<<(j-1))][j-1]);
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	m=read();
	q=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	for(ll i=1;i<=m;i++){
		b[i]=read();
	}
	make_st();
	while(q--){
		ll l1,r1,l2,r2;
		l1=read();
		r1=read();
		l2=read();
		r2=read();
		ll k=lo[r1-l1+1],val=min(f_a[l1][k],f_a[r1-(1<<k)+1][k]),val1,val2,val3,pf,pz;
		k=lo[r1-l1+1],val1=max(dp_a[l1][k],dp_a[r1-(1<<k)+1][k]);
		k=lo[r2-l2+1],val2=max(f_b[l2][k],f_b[r2-(1<<k)+1][k]);
		k=lo[r2-l2+1],val3=min(dp_b[l2][k],dp_b[r2-(1<<k)+1][k]);
		if(val>=0){
			if(val3>=0)
				work(val1*val3);
			else
				work(val3*val);
		}
		else if(val1<=0){
			if(val2<=0)
				work(val*val2);
			else
				work(val1*val2);
		}
		else if(val2<=0)
			work(val2*val);
		else if(val3>=0)
			work(val1*val3);
		else{
			k=lo[r1-l1+1];
			pf=max(fa[l1][k],fa[r1-(1<<k)+1][k]);
			pz=min(za[l1][k],za[r1-(1<<k)+1][k]);
			work(max(pf*val2,pz*val3));
		}
		puts("");
	}
	return 0;
}
