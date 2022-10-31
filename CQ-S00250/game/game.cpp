#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],ans[100005];
long long jdz(long long a,long long b){
	if(a>=b)
		return a-b;
	return b-a;
}
int main(){
	int n,m,q;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	for(int i=0,l1,l2,r1,r2;i<q;i++){
		long long zj=INT_MIN,max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX;
		bool zf1=0,zf2=0,zjzf;
		cin>>l1>>r1>>l2>>r2;
		for(int j=l1-1;j<r1;j++){
			max1=max(max1,a[j]);
			min1=min(min1,a[j]);
			if(jdz(zj,0)>jdz(a[j],0)){
				zj=a[j];
				zjzf=0;
			}
			else if(zj==a[j]*-1)
				zjzf=1;
		}
		for(int j=l2-1;j<r2;j++){
			min2=min(min2,b[j]);
			max2=max(max2,b[j]);
			if(b[j]>0)
				zf1=1;
			else if(b[j]<0)
				zf2=1;
		}
		if(!zf1)
			ans[i]=min1*max2;
		else if(!zf2)
			ans[i]=max1*min2;
		else if(zj>=0&&!zjzf)
			ans[i]=zj*min2;
		else if(zj>=0&&zjzf&&max2*-1<min2)
			ans[i]=zj*min2*-1;
		else if(zj<0&&!zjzf)
			ans[i]=zj*max2;
		else
			ans[i]=zj*min2*-1;
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<endl;
	return 0;
}
