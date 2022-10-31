#include<iostream>
using namespace std;
const int N=100001;
int n,m,q;
int l1,r1,l2,r2;
long long a[N],b[N],ans[N];
long long tl1,tl2,tq1,tq2;
int L,Q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=0;i<q;i++){
		cin>>l1>>r1>>l2>>r2;
		tl2=a[l1]*b[l2];
		tq2=a[l1]*b[l2];
		L=l1;
		Q=l2;
		for(int x=l1;x<=r1;x++){
			tl1=a[x]*b[l2];
			for(int y=l2;y<=r2;y++)	tl1=tl1<a[x]*b[y]?tl1:a[x]*b[y];
			if(x==l1) tl2=tl1;
			else tl2=tl2>tl1?tl2:tl1;
			if(tl2==tl1) L=x;
//			cout<<tl1<<' '<<tl2<<' ';
//			cout<<L<<' '<<endl;
		}
//		cout<<endl;
		for(int y=l2;y<=r2;y++){
			tq1=a[l1]*b[y];
			for(int x=l1;x<=r1;x++) tq1=tq1>a[x]*b[y]?tq1:a[x]*b[y];
			if(y==l2) tq2=tq1;
			else tq2=tq2<tq1?tq2:tq1;
			if(tq2==tq1) Q=y;
//			cout<<tq1<<' '<<tq2<<' ';
//			cout<<Q<<' '<<endl;
		}
//		cout<<endl;
//		cout<<tl2<<tq2<<endl;
		ans[i]=a[L]*b[Q];
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
