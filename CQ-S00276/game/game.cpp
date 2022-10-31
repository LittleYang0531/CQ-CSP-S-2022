#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100005],b[100005],L1,R1,L2,R2,E1,E2,W1,W2,Zmin1,Zmax1,Zmin2,Zmax2,Fmin1,Fmax1,Fmin2,Fmax2;
int Faminz[100005][20],Famaxz[100005][20],Fbminz[100005][20],Fbmaxz[100005][20];
int Faminf[100005][20],Famaxf[100005][20],Fbminf[100005][20],Fbmaxf[100005][20];
int Faz[100005][20],Fbz[100005][20];
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0){
			Faminz[i][0]=Famaxz[i][0]=a[i];
			Faminf[i][0]=Famaxf[i][0]=1;
			Faz[i][0]=0;
		}else if(a[i]<0){
			Faminf[i][0]=Famaxf[i][0]=a[i];
			Faminz[i][0]=Famaxz[i][0]=-1;
			Faz[i][0]=0;
		}else{
			Faz[i][0]=1;
			Faminf[i][0]=Famaxf[i][0]=1;
			Faminz[i][0]=Famaxz[i][0]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(b[i]>0){
			Fbminz[i][0]=Fbmaxz[i][0]=b[i];
			Fbminf[i][0]=Fbmaxf[i][0]=1;
			Fbz[i][0]=0;
		}else if(b[i]<0){
			Fbminf[i][0]=Fbmaxf[i][0]=b[i];
			Fbminz[i][0]=Fbmaxz[i][0]=-1;
			Fbz[i][0]=0;
		}else{
			Fbz[i][0]=1;
			Fbminf[i][0]=Fbmaxf[i][0]=1;
			Fbminz[i][0]=Fbmaxz[i][0]=-1;
		}
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			if(Faminz[i][j-1]==-1){
				Faminz[i][j]=Faminz[i+(1<<(j-1))][j-1];
			}else if(Faminz[i+(1<<(j-1))][j-1]==-1){
				Faminz[i][j]=Faminz[i][j-1];
			}else{
				Faminz[i][j]=min(Faminz[i][j-1],Faminz[i+(1<<(j-1))][j-1]);
			}
			if(Famaxz[i][j-1]==-1){
				Famaxz[i][j]=Famaxz[i+(1<<(j-1))][j-1];
			}else if(Famaxz[i+(1<<(j-1))][j-1]==-1){
				Famaxz[i][j]=Famaxz[i][j-1];
			}else{
				Famaxz[i][j]=max(Famaxz[i][j-1],Famaxz[i+(1<<(j-1))][j-1]);
			}			
			if(Faminf[i][j-1]==1){
				Faminf[i][j]=Faminf[i+(1<<(j-1))][j-1];
			}else if(Faminf[i+(1<<(j-1))][j-1]==1){
				Faminf[i][j]=Faminf[i][j-1];
			}else{
				Faminf[i][j]=min(Faminf[i][j-1],Faminf[i+(1<<(j-1))][j-1]);
			}
			if(Famaxf[i][j-1]==1){
				Famaxf[i][j]=Famaxf[i+(1<<(j-1))][j-1];
			}else if(Famaxf[i+(1<<(j-1))][j-1]==1){
				Famaxf[i][j]=Famaxf[i][j-1];
			}else{
				Famaxf[i][j]=max(Famaxf[i][j-1],Famaxf[i+(1<<(j-1))][j-1]);
			}
			Faz[i][j]=max(Faz[i][j-1],Faz[i+(1<<(j-1))][j-1]);
		}
	}
	for(int j=1;(1<<j)<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			if(Fbminz[i][j-1]==-1){
				Fbminz[i][j]=Fbminz[i+(1<<(j-1))][j-1];
			}else if(Fbminz[i+(1<<(j-1))][j-1]==-1){
				Fbminz[i][j]=Fbminz[i][j-1];
			}else{
				Fbminz[i][j]=min(Fbminz[i][j-1],Fbminz[i+(1<<(j-1))][j-1]);
			}
			if(Fbmaxz[i][j-1]==-1){
				Fbmaxz[i][j]=Fbmaxz[i+(1<<(j-1))][j-1];
			}else if(Fbmaxz[i+(1<<(j-1))][j-1]==-1){
				Fbmaxz[i][j]=Fbmaxz[i][j-1];
			}else{
				Fbmaxz[i][j]=max(Fbmaxz[i][j-1],Fbmaxz[i+(1<<(j-1))][j-1]);
			}			
			if(Fbminf[i][j-1]==1){
				Fbminf[i][j]=Fbminf[i+(1<<(j-1))][j-1];
			}else if(Fbminf[i+(1<<(j-1))][j-1]==1){
				Fbminf[i][j]=Fbminf[i][j-1];
			}else{
				Fbminf[i][j]=min(Fbminf[i][j-1],Fbminf[i+(1<<(j-1))][j-1]);
			}
			if(Fbmaxf[i][j-1]==1){
				Fbmaxf[i][j]=Fbmaxf[i+(1<<(j-1))][j-1];
			}else if(Fbmaxf[i+(1<<(j-1))][j-1]==1){
				Fbmaxf[i][j]=Fbmaxf[i][j-1];
			}else{
				Fbmaxf[i][j]=max(Fbmaxf[i][j-1],Fbmaxf[i+(1<<(j-1))][j-1]);
			}
			Fbz[i][j]=max(Fbz[i][j-1],Fbz[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--){
		scanf("%d%d%d%d",&L1,&R1,&L2,&R2);
		E1=log2(R1-L1+1);
		E2=log2(R2-L2+1);
		W1=max(Faz[L1][E1],Faz[R1-(1<<E1)+1][E1]);
		W2=max(Fbz[L2][E2],Fbz[R2-(1<<E2)+1][E2]);
		if(Famaxz[L1][E1]==-1){
			Zmax1=Famaxz[R1-(1<<E1)+1][E1];
		}else if(Famaxz[R1-(1<<E1)+1][E1]==-1){
			Zmax1=Famaxz[L1][E1];
		}else{
			Zmax1=max(Famaxz[L1][E1],Famaxz[R1-(1<<E1)+1][E1]);
		}
		if(Faminz[L1][E1]==-1){
			Zmin1=Faminz[R1-(1<<E1)+1][E1];
		}else if(Faminz[R1-(1<<E1)+1][E1]==-1){
			Zmin1=Faminz[L1][E1];
		}else{
			Zmin1=min(Faminz[L1][E1],Faminz[R1-(1<<E1)+1][E1]);
		}
		if(Famaxf[L1][E1]==1){
			Fmax1=Famaxf[R1-(1<<E1)+1][E1];
		}else if(Famaxf[R1-(1<<E1)+1][E1]==1){
			Fmax1=Famaxf[L1][E1];
		}else{
			Fmax1=max(Famaxf[L1][E1],Famaxf[R1-(1<<E1)+1][E1]);
		}
		if(Faminf[L1][E1]==1){
			Fmin1=Faminf[R1-(1<<E1)+1][E1];
		}else if(Faminf[R1-(1<<E1)+1][E1]==1){
			Fmin1=Faminf[L1][E1];
		}else{
			Fmin1=min(Faminf[L1][E1],Faminf[R1-(1<<E1)+1][E1]);
		}	
		if(Fbmaxz[L2][E2]==-1){
			Zmax2=Fbmaxz[R2-(1<<E2)+1][E2];
		}else if(Fbmaxz[R2-(1<<E2)+1][E2]==-1){
			Zmax2=Fbmaxz[L2][E2];
		}else{
			Zmax2=max(Fbmaxz[L2][E2],Fbmaxz[R2-(1<<E2)+1][E2]);
		}
		if(Fbminz[L2][E2]==-1){
			Zmin2=Fbminz[R2-(1<<E2)+1][E2];
		}else if(Fbminz[R2-(1<<E2)+1][E2]==-1){
			Zmin2=Fbminz[L2][E2];
		}else{
			Zmin2=min(Fbminz[L2][E2],Fbminz[R2-(1<<E2)+1][E2]);
		}
		if(Fbmaxf[L2][E2]==1){
			Fmax2=Fbmaxf[R2-(1<<E2)+1][E2];
		}else if(Fbmaxf[R2-(1<<E2)+1][E2]==1){
			Fmax2=Fbmaxf[L2][E2];
		}else{
			Fmax2=max(Fbmaxf[L2][E2],Fbmaxf[R2-(1<<E2)+1][E2]);
		}
		if(Fbminf[L2][E2]==1){
			Fmin2=Fbminf[R2-(1<<E2)+1][E2];
		}else if(Fbminf[R2-(1<<E2)+1][E2]==1){
			Fmin2=Fbminf[L2][E2];
		}else{
			Fmin2=min(Fbminf[L2][E2],Fbminf[R2-(1<<E2)+1][E2]);
		}
		if(Fmin2!=1){
			if(Zmin2!=-1){
				if(W1){
					ans=0;
				}else{
					if(Zmin1!=-1){
						if(Fmin1!=1){
							ans=max((long long)Zmin1*Fmin2,(long long)Fmax1*Zmax2);
						}else{
							ans=(long long)Zmin1*Fmin2;
						}
					}else{
						ans=(long long)Fmax1*Zmax2;
					}
				}
			}else{
				if(Fmin1!=1){
					ans=(long long)Fmin1*Fmax2;
				}else{
					if(W1){
						ans=0;
					}else{
						ans=(long long)Fmin2*Zmin1;
					}
				}
			}
		}else if(Zmin2!=-1){
			if(Zmin1!=-1){
				ans=(long long)Zmin2*Zmax1;
			}else{
				if(W1){
					ans=0;
				}else{
					ans=(long long)Zmax2*Fmax1;
				}
			}
		}else{
			ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
