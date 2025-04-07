/*
 * Suffix Array
 *
 * Time: O(n log n)
 * Status: tested (https://judge.yosupo.jp/submission/277419)
 */
struct SuffixArray {
	vi sa, lcp;
	string smem;
	SuffixArray(string s, int lim=256) { // or vector<int>
		smem = s;
		s.push_back(0); int n = sz(s), k = 0, a, b;
		vi x(all(s)), y(n), ws(max(n, lim));
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
	void view() {
		cerr << " sa   lcp   suffix" << '\n';
		int n = sz(smem);
		for (int i = 0; i < n + 1; i++) {
			cerr << std::setw(3) << sa[i];
			cerr << std::setw(6) << lcp[i] << "   ";
			cerr << smem.substr(sa[i], n - sa[i]) << "$" << '\n';
		}
	}
};
// SuffixArray sa(s)		// Construct suffix array for string s
// int x = sa.lcp[i];       // gives lcp(sa[i], sa[i-1]) for [1, n]
// sa.view();				// View suffix array structure