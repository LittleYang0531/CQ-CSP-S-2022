#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
const int N=1e5+5;
int n,m,q,a[N],b[N],tre[2][2][N*4];
long long Tre[maxn][maxn*4];
bool flag1=1,flag2=1;
long long Tabby(int u,int stdl,int stdr,int l,int r,int i);
void Change(int u,int stdl,int stdr,int x,int num,bool who);
void Melody(int u,int stdl,int stdr,int x,int i,long long num);
int Find(int u,int stdl,int stdr,int l,int r,int who,bool op);
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);if(a[i]<0)flag1=0;
	}for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);if(b[i]<0)flag1=0;
	}
	if(flag1==1){memset(tre[0],-0x3f,sizeof tre[0]);memset(tre[1],0x3f,sizeof tre[1]);
		for(int i=1;i<=n;i++)Change(1,1,n,i,a[i],0);
		for(int i=1;i<=m;i++)Change(1,1,m,i,b[i],1);
		int l1,l2,r1,r2;
		while(q--){
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			printf("%lld\n",(long long)Find(1,1,n,l1,r1,0,0)*Find(1,1,m,l2,r2,1,1));
		}
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n*4;j++){
				Tre[i][j]=4e16;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)Melody(1,1,m,j,i,(long long)a[i]*b[j]);
		}int l1,r1,l2,r2;
		while(q--){
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			long long ans=-4e18;
			for(int i=l1;i<=r1;i++){
				ans=max(ans,Tabby(1,1,m,l2,r2,i));
			}printf("%lld\n",ans);
		}
		return 0;	
	}int l1,r1,l2,r2;memset(tre[0],-0x3f,sizeof tre[0]);memset(tre[1],0x3f,sizeof tre[1]);
	for(int i=1;i<=n;i++)Change(1,1,n,i,a[i],0);
	for(int i=1;i<=m;i++)Change(1,1,m,i,b[i],1);
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1){
			if(a[l1]<0)printf("%lld\n",(long long)a[l1]*Find(1,1,m,l2,r2,1,0));
			else printf("%lld\n",(long long)a[l1]*Find(1,1,m,l2,r2,1,1));
		}else{
			if(b[l2]<0)printf("%lld\n",(long long)b[l2]*Find(1,1,n,l1,r1,0,1));
			else printf("%lld\n",(long long)b[l2]*Find(1,1,n,l1,r1,0,0));
		}
	}
	return 0;
}
void Melody(int u,int stdl,int stdr,int x,int i,long long num){
	if(stdl==x&&stdr==x){
		Tre[i][u]=num;return;
	}
	int mid=(stdl+stdr)/2;
	if(x<=mid)Melody(u*2,stdl,mid,x,i,num);
	else Melody(u*2+1,mid+1,stdr,x,i,num);
	Tre[i][u]=min(Tre[i][u*2],Tre[i][u*2+1]);
}
long long Tabby(int u,int stdl,int stdr,int l,int r,int i){
	if(stdl==l&&stdr==r)return Tre[i][u];
	int mid=(stdl+stdr)/2;
	if(r<=mid)return Tabby(u*2,stdl,mid,l,r,i);
	else if(l>=mid+1)return Tabby(u*2+1,mid+1,stdr,l,r,i);
	else return min(Tabby(u*2,stdl,mid,l,mid,i),Tabby(u*2+1,mid+1,stdr,mid+1,r,i));
}
void Change(int u,int stdl,int stdr,int x,int num,bool who){
	if(stdl==x&&stdr==x){
		tre[0][who][u]=tre[1][who][u]=num;
		return;
	}
	int mid=(stdl+stdr)/2;
	if(x<=mid)Change(u*2,stdl,mid,x,num,who);
	else Change(u*2+1,mid+1,stdr,x,num,who);
	tre[0][who][u]=max(tre[0][who][u*2],tre[0][who][u*2+1]);
	tre[1][who][u]=min(tre[1][who][u*2],tre[1][who][u*2+1]);
}
int Find(int u,int stdl,int stdr,int l,int r,int who,bool op){
	if(stdl==l&&stdr==r){
		return tre[op][who][u];
	}
	int mid=(stdl+stdr)/2;
	if(r<=mid)return Find(u*2,stdl,mid,l,r,who,op);
	else if(l>=mid+1)return Find(u*2+1,mid+1,stdr,l,r,who,op);
	else if(op==0){
		return max(Find(u*2,stdl,mid,l,mid,who,op),Find(u*2+1,mid+1,stdr,mid+1,r,who,op));
	}else{
		return min(Find(u*2,stdl,mid,l,mid,who,op),Find(u*2+1,mid+1,stdr,mid+1,r,who,op));
	}
}
