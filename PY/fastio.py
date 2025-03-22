'''
Fast IO Methods for python

- able to do IO at speeds comparable to C's scanf/printf (anecdotally)

- faster than python input()/print, faster than C++ cin/cout

Testimonials
- Handled up to ~1M inputs in kattis-unionfind where cin/cout could not
'''
from sys import stdin, stdout

def main():
    # Reading in a line of integer delimited by spaces
    # ie. "4, 9, 16"
    a, b, c = [int(i) for i in stdin.readline().split(' ')]

    # Reading in a grid fashion, with each line being a number of variables separated by whitespace until newline
    for line in stdin.read()[:-1].split('\n'):
        var1, var2, var3 = line.split(' ')      # as separate variables
        list_A = line.split(' ')                # as list of variable length

main()
