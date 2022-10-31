#include<iostream>
#include<cstdio>
using namespace std;
int maxn=-999;
int minn=999;
int n,m,q;
int cou[1000]={};
int f[1000]={};
int a[1000]={};
int b[1000]={};
int h=999,k=-999,o;
int l1,l2,r1,r2;
int cmp(int x,int y){
	return x<y;
}
int move(int l1,int l2,int r1,int r2){
	for(int i=l1;i<=r1;i++){
		for(int j=l2;j<=r2;j++){
			if(maxn>0&&minn<0&&a[i]==0){
				return o=0;
			}
			if(a[i]<0&&a[i+1]>0){
				if(b[j]<0&&b[j+1]>0){
					return o=a[i+1]*b[j+1];
				}
			}
			if(l1==r1&&l2==r2){
				return o=a[i]*b[i];
			}
			if(l2==r2){
				if(b[i]>0){
					return o=maxn*b[i];
				}
				if(b[i]<0){
					return o=h*b[i];
				}
			}
			if(l1==r1){
				if(a[i]>0){
					return o=k*a[i];
				}
				if(a[i]<0){
					return o=minn*a[i];
				}
			}
		}
	}	
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
		if(a[i]<h) h=a[i];
	} 
	for(int i=1;i<=m;i++){
		cin>>b[i];
		if(b[i]<minn) minn=b[i];
		if(b[i]>k) k=b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>l1>>r1>>l2>>r2;
		move(l1,l2,r1,r2);
		cou[i]={o};
	}
	for(int i=1;i<=q;i++){
		cout<<cou[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

