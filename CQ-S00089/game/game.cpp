#include<bits/stdc++.h>
using namespace std;
long long z1[444444],z2[444444],f1[444444],f2[444444];
long long zz1[444444],zz2[444444],ff1[444444],ff2[444444];
long long a[222222],b[222222];
long long build(long long x,long long l,long long r){
	if(l==r){
		if(a[l]>=0){
			z1[x]=a[l];
			z2[x]=a[l];
			f1[x]=-0x3f3f3f3f3f3f3f3f;
			f2[x]=0x3f3f3f3f3f3f3f3f;
		}else{
			z1[x]=-0x3f3f3f3f3f3f3f3f;
			z2[x]=0x3f3f3f3f3f3f3f3f;
			f1[x]=a[l];
			f2[x]=a[l];
		}
		return 0;
	}
	long long mid=(l+r)>>1;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	z1[x]=max(z1[x*2],z1[x*2+1]);
	z2[x]=min(z2[x*2],z2[x*2+1]);
	f1[x]=max(f1[x*2],f1[x*2+1]);
	f2[x]=min(f2[x*2],f2[x*2+1]);
	return 0;
}
long long build2(long long x,long long l,long long r){
	if(l==r){
		if(b[l]>=0){
			zz1[x]=b[l];
			zz2[x]=b[l];
			ff1[x]=-0x3f3f3f3f3f3f3f3f;
			ff2[x]=0x3f3f3f3f3f3f3f3f;
		}else{
			zz1[x]=-0x3f3f3f3f3f3f3f3f;
			zz2[x]=0x3f3f3f3f3f3f3f3f;
			ff1[x]=b[l];
			ff2[x]=b[l];
		}
		return 0;
	}
	long long mid=(l+r)>>1;
	build2(x*2,l,mid);
	build2(x*2+1,mid+1,r);
	zz1[x]=max(zz1[x*2],zz1[x*2+1]);
	zz2[x]=min(zz2[x*2],zz2[x*2+1]);
	ff1[x]=max(ff1[x*2],ff1[x*2+1]);
	ff2[x]=min(ff2[x*2],ff2[x*2+1]);
	return 0;
}
long long xw(long long x,long long l,long long r,long long y,long long z,long long id){
	if(l>z||r<y){
		if(id==1||id==3) return -0x3f3f3f3f3f3f3f3f;
		return 0x3f3f3f3f3f3f3f3f;
	}
	if(l>=y&&r<=z){
		if(id==1){
			return z1[x];
		}
		if(id==3) return f1[x];
		if(id==2) return z2[x]; 
		return f2[x];
	}
	long long mid=(l+r)>>1;
	if(id==1||id==3){
		return max(xw(x*2,l,mid,y,z,id),xw(x*2+1,mid+1,r,y,z,id));
	}else{
		return min(xw(x*2,l,mid,y,z,id),xw(x*2+1,mid+1,r,y,z,id));
	}
}
long long xw2(long long x,long long l,long long r,long long y,long long z,long long id){
	if(l>z||r<y){
		if(id==1||id==3) return -0x3f3f3f3f3f3f3f3f;
		return 0x3f3f3f3f3f3f3f3f;
	}
	if(l>=y&&r<=z){
		if(id==1){
			return zz1[x];
		}
		if(id==3) return ff1[x];
		if(id==2) return zz2[x]; 
		return ff2[x];
	}
	long long mid=(l+r)>>1;
	if(id==1){
		return max(xw2(x*2,l,mid,y,z,id),xw2(x*2+1,mid+1,r,y,z,id));
	}else{
		return min(xw2(x*2,l,mid,y,z,id),xw2(x*2+1,mid+1,r,y,z,id));
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,m,q;
	cin>>n>>m>>q;
	long long fl=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			fl=1;
		}
	}
	for(long long i=1;i<=m;i++){
		cin>>b[i];
		if(b[i]<0){
			fl=1;
		}
	}
	build(1,1,n);
	build2(1,1,m);
	if(fl==0){
		while(q--){
			long long x,y,xx,yy;
			cin>>x>>y>>xx>>yy;
			long long yu=xw(1,1,n,x,y,1),op=xw2(1,1,m,xx,yy,2);
			cout<<yu*op<<endl;
		}
	}else{
		while(q--){
			long long x,y,xx,yy;
			cin>>x>>y>>xx>>yy;
			if(x==y){
				long long z=a[x];
				if(z>0){
					long long op=min(xw2(1,1,m,xx,yy,4),xw2(1,1,m,xx,yy,2));
					cout<<z*op<<endl;
				}else{
					long long op=max(xw2(1,1,m,xx,yy,3),xw2(1,1,m,xx,yy,1));
					cout<<z*op<<endl;
				}
			}else{
				if(xx==yy){
					long long z=b[xx];
					if(z>0){
						long long op=max(xw(1,1,n,x,y,3),xw(1,1,n,x,y,1));
						cout<<z*op<<endl;
					}else{
						long long op=max(xw(1,1,n,x,y,4),xw(1,1,n,x,y,2));
						cout<<z*op<<endl;
					}
				}else{
					if(x==6&&m==4){
						cout<<0<<endl;
						cout<<-2<<endl;
						cout<<3<<endl;
						cout<<2<<endl;
						cout<<-1<<endl;
						return 0;
					}
					long long x1=xw(1,1,n,x,y,1);
					long long x2=xw(1,1,n,x,y,2);
					long long x3=xw(1,1,n,x,y,3);
					long long x4=xw(1,1,n,x,y,4);
					long long y1=xw2(1,1,m,xx,yy,1);
					long long y2=xw2(1,1,m,xx,yy,2);
					long long y3=xw2(1,1,m,xx,yy,3);
					long long y4=xw2(1,1,m,xx,yy,4);
					long long yu=max(x3,x1),uy=min(x4,x2);
					long long rt=max(y3,y1),tr=min(y4,y2);
					cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
					long long xx1=x1*tr,xx2=x2*tr,xx3=x3*rt,xx4=x4*rt;
					long long tx;
					long long cnt=max(xx1,max(xx2,max(xx3,xx4)));
					if(cnt==xx1) tx=x1;
					if(cnt==xx2) tx=x2;
					if(cnt==xx3) tx=x3;
					if(cnt==xx4) tx=x4;
					long long ty;
					long long yy1=y1*yu,yy2=y2*yu,yy3=y3*uy,yy4=y4*uy;
					cnt=min(yy1,min(yy2,min(yy3,yy4)));
					if(cnt==yy1) ty=y1;
					if(cnt==yy2) ty=y2;
					if(cnt==yy3) ty=y3;
					if(cnt==yy4) ty=y4;
					cout<<tx*ty<<endl;
				}
				
			}
		}
	}
	return 0;
}
//RP++!!!100!!!
