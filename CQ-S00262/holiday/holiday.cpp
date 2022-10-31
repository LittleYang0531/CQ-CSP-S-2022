#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define IL inline
#define int long long
using namespace std;
const int Mxn=2505,Mxm=1e4+5;
int N,M,K,Ans,A[Mxn],Fg[Mxn],F[Mxn][Mxn];
int Ct,Hd[Mxn],Nt[Mxm<<1],To[Mxm<<1];
//int ct,hd[Mxn],nt[Mxm<<1],to[Mxm<<1];
vector<int> R[Mxn];
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
struct DATA{
	int x,c;
};
queue<DATA> Q;
void Merge(int x,int y) {Nt[++Ct]=Hd[x],To[Ct]=y,Hd[x]=Ct;}
//void merge(int x,int y) {nt[++ct]=hd[x],to[Ct]=y,hd[x]=ct;}
int Max(int x,int y) {return x>y?x:y;}
void Go(int r) {
	Q.push((DATA){r,0});
	while(!Q.empty()) {
		int x=Q.front().x,c=Q.front().c;Q.pop();
		if(c>K) continue;
		for(int v,i=Hd[x];i;i=Nt[i]) {
			if(!F[r][v=To[i]]) F[r][v]=1,R[r].push_back(v);
			Q.push((DATA){v,c+1});
		}
	}
}
signed main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	N=_(),M=_(),K=_();
	for(int i=2;i<=N;++i) A[i]=_();
	for(int i=1;i<=M;++i) {
		int x=_(),y=_();
		Merge(x,y),Merge(y,x);
	}
	for(int i=1;i<=N;++i) Go(i);
//	pt("!!!");
	for(int a:R[1]) {
		for(int b:R[a]) {
			if(a==b) continue;
			for(int c:R[b]) {
				if(a==c||b==c) continue;
				for(int d:R[c]) {
					if(a==d||b==d||c==d||!F[d][1]) continue;
					Ans=Max(Ans,A[a]+A[b]+A[c]+A[d]);
				}
			}
		}
	}
//	for(int a,i=hd[1];i;i=nt[i]) {
//		a=to[i],s+=A[a];
//		for(int b,j=hd[a];j;j=nt[j]) {
//			b=to[j],s+=A[b];
//			for(int c,k=hd[b];k;k=nt[k]) {
//				c=to[k],s+=A[c];
//				for(int h=hd[c];h;h=nt[h]) {
//					pt("%d %d %d\n",a,b,c);
//					if(F[to[h]][1]) Ans=Max(Ans,s+A[to[h]]);
//				}
//				s-=A[c];
//			}
//			s-=A[b];
//		}
//		s-=A[a];
//	}
	__(Ans),pc('\n');
	return 0;
}
