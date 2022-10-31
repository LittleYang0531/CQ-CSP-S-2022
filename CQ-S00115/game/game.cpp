#include<bits/stdc++.h>
template<typename G>inline void read(G&x) {G f=1;x=0;char ch=getchar();while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();if(ch=='-') f=-1,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();x*=f;}
template<typename G>inline void write(G x) {if(x<0) putchar('-'),x=-x;if(x>=10) write(x/10);putchar('0'+x%10);}
using namespace std;
const int MAXN=1e5+5;
int l[2][MAXN][2][20],r[2][MAXN][2][20];
long long qlmin(int x,int y,bool z) {
	int k=log2(y-x+1),f=1;
	if(!z) f=-1;
	return f*min(l[0][x][z][k],l[0][y-(1<<k)+1][z][k]);
}
long long qlmax(int x,int y,bool z) {
	int k=log2(y-x+1),f=1;
	if(!z) f=-1;
	return f*max(l[1][x][z][k],l[1][y-(1<<k)+1][z][k]);
}
long long qrmin(int x,int y,bool z) {
	int k=log2(y-x+1),f=1;
	if(!z) f=-1;
	return f*min(r[0][x][z][k],r[0][y-(1<<k)+1][z][k]);
}
long long qrmax(int x,int y,bool z) {
	int k=log2(y-x+1),f=1;
	if(!z) f=-1;
	return f*max(r[1][x][z][k],r[1][y-(1<<k)+1][z][k]);
}
int n,m,q,a[MAXN],b[MAXN],l1,r1,l2,r2;
long long ans;
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=n;++i) {
		read(a[i]);
		if(a[i]<0) l[0][i][0][0]=l[1][i][0][0]=-a[i],l[0][i][1][0]=1e9+1,l[1][i][1][0]=-1;
		else if(a[i]>0) l[0][i][1][0]=l[1][i][1][0]=a[i],l[0][i][0][0]=1e9+1,l[1][i][0][0]=-1;
		else l[0][i][0][0]=l[1][i][0][0]=l[0][i][1][0]=l[1][i][1][0]=0;
	}
	for(int i=1;i<=m;++i) {
		read(b[i]);
		if(b[i]<0) r[0][i][0][0]=r[1][i][0][0]=-b[i],r[0][i][1][0]=1e9+1,r[1][i][1][0]=-1;
		else if(b[i]>0) r[0][i][1][0]=r[1][i][1][0]=b[i],r[0][i][0][0]=1e9+1,r[1][i][0][0]=-1;
		else r[0][i][0][0]=r[1][i][0][0]=r[0][i][1][0]=r[1][i][1][0]=0;
	}
	for(int j=1;(1<<j)<=n;++j) {
		for(int i=1;i+(1<<j)-1<=n;++i) {
			for(int z=0;z<=1;++z) {
				l[0][i][z][j]=min(l[0][i][z][j-1],l[0][i+(1<<(j-1))][z][j-1]);
				l[1][i][z][j]=max(l[1][i][z][j-1],l[1][i+(1<<(j-1))][z][j-1]);
			} 
		}
	} 
	for(int j=1;(1<<j)<=m;++j) {
		for(int i=1;i+(1<<j)-1<=m;++i) {
			for(int z=0;z<=1;++z) {
				r[0][i][z][j]=min(r[0][i][z][j-1],r[0][i+(1<<(j-1))][z][j-1]);
				r[1][i][z][j]=max(r[1][i][z][j-1],r[1][i+(1<<(j-1))][z][j-1]);
			} 
		}
	} 
	while(q--) {
		read(l1),read(r1),read(l2),read(r2);
		ans=-2e18;
		if(qlmax(l1,r1,0)<=0) {
			long long now=2e18;
			if(qrmin(l2,r2,0)<=0) now=min(now,qlmax(l1,r1,0)*qrmin(l2,r2,0));
			if(qrmax(l2,r2,1)>=0) now=min(now,qlmax(l1,r1,0)*qrmax(l2,r2,1));
			if(now!=2e18) ans=max(ans,now);
		}
		if(qlmin(l1,r1,0)<=0) {
			long long now=2e18;
			if(qrmin(l2,r2,0)<=0) now=min(now,qlmin(l1,r1,0)*qrmin(l2,r2,0));
			if(qrmax(l2,r2,1)>=0) now=min(now,qlmin(l1,r1,0)*qrmax(l2,r2,1));
			if(now!=2e18) ans=max(ans,now);
		}
		if(qlmax(l1,r1,1)>=0) {
			long long now=2e18;
			if(qrmin(l2,r2,1)>=0) now=min(now,qlmax(l1,r1,1)*qrmin(l2,r2,1));
			if(qrmax(l2,r2,0)<=0) now=min(now,qlmax(l1,r1,1)*qrmax(l2,r2,0));
			if(now!=2e18) ans=max(ans,now);
		}
		if(qlmin(l1,r1,1)>=0) {
			long long now=2e18;
			if(qrmin(l2,r2,1)>=0) now=min(now,qlmin(l1,r1,1)*qrmin(l2,r2,1));
			if(qrmax(l2,r2,0)<=0) now=min(now,qlmin(l1,r1,1)*qrmax(l2,r2,0));
			if(now!=2e18) ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

