/*
 * String Hashing
 *
 * Time: O(n) for constructing HashInterval, get_hashes()
 *       O(1) for get_hash()
 * Test: kattis-longestcommonsubstring (get_hashes),
 * 		 kattis-baza (HashInterval)
 * Source: KACTL
 */
typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str) + 1), pw(ha) {
		pw[0] = 1;
        for (int i = 0; i < sz(str); i++)
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H get_hash(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> get_hashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
    for (int i = 0; i < length; i++)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
    for (int i = length; i < sz(str); i++) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}
#include<sys/time.h>
// in main():
//      timeval tp;
//      gettimeofday(&tp, 0);
//      C = (int)tp.tv_usec; // (less than modulo)

// HashInterval hi(s)                       // Hash object of string s
// ull h = (ull)hi.get_hash(a, b)           // Get hash of substring s[a, b)

// auto hs = get_hashes(s, l)               // Get all hashes of length l for s