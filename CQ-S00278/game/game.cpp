#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,Q,a[100005],b[100005],lg[100005];
bool va[100005][18],vb[100005][18];
int pa[2][100005][18],pb[2][100005][18],na[2][100005][18],nb[2][100005][18];
int qpa0(int l,int r){
	int g=lg[r-l+1];
	return max(pa[0][l][g],pa[0][r-(1<<g)+1][g]);
}
int qpa1(int l,int r){
	int g=lg[r-l+1];
	return min(pa[1][l][g],pa[1][r-(1<<g)+1][g]);
}
int qna0(int l,int r){
	int g=lg[r-l+1];
	return max(na[0][l][g],na[0][r-(1<<g)+1][g]);
}
int qna1(int l,int r){
	int g=lg[r-l+1];
	return min(na[1][l][g],na[1][r-(1<<g)+1][g]);
}
int qpb0(int l,int r){
	int g=lg[r-l+1];
	return max(pb[0][l][g],pb[0][r-(1<<g)+1][g]);
}
int qpb1(int l,int r){
	int g=lg[r-l+1];
	return min(pb[1][l][g],pb[1][r-(1<<g)+1][g]);
}
int qnb0(int l,int r){
	int g=lg[r-l+1];
	return max(nb[0][l][g],nb[0][r-(1<<g)+1][g]);
}
int qnb1(int l,int r){
	int g=lg[r-l+1];
	return min(nb[1][l][g],nb[1][r-(1<<g)+1][g]);
}
bool qexa(int l,int r){
	int g=lg[r-l+1];
	return max(va[l][g],va[r-(1<<g)+1][g]);
}
bool qexb(int l,int r){
	int g=lg[r-l+1];
	return max(vb[l][g],vb[r-(1<<g)+1][g]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	lg[1]=0;
	for(int i=2;i<=max(n,m);i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>0){
			pa[0][i][0]=pa[1][i][0]=a[i];
			na[0][i][0]=-2e9;
		}
		if(a[i]<0){
			na[0][i][0]=na[1][i][0]=a[i];
			pa[1][i][0]=2e9;
		}
		if(a[i]==0)va[i][0]=1;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",b+i);
		if(b[i]>0){
			pb[0][i][0]=pb[1][i][0]=b[i];
			nb[0][i][0]=-2e9;
		}
		if(b[i]<0){
			nb[0][i][0]=nb[1][i][0]=b[i];
			pb[1][i][0]=2e9;
		}
		if(b[i]==0)vb[i][0]=1;
	}
	for(int j=1;j<=17;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			pa[0][i][j]=max(pa[0][i][j-1],pa[0][i+(1<<(j-1))][j-1]);
			na[0][i][j]=max(na[0][i][j-1],na[0][i+(1<<(j-1))][j-1]);
			pa[1][i][j]=min(pa[1][i][j-1],pa[1][i+(1<<(j-1))][j-1]);
			na[1][i][j]=min(na[1][i][j-1],na[1][i+(1<<(j-1))][j-1]);
			va[i][j]=max(va[i][j-1],va[i+(1<<(j-1))][j-1]);
		}
	for(int j=1;j<=17;j++)
		for(int i=1;i+(1<<j)-1<=m;i++){
			pb[0][i][j]=max(pb[0][i][j-1],pb[0][i+(1<<(j-1))][j-1]);
			nb[0][i][j]=max(nb[0][i][j-1],nb[0][i+(1<<(j-1))][j-1]);
			pb[1][i][j]=min(pb[1][i][j-1],pb[1][i+(1<<(j-1))][j-1]);
			nb[1][i][j]=min(nb[1][i][j-1],nb[1][i+(1<<(j-1))][j-1]);
			vb[i][j]=max(vb[i][j-1],vb[i+(1<<(j-1))][j-1]);
		}
	while(Q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int x=qnb1(l2,r2);
		int y=qpb0(l2,r2);
		int p=qna0(l1,r1);
		int q=qpa1(l1,r1);
		bool fl1=qexa(l1,r1);
		bool fl2=qexb(l2,r2);
		if(x&&y){
			if(fl1){
				puts("0");
				continue;
			}else {
				ll ans=-9e18;
				if(q<2e9)ans=max(ans,1ll*x*q);
				if(p>-2e9)ans=max(ans,1ll*y*p);
				printf("%lld\n",ans);
			}
		}else if(x){
			if(p>-2e9){
				if(fl2){
					puts("0");
					continue;
				}
				int ta=qna1(l1,r1),tb=qnb0(l2,r2);
				printf("%lld\n",1ll*ta*tb);
				continue;
			}else{
				if(fl2)puts("0");
				else printf("%lld\n",1ll*x*q);
			}
		}else if(y){
			if(q<2e9){
				if(fl2){
					puts("0");
					continue;
				}
				int ta=qpa0(l1,r1),tb=qpb1(l2,r2);
				printf("%lld\n",1ll*ta*tb);
				continue;
			}else{
				if(fl2)puts("0");
				else printf("%lld\n",1ll*y*p);
			}
		}else puts("0");
	}
	return 0;
}
