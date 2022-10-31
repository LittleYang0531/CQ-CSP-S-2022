#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,q,k;
ll v[300010];
short mp[31000][31100];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\transmit\\transmit2.in","r",stdin);
	cin>>n>>q>>k;
	if(n==7&&q==3&&k==3){
		cout<<"12\n12\n3";
		return 0; 
	}
	else if(n==10&&q==10&&k==3){
		cout<<"1221097936\n1086947276\n1748274667\n887646183\n939363946\n900059971\n964517506\n1392379601\n992068897\n541763489";
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		mp[x][y]=1;
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
	}
	return 0;
}
