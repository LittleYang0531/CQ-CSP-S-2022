#include<iostream>
using namespace std;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    int a[10005],b[10005],yof,n,m,mj[10005];
    int q,l1,r1,l2,r2;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++)cin>>b[j];
	while(q!=0){
		cin>>l1>>r1>>l2>>r2;
		mj[0]=1000000005;yof=-1000000005;
		for(int i=l1;i<=r1;i++){
			long long o=1234567891234567891;
		for(int j=l2;j<=r2;j++){
		if(a[i]*b[j]<o)o=a[i]*b[j];
	}
	mj[i]=o;
	if(mj[i]>yof)  yof=mj[i];
	
	}
	q=q-1;
	cout<<yof<<endl;
   }
   return 0;
}
 

    
                






















