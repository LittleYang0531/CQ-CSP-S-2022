#include<bits/stdc++.h>
#define ll1 long long
using namespace std;
const ll1 N=1e6+10;
ll1 n,m9,q;
ll1 a[N],b[N];
ll1 m[6][6];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m9,&q);
	for(ll1 i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll1 i=1;i<=m9;i++){
		scanf("%lld",&b[i]);
	}
	m[1][1]=21;
	m[1][2]=12;
	m[1][3]=12;
	m[1][4]=0;
	m[2][1]=12;
	m[2][2]=21;
	m[2][3]=21;
	m[2][4]=22;
	m[3][1]=12;
	m[3][2]=21;
	m[3][3]=21;
	m[3][4]=0;
	m[4][1]=0;
	m[4][2]=0;
	m[4][3]=0;
	m[4][4]=0;
	while(q--){
		ll1 l1,r1,l2,r2,ans=0;
		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
		ll1 c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
		ll1 m1=0,m2=1e10,m3=0,m4=1e10;
		ll1 x=(r1-l1+1),y=(r2-l2+1);
		for(ll1 i=l1;i<=r1;i++){
			m1=max(m1,a[i]);
			m2=min(m2,a[i]);
			if(a[i]>0){
				c1++;
			}else if(a[i]==0) c3++;
			else c2++;
		}
		for(ll1 i=l2;i<=r2;i++){
			m3=max(m3,b[i]);
			m4=min(m4,b[i]);
			if(b[i]>0){
				c4++;
			}else if(b[i]==0) c6++;
			else c5++;
		}
		if(c6>0||c3>0){
			printf("0\n");
			continue;
		}
		ll1 tmp;
		if(c1==x) c1=1;
		else if(c2==x) c1=2;
		else c1=3;
		if(c4==y) c2=1;
		else if(c5==y) c2=2;
		else c2=3;
		tmp=m[c1][c2];
		if(tmp==12){
			printf("%lld\n",m1*m4);
		}else if(tmp==21){
			printf("%lld\n",m2*m3);
		}else{
			printf("%lld\n",m1*m3);
		}
	}
	return 0; 
}
