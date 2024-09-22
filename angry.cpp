// ## Yuji snippet ##//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pll pair<ll, ll>
#define fr(a, b, i) for (ll i = a; i < b; i++)
#define fre(a, b, i) for (ll i = a; i <= b; i++)
#define srt(a) sort(a.begin(), a.end())
#define rsrt(a) sort(a.rbegin(), a.rend())
#define rv(a) reverse(a.begin(), a.end())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vl vector<long>
#define vll vector<long long>
#define umi unordered_map<int, int>
#define mi map<int, int>
#define pq priority_queue<int>
#define mpq priority_queue<int, vi, greater<int>>
#define pqll priority_queue<ll>
#define mpqll priority_queue<ll, vll, greater<ll>>
#define vc vector<char>
#define mod 1000000007
#define INF 4e18
#define inf 1e9
#include <bitset>
using namespace std;
using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order - give element at xth index
//  order_of_key - find no of elements smaller than x
ll dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
/*-------------------------factorial and modinv-------------------------*/
//(a/b)%mod = ((a%mod)*((b^(mod-2))%mod))%mod

ll fact[1000004];
ll modinv[1000004];

// power calculator
ll power(ll base, ll x)
{
    if (x < 0)
    {
        return 0;
    }

    ll ans = 1;
    while (x)
    {
        if (x % 2 == 0)
        {
            base = (base * base) % mod;
            x /= 2;
        }
        else
        {
            ans = (ans * base) % mod;
            x--;
        }
    }
    return ans;
    // log(x)
}

void precomp()
{
    modinv[0] = 1;
    fact[0] = 1;
    for (ll i = 0; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        modinv[i] = power(fact[i], mod - 2);
    }
}

// nCr calculator
ll ncr(ll n, ll r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;

    return (((fact[n] * modinv[r]) % mod) * modinv[n - r]) % mod;
}

/*-------------------------LCM-------------------------*/

ll lcm(ll a, ll b)
{
    return a / (__gcd(a, b)) * b;
}

// mod stuff starts here
long long MOD(long long x)
{
    return ((x % mod + mod) % mod);
}
long long add(long long a, long long b)
{
    return MOD(MOD(a) + MOD(b));
}
long long mul(long long a, long long b)
{
    return MOD(MOD(a) * MOD(b));
}
int modularInverse(int number)
{
    return power(number, mod - 2);
}
/*-------------------------SOLUTION-------------------------*/

void solve()
{
    cout << fixed << setprecision(25);
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    srt(a);

    auto f = [&](ll mid) -> bool
    {
        int cnt = 1;
        int i = 0, ck = a[0] + 2 * mid;
        while (i < n)
        {
            if (ck >= a[i])
            {
                i++;
            }
            else
            {
                cnt++;
                ck = a[i] + 2 * mid;
            }
        }

        return cnt > m;
    };

    ll l = -1, r = a[n - 1] - a[0] + 1;
    while (r - l > 1)
    {
        ll mid = l + (r - l) / 2;
        if (f(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << r << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    // precomp();
    solve();
    return 0;
}