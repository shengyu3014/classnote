#include<bits/stdc++.h>
using namespace std;
int n;
int ans[200];
int ansh[200];

void dfs(int idx){
	if(ansh[idx]==n){
		cout<<n<<"=";
		for(int i=1;i<=idx;i++){
			if(i>1){
				cout<<"+";
			}
			cout<<ans[idx];
		}
		return;
	}
	for(int i=ans[idx-1];i<=n-1;i++){
		ans[idx]=i;
		ansh[idx]=ansh[idx-1]+ans[idx];
		dfs(idx+1);
	}
	
	
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}

