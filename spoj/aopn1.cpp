#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <limits.h>
#include <vector>
#include <map>
#include <bitset>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define MAX 100100
#define mod 1000000007LL
#define bitcnt(x) __builtin_popcountll(x)
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
#define ll long long int
#define mp(x, y) make_pair(x, y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define in(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define ins(x) scanf("%s", x)
#define pr(x) printf("%lld\n", x)
#define prd(x) printf("%d\n", x)
#define pi acos(-1.0)
#define ff first
#define ss second

using namespace std;
int n, x[50];
ll dp[22][15][15][5];

ll rec(int len, int cur, int prev, int mask, bool flag)
{
	if (len == 0)
		return ((mask == 3) ? 1 : 0);

	if (flag && dp[len][cur][prev][mask] != -1)
		return dp[len][cur][prev][mask];
	ll ans = 0;
	if (flag)
	{
		int m = 0;
		for (int i = 0; i < 10; i++)
		{
			m = 0;
			if (i == cur)
				m |= 1;
			if (i == prev)
				m |= 2;
			ans += rec(len - 1, i, cur, mask | m, 1);
		}
		dp[len][cur][prev][mask] = ans;
	}
	else
	{
		int m = 0;
		for (int i = 0; i < x[n - len]; i++)
		{
			m = 0;
			if (i == cur)
				m |= 1;
			if (i == prev)
				m |= 2;
			ans += rec(len - 1, i, cur, mask | m, 1);
		}
		m = 0;
		if (x[n - len] == cur)
			m |= 1;
		if (x[n - len] == prev)
			m |= 2;
		ans += rec(len - 1, x[n - len], cur, mask | m, 0);
	}
	return ans;
}

ll fun(ll y)
{
	char s[50];
	n = sprintf(s, "%lld", y);
	for (int i = 0; i < n; i++)
		x[i] = s[i] - '0';

	ll ans = 0;
	for (int len = 3; len < n; len++)
		for (int i = 1; i < 10; i++)
			for (int j = 0; j < 10; j++)
				ans += rec(len - 2, j, i, ((i == j) ? 1 : 0), 1);

	for (int i = 1; i < x[0]; i++)
		for (int j = 0; j < 10; j++)
			ans += rec(n - 2, j, i, ((i == j) ? 1 : 0), 1);

	for (int i = 0; i < x[1]; i++)
		ans += rec(n - 2, i, x[0], ((i == x[0]) ? 1 : 0), 1);

	ans += rec(n - 2, x[1], x[0], ((x[1] == x[0]) ? 1 : 0), 0);
	return ans;
}

int main()
{
#ifdef LOCAL_PROJECT
	freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
#endif
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	MS1(dp);
	ll a, b, ans;
	int t;
	ind(t);
	while (t--)
	{
		in(a);
		in(b);
		ans = fun(b) - fun(a);
		pr(ans);
	}
	return 0;
}
