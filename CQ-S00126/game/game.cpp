#include<bits/stdc++.h>

using namespace std;
long long int a[100005],b[100005],c[100005][100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[i]*b[j];
			
		}
		
	}
	int l1,r1,l2,r2;
	while(q--){
		long long int rer=-999999,re=999999,ret=999999;
		cin>>l1>>r1>>l2>>r2;
		for(int i=l1;i<=r1;i++)
		{
			re=999999;
			for(int j=l2;j<=r2;j++){
				re=min(re,c[i][j]);
			}
			
			if(re>rer){
					rer=re;
					ret=i;
				}
		}
		long long int re2=999999,t2;
		for(int j=l2;j<=r2;j++){
			if(c[ret][j]<re2){
				re2=c[ret][j];
				t2=j;
			}
		}
		cout<<c[ret][t2]<<endl;
	}
	return 0;
}
