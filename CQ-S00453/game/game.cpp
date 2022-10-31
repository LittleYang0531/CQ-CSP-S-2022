#include<bits/stdc++.h>
using namespace std;
inline void qr(int&x){
	bool f=(x=0);
	char c;
	while(c=getchar(),!isdigit(c)) f|=c=='-';
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	x=f?-x:x;
}
const int MAXN=1e5+5;
int a[MAXN],b[MAXN];
int ap[MAXN],bp[MAXN];
int a0[MAXN],b0[MAXN];
int st[MAXN][20][6];
int lg[MAXN];
const int inf=2e9+1;
long long ask(int l,int r,int k){
	int t=lg[r-l+1];
	if(k&1) return min(st[l][t][k],st[r-(1<<t)+1][t][k]);
	return max(st[l][t][k],st[r-(1<<t)+1][t][k]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	qr(n),qr(m),qr(q);
	int N=max(n,m);
	for(int i=1;i<=n;++i) qr(a[i]),ap[i]=ap[i-1]+(a[i]>0),a0[i]=a0[i-1]+(a[i]==0);
	for(int i=1;i<=m;++i) qr(b[i]),bp[i]=bp[i-1]+(b[i]>0),b0[i]=b0[i-2]+(b[i]==0);

	
	for(int i=1;i<=N;++i) st[i][0][1]=st[i][0][3]=st[i][0][5]=inf;
	for(int i=1;i<=N;++i) st[i][0][0]=st[i][0][2]=st[i][0][4]=-inf;
	for(int i=1;i<=n;++i){
		st[i][0][0]=st[i][0][1]=a[i];
		if(a[i]<0) st[i][0][2]=a[i];
		if(a[i]>0) st[i][0][3]=a[i];
	}
	for(int i=1;i<=m;++i){
		st[i][0][4]=st[i][0][5]=b[i];
	}
	lg[0]=-1;
	for(int i=1;i<=N;++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<20;++i){
		for(int j=1;j+(1<<i)-1<=N;++j){
			for(int k=0;k<6;++k){
				if(k&1) st[j][i][k]=min(st[j][i-1][k],st[j+(1<<(i-1))][i-1][k]);
				else	st[j][i][k]=max(st[j][i-1][k],st[j+(1<<(i-1))][i-1][k]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		int l1,r1,l2,r2;
		qr(l1),qr(r1),qr(l2),qr(r2);
		int len1=r1-l1+1,len2=r2-l2+1;
		if(bp[r2]-bp[l2-1]+b0[r2]-b0[l2-1]==len2){
			long long y=ask(l1,r1,0);
			if(y>0)printf("%lld\n",y*ask(l2,r2,5));
			else printf("%lld\n",y*ask(l2,r2,4));
		}
		else if(bp[r2]-bp[l2-1]+b0[r2]-b0[l2-1]==0){
			long long y=ask(l1,r1,1);
			if(y>0)printf("%lld\n",y*ask(l2,r2,5));
			else printf("%lld\n",y*ask(l2,r2,4));
		}
		else{
			if(a0[r1]-a0[l1-1]>0) puts("0");
			else if(ap[r1]-ap[l1-1]==len1) printf("%lld\n",ask(l1,r1,3)*ask(l2,r2,5));
			else if(ap[r1]-ap[l1-1]==0) printf("%lld\n",ask(l1,r1,2)*ask(l2,r2,4));
			else printf("%lld\n",max(ask(l1,r1,3)*ask(l2,r2,5),ask(l1,r1,2)*ask(l2,r2,4)));
		}
	}
}
/*
0: maxa
1: mina
2: max-a
3: min+a
4: maxb
5: minb
*/
/*
期望 100pts
怨言丁真
鉴定为：分类讨论。
加个st表就水过去了。 

18:22 貌似有简单得多的做法，但是无法写完
做法：两边正数的 max,min;负数的 max,min 共 4*4=16 种组合，直接枚举。
好吧似乎更麻烦。 
*/ 
//written by luogu-Stream_X
//coded by luogu-Stream_X
