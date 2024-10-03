#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin>>str;

	int a=0, b=0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') a++;
		else b++;
	}

	vector<pii> v;
	vector<pii> res;

	for (int i = 0; i <= a; i++) {
		v.push_back({0,0});
		res.push_back({0,0});
	}

	for (int i = 0; i < str.length(); i++){
		for(int j=1; j<=a; j++){
			if(str[i] == 'A') v[j].first++;
			else v[j].second++;

			if(v[j].first == j){
				res[j].first++;
				v[j].first=0; v[j].second=0;
			}
			else if (v[j].second == j){
				res[j].second++;
				v[j].first=0; v[j].second=0;
			}
		}

		// cout<<"str[i] : "<<str[i]<<"\n";
		// for(int j=1; j<=a; j++){
		// 	cout<<v[j].first<<" "<<v[j].second<<"\n";
		// }
		// cout<<"\n";
	}

	queue<int> q;
	int ans=0;
	for(int i=1; i<=a; i++){
		// cout<<res[i].first <<" "<< res[i].second<<" \n";
		if(res[i].first > res[i].second){
			ans++;
			q.push(i);
		}
	}

	cout<<ans<<"\n";
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}
