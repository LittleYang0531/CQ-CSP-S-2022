#include<bits/stdc++.h>
#define int long long
#define inf 10000000000
//belief2022
using namespace std;
struct node{
	int vol,to,next;
};
int rd(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
node e[10086];
int po(int a,int b){
	int s=1;
	while(b){
		if(b&1)s*=a;
		b/=2,a*=a;
	}
	return s;
}
int n,m,k,a[2505],b[10005];
main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=rd();m=rd();k=rd();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	while(k--){
		int l1=rd(),r1=rd(),l2=rd(),r2=rd(),f=0,f2=0,z=0,z1=0,s=0,s2=0,mm1=-10000000000,mm2=-110000000000,mi1=inf,mi2=inf;
		int w=inf,t=-10000000000;
		for(int i=l1;i<=r1;i++){
			if(a[i]<0)f=1,t=max(t,a[i]);
			else if(a[i]>0)s=1,w=min(w,a[i]);
			else z=1,t=w=0;
			mm1=max(mm1,a[i]);
			mi1=min(mi1,a[i]);
		}
		
		for(int i=l2;i<=r2;i++){
			if(b[i]<0)f2=1;
			else if(b[i]>0)s2=1;
			else z1=1;
			mm2=max(mm2,b[i]);
			mi2=min(mi2,b[i]);
		}
		if(f==0){
			if(f2==0){
				cout<<mm1*mi2;
			}else{
				cout<<w*mi2;
			}
		}else{
			if(f2==0){
				cout<<mm1*mi2;
			}else{
				if(s2==0){
					cout<<mi1*mm2;
				}else{
					cout<<max(w*mi2,t*mm2);
				}
			}
		}
		cout<<endl;
	}
}
