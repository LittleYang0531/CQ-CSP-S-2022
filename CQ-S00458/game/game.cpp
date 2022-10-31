#include<iostream>
#include<algorithm>
int n,m,q,l1,r1,l2,r2;

long long int zx(long long int x,long long int y){
	if(x<=y) return x;
	return y;
}
long long int zd(long long int x,long long int y){
	if(x>=y) return x;
	return y;
}

long long int ask(int a[],int b[])
{
	int i,e;
	long long int mina,maxa=-10e17,t;
	for(i=l1;i<=r1;i++){
		mina=10e17;
		for(e=l2;e<=r2;e++){
			t=a[i]*b[e];
			mina=zx(mina,t);
		}
		maxa=zd(maxa,mina);
	}
	return maxa;
}

using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	int a[n+1],b[m+1],i;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	for(i=0;i<q;i++){
		cin>>l1>>r1>>l2>>r2;
		cout<<ask(a,b)<<endl;
	}
	
	return 0;
}
