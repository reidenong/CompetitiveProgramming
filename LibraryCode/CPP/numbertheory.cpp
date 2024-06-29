typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
