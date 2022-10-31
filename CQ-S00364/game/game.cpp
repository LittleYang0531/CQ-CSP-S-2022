#include<bits/stdc++.h>
#pragma GCC optimeze(2)
using namespace std;
const int N=1e5+10; 
long long n,m,q,a[N],b[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(long long dfgd=1;dfgd<=q;dfgd++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		long long mi=99999999999,pos,fmi=-999999999,fmi1=-99999999;
		long long fg=0,zg=0,zr=0,fmx=9999999999,zmx=-99999999999,zmi=999999999999,fg1=0,zg1=0,zr1=0,fmx1=9999999999,zmx1=-99999999999,zmi1=999999999999,absmi=9999999999;
		
		for(int i=l2;i<=r2;i++){
			if(b[i]<0){
				fg=1;
				fmx=min(fmx,b[i]);	
				fmi=max(fmi,b[i]);
			}
			if(b[i]>0){
				zg=1; 
				zmx=max(zmx,b[i]);
				zmi=min(b[i],zmi);
			}
			if(!b[i])zr=1;
		}
	for(int i=l1;i<=r1;i++){
			if(a[i]<0){
				fg1=1;
				fmx1=min(fmx1,a[i]);	
				fmi1=max(fmi1,a[i]);
			}
			if(a[i]>0){
				zg1=1; 
				zmx1=max(zmx1,a[i]);
				zmi1=min(a[i],zmi1);
			}
			if(!a[i])zr1=1;
			if(absmi>abs(a[i])){
				absmi=abs(a[i]);
				pos=a[i];
			}
			if(absmi==abs(a[i])&&pos==-a[i]){
				if(a[i]<0){
					if(-fmx>zmx)pos=a[i];
				}
				else if(a[i]>0){
					if(zmx>-fmx)pos=a[i];
				} 
			}
			}

	if(fg&&zg){
		if(fg1&&zg1){	
			if(pos<0)cout<<pos*zmx<<endl;
			else if(pos>0)cout<<pos*fmx<<endl;
			if(pos==0)cout<<0<<endl; 
		}
		else if(fg1&&!zg1)cout<<pos*zmx<<endl;
		else if(zg1&&!fg1)cout<<pos*fmx<<endl; 
		else if(!zg1&&!fg1&&zr)cout<<0<<endl;
	}
	else if(fg&&!zg){
		if(fg1&&zg1)cout<<fmx1*fmi<<endl;
		else if(!fg1&&zg1)cout<<zmi1*fmx<<endl;
		else if(fg1&&!zg1)cout<<fmx1*fmi<<endl;
		else if(!zg1&&!fg1&&zr)cout<<0<<endl;
	}
	else if(zg&&!fg){
		if(fg1&&zg1)cout<<zmx1*zmi<<endl;
		else if(fg1&&!zg1)cout<<fmi1*zmx<<endl;
		else if(zg1&&!fg1)cout<<zmx1*zmi<<endl;
		else if(!zg1&&!fg1&&zr)cout<<0<<endl;
	}
	else if(!zg&&!fg&&zr)cout<<0;
		}
	return 0;
} //AC£¡AC! AC! 
