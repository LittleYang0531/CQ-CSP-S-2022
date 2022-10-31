#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[10005],b[10005],c[10005][10005],l1,r1,l2,r2,maxx1,m1,m2,maxx2,n1,n2,minn1,minn2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=m;i++){
		cin>>b[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			c[i][j]=a[i]*b[j];
		}
	}
	for(int k = 1;k<=q;k++){
		cin>>l1>>r1>>l2>>r2;
		int y=0,s=0,e=0;
		maxx1=a[l1];
		maxx2=b[l2];
		minn1=a[l1];
		minn2=b[l2];
		for(int i = l1;i<=r1;i++){
			if(a[i]==0)e=1;
			if(a[i]>0){
				y=1;
				break;
			}
		}
		for(int i = l1;i<=r1;i++){
			if(maxx1<a[i])maxx1=a[i],m1=i;
			if(minn1<a[i])minn1=a[i],n1=i;	
		}
		for(int j = l2;j<=r2;j++){
			if(maxx2<b[j])maxx2=b[j],m2=j;
			if(minn2<b[j])minn2=b[j],n2=j;	
			if(b[j]<0){
				s=1;
			}
		}
		if(s==1){
			if(e==1)cout<<"0"<<"\n";
			else cout<<c[n1][n2]<<"\n";
		}
		else if(y==0){
			cout<<c[m1][m2]<<"\n";
		}
		else cout<<c[m1][n2]<<"\n";
	}
	return 0;
}
