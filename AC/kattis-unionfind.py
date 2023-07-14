'''
kattis-unionfind

- classic UFDS.

- use fast io template for 1M IO
'''
class UFDS:
    def __init__(self, n):
        self.parents = list(range(n))
        self.ranks = [0] * n
        self.sizes = [1] * n
        self.numdisjoint = n

    def find(self, x):
        xp = x
        children = []
        while xp != self.parents[xp]:
            children.append(xp)
            xp = self.parents[xp]
        for c in children:
            self.parents[c] = xp
        return xp

    def union(self, a, b):
        ap = self.find(a)
        bp = self.find(b)
        if ap == bp:
            return

        if self.ranks[ap] < self.ranks[bp]:
            self.parents[ap] = bp
            self.sizes[bp] += self.sizes[ap]
        elif self.ranks[bp] < self.ranks[ap]:
            self.parents[bp] = ap
            self.sizes[ap] += self.sizes[bp]
        else:
            self.parents[bp] = ap
            self.ranks[ap] += 1
            self.sizes[ap] += self.sizes[bp]

        self.numdisjoint -= 1

    def size(self, x):
        return self.sizes[self.find(x)]

from sys import stdin, stdout

def main():
    n, q = [int(i) for i in stdin.readline().split(' ')]
    u = UFDS(n)
    for l in stdin.read()[:-1].split('\n'):
        c, a, b = l.split(' ')
        if c == '?':
            stdout.write("yes\n" if u.find(int(a)) == u.find(int(b)) else "no\n")
        else:
            u.union(int(a), int(b))

main()
