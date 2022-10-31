#include <cstdio>
char ch;
bool fh;
template<typename T>
inline void r(T&x){
	fh=false;
	while((ch=getchar())<48||ch>57)fh=ch==45;
	x=ch^48;
	while((ch=getchar())<58&&ch>47)x=(x<<1)+(x<<3)+(ch^48);
	if(fh)x=-x;
}
template<typename... Ar>
inline void r(Ar&...ar){
	int a[]{(r(ar),0)...};
}
template<typename T>
void uw(T&&x){
	if(x>9)uw(x/10);
	putchar(x%10^48);
}
template<typename T>
void w(T x){
	if(x<0){
		x=-x;
		putchar(45);
	}
	if(x>9)uw(x/10);
	putchar(x%10^48);
}
inline void w(const char&x){
	putchar(x);
}
template<typename... Ar>
inline void w(const Ar&...ar){
	int a[]{(w(ar),0)...};
}
template<typename T>
inline T fi(const T&a,const T&b){
	return a>b?b:a;
}
template<typename T>
inline T fa(const T&a,const T&b){
	return a>b?a:b;
}
int la,lb,q,i,j,l1,l2,r1,r2,x,y,a[100010],b[100010],zma_a[18][100010],zmi_a[18][100010],fma_a[18][100010],fmi_a[18][100010],ma_b[18][100010],mi_b[18][100010],lg[100010],*zmi,*zma,*lzmi,*lzma,*fmi,*fma,*lfmi,*lfma;
template<typename T>
inline T ma(T Ma[][100010],const int&l,const int&r){
	int len=r-l+1,*a=Ma[lg[len]];
	return fa(a[l],a[r-(1<<lg[len])+1]);
}
template<typename T>
inline T mi(T Mi[][100010],const int&l,const int&r){
	int len=r-l+1,*a=Mi[lg[len]];
	return fi(a[l],a[r-(1<<lg[len])+1]);
}
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	r(la,lb,q);
	lzma=zma=*zma_a;
	lzmi=zmi=*zmi_a;
	lfma=fma=*fma_a;
	lfmi=fmi=*fmi_a;
	*lg=-1;
	for(i=1;i<=la;i++){
		r(a[i]);
		if(a[i]>=0){
			zmi[i]=zma[i]=a[i];
			fma[i]=-2000000000;
		}
		else{
			fmi[i]=fma[i]=a[i];
			zma[i]=-1;
			zmi[i]=2000000000;
		}
		lg[i]=lg[i>>1]+1;
	}
	zmi=*mi_b;
	zma=*ma_b;
	for(i=1;i<=lb;i++){
		r(b[i]);
		zmi[i]=zma[i]=b[i];
		lg[i]=lg[i>>1]+1;
	}
	for(i=1;i<=lg[la];i++){
		zmi=zmi_a[i];
		zma=zma_a[i];
		fmi=fmi_a[i];
		fma=fma_a[i];
		l1=1<<i-1;
		for(j=1;j+l1<=la;j++){
			zmi[j]=fi(lzmi[j],lzmi[j+l1]);
			zma[j]=fa(lzma[j],lzma[j+l1]);
			fmi[j]=fi(lfmi[j],lfmi[j+l1]);
			fma[j]=fa(lfma[j],lfma[j+l1]);
		}
		lzmi=zmi;
		lzma=zma;
		lfmi=fmi;
		lfma=fma;
	}
	lzmi=*mi_b;
	lzma=*ma_b;
	for(i=1;i<=lg[lb];i++){
		zmi=mi_b[i];
		zma=ma_b[i];
		l1=1<<i-1;
		for(j=1;j+l1<=lb;j++){
			zmi[j]=fi(lzmi[j],lzmi[j+l1]);
			zma[j]=fa(lzma[j],lzma[j+l1]);
		}
		lzmi=zmi;
		lzma=zma;
	}
	while(q--){
		r(l1,r1,l2,r2);
		ans=0x8000000000000000LL;
		x=ma(zma_a,l1,r1);
		if(x>=0){
			y=mi(mi_b,l2,r2);
			ans=fa(ans,(long long)x*y);
		}
		x=ma(fma_a,l1,r1);
		if(x>=-1000000000){
			y=ma(ma_b,l2,r2);
			ans=fa(ans,(long long)x*y);
		}
		x=mi(zmi_a,l1,r1);
		if(x<=1000000000){
			y=mi(mi_b,l2,r2);
			ans=fa(ans,(long long)x*y);
		}
		x=mi(fmi_a,l1,r1);
		if(x<0){
			y=ma(ma_b,l2,r2);
			ans=fa(ans,(long long)x*y);
		}
		w(ans,'\n');
	}
	return 0;
}
