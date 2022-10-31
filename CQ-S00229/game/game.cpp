#include<bits/stdc++.h>
using namespace std;
void laozhuma_file(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
#define MAXN 100000
int n,m,q;
int a[MAXN+5];
int b[MAXN+5];
int Log[MAXN+5];
int zd1[MAXN+5][17];
int zx1[MAXN+5][17];
int fd1[MAXN+5][17];
int fx1[MAXN+5][17];
int zd2[MAXN+5][17];
int zx2[MAXN+5][17];
int fd2[MAXN+5][17];
int fx2[MAXN+5][17];
int ZD1(int l,int r){
	int s=Log[r-l+1];
	return max(zd1[l][s],zd1[r-(1<<s)+1][s]);
}
int FD1(int l,int r){
	int s=Log[r-l+1];
	return max(fd1[l][s],fd1[r-(1<<s)+1][s]);
}
int ZX1(int l,int r){
	int s=Log[r-l+1];
	return min(zx1[l][s],zx1[r-(1<<s)+1][s]);
}
int FX1(int l,int r){
	int s=Log[r-l+1];
	return min(fx1[l][s],fx1[r-(1<<s)+1][s]);
}

int ZD2(int l,int r){
	int s=Log[r-l+1];
	return max(zd2[l][s],zd2[r-(1<<s)+1][s]);
}
int FD2(int l,int r){
	int s=Log[r-l+1];
	return max(fd2[l][s],fd2[r-(1<<s)+1][s]);
}
int ZX2(int l,int r){
	int s=Log[r-l+1];
	return min(zx2[l][s],zx2[r-(1<<s)+1][s]);
}
int FX2(int l,int r){
	int s=Log[r-l+1];
	return min(fx2[l][s],fx2[r-(1<<s)+1][s]);
}
int main(){
	laozhuma_file();
	Log[1]=0;
	Log[2]=1;
	for(int i=3;i<=MAXN;i++){
		Log[i]=Log[i>>1]+1;
	}
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			zd1[i][0]=0;
			zx1[i][0]=0;
			fd1[i][0]=0;
			fx1[i][0]=0;
		}else
		if(a[i]>0){
			zd1[i][0]=a[i];
			zx1[i][0]=a[i];
			fd1[i][0]=-(0x3f3f3f3f);
			fx1[i][0]=0x3f3f3f3f;
		}else
		if(a[i]<0){
			zd1[i][0]=-(0x3f3f3f3f);
			zx1[i][0]=0x3f3f3f3f;
			fd1[i][0]=-a[i];
			fx1[i][0]=-a[i];
		}
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;(i+(1<<j)-1)<=n;i++){
			zd1[i][j]=max(zd1[i][j-1],zd1[i+(1<<(j-1))][j-1]);
			fd1[i][j]=max(fd1[i][j-1],fd1[i+(1<<(j-1))][j-1]);
			fx1[i][j]=min(fx1[i][j-1],fx1[i+(1<<(j-1))][j-1]);
			zx1[i][j]=min(zx1[i][j-1],zx1[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(b[i]>=0){
			zd2[i][0]=b[i];
			zx2[i][0]=b[i];
			fd2[i][0]=-(0x3f3f3f3f);
			fx2[i][0]=0x3f3f3f3f;
		}
		if(b[i]<=0){
			zd2[i][0]=-(0x3f3f3f3f);
			zx2[i][0]=0x3f3f3f3f;
			fd2[i][0]=-b[i];
			fx2[i][0]=-b[i];
		}
	}
	for(int j=1;(1<<j)<=m;j++){
		for(int i=1;(i+(1<<j)-1)<=m;i++){
			zd2[i][j]=max(zd2[i][j-1],zd2[i+(1<<(j-1))][j-1]);
			fd2[i][j]=max(fd2[i][j-1],fd2[i+(1<<(j-1))][j-1]);
			fx2[i][j]=min(fx2[i][j-1],fx2[i+(1<<(j-1))][j-1]);
			zx2[i][j]=min(zx2[i][j-1],zx2[i+(1<<(j-1))][j-1]);
		}
	}
	int l1,r1,l2,r2;
	long long ans,ans1;
	for(int i=1;i<=q;i++){
		ans=LONG_LONG_MIN;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(ZD1(l1,r1)>=0){
			ans1=LONG_LONG_MAX;
			if(FD2(l2,r2)>=0){
				ans1=min(ans1,-(1ll*ZD1(l1,r1)*FD2(l2,r2)));
			}
			if(ZX2(l2,r2)<0x3f3f3f3f){
				ans1=min(ans1,1ll*ZD1(l1,r1)*ZX2(l2,r2));
			}if(ans1!=LONG_LONG_MAX) 
			ans=max(ans,ans1);
		}
		if(FD1(l1,r1)>=0){
			ans1=LONG_LONG_MAX;
			if(ZD2(l2,r2)>=0){
				ans1=min(ans1,-(1ll*FD1(l1,r1)*ZD2(l2,r2)));
			}
			if(FX2(l2,r2)<0x3f3f3f3f){
				ans1=min(ans1,1ll*FD1(l1,r1)*FX2(l2,r2));
			}if(ans1!=LONG_LONG_MAX) 
			ans=max(ans,ans1);
		}
		if(ZX1(l1,r1)<0x3f3f3f3f){
			ans1=LONG_LONG_MAX;
			if(FD2(l2,r2)>=0){
				ans1=min(ans1,-(1ll*ZX1(l1,r1)*FD2(l2,r2)));
			}
			if(ZX2(l2,r2)<0x3f3f3f3f){
				ans1=min(ans1,1ll*ZX1(l1,r1)*ZX2(l2,r2));
			}if(ans1!=LONG_LONG_MAX) 
			ans=max(ans,ans1);
		}
		if(FX1(l1,r1)<0x3f3f3f3f){
			ans1=LONG_LONG_MAX;
			if(ZD2(l2,r2)>=0){
				ans1=min(ans1,-(1ll*FX1(l1,r1)*ZD2(l2,r2)));
			}
			if(FX2(l2,r2)<0x3f3f3f3f){
				ans1=min(ans1,1ll*FX1(l1,r1)*FX2(l2,r2));
			}if(ans1!=LONG_LONG_MAX) 
			ans=max(ans,ans1);
		}printf("%lld\n",ans);
	}
	return 0;
}

