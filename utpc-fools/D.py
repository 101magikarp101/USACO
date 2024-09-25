from sys import stdin
from math import erf, exp, atan, fabs, gamma, sin, cos, log10, sqrt

def main():
    s = stdin.readline().strip()
    s = s.replace("quendle", "erf")
    s = s.replace("holofy", "exp")
    s = s.replace("ensalex", "atan")
    s = s.replace("chaness", "abs")
    s = s.replace("strustate", "gamma")
    s = s.replace("sploop", "sin")
    s = s.replace("fallocest", "cos")
    s = s.replace("tudefy", "log10")
    s = s.replace("fabrate", "sqrt")
    res = eval(s)
    print(res)

if __name__ == "__main__":
    main()