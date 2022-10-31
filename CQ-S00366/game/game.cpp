#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long c[1005][1005];
long long a[100005],b[100005];
void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=c[i][0]*c[0][j];
			//cout<<c[i][0]<<" "<<c[0][j]<<endl;
		}
	}
}
int query(int l1,int r1,int l2,int r2){
	long long ans=-0x3f3f3f3f,minj;
	for(int i=l1;i<=r1;i++){
		minj=0x3f3f3f3f;
		for(int j=l2;j<=r2;j++){
			minj=min(minj,a[i]*b[j]);
		}
		ans=max(ans,minj);
	}
	return ans;
}
int query2(int l1,int r1,int l2,int r2){
	long long ans=-0x3f3f3f3f,minj;
	for(int i=l1;i<=r1;i++){
		minj=0x3f3f3f3f;
		for(int j=l2;j<=r2;j++){
			minj=min(minj,c[i][j]);
		}
		ans=max(ans,minj);
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	if(n>100000&&m>100000){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i];
		//build();
		int l1,r1,l2,r2;
		while(q--){
			cin>>l1>>r1>>l2>>r2;
			cout<<query(l1,r1,l2,r2)<<endl;
		}
	}else{
		for(int i=1;i<=n;i++)cin>>c[i][0];
		for(int i=1;i<=m;i++)cin>>c[0][i];
		build();
		int l1,r1,l2,r2;
		while(q--){
			cin>>l1>>r1>>l2>>r2;
			cout<<query2(l1,r1,l2,r2)<<endl;
		}
	}
	return 0;
}
