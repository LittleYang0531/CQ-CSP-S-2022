#include<bits/stdc++.h>
#define LL long long
#define Max(x,y) (x<y?y:x)
#define Min(x,y) (x<y?x:y)
#define LLF (1e18+10)
using namespace std;
void read(int&x){
	x=0;
	int fh=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c == '-')fh=-1;
		c=getchar();
	}
	while(c<':'&&'/'<c){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=fh;
}
void read_LL(LL&x){
	x=0;
	int fh=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c == '-')fh=-1;
		c=getchar();
	}
	while(c<':'&&'/'<c){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=fh;
}

int n,m,q;
LL a[100005],b[100005];
LL s[1005][1005][13];
int lo[1005];
void stset(){
	for(int i=2;i<=n;i++){
		lo[i]=lo[i>>1]+1;
	}
	memset(s,128,sizeof s);
	for(int ijk=1;ijk<=n;ijk++){
		for(int i=1;i<=m;i++)s[ijk][i][0]=a[ijk]*b[i];
		for(int k=1;k<=11;k++){
			for(int i=1;i+(1<<k)-1<=n;i++){
				s[ijk][i][k]=min(s[ijk][i][k-1],s[ijk][i+(1<<(k-1))][k-1]);
//				cout<<s[ijk][i][k]<<' ';
			}
//			cout<<"{{{{{";
		}
//	cout<<endl;
	}
}
void f1(){
	stset();
	for(int ijk=1;ijk<=q;ijk++){
		int l1,r1,l2,r2;
		read(l1);
		read(r1);
		read(l2);
		read(r2);
		LL mx=-LLF;
		for(int i=l1;i<=r1;i++){
			LL mn=Min(s[i][l2][lo[r2-l2]],s[i][r2-(1<<lo[r2-l2])+1][lo[r2-l2]]);
			mx=Max(mx,mn);
		}
		printf("%lld\n",mx);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=n;i++)read_LL(a[i]);
	for(int i=1;i<=m;i++)read_LL(b[i]);
	f1();
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2


*/ 
