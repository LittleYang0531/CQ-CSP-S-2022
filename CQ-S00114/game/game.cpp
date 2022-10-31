#include<bits/stdc++.h>
using namespace std;
namespace hyS_namespace{
	long long a[100003],b[100003];
	int lf,ls,rf,rs;
	int sig(long long x){
		if(x>0)
			return 1;
		return -(x<0);
	}
	long long mi(bool isa){
		long long ans=LONG_LONG_MAX;
		if(isa){
			for(int i=lf;i<=rf;i++)
				ans=min(ans,a[i]);
			return ans;
		}
		for(int i=ls;i<=rs;i++)
			ans=min(ans,b[i]);
		return ans;
	}
	long long ma(bool isa){
		long long ans=LONG_LONG_MIN;
		if(isa){
			for(int i=lf;i<=rf;i++)
				ans=max(ans,a[i]);
			return ans;
		}
		for(int i=ls;i<=rs;i++)
			ans=max(ans,b[i]);
		return ans;
	}
	long long closezero(bool isa){
		long long ans=LONG_LONG_MAX;
		if(isa){
			for(int i=lf;i<=rf;i++)
				if(abs(ans)>abs(a[i]))
					ans=a[i];
			return ans;
		}
		for(int i=ls;i<=rs;i++)
			if(abs(ans)>abs(b[i]))
				ans=b[i];
		return ans;
	}
	int siging(bool isa){
		if(isa){
			int ans=sig(a[lf]);
			for(int i=lf+1;i<=rf;i++){
				if(ans!=sig(a[i]))
					return 0;
			}
			return ans;
		}
		int ans=sig(b[ls]);
		for(int i=ls+1;i<=rs;i++){
			if(ans!=sig(b[i]))
				return 0;
		}
		return ans;
	}
	int main(){
		long long n,m,q;
		scanf("%lld %lld %lld",&n,&m,&q);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%lld",&b[i]);
		while(q--){
			scanf("%d %d %d %d",&lf,&rf,&ls,&rs);
			long long ans=LONG_LONG_MIN;
			int as=siging(1),bs=siging(0);
			switch(as){
				case 1:
					switch(bs){
						case 1:
							ans=ma(1)*mi(0);
							break;
						default:
							ans=mi(1)*mi(0);
					}
					break;
				case 0:
					switch(bs){
						case 0:
							for(int i=lf;i<=rf;i++)
								if(sig(a[i])>=0)
									ans=max(ans,a[i]*mi(0));
								else
									ans=max(ans,a[i]*ma(0));
							break;
						default:
							ans=ma(bs==1)*mi(bs!=1);
					}
					break;
				case -1:
					switch(bs){
						case -1:
							ans=mi(1)*ma(0);
							break;
						default:
							ans=ma(1)*ma(0);
					}
					break;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main(){
	freopen("game.in","rb",stdin);
	freopen("game.out","wb",stdout);
	hyS_namespace::main();
	return 0;
}
