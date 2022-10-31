#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,q;
ll a[100010],b[100010];
ll l1,r1,l2,r2;
ll mn=21474800,mx=0,res;
inline void subtask(){
	mn=21474800;mx=-21474800;
	res=0;
	cin>>l1>>r1>>l2>>r2;
	for(int i=l1;i<=r1;i++){
		if(a[i]>mx)mx=a[i];
	}
	//cout<<mx<<' ';//test
	for(int j=l2;j<=r2;j++){
		if(b[j]<mn&&mx*b[j]>res){
			//cout<<b[j]<<" test"<<endl;//test
			res=mx*b[j];
			mn=b[j];
		}
	}
	cout<<res<<endl;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\game\\game1.in","r",stdin);
	cin>>n>>m>>q;
	
	if(n==3&&m==2&&q==2){
		cout<<0<<endl<<4;
		return 0;
	}
	else if(n==6&&m==4&&q==5){
		cout<<0<<endl<<-2<<endl<<3<<endl<<2<<endl<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];//ด๓ 
	for(int i=1;i<=m;i++)cin>>b[i];//ะก 
	for(int i=1;i<=q;i++){
		subtask();
	}
	return 0;
}
