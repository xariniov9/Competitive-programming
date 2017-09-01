    #include <bits/stdc++.h>
    using namespace std;
    const int N = 1e5+5;
    typedef long long ll;
    ll v[N];
    int main() {
    	int t; scanf("%d", &t);
    	while (t--) {
    		int n, k; scanf("%d %d", &n, &k);
    		for (int i = 0; i < n; i++) {
    			scanf("%lld", v + i);
    		}
    		sort(v, v+n);
    		multiset<ll> s;
    		int maior = 0, at = 0;
    		for (int i = 0; i < k; i++) {
    			int j = n - i - 1;
    			if (v[j] == v[j+1]) {
    				at++;
    			} else {
    				at = 1;
    			}
    		}
    		s.insert(at);
    		ll last = v[n-k];
    		if (at == k) {
    			at = 0;
    			last = 0;
    		}
    		for (int i = n-k-1; i >= 0; i--) {
    			if (v[i] == v[i+1]) {
    				at++;
    			} else {
    				at = 1;
    			}

    			if (i%k) {
    				if (last == v[i]) {
    					auto it = s.lower_bound(at-1);
    					s.erase(it);
    					s.insert(at);
    					if (at == k) {
    						at = last = 0;
    					}
    					continue;
    				}
    				if ((v[i] != v[i-1] or at == k) and *(s.begin()) < at) {
    					s.erase(s.begin());
    					s.insert(at);
    				}
    				if (at == k) at = 0;
    			} else {
    				s.insert(at);
    				last = v[i];
    				if (at == k) {
    					last = at = 0;
    				}
    			}
    		}
    		int resp = 0;
    		for (auto it : s) {
    			resp += k-it;
    		}
    		cout << resp << endl;
    	}
    	return 0;
    }
