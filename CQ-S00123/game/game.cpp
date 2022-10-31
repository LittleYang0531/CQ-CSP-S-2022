#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int n,m,q;
int a[100010],b[100010],l1,r1,ll,rr;
//struct node {
//	int v[MAXN<<2];
//	build()
//};
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(int i=1; i<=m; i++)scanf("%d",&b[i]);
	for(int i=1; i<=q; i++) {
		scanf("%d%d%d%d",&l1,&r1,&ll,&rr);
		int maxn=-INT_MAX,minn=INT_MAX,jd=INT_MAX,jx=-INT_MAX;
		for(int j=l1; j<=r1; j++) {
			maxn=max(maxn,a[j]),minn=min(minn,a[j]);
			if(a[j]<=0&&a[j]>jx)jx=a[j];
			if(a[j]>=0&&a[j]<jd)jd=a[j];
		}
		int maxn1=-INT_MAX,minn1=INT_MAX,jd1=INT_MAX,jx1=-INT_MAX;
		for(int j=ll; j<=rr; j++) {
			maxn1=max(maxn1,b[j]),minn1=min(minn1,b[j]);
			if(b[j]<=0&&b[j]>jx)jx1=b[j];
			if(b[j]>=0&&b[j]<jd)jd1=b[j];
		}
		if(minn1<=0&&maxn1<=0)cout<<minn*maxn1<<endl;
		if(minn1>0)cout<<maxn*minn1<<endl;
		if(minn1<0&&maxn1>0){
			if(maxn1>-minn1)cout<<jd*minn1<<endl;
			else cout<<jx*maxn1<<endl;
		}
	}
	return 0;
}

