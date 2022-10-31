#include <bits/stdc++.h>
#define in(x) scanf("%lld",&x)
#define out(x) printf("%lld\n",x)
#define int long long
using namespace std ;
const int N=1e5+10;
const int M=2e3+10;
int n,m,q;
int a[N],b[N];
int c[M][M];
int l1,r1,l2,r2;
int A[N],B[N];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    in(n);
    in(m);
    in(q);
    for(int i=1;i<=n;i++) in(a[i]);
    for(int i=1;i<=m;i++) in(b[i]);
    for(int i=1;i<=min(M-1,n);i++){
    	for(int j=1;j<=min(M-1,m);j++) {
    		c[i][j]=a[i]*b[j];
		}
	}
	while(q--){
		cin>>l1>>r1>>l2>>r2;
		memset(B,-0x3f,sizeof B);
		memset(A,0x3f,sizeof A);
		int idx=0,maxn=-0x3f;
		for(int i=l1;i<=r1;i++){
			for(int j=l2;j<=r2;j++){
				A[i]=min(A[i],c[i][j]);
			}
			if(A[i]>maxn) {
				maxn=A[i];
				idx=i;
			}
		}
		int idy=0,minn=0x3f;
		for(int j=l2;j<=r2;j++){
			for(int i=l1;i<=r1;i++){
				B[j]=max(B[j],c[i][j]);
			}
			if(B[j]<minn) {
				minn=B[j];
				idy=j;
			}
		}
		cout<<c[idx][idy]<<endl;
	}
	return false;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
