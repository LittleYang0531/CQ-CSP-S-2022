#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
long long A[100005],B[100005];
int l1,r1,l2,r2;
int read(){
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
	}
	for(int j=1;j<=m;j++){
		scanf("%lld",&B[j]);
	}
	for(int i=1;i<=q;i++){
		l1=read(),r1=read(),l2=read(),r2=read();
		long long Max,Max_,Min,Min_,ans=-1e18;
		long long a,b,c,d;
		int a2,b2,c2,d2;
		a2=b2=c2=d2=0;
		Max=Max_=-1e18;
		Min=Min_=1e18;
		for(int j=l1;j<=r1;j++){
			if(A[j]>=0){
				a2++;
				Max=max(Max,A[j]);
				Min=min(Min,A[j]);
			}else{
				b2++;
				Max_=max(Max_,A[j]);
				Min_=min(Min_,A[j]); 
			}
		}
		a=Max,b=Max_,c=Min,d=Min_;
		Max=Max_=-1e18;
		Min=Min_=1e18;
		for(int j=l2;j<=r2;j++){
			if(B[j]>=0){
				c2++;
				Max=max(Max,B[j]);
				Min=min(Min,B[j]);
			}else{
				d2++; 
				Max_=max(Max_,B[j]);
				Min_=min(Min_,B[j]);
			}
		}
		if(a2&&b2&&c2&&d2){
			ans=max(b*Max,c*Min_);
		}else{
			if(a2&&b2){
				if(c2) ans=a*Min;
				else ans=d*Max_;
			}else if(c2&&d2){
				if(a2) ans=c*Min_;
				else ans=b*Max;
			}else{
				if(b2&&c2) ans=b*Max;
				if(a2&&d2) ans=c*Min_;
				if(a2&&c2) ans=a*Min;
				if(b2&&d2) ans=d*Max_; 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
