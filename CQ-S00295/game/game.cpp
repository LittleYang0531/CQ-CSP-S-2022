#include<bits/stdc++.h>
//stO stO stO Orz Orz Orz¿¼Éñ£¨»®µô£©CCF±£ÓÓ 
using namespace std;
#define il inline
#define ll long long
#define N 100010
il ll read(){
	ll x=0;
	bool w=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch==45) w=0;
		ch=getchar();
	}while(ch>47&&ch<58){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return (w)?(x):(-x);
}
int n,m,QAQ;
ll a[N],b[N];
bool t=1;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),QAQ=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<=0) t=0;
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		if(b[i]<=0) t=0;
	}
	while(QAQ--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(t){
			ll mx=0,mn=0x7fffffffffffffff;
			for(int i=l1;i<=r1;i++){
				mx=max(mx,a[i]);
			}for(int j=l2;j<=r2;j++){
				mn=min(mn,b[j]);
			}
			printf("%lld\n",mx*mn);
		}else if(l1==r1){
			if(a[l1]==0) puts("0");
			else if(a[l1]>0){
				ll mn=0x7fffffffffffffff;
				for(int j=l2;j<=r2;j++){
					mn=min(mn,b[j]);
				}
				printf("%lld\n",a[l1]*mn);
			}else{
				ll mx=-0x7fffffffffffffff;
				for(int j=l2;j<=r2;j++){
					mx=max(mx,b[j]);
				}
				printf("%lld\n",a[l1]*mx);
			}
		}else if(l2==r2){
			if(b[l2]==0) puts("0");
			else if(b[l2]>0){
				ll mx=-0x7fffffffffffffff;
				for(int j=l1;j<=r1;j++){
					mx=max(mx,a[j]);
				}
				printf("%lld\n",b[l2]*mx);
			}else{
				ll mn=0x7fffffffffffffff;
				for(int j=l1;j<=r1;j++){
					mn=min(mn,a[j]);
				}
				printf("%lld\n",b[l2]*mn);
			}
		}
		else puts("0");
	}
	return 0;
}
