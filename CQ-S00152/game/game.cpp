#include<bits/stdc++.h>
using namespace std;
#define M 100005
typedef long long ll; 
int n,m,q,a[M],l1,r1,l2,r2;
ll ans=LONG_LONG_MIN;
struct node{
	int x,y;
}b[M];
bool cmp(node p,node q){//从小到大排 
	return p.x<q.x;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=m;j++){
		scanf("%d",&b[j].x);
		b[j].y=j;
	}
	sort(b+1,b+1+m,cmp);
	while(q--){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		int mi=1,ma=m;
		ans=LONG_LONG_MIN;
		while(b[mi].y<l2 || b[mi].y>r2)
			mi++;
		while(b[ma].y<l2 || b[ma].y>r2)
			ma--;
		for(int i=l1;i<=r1;i++){
			if(a[i]>=0)
				ans=max(ans,1ll*a[i]*b[mi].x);
			else
				ans=max(ans,1ll*a[i]*b[ma].x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
