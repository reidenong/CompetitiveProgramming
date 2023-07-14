'''
Union Find Disjoint sets

- Data structure used to model a collection of disjoint sets which can efficiently determine which set an item belongs to
  as well as to unite two sets

- code taken from cp-book github, here for easy reference

Time: O(1) operations
Space: O(N) 
'''
# UFDS Data Structure
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

    def isSameSet(self, x, y) :
        return self.find(x) == self.find(y)


def main():
    # Initialize ufds
    u = UFDS(10)          

    # Functions
    ufds.find(x)                     # Returns parent of x
    ufds.union(parent, child)        # Unifies set containing x and set containing y
    ufds.isSameSet(x, y)             # Returns bool if x, y are in the same set
    ufds.numdisjoint()               # Returns int, number of disjoint sets
    ufds.size(x)                     # Returns size of set of which x is parent


main()
