#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n,m,q,l,r;
int f1[M][20],f2[M][20],f3[M][20],f4[M][20],f5[M][20],f6[M][20],f7[M][20],f8[M][20];
int cnta[M],cntb[M];
int a[M],_a[M],b[M],_b[M],A[M],B[M];
int Get1(int l,int r){
	if(l==r) return f1[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return max(f1[l][e-1],f1[r-(1<<(e-1))+1][e-1]);
}
int Get2(int l,int r){
	if(l==r) return f2[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return min(f2[l][e-1],f2[r-(1<<(e-1))+1][e-1]);
}
int Get3(int l,int r){
	if(l==r) return f3[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return max(f3[l][e-1],f3[r-(1<<(e-1))+1][e-1]);
}
int Get4(int l,int r){
	if(l==r) return f4[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return min(f4[l][e-1],f4[r-(1<<(e-1))+1][e-1]);
}
int Get5(int l,int r){
	if(l==r) return f5[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return max(f5[l][e-1],f5[r-(1<<(e-1))+1][e-1]);
}
int Get6(int l,int r){
	if(l==r) return f6[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return min(f6[l][e-1],f6[r-(1<<(e-1))+1][e-1]);
}
int Get7(int l,int r){
	if(l==r) return f7[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return max(f7[l][e-1],f7[r-(1<<(e-1))+1][e-1]);
}
int Get8(int l,int r){
	if(l==r) return f8[l][0];
	int k=1,e=0;
	while(k<r-l+1){
		k*=2;
		e++;
	}
	return min(f8[l][e-1],f8[r-(1<<(e-1))+1][e-1]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int we=1061109567;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=n;i++){
		cnta[i]=cnta[i-1];
		if(A[i]==0)
		cnta[i]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&B[i]);
	}
	for(int i=1;i<=m;i++){
		cntb[i]=cntb[i-1];
		if(B[i]==0)
		cntb[i]++;
	}
	for(int i=1;i<=n;i++){
		if(A[i]>0){
			a[i]=A[i];
		}
		if(A[i]<0){
			_a[i]=A[i];
		}
	}
	for(int i=1;i<=m;i++){
		if(B[i]>=0){
			b[i]=B[i];
		}
		if(B[i]<0){
			_b[i]=B[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0) a[i]=-we;
		f1[i][0]=a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
		}
	}
	memset(f2,0x3f3f3f3f,sizeof(f2));
	for(int i=1;i<=n;i++){
		if(a[i]==0) a[i]=we;
		f2[i][0]=a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		if(_a[i]==0) _a[i]=-we;
		f3[i][0]=_a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f3[i][j]=max(f3[i][j-1],f3[i+(1<<(j-1))][j-1]);
		}
	}
	memset(f4,0x3f3f3f3f,sizeof(f4));
	for(int i=1;i<=n;i++){
		if(_a[i]==0) _a[i]=we;
		f4[i][0]=_a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f4[i][j]=min(f4[i][j-1],f4[i+(1<<(j-1))][j-1]);
		}
	}
	
	
	for(int i=1;i<=m;i++){
		if(b[i]==0) b[i]=-we;
		f5[i][0]=b[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			f5[i][j]=max(f5[i][j-1],f5[i+(1<<(j-1))][j-1]);
		}
	}
	memset(f6,0x3f3f3f3f,sizeof(f6));
	for(int i=1;i<=m;i++){
		if(b[i]==0) b[i]=we;
		f6[i][0]=b[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			f6[i][j]=min(f6[i][j-1],f6[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		if(_b[i]==0) _b[i]=-we;
		f7[i][0]=_b[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			f7[i][j]=max(f7[i][j-1],f7[i+(1<<(j-1))][j-1]);
		}
	}
	memset(f8,0x3f3f3f3f,sizeof(f8));
	for(int i=1;i<=m;i++){
		if(_b[i]==0) _b[i]=we;
		f8[i][0]=_b[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			f8[i][j]=min(f8[i][j-1],f8[i+(1<<(j-1))][j-1]);
		}
	}
	long long ans;
	for(int i=1;i<=q;i++){
		int l1,l2,r1,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		int aa=Get1(l1,r1),ab=Get2(l1,r1),ac=Get3(l1,r1),ad=Get4(l1,r1);
		int ba=Get5(l2,r2),bb=Get6(l2,r2),bc=Get7(l2,r2),bd=Get8(l2,r2);
		int ak=cnta[r1]-cnta[l1-1],bk=cntb[r2]-cntb[l2-1];
		if(aa!=-we&&ad!=we){
			if(ba!=-we&&bd!=we){
				if(ak>0||bk>0){
					ans=0;
					printf("%lld\n",ans);
					continue;
				}
				ans=max(1ll*ab*bd,1ll*ac*ba);
				printf("%lld\n",ans);
				continue;
			}
			if(ba==-we&&bd!=we){
				if(bk>0){
					ans=0;
					printf("%lld\n",ans);
					continue;
				}
				ans=1ll*ad*bc;
				printf("%lld\n",ans);
					continue;
			}
			if(ba!=-we&&bd==we){
				if(bk>0){
					ans=0;
					printf("%lld\n",ans);
					continue;
				}
				//printf("yzk\n");
				ans=1ll*aa*bb;
				printf("%lld\n",ans);
					continue;
			}
			if(ba==-we&&bd==we){
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
		}
		if(ba!=-we&&bd!=we){
			if(aa!=-we&&ad!=we){
				if(ak>0||bk>0){
					ans=0;
					printf("%lld\n",ans);
					continue;
				}
				ans=max(1ll*ab*bd,1ll*ac*ba);
				printf("%lld\n",ans);
				continue;
			}
			if(aa==-we&&ad!=we){
				if(ak>0){
					ans=0;
					printf("%lld\n",ans);
					continue;
				}
				ans=1ll*bd*ac;
				printf("%lld\n",ans);
					continue;
			}
			if(aa!=-we&&ad==we){
				if(ak>0){
					ans=0;
					printf("%lld\n",ans);
					continue;
				}
				ans=1ll*ba*ab;
				printf("%lld\n",ans);
					continue;
			}
			if(aa==-we&&ad==we){
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
		}
		if(aa==-we&&ad==we){
			ans=0;
			printf("%lld\n",ans);
			continue;
		}
		if(ba==-we&&bd==we){
			ans=0;
			printf("%lld\n",ans);
			continue;
		}
		if(aa==-we&&ba==-we){
			if(bk>0){
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
			ans=1ll*ad*bc;
			printf("%lld\n",ans);
			continue;
		}
		if(ad==we&&bd==we){
			if(bk>0){
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
			ans=1ll*aa*bb;
			printf("%lld\n",ans);
			continue;
		}
		if(aa==-we&&bd==we){
			if(ak>0){
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
			ans=1ll*ac*ba;
			printf("%lld\n",ans);
			continue;
		}
		if(ad==we&&ba==-we){
			if(ak>0){
				ans=0;
				printf("%lld\n",ans);
				continue;
			}
			ans=1ll*ab*bd;
			printf("%lld\n",ans);
			continue;
		}
	}
/*	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",Get3(l,r));
	}*/
}
