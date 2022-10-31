#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int qwe=1e5+4;
int n,m,q,a[qwe],b[qwe],ans;
/*
c[i][j]=a[i]*b[j]
*/
int minn[204][204][204];//第i行地j~k的最小值
void work1(){
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j){
			minn[i][j][j-1]=1e9;
			for(re int k=j;k<=m;++k)
				minn[i][j][k]=min(minn[i][j][k-1],a[i]*b[k]);
		}
	int l1,r1,l2,r2;
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int ans=-1e9;
		for(re int i=l1;i<=r1;++i)ans=max(ans,minn[i][l2][r2]);
		printf("%d\n",ans);
	}	
}
void work2(){
	int l1,r1,l2,r2;
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1){
			ans=1e9;
			for(re int i=l2;i<=r2;++i)ans=min(ans,a[l1]*b[i]);
			printf("%d\n",ans);
		}
		else if(l2==r2){
			ans=-1e9;
			for(re int i=l1;i<=r2;++i)ans=max(ans,a[i]*b[l2]);
			printf("%d\n",ans);
		}
		else{
			cout<<endl;
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(re int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(re int i=1;i<=m;++i)scanf("%d",&b[i]);
	if(n<=200&&m<=200)work1();
	else work2();
	return 0;
}
