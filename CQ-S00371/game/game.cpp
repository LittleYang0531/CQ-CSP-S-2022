#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,q,lg[100005];
struct star{
	vector<int>mx[20],mn[20];
	void build(){
		int n=mx[0].size()-1;
		for(int len=1;len<=lg[n];len++)
		for(int i=1;i+(1<<len)-1<=n;i++){
			mx[len][i]=max(mx[len-1][i],mx[len-1][i+(1<<(len-1))]);
			mn[len][i]=min(mn[len-1][i],mn[len-1][i+(1<<(len-1))]);
		}
	}
	int getmx(int l,int r){
		int len=r-l+1;
		return max(mx[lg[len]][l],mx[lg[len]][r-(1<<lg[len])+1]);
	}
	int getmn(int l,int r){
		int len=r-l+1;
		return min(mn[lg[len]][l],mn[lg[len]][r-(1<<lg[len])+1]);
	}
}A,B,C;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	lg[0]=-1;
	for(int i=1;i<=max(n,m);i++)lg[i]=lg[i>>1]+1;
	for(int i=0;i<20;i++){
		A.mx[i].resize(n+1),A.mn[i].resize(n+1);
		B.mx[i].resize(m+1),B.mn[i].resize(m+1);
		C.mx[i].resize(n+1,-inf),C.mn[i].resize(n+1,inf);
	}
	for(int i=1,tmp;i<=n;i++){
		scanf("%d",&tmp);
		A.mn[0][i]=A.mx[0][i]=tmp;
		if(tmp<=0)C.mx[0][i]=max(C.mx[0][i],tmp);
		if(tmp>=0)C.mn[0][i]=min(C.mn[0][i],tmp);
	}
	for(int i=1,tmp;i<=m;i++){
		scanf("%d",&tmp);
		B.mn[0][i]=B.mx[0][i]=tmp;
	}
	A.build(),B.build(),C.build();
	while(q--){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int mx1=A.getmx(l1,r1),mn1=A.getmn(l1,r1);
		int mx2=B.getmx(l2,r2),mn2=B.getmn(l2,r2);
		int mx3=C.getmx(l1,r1),mn3=C.getmn(l1,r1);
		if(mx1>=0&&mn2>=0)printf("%lld\n",1ll*mx1*mn2);
		else if(mn1>=0&&mn2<=0)printf("%lld\n",1ll*mn1*mn2);
		else if(mx1>=0&&mn1<=0&&mx2>=0&&mn2<=0)printf("%lld\n",max(1ll*mn3*mn2,1ll*mx3*mx2));
		else if(mx1<=0&&mx2>=0)printf("%lld\n",1ll*mx1*mx2);
		else printf("%lld\n",1ll*mn1*mx2);
	}return 0;
}
