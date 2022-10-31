#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int l1,l2,r1,r2;
int minn=1000000001,maxn=-1000000001;
int a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=q;i++){
		minn=1000000001;
		maxn=-1000000001;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int j=l1;j<=r1;j++){
			if(a[j]>maxn) maxn=a[j];
		}
		for(int j=l2;j<=r2;j++){
			if(b[j]<minn) minn=b[j];
		}
		printf("%lld\n",maxn*minn);
	}
	return 0;
}
