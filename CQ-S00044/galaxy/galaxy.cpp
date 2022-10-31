#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<ll> op[500005];
vector<ll> op1[500005];
ll n,m,k,x,y,i,z,temp,p[500005],now,l[500005];
deque<ll> op2;
bool check(ll x){
	op2.clear();
	for(i=1;i<=n;i++) p[i]=LLONG_MIN/2;
	p[x] = 0;
	op2.push_back(x);
	while(op2.size()){
		x = op2.front(),op2.pop_front();
		for(auto a1=op[x].begin();a1!=op[x].end();a1++){
			if(p[*a1]<p[x]+1){
				p[*a1] = p[x]+1;
				if(p[*a1]>=now) return 1;
				op2.push_back(*a1);
			}
		}
	}
	return 0;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	l[0] = n;
	for(i=1;i<=m;i++){
		cin>>x>>y;
		l[op[x].size()]--;
		op[x].insert(y),op1[y].push_back(x);
		l[op[x].size()]++;
	}
	cin>>k;
	while(k--){
		cin>>x>>y;
		if(x==1){
			cin>>z;
			l[op[y].size()]--;
			op[y].erase(z);
			l[op[y].size()]++;
			now--;
		}
		if(x==2){
			now -= op1[y].size();
			for(i=0;i<op1[y].size();i++) l[op[op1[y][i]].size()]--,op[op1[y][i]].erase(y),l[op[op1[y][i]].size()]++;
		}
		if(x==3){
			cin>>z;
			l[op[y].size()]--;
			op[y].insert(z);
			l[op[y].size()]++;
			now++;
		}
		if(x==4){
			for(i=0;i<op1[y].size();i++) l[op[op1[y][i]].size()]--,op[op1[y][i]].insert(y),l[op[op1[y][i]].size()]++;
			now += op1[y].size();
		}
		temp=0;
		if(l[1]!=n){
			cout<<"NO\n";
			continue;
		}
		for(i=1;i<=n;i++){
			if(!check(i)){
				cout<<"NO\n";
				temp=1;
				break;
			}
		}
		if(temp==0) cout<<"YES\n";
	}
	return 0;
}
