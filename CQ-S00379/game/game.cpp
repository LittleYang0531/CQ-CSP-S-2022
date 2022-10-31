#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[100005],b[100005],LOG[100005];
int F1[100005][20],F2[100005][20];
int f1[100005][20],f2[100005][20],f3[100005][20],f4[100005][20];
int MAX(int l,int r){
	int k=LOG[r-l+1];
	return max(f1[l][k],f1[r-(1<<k)+1][k]);
}
int MAX1(int l,int r){
	int k=LOG[r-l+1];
	return max(F1[l][k],F1[r-(1<<k)+1][k]);
}
int MAX2(int l,int r){
	int k=LOG[r-l+1];
	return max(f2[l][k],f2[r-(1<<k)+1][k]);
}
int MIN(int l,int r){
	int k=LOG[r-l+1];
	return min(f3[l][k],f3[r-(1<<k)+1][k]);
}
int MIN1(int l,int r){
	int k=LOG[r-l+1];
	return min(F2[l][k],F2[r-(1<<k)+1][k]);
}
int MIN2(int l,int r){
	int k=LOG[r-l+1];
	return min(f4[l][k],f4[r-(1<<k)+1][k]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f1[i][0]=a[i],f2[i][0]=(a[i]<=0?a[i]:-0x3f3f3f3f),f3[i][0]=a[i],f4[i][0]=(a[i]>=0?a[i]:0x3f3f3f3f);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),F1[i][0]=F2[i][0]=b[i];
	for(int i=1;i<=max(n,m);i++)LOG[i]=log2(i);
	int t=log2(n);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n-(1<<i)+1;j++){
			f1[j][i]=max(f1[j][i-1],f1[j+(1<<(i-1))][i-1]);//MAX
			f2[j][i]=max(f2[j][i-1],f2[j+(1<<(i-1))][i-1]);//MAX2
			f3[j][i]=min(f3[j][i-1],f3[j+(1<<(i-1))][i-1]);//MIN
			f4[j][i]=min(f4[j][i-1],f4[j+(1<<(i-1))][i-1]);//MIN2
		}
	}
	t=log2(m);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=m-(1<<i)+1;j++){
			F1[j][i]=max(F1[j][i-1],F1[j+(1<<(i-1))][i-1]);//MAX1
			F2[j][i]=min(F2[j][i-1],F2[j+(1<<(i-1))][i-1]);//MIN2
		}
	}
	for(int i=1,l,r,L,R;i<=q;i++){
		scanf("%d%d%d%d",&l,&r,&L,&R);
		long long ans=-1e18;
		if(MAX(l,r)>=0&&MIN1(L,R)>=0)ans=max(ans,1ll*MAX(l,r)*MIN1(L,R));
		if(MAX(l,r)>=0&&MIN1(L,R)<=0)ans=max(ans,1ll*MIN2(l,r)*MIN1(L,R));
		if(MIN(l,r)<=0&&MAX1(L,R)<=0)ans=max(ans,1ll*MIN(l,r)*MAX1(L,R));
		if(MIN(l,r)<=0&&MAX1(L,R)>=0)ans=max(ans,1ll*MAX2(l,r)*MAX1(L,R));
		printf("%lld\n",ans);
	}
	return 0;
}

