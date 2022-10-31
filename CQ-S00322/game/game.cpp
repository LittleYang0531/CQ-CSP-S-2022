#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+3;
int n,m,q,asum[3][N],bsum[3][N];
ll azmin[2][N][20],afmin[2][N][20],bzmin[2][N][20],bfmin[2][N][20],azmax[2][N][20],afmax[2][N][20],bzmax[2][N][20],bfmax[2][N][20];
ll a[N],b[N];
ll mymax(ll x,ll y){
	return x>y?x:y;
}
ll mymin(ll x,ll y){
	return x<y?x:y;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0){	
			asum[0][i]=asum[0][i-1]+1;
			azmin[0][i][0]=a[i];
			azmax[0][i][0]=a[i];
			azmin[1][i][0]=a[i];
			azmax[1][i][0]=a[i];
			afmin[0][i][0]=0;
			afmax[0][i][0]=-1e15;
			afmin[1][i][0]=0;
			afmax[1][i][0]=-1e15;
			asum[1][i]=asum[1][i-1];
			asum[2][i]=asum[2][i-1];
		}
		else if(a[i]==0){
			asum[0][i]=asum[0][i-1];
			asum[1][i]=asum[1][i-1];
			asum[2][i]=asum[2][i-1]+1;
			azmin[0][i][0]=1e15;
			azmax[0][i][0]=0;
			azmin[1][i][0]=1e15;
			azmax[1][i][0]=0;
			afmin[0][i][0]=0;
			afmax[0][i][0]=-1e15;
			afmin[1][i][0]=0;
			afmax[1][i][0]=-1e15;
		}
		else{
			asum[0][i]=asum[0][i-1];
			asum[1][i]=asum[1][i-1]+1;
			asum[2][i]=asum[2][i-1];
			azmin[0][i][0]=1e15;
			azmax[0][i][0]=0;
			azmin[1][i][0]=1e15;
			azmax[1][i][0]=0;
			afmin[0][i][0]=a[i];
			afmax[0][i][0]=a[i];
			afmin[1][i][0]=a[i];
			afmax[1][i][0]=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]>0){	
			bsum[0][i]=bsum[0][i-1]+1;
			bsum[1][i]=bsum[1][i-1];
			bsum[2][i]=bsum[2][i-1];
			bzmin[0][i][0]=b[i];
			bzmax[0][i][0]=b[i];
			bzmin[1][i][0]=b[i];
			bzmax[1][i][0]=b[i];
			bfmin[0][i][0]=0;
			bfmax[0][i][0]=-1e15;
			bfmin[1][i][0]=0;
			bfmax[1][i][0]=-1e15;
		}
		else if(b[i]==0){
			bsum[0][i]=bsum[0][i-1];
			bsum[1][i]=bsum[1][i-1];
			bsum[2][i]=bsum[2][i-1]+1;
			bzmin[0][i][0]=1e15;
			bzmax[0][i][0]=0;
			bzmin[1][i][0]=1e15;
			bzmax[1][i][0]=0;
			bfmin[0][i][0]=0;
			bfmax[0][i][0]=-1e15;
			bfmin[1][i][0]=0;
			bfmax[1][i][0]=-1e15;
		}
		else{
			bsum[0][i]=bsum[0][i-1];
			bsum[1][i]=bsum[1][i-1]+1;
			bsum[2][i]=bsum[2][i-1];
			bzmin[0][i][0]=1e15;
			bzmax[0][i][0]=0;
			bzmin[1][i][0]=1e15;
			bzmax[1][i][0]=0;
			bfmin[0][i][0]=b[i];
			bfmax[0][i][0]=b[i];
			bfmin[1][i][0]=b[i];
			bfmax[1][i][0]=b[i];
		}
	}
	for(int i=1;i<=n;i++){
		int k=2;
		for(int j=1;j<20&&i-k+1>=1;j++){
			azmin[1][i][j]=mymin(azmin[1][i][j-1],azmin[1][i-k/2][j-1]);
			azmax[1][i][j]=mymax(azmax[1][i][j-1],azmax[1][i-k/2][j-1]);
			afmin[1][i][j]=mymin(afmin[1][i][j-1],afmin[1][i-k/2][j-1]);
			afmax[1][i][j]=mymax(afmax[1][i][j-1],afmax[1][i-k/2][j-1]);
			k*=2;
		}
	}
	for(int i=n;i>=1;i--){
		int k=2;
		for(int j=1;j<20&&i+k-1<=n;j++){
			azmin[0][i][j]=mymin(azmin[0][i][j-1],azmin[0][i+k/2][j-1]);
			azmax[0][i][j]=mymax(azmax[0][i][j-1],azmax[0][i+k/2][j-1]);
			afmin[0][i][j]=mymin(afmin[0][i][j-1],afmin[0][i+k/2][j-1]);
			afmax[0][i][j]=mymax(afmax[0][i][j-1],afmax[0][i+k/2][j-1]);
			k*=2;
		}
	}
	for(int i=1;i<=m;i++){
		int k=2;
		for(int j=1;j<20&&i-k+1>=1;j++){
			bzmin[1][i][j]=mymin(bzmin[1][i][j-1],bzmin[1][i-k/2][j-1]);
			bzmax[1][i][j]=mymax(bzmax[1][i][j-1],bzmax[1][i-k/2][j-1]);
			bfmin[1][i][j]=mymin(bfmin[1][i][j-1],bfmin[1][i-k/2][j-1]);
			bfmax[1][i][j]=mymax(bfmax[1][i][j-1],bfmax[1][i-k/2][j-1]);
			k*=2;
		}
	}
	for(int i=m;i>=1;i--){
		int k=2;
		for(int j=1;j<20&&i+k-1<=m;j++){
			bzmin[0][i][j]=mymin(bzmin[0][i][j-1],bzmin[0][i+k/2][j-1]);
			bzmax[0][i][j]=mymax(bzmax[0][i][j-1],bzmax[0][i+k/2][j-1]);
			bfmin[0][i][j]=mymin(bfmin[0][i][j-1],bfmin[0][i+k/2][j-1]);
			bfmax[0][i][j]=mymax(bfmax[0][i][j-1],bfmax[0][i+k/2][j-1]);
			k*=2;
		}
	}
	int l1,r1,l2,r2,az,af,al,bz,bf,bl;
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll ans=0;
		az=asum[0][r1]-asum[0][l1-1];
		af=asum[1][r1]-asum[1][l1-1];
		al=asum[2][r1]-asum[2][l1-1];
		bz=bsum[0][r2]-bsum[0][l2-1];
		bf=bsum[1][r2]-bsum[1][l2-1];
		bl=bsum[2][r2]-bsum[2][l2-1];
		int abj=r1-l1+1,bbj=r2-l2+1,aci=0,bci=0;
		for(int i=1;i*2<abj;i*=2){
			aci++;
		}
		for(int i=1;i*2<bbj;i*=2){
			bci++;
		}
		if(bz){
			if(bf){
				if(bl){
					if(az){
						if(af){
							if(al)ans=0;
							else ans=mymax(mymin(azmin[0][l1][aci],azmin[1][r1][aci])*mymin(bfmin[0][l2][bci],bfmin[1][r2][bci]),mymax(afmax[0][l1][aci],afmax[1][r1][aci])*mymax(bzmax[0][l2][bci],bzmax[1][r2][bci]));
						}
						else{
							if(al)ans=0;
							else ans=mymin(azmin[0][l1][aci],azmin[1][r1][aci])*mymin(bfmin[0][l2][bci],bfmin[1][r2][bci]);
						}
					}
					else{
						if(af){
							if(al)ans=0;
							else ans=mymax(afmax[0][l1][aci],afmax[1][r1][aci])*mymax(bzmax[0][l2][bci],bzmax[1][r2][bci]);
						}
					}
				}
				else{
					if(az){
						if(af){
							if(al)ans=0;
							else{	
								ans=mymax(mymin(azmin[0][l1][aci],azmin[1][r1][aci])*mymin(bfmin[0][l2][bci],bfmin[1][r2][bci]),mymax(afmax[0][l1][aci],afmax[1][r1][aci])*mymax(bzmax[0][l2][bci],bzmax[1][r2][bci]));
//								cout<<azmin[0][l1][aci]<<" "<<azmin[1][r1][aci]<<" "<<bfmin[0][l2][bci]<<" "<<bfmin[1][r2][bci]<<" "<<afmax[0][l1][aci]<<" "<<afmax[1][r1][aci]<<" "<<bzmax[0][l2][bci]<<" "<<bzmax[1][r2][bci]<<endl;
//								cout<<aci<<" "<<bci<<endl;
							}
						}
						else{
							if(al)ans=0;
							else ans=mymin(azmin[0][l1][aci],azmin[1][r1][aci])*mymin(bfmin[0][l2][bci],bfmin[1][r2][bci]);
						}
					}
					else{
						if(af){
							if(al)ans=0;
							else ans=mymax(afmax[0][l1][aci],afmax[1][r1][aci])*mymax(bzmax[0][l2][bci],bzmax[1][r2][bci]);
						}
					}
				}
			}
			else{
				if(bl){
					if(az)ans=0;
					else{
						if(af){
							if(al)ans=0;
							else ans=mymax(afmax[0][l1][aci],afmax[1][r1][aci])*mymax(bzmax[0][l2][bci],bzmax[1][r2][bci]);
						}
					}
				}
				else{
					if(az){
						ans=mymax(azmax[0][l1][aci],azmax[1][r1][aci])*mymin(bzmin[0][l2][bci],bzmin[1][r2][bci]);
					}
					else{
						if(af){
							if(al)ans=0;
							else ans=mymax(afmax[0][l1][aci],afmax[1][r1][aci])*mymax(bzmax[0][l2][bci],bzmax[1][r2][bci]);
						}
					}
				}
			}
		}
		else{
			if(bf){
				if(bl){
					if(az){
						if(af)ans=0;
						else{
							if(al)ans=0;
							else ans=mymin(azmin[0][l1][aci],azmin[1][r1][aci])*mymin(bfmin[0][l2][bci],bfmin[1][r2][bci]);
						}
					}
				}
				else{
					if(az){
						if(af){
							ans=mymin(afmin[0][l1][aci],afmin[1][r1][aci])*mymax(bfmax[0][l2][bci],bfmax[1][r2][bci]);
						}
						else{
							if(al)ans=0;
							else ans=mymin(azmin[0][l1][aci],azmin[1][r1][aci])*mymin(bfmin[0][l2][bci],bfmin[1][r2][bci]);
						}
					}
					else{
						if(af){
							ans=mymin(afmin[0][l1][aci],afmin[1][r1][aci])*mymax(bfmax[0][l2][bci],bfmax[1][r2][bci]);
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
