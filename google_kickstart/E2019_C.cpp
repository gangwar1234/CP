#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<lo> vl;
typedef vector<vl>vll;
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) 
#define REP(a,b) for(lo i =(a) ;i<(b);i++)

template <typename T>

istream &operator>>(istream &in, vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++)
		in >> v[i];
	return in;
}


#include <bits/stdc++.h>
using namespace std;


/* @euler sieve, finding all primes in range [2, maxn) {{{ */
const int prime_maxn = 1e5 + 10;
int prime[prime_maxn], prime_cnt = 0;
bool prime_vis[prime_maxn];
void euler() {
    for (int i = 2; i < prime_maxn; i++) {
        if (!prime_vis[i])
            prime[prime_cnt++] = i;
        for (int j = 0; j < prime_cnt && i*prime[j] < prime_maxn; j++) {
            prime_vis[i*prime[j]]  = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
/* }}} */

inline int solve(int t) {
    int phi = 1, p2 = 0;
    while ((t & 1) ^ 1) t >>= 1, p2++;
    for (int i = 1; i < prime_cnt && prime[i] * prime[i] <= t; i++) {
        int times = 0;

        while (t % prime[i] == 0) {
            t /= prime[i];
            times++;
        }

        phi *= times + 1;
    }
    if (t > 1)
        phi *= 2;

    return abs(phi - phi * p2) <= 2;
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(20);
    euler();

    int cas, l, r;
    scanf("%d", &cas);
    for (int _cas = 1; _cas <= cas; _cas++) {
        scanf("%d%d", &l, &r);
        int ans = 0;
        for (int i = l; i <= r; i++)
            ans += solve(i);
        printf("Case #%d: %d\n", _cas, ans);
    }

    return 0;
	return 0;
}