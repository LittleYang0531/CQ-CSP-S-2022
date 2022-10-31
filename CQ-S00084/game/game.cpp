#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define il inline
#define ct const
#define dl double
#define pk push_back
#define N 100010
#define inf 1000000001
using namespace std;
//bool ppp;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
il void write(int x){
	int cnt=0;char f[40];
	if(!x) putchar('0');
	if(x<0){
		x=-x;putchar('-');
	}
	while(x){
		f[cnt++]=x%10+'0';x/=10;
	}
	while(cnt) putchar(f[--cnt]);
	putchar('\n');
}
int n,m,q,a[N],b[N],mul[20],lg[N];
struct excel1{
	int st[N][20];
	il void init(){
		for(int i=n;i;--i){
			st[i][0]=a[i]>=0?a[i]:inf;
			for(int j=1;i+mul[j]-1<=n;++j) st[i][j]=min(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return min(st[l][len],st[r-mul[len]+1][len]);
	}
} ST1;
struct excel2{
	int st[N][20];
	il void init(){
		for(int i=n;i;--i){
			st[i][0]=a[i]<=0?a[i]:-inf;
			for(int j=1;i+mul[j]-1<=n;++j) st[i][j]=max(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return max(st[l][len],st[r-mul[len]+1][len]);
	}
} ST2;
struct excel3{
	int st[N][20];
	il void init(){
		for(int i=m;i;--i){
			st[i][0]=b[i]<=0?b[i]:inf;
			for(int j=1;i+mul[j]-1<=m;++j) st[i][j]=min(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return min(st[l][len],st[r-mul[len]+1][len]);
	}
} ST3;
struct excel4{
	int st[N][20];
	il void init(){
		for(int i=m;i;--i){
			st[i][0]=b[i]>=0?b[i]:-inf;
			for(int j=1;i+mul[j]-1<=m;++j) st[i][j]=max(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return max(st[l][len],st[r-mul[len]+1][len]);
	}
} ST4;
struct excel5{
	int st[N][20];
	il void init(){
		for(int i=n;i;--i){
			st[i][0]=a[i];
			for(int j=1;i+mul[j]-1<=n;++j) st[i][j]=max(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return max(st[l][len],st[r-mul[len]+1][len]);
	}
} ST5;
struct excel6{
	int st[N][20];
	il void init(){
		for(int i=n;i;--i){
			st[i][0]=a[i];
			for(int j=1;i+mul[j]-1<=n;++j) st[i][j]=min(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return min(st[l][len],st[r-mul[len]+1][len]);
	}
} ST6;
struct excel7{
	int st[N][20];
	il void init(){
		for(int i=m;i;--i){
			st[i][0]=b[i];
			for(int j=1;i+mul[j]-1<=m;++j) st[i][j]=min(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return min(st[l][len],st[r-mul[len]+1][len]);
	}
} ST7;
struct excel8{
	int st[N][20];
	il void init(){
		for(int i=m;i;--i){
			st[i][0]=b[i];
			for(int j=1;i+mul[j]-1<=m;++j) st[i][j]=max(st[i][j-1],st[i+mul[j-1]][j-1]);
		}
	}
	il int query(int l,int r){
		int len=lg[r-l+1];
		return max(st[l][len],st[r-mul[len]+1][len]);
	}
} ST8;
//bool pppp;
signed main(){
//	cerr<<(&ppp-&pppp)/1024.0/1024.0<<"\n";
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();q=read();mul[0]=1;
	for(int i=1;i<20;++i) mul[i]=mul[i-1]<<1;
	for(int i=2;i<=100000;++i) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	ST1.init();ST2.init();ST3.init();ST4.init();ST5.init();ST6.init();ST7.init();ST8.init();
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read(),res=-1e18;
		if(ST1.query(l1,r1)!=inf)
			if(ST3.query(l2,r2)!=inf) res=ST1.query(l1,r1)*ST3.query(l2,r2);
			else res=ST5.query(l1,r1)*ST7.query(l2,r2);
		if(ST2.query(l1,r1)!=-inf)
			if(ST4.query(l2,r2)!=-inf) res=max(res,ST2.query(l1,r1)*ST4.query(l2,r2));
			else res=max(res,ST6.query(l1,r1)*ST8.query(l2,r2));
		write(res);
	}
	return 0;
}

