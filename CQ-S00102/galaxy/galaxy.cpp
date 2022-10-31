#include<bits/stdc++.h>
#define ll long long
#define N 500000
using namespace std;

inline int read(){
	int s=0;char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s;
}

inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

int n,m,q;
vector<pair<int,bool> > a[N+100];

struct node{int ope,x,y;}ask[N+100];
int oud[N+100];

void getoud(){
	for(int j=1;j<=n;j++) oud[j]=0;
	for(int j=1;j<=n;j++)
		for(int z=0;z<a[j].size();z++)
			if(a[j][z].second) oud[a[j][z].first]++;
}

int main(){

	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);

	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		a[y].push_back(make_pair(x,1));
	}
	
	q=read();bool kope2=0,kope4=0;
	for(int i=1;i<=q;i++){
		int ope=read(),x=read();
		if(ope&1) ask[i]=(node){ope,x,read()};
		else ask[i]=(node){ope,x,-1};
		if(ope==4) kope4=1;
		if(ope==2) kope2=1;
	}

	if(n<=1000&&q<=1000){
		
		for(int i=1;i<=q;i++){
			int ope=ask[i].ope,x=ask[i].x,y=ask[i].y;
			
			if(ope==1){
				for(int j=0;j<a[y].size();j++)
					if(a[y][j].first==x) 
						{a[y][j].second=0;break;}
			}
			else if(ope==2){
				for(int j=0;j<a[x].size();j++)
					a[x][j].second=0;
			}
			else if(ope==3){
				for(int j=0;j<a[y].size();j++)
					if(a[y][j].first==x)
						{a[y][j].second=1;break;}
			}
			else{
				for(int j=0;j<a[x].size();j++)
					a[x][j].second=1;
			}
			
			getoud();
			bool kk=0;for(int j=1;j<=n;j++) kk|=(oud[j]!=1);
			puts(kk?"NO":"YES");
		}
		return 0;
	}
	
	if(!kope2&&!kope4){
		getoud();
		int cnt=0;
		for(int i=1;i<=n;i++) if(oud[i]!=1) cnt++;
		
		for(int i=1;i<=q;i++){
			int ope=ask[i].ope,x=ask[i].x,y=ask[i].y;
			
			if(ope==1){
				if(oud[x]==1) cnt++;
				oud[x]--;
				if(oud[x]==1) cnt--;
			}
			if(ope==3){
				if(oud[x]==1) cnt++;
				oud[x]++;
				if(oud[x]==1) cnt--;
			}
			puts(cnt?"NO":"YES");
		}
		return 0;
	}

	return 0;
}

