#include<bits/stdc++.h>
using namespace std;
#define int long long

const int Maxn=1e5+10;
const int INF=1e9+7;
int N,M,Q,A[Maxn],B[Maxn];
bool f,f1;
struct ST{
	int mx[27][Maxn],mn[27][Maxn];
	int &operator [](int t){return mx[0][t];}
	
	void build(int len){
		for(int i=1;i<=len;++i) mn[0][i]=mx[0][i];
		for(int i=1;i<=25;++i){
			for(int j=1;j+(1<<i)-1<=len;++j){
				mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
				mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
			}
		}
	}
	
	int query1(int l,int r){
		int lg=log2(r-l+1);
		return max(mx[lg][l],mx[lg][r-(1<<lg)+1]);
	}
	
	int query2(int l,int r){
		int lg=log2(r-l+1);
		return min(mn[lg][l],mn[lg][r-(1<<lg)+1]);
	}
}SA,SB;

inline int read(){
	int ret=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
	return f?-ret:ret;
}

void Solve1(){
	while(Q--){
		int l1=read(),r1=read(),l2=read(),r2=read(),ans=-INF;
		for(int i=l1;i<=r1;++i){
			int tmp=INF;
			for(int j=l2;j<=r2;++j) tmp=min(tmp,A[i]*B[j]);
			ans=max(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	exit(0);
}

void Solve2(){
	SA.build(N),SB.build(M);
	while(Q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(!f){
			int a=SA.query1(l1,r1),b=SB.query2(l2,r2);
			printf("%lld\n",a*b);
		}
		else{
			int a=SA.query2(l1,r1),b=SB.query1(l2,r2);
			printf("%lld",a*b);
		}
	}
	exit(0);
}

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	N=read(),M=read(),Q=read();
	for(int i=1;i<=N;++i) A[i]=SA[i]=read(),f|=(A[i]<=0),f|=(A[i]>=0);
	for(int i=1;i<=M;++i) B[i]=SB[i]=read(),f|=(B[i]<=0),f1|=(B[i]>=0);
	if((!f)||(!f1)) Solve2();
	Solve1();
	return 0;
}
