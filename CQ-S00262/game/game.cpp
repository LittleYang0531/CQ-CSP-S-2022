#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define IL inline
#define int long long
using namespace std;
const int LG=20,Mxk=1005,Mxn=1e5+5,INF=1e18;
int N,M,Q,A[Mxn],B[Mxn],Lg[Mxn],Sx[LG][Mxn],Sn[LG][Mxn],C[Mxk][Mxk];
IL int _() {
	int x=0,f=0;char ch=gc();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}
IL void __(int x) {
	int stk[30],tp=0;
	if(x<0) x=-x,pc('-');
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp) pc(stk[tp--]^48);
}
int Log(int x) {
	int c=0;
	while(x>1) x>>=1,++c;
	return c;
}
int Max(int x,int y) {return x>y?x:y;}
int Min(int x,int y) {return x<y?x:y;}
struct ST{
	int Mn[LG][Mxk],Mx[LG][Mxk];
	void Build(int *A) {
		for(int i=1;i<=M;++i) Mn[0][i]=Mx[0][i]=A[i];
		for(int i=1;i<=Lg[M];++i) {
			for(int j=1;j+(1<<i)-1<=M;++j) {
//				pt("(%d %d) (%d %d) ",Mn[i-1][j],Mn[i-1][j+(1<<(i-1))],
//				Mx[i-1][j],Mx[i-1][j+(1<<(i-1))]);
				Mn[i][j]=Min(Mn[i-1][j],Mn[i-1][j+(1<<(i-1))]);
				Mx[i][j]=Max(Mx[i-1][j],Mx[i-1][j+(1<<(i-1))]);
//				pt("[%d %d] Mn=%d Mx=%d\n",j,j+(1<<i)-1,Mn[i][j],Mx[i][j]);
			}
		}
	}
	int GetMin(int l,int r) {
		int k=Lg[r-l+1];
		return Min(Mn[k][l],Mn[k][r-(1<<k)+1]);
	}
	int GetMax(int l,int r) {
		int k=Lg[r-l+1];
		return Max(Mx[k][l],Mx[k][r-(1<<k)+1]);
	}
}Rw[Mxk];
void Task1() {
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			C[i][j]=A[i]*B[j];
//			pt("%d ",C[i][j]);
		}
//		pc('\n');
		Rw[i].Build(C[i]);
	}
	while(Q--) {
		int lx=_(),rx=_(),ly=_(),ry=_(),Res=-INF;
		for(int i=lx;i<=rx;++i) {
			Res=Max(Res,Rw[i].GetMin(ly,ry));
//			int x=Rw[i].GetMax(ly,ry),y=Rw[i].GetMin(ly,ry);
//			pt("<%d> %d %d\n",i,x,y);
//			if(A[i]<0) Res=Max(Res,A[i]*Rw[i].GetMax(ly,ry));
//			else Res=Max(Res,A[i]*Rw[i].GetMin(ly,ry));
		}
//		pt("The Answer Is_____________");
		__(Res),pc('\n');
	}
}

void Build() {
	for(int i=1;i<=N;++i) Sx[0][i]=A[i];
	for(int i=1;i<=M;++i) Sn[0][i]=B[i];
	for(int i=1;i<=Lg[N];++i) {
		for(int j=1;j+(1<<i)-1<=N;++j) {
			Sx[i][j]=Max(Sx[i-1][j],Sx[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1;i<=Lg[M];++i) {
		for(int j=1;j+(1<<i)-1<=M;++j) {
			Sn[i][j]=Min(Sn[i-1][j],Sn[i-1][j+(1<<(i-1))]);
		}
	}
}
int GetMax(int l,int r) {
	int k=Lg[r-l+1];
	return Max(Sx[k][l],Sx[k][r-(1<<k)+1]);
}
int GetMin(int l,int r) {
	int k=Lg[r-l+1];
	return Min(Sn[k][l],Sn[k][r-(1<<k)+1]);
}
void Task2() {
	Build();
	while(Q--) {
		int lx=_(),rx=_(),ly=_(),ry=_();
//		pt("The Answer Is_____________");
		__(GetMax(lx,rx)*GetMin(ly,ry)),pc('\n');
	}
}
signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	int x=_();__(x);
	N=_(),M=_(),Q=_();
	for(int i=1;i<=Max(N,M);++i) Lg[i]=Log(i);
	for(int i=1;i<=N;++i) A[i]=_();
	for(int i=1;i<=M;++i) B[i]=_();
//	for(int i=1;i<=N;++i) __(A[i]),pc(' ');pc('\n');
//	for(int i=1;i<=M;++i) pt("%d ",B[i]);pc('\n');
//Task1(),exit(0);
//Task2(),exit(0);
	if(N<=1000&&M<=1000&&Q<=1000) {
		Task1();
	}
	else Task2();
	return 0;
}
