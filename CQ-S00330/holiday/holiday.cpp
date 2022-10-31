#include <bits/stdc++.h>
using namespace std;
long long maxn=-1;
int n,m,k,a[2501][2501],p[2501];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	p[1]=0;
	for(int i=2;i=n;i++){
		scanf("%d",p[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	long long s=0;
	for(int i=1;i<=4;i++){
		long long maxn1=-1,l;
		for(int j=1;j<=n;j++){
			if(maxn1<p[j]) l=j;
			long long o=p[j];
			maxn1=max(maxn1,o);
		}
		s+=maxn;
		p[l]=0;
	}
	cout<<s;
}
