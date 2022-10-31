#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define IL inline
using namespace std;
const int Mxn=1005,Mxm=1e4+5;
int N,M,Q,R[Mxn][Mxn],F[Mxn][Mxn],Vis[Mxn],Ot[Mxn];
int Ct,Nt[Mxm],To[Mxm],Hd[Mxn];
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
void Merge(int x,int y) {Nt[++Ct]=Hd[x],To[Ct]=y,Hd[x]=Ct;}
void Del(int x,int y) {
	F[x][y]=0,Ot[x]--;
}
void Add(int x,int y) {
	F[x][y]=1,Ot[x]++;
}
void DEL(int x) {
	for(int i=1;i<=N;++i) {
		if(R[i][x]&&F[i][x]) F[i][x]=0,Ot[i]--;
	}
}
void ADD(int x) {
	for(int i=1;i<=N;++i) {
		if(R[i][x]&&!F[i][x]) F[i][x]=1,Ot[i]++;
	}
}
bool DFS(int x) {
	Vis[x]=1; 
//	pt("<%d> ",x);
	for(int v,i=Hd[x];i;i=Nt[i]) {
		if(F[x][v=To[i]]) {
			if(Vis[v]) return 1;
			return DFS(v);
		}
	}
	return 0;
}
bool Check() {
	memset(Vis,0,sizeof(Vis));
//	for(int i=1;i<=N;++i) {
//		pt("[ ");
//		for(int j=1;j<=N;++j) {
//			pt("%d ",F[i][j]);
//		}
//		pt("]\n");
//	}
//	for(int i=1;i<=N;++i) pt("%d ",Ot[i]);pc('\n');
	for(int i=1;i<=N;++i) if(Ot[i]^1) return 0;
	for(int i=1;i<=N;++i) if(!Vis[i]) if(!DFS(i)) return 0;
	return 1;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	N=_(),M=_();
	for(int i=1;i<=M;++i) {
		int x=_(),y=_();
		R[x][y]=1,F[x][y]=1,Ot[x]++;
		Merge(x,y);
	}
	Q=_();
	while(Q--) {
		int t=_(),x=_();
		if(t==1) Del(x,_());
		if(t==2) DEL(x);
		if(t==3) Add(x,_());
		if(t==4) ADD(x);
		pt(Check()?"YES\n":"NO\n");
	}
	return 0;
}
