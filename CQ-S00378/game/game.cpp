#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
#define lll __int128
#define uns unsigned
#define fi first
#define se second
#define IF (it->fi)
#define IS (it->se)
#define lowbit(x) ((x)&-(x))
#define END putchar('\n')
#define inline jzmyyds
using namespace std;
const int MAXN=1e5+5;
const ll INF=1e9+7;
ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int ptf[50],lpt;
void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	ptf[lpt=1]=x%10;
	while(x>9)x/=10,ptf[++lpt]=x%10;
	while(lpt)putchar(ptf[lpt--]^48);
	if(c>0)putchar(c);
}
int n,m,Q;
struct zkw{
	int f[MAXN*3],g[MAXN*3],p;
	void init(int n){
		for(p=1;p<n+2;p<<=1);
		for(int i=p+n+1;i>0;i--)f[i]=-INF,g[i]=INF;
	}
	void upd(int x){
		f[x]=max(f[x<<1],f[x<<1|1]),g[x]=min(g[x<<1],g[x<<1|1]);
	}
	void chg(int x,int d){
		for(f[p^x]=g[p^x]=d,x=(p^x)>>1;x;x>>=1)
			f[x]=max(f[x<<1],f[x<<1|1]),g[x]=min(g[x<<1],g[x<<1|1]);
	}
	int gmax(int l,int r){
		int re=-INF;
		for(l=p^(l-1),r=p^(r+1);l^1^r;l>>=1,r>>=1){
			if(~l&1)re=max(re,f[l^1]);
			if(r&1)re=max(re,f[r^1]);
		}
		return re;
	}
	int gmin(int l,int r){
		int re=INF;
		for(l=p^(l-1),r=p^(r+1);l^1^r;l>>=1,r>>=1){
			if(~l&1)re=min(re,g[l^1]);
			if(r&1)re=min(re,g[r^1]);
		}
		return re;
	}
}A[3],B[3];//(mod 3) 0,1,-1
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),Q=read();
	for(int i=0;i<3;i++)A[i].init(n),B[i].init(m);
	for(int i=1;i<=n;i++){
		int a=read();
		if(a>0)A[1].chg(i,a);
		else if(a<0)A[2].chg(i,a);
		else A[0].chg(i,0);
	}
	for(int i=1;i<=m;i++){
		int b=read();
		if(b>0)B[1].chg(i,b);
		else if(b<0)B[2].chg(i,b);
		else B[0].chg(i,0);
	}
	while(Q--){
		vector<ll>u,v;
		int l=read(),r=read(),in;
		if(A[0].gmax(l,r)==0)u.push_back(0);
		if((in=A[1].gmax(l,r))>-INF)u.push_back(in);
		if((in=A[1].gmin(l,r))<INF)u.push_back(in);
		if((in=A[2].gmax(l,r))>-INF)u.push_back(in);
		if((in=A[2].gmin(l,r))<INF)u.push_back(in);
		l=read(),r=read();
		if(B[0].gmax(l,r)==0)v.push_back(0);
		if((in=B[1].gmax(l,r))>-INF)v.push_back(in);
		if((in=B[1].gmin(l,r))<INF)v.push_back(in);
		if((in=B[2].gmax(l,r))>-INF)v.push_back(in);
		if((in=B[2].gmin(l,r))<INF)v.push_back(in);
		ll ans=-INF*INF;
		for(ll&x:u){
			ll z=INF*INF;
			for(ll&y:v)z=min(z,x*y);
			ans=max(ans,z);
		}
		print(ans);
	}
	return 0;
}
