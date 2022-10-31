#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2.5e4+5,M=1e5+5;
struct aa{
	int a,b;
	aa(){
	}
	aa(int a1,int b1){
		a=a1;
		b=b1;
	}
}tu1[2*M];
int tu2[N],n,m,k,b[N],a[N][6],an[N],no[N],ans;
void add(int a,int b){
	tu1[++tu2[0]]=aa(b,tu2[a]);
	tu2[a]=tu2[0];
}
queue<aa> c;
void cl(int *an,int fr){
	while(!c.empty()) c.pop();
	c.push(aa(fr,-1));
	while(!c.empty()){
		aa no=c.front();
		c.pop();
		if(an[no.a]!=an[0]) continue;
		an[no.a]=no.b;
		for(int i=tu2[no.a];i;i=tu1[i].b) c.push(aa(tu1[i].a,no.b+1));
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++) an[i]--;
	memset(an,0x3f,sizeof(an));
	cl(an,1);
	for(int i=2;i<=n;i++){
		if(an[i]>2*k+4) continue;
		memset(no,0x3f,sizeof(no));
		cl(no,i);
		for(int j=2;j<=n;j++){
			if(an[j]>k || no[j]>k || j==i) continue;
			for(int k=1;k<=3;k++){
				if(b[j]>b[a[i][k]]){
					for(int l=3;l>=k+1;l--) a[i][l]=a[i][l-1];
					a[i][k]=j;
					break;
				}
			}
		}
		for(int j=2;j<=i-1;j++){
			if(no[j]>k) continue;
			for(int i1=1;i1<=3;i1++){
				if(!a[i][i1]) break;
				for(int i2=1;i2<=3;i2++){
					if(!a[j][i2]) break;
					if(a[i][i1]==j || a[i][i1]==a[j][i2] || a[j][i2]==i)
						continue;
					ans=max(ans,b[i]+b[j]+b[a[i][i1]]+b[a[j][i2]]);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
