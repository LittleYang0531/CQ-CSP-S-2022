#include<bits/stdc++.h>
using namespace std; 
const int N=100005;
inline int read(){int f=0,t=1;char c=getchar();while(!isdigit(c)){if(c=='-')t=-1;c=getchar();}while(isdigit(c))f=(f<<3)+(f<<1)+c-'0',c=getchar();return t*f;}
void write(long long x){if(x>=10)write(x/10);putchar(x%10+'0');return;}
int n,m,q,L[N],a[N],b[N],pre1[N],pre2[N];
int st1[N][21],st2[N][21];
int st3[N][21],st4[N][21];
int st5[N][21],st6[N][21];
inline long long min(long long x,long long y) {
	return x<y?x:y;
}
inline long long max(long long x,long long y) {
	return x>y?x:y;
}
inline int get1(int l,int r) {
	int len=L[r-l+1];
	return min(st1[l][len],st1[r-(1<<len)+1][len]);
}
inline int get2(int l,int r) {
	int len=L[r-l+1];
	return max(st2[l][len],st2[r-(1<<len)+1][len]);
}
inline int get3(int l,int r) {
	int len=L[r-l+1];
	return min(st3[l][len],st3[r-(1<<len)+1][len]);
}
inline int get4(int l,int r) {
	int len=L[r-l+1];
	return max(st4[l][len],st4[r-(1<<len)+1][len]);
}
inline int get5(int l,int r) {
	int len=L[r-l+1];
	return min(st5[l][len],st5[r-(1<<len)+1][len]);
}
inline int get6(int l,int r) {
	int len=L[r-l+1];
	return max(st6[l][len],st6[r-(1<<len)+1][len]);
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for (int i=1;i<=100000;i++) L[i]=floor(log2(i));
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++) {
		a[i]=read();
		if (a[i]>0) st3[i][0]=st4[i][0]=a[i],st5[i][0]=2e9,st6[i][0]=-2e9,pre1[i]=pre1[i-1]+1,pre2[i]=pre2[i-1];
		else st5[i][0]=st6[i][0]=a[i],st3[i][0]=2e9,st4[i][0]=-2e9,pre1[i]=pre1[i-1],pre2[i]=pre2[i-1]+1;
	}
	for (int i=1;i<=m;i++) {
		b[i]=read();
		st1[i][0]=st2[i][0]=b[i];
	}
	for (int i=1;(1<<i)<=m;i++) {
		for (int j=1;j+(1<<i)-1<=m;j++) {
			st1[j][i]=min(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
			st2[j][i]=max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i=1;(1<<i)<=n;i++) {
		for (int j=1;j+(1<<i)-1<=n;j++) {
			st3[j][i]=min(st3[j][i-1],st3[j+(1<<(i-1))][i-1]);
			st4[j][i]=max(st4[j][i-1],st4[j+(1<<(i-1))][i-1]);
			st5[j][i]=min(st5[j][i-1],st5[j+(1<<(i-1))][i-1]);
			st6[j][i]=max(st6[j][i-1],st6[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i=1;i<=q;i++) {
		int l1=read(),r1=read(),l2=read(),r2=read();
		long long ans=-4e18;
		int g1=get1(l2,r2);
		int g2=get2(l2,r2);
		int g3=get3(l1,r1);
		int g4=get4(l1,r1);
		int g5=get5(l1,r1);
		int g6=get6(l1,r1);
		if (pre2[r1]==pre2[l1-1]) {
			ans=max(ans,max(min(1ll*g3*g1,1ll*g3*g2),min(1ll*g4*g1,1ll*g4*g2)));
		} else if (pre1[r1]==pre1[l1-1]) {
			ans=max(ans,max(min(1ll*g5*g1,1ll*g5*g2),min(1ll*g6*g1,1ll*g6*g2)));
		} else {
			ans=max(ans,max(max(min(1ll*g3*g1,1ll*g3*g2),min(1ll*g4*g1,1ll*g4*g2)),max(min(1ll*g5*g1,1ll*g5*g2),min(1ll*g6*g1,1ll*g6*g2))));
		}
		if (ans<0) ans=-ans,putchar('-');
		write(ans),putchar('\n');
	}
	return 0;
}
