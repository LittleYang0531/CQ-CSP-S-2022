#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[100005],b[100005];//0+ 1- 2h
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> m >>q ;
	for(int  i = 1;  i <= n ;i++){
		scanf("%lld",&a[i]);
	}
	for(int  i = 1;  i <= m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i = 1; i <= q ;i++){
		int l,r,l2,r2;
		bool asf = 0,bsf = 0;
		long long azd = -9000000000,azx = 1 << 29,azkf = -9000000000,azkz = 1 << 29;
		long long bzd = -9000000000,bzx = 1 << 29,bzkf = -9000000000,bzkz = 1 << 29;
		scanf("%d %d %d %d",&l,&r,&l2,&r2);
		for(int j = l; j <= r; j++){
			azd = max(azd,a[j]);
			azx = min(azx,a[j]);
			if(a[j] < 0 && a[j] > azkf){
				azkf = a[j];
			}
			if(a[j] > 0 && a[j] < azkz){
				azkz = a[j];
			}
			if(a[j]==0){
				asf = 1;
			}
		}
		if(azkf == -9000000000){
			azkf = azkz;
		}
		if(azkz == 1 << 29){
			azkz = azkf;
		}
		for(int j = l2; j <= r2; j++){
			bzd = max(bzd,b[j]);
			bzx = min(bzx,b[j]);
			if(b[j] < 0 && b[j] > bzkf){
				bzkf = b[j];
			}
			if(b[j] > 0 && b[j] < bzkz){
				bzkz = b[j];
			}
			if(b[j]==0){
				bsf = 1;
			}
		}
		if(bzkf == -9000000000){
			bzkf = bzkz;
		}
		if(bzkz == 1 << 29){
			bzkz = bzkf;
		}
		if(bzx < 0){
			if(bzd<=0){
				long long ans = azx * bzd;
				printf("%lld\n",ans);
			}
			else {
				if(asf){
					printf("0\n");
				}
				else{
					if(bzd < 0){
						if(bsf){
							printf("0\n");
						}
						else{
							long long ans = max(azkz * bzx,azkf * bzd);
						printf("%lld\n",ans);
						}
					}
					else{
						long long ans = max(azkz * bzx,azkf * bzd);
						printf("%lld\n",ans);
					}
					
				}
			}
			
		}
		else{
			if(azd < 0){
				if(asf){
					printf("0\n");
				}
				else{
					long long ans = azd * bzd;
					printf("%lld\n",ans);
				}
			}
			else{
				long long ans = azd * bzx;
				printf("%lld\n",ans);
			}
			
			
		}
	}
	return 0;
}
