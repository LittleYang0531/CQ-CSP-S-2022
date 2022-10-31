#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int f1[2*N][30],f2[2*N][30],f11[2*N][30],f22[2*N][30];
int n,m,q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	memset(f1,-0x3f,sizeof(f1));
	memset(f11,0x3f,sizeof(f11));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f1[i][0]=a[i];
		f11[i][0]=a[i];
	}
	memset(f2,0x3f,sizeof(f2));
	memset(f22,-0x3f,sizeof(f22));
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		f2[i][0]=b[i];
		f22[i][0]=b[i];
	}
	int k1=log2(n);
	for(int j=1;j<=k1;j++){
		for(int i=1;i<=n;i++){
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f11[i][j]=min(f11[i][j-1],f11[i+(1<<(j-1))][j-1]);
		}
	}
	int k2=log2(m);
	for(int j=1;j<=k2;j++){
		for(int i=1;i<=m;i++){
			f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
			f22[i][j]=max(f22[i][j-1],f22[i+(1<<(j-1))][j-1]);
//			cout<<f2[i][j]<</" ";
		} 
	}
	for(int i=1;i<=q;i++){
		int l,r,l1,r1;
		scanf("%d%d",&l1,&r1);
		int k;
		k=log2(r1-l1+1);
		int sum1=max(f1[l1][k],f1[r1-(1<<k)+1][k]);
		int sum2=min(f11[l1][k],f11[r1-(1<<k)+1][k]);
		bool flag=0;		
		if(l==r)flag=1;
		scanf("%d%d",&l,&r);
		k=log2(r-l+1);
		int sum3=min(f2[l][k],f2[r-(1<<k)+1][k]);
		int sum4=max(f22[l][k],f22[r-(1<<k)+1][k]);
		if(l==r){
			if(b[l]>=0){
				printf("%d\n",b[l]*sum1);
			}
			else{
				printf("%d\n",b[l]*sum2);
			}
			continue;
		}
		if(flag==1){
			if(a[l]>=0){
				printf("%d\n",a[l]*sum3);
			}
			else{
				printf("%d\n",a[l]*sum4);
			}continue;
		}
//		cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<endl;
		if(sum3<0&&sum4<0){
			if(sum2>0)printf("%d\n",sum2*sum3);
			if(sum2<0)printf("%d\n",sum2*sum4);continue;
		}
		if(sum3>0&&sum4>0){
			if(sum1>0)printf("%d\n",sum1*sum3);
			if(sum1<0)printf("%d\n",sum2*sum3);continue;
		}
		if(sum1>0&&sum2>0){
			if(sum3>0)printf("%d\n",sum1*sum3);
			if(sum3<0)printf("%d\n",sum2*sum3);continue;
		}
		if(sum1<0&&sum2<0){
			if(sum4>0)printf("%d\n",sum1*sum4);
			if(sum4<0)printf("%d\n",sum2*sum4);continue;
		}
		int ss1=1e8,ss2=-1e8;
		for(int j=l1;j<=r1;j++){
			if(a[j]>0){
				if(a[j]<ss1){
					ss1=a[j];
				}
			}
			else{
				if(a[j]>ss2){
					ss2=a[j];
				}
			}
		}
		int ans=max(ss1*sum3,ss2*sum4);
		printf("%d\n",ans);
	}
	return 0;
}

