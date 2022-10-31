#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[100001],b[100001],s[100001];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=q;i++){
		int l1,l2,r1,r2,maxn=-1000000001,maxx,maxy,aa,bb;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int o=l1;o<=r1;o++){
			int minn=1000000001;
			for(int j=l2;j<=r2;j++){
				if(minn>=a[o]*b[j]) aa=o,bb=j;
				minn=min(a[o]*b[j],minn);
			}
			if(maxn<=minn) maxx=aa,maxy=bb;
			maxn=max(maxn,minn);
		}
		s[i]=maxn;
	}
	for(int i=1;i<=q;i++) cout<<s[i]<<endl;
}
