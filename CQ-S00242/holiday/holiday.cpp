#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum,i;
int fs[10005],ls[10005],v[10005],v2[10005];
struct d{
	long long f;
	int id;
}j[10005];
void add(int x,int y){
	ls[x]=fs[y];fs[x]=y;ls[y]=ls[fs[x]];
	ls[y]=fs[x];fs[y]=x;ls[x]=ls[fs[y]];
}
int z(int s,int ans,int x){
	if(ans>k) return -1;
	if(s==x) return x;
	v[x]=1;
	while(ls[x]!=0&&!v[ls[x]]){
		if(s!=x){
			v[x]=1;
			return z(s,ans+1,ls[x]);
		}else return x;
		x=fs[x];
	}
}
bool cmp(d a,d b){
	return a.f>b.f;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	j[1].f=-1;
	for(i=2;i<=n;i++){
		cin>>j[i].f;
		j[i].id=i;
	}
	for(i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	sort(j+1,j+n+1,cmp);
	int ag=1;
	i=1;
	for(;i<=4;){
		for(int c=1;c<n;c++){
			if(v[j[c].id]==0&&j[c].id!=ag){
				for(int i=1;i<=n;i++) v2[i]=0;
				int s=z(j[c].id,0,fs[ag]);
				if(s!=-1){
					i++;
					sum+=j[c].f;
					v[j[c].id]=1;
					ag=c;
					break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
