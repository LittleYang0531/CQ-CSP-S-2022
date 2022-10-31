#include<bits/stdc++.h>
using namespace std;
long long a[200000],b[200000];
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,m,q;
	n=read(),m=read(),q=read();
	for(long long i=1;i<=n;i++)a[i]=read();
	for(long long i=1;i<=m;i++)b[i]=read();
	while(q--){
		long long ans=-1;
		long long l1,r1,l2,r2;
		l1=read(),r1=read(),l2=read(),r2=read();
		if(l1==r1){
			ans=a[l1]*b[l2];
			for(long long i=l2+1;i<=r2;i++){
				ans=min(ans,a[l1]*b[i]);
			}
		}
		else if(l2==r2){
			ans=a[l1]*b[l2];
			for(long long i=l1+1;i<=r1;i++){
				ans=max(ans,a[i]*b[l2]);
			}
		}
		else {
			for(long long i=l1;i<=r1;i++){
				long long MIN=a[i]*b[l2];
				for(long long j=l2+1;j<=r2;j++){
					MIN=min(MIN,a[i]*b[j]);
				}
				if(i==l1)ans=MIN;
				ans=max(ans,MIN);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

