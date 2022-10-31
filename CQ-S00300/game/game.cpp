#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace TYGAKIOI{
	int a[100010],b[100010];
	int minn[100010],maxn[100010];
	int n,m,q;
	void work(){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int ans1=-0x7fffffff,cnt1;
		for(int i=l1;i<=r1;i++){
			int minn=0x7fffffff;
			for(int j=l2;j<=r2;j++)
				minn=min(minn,a[i]*b[j]);
			if(ans1<minn){
				ans1=minn;
				cnt1=i;
			}
		}
		int ans2=0x7fffffff,cnt2;
		for(int j=l2;j<=r2;j++){
			int maxn=-0x7fffffff;
			for(int i=l1;i<=r1;i++)
				maxn=max(maxn,a[i]*b[j]);
			if(ans2>maxn){
				ans2=maxn;
				cnt2=j;
			}
		}
		printf("%d\n",a[cnt1]*b[cnt2]);
	}
	int main(){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		while(q--)
			work();
		return 0;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	TYGAKIOI::main();
	return 0;
}
