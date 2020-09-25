#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<int> v;
	map<string, int> mp;
	mp["ABCDEF"] = 0;
	mp["BC"] = 1;
	mp["ABDEG"] = 2;
	mp["ABCDG"] = 3;
	mp["BCFG"] = 4;
	mp["ACDFG"] = 5;
	mp["ACDEFG"] = 6;
	mp["ABCF"] = 7;
	mp["ABCDEFG"] = 8;
	mp["ABCDFG"] = 9;
	for (int i = 0; i < n; i++) {
		v.emplace_back(mp[s[i]]);
	}
	bool vis[(int) v.size()];
	memset(vis, true, sizeof(vis));
	for (int i = 0; i < n; i++) {
		if (vis[i]) {
			for (int j = 0; j < n; j++) {
				if (v[i] == v[j]) {
					vis[j] = false;
					vis[i] = true;
				}
			}
		}
	}
	vector<int> nv;
	for (int i = 0; i < (int) v.size(); i++) {
		if (vis[i]) {
			nv.emplace_back(v[i]);
		}
	}
	vector<int> v2;
	int arr[10] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
	for (int i = 0; i < (int) nv.size(); i++) {
		v2.emplace_back(arr[nv[i]]);
	}
	int mn = *min_element(v2.begin(), v2.end());
	bool vis2[(int) v2.size()];
	memset(vis2, false, sizeof(vis2));
	for (int i = 0; i < (int) v2.size(); i++) {
		if (v2[i] == mn) {
			vis2[i] = true;
		}
	}
	for (int i = 0; i < (int) v2.size(); i++) {
		if (vis2[i]) {
			cout << nv[i] << " ";
		}
	}
	cout << '\n';
	return 0;
}
