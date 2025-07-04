import timeit

def triangle(row):
    #map R to 0, G to 1, B to 2
    start = timeit.default_timer()
    s = list(row)
    sz = len(s)
    pows = [1,1,3,3,9,9,27,27,81,81,243,243,729,729,2187,2187,6561,6561,19683,19683,59049,59049,177147,177147,531441,531441,1594323,1594323,4782969,4782969,14348907,14348907,43046721,43046721,129140163,129140163,387420489,387420489,1162261467,1162261467,3486784401,3486784401]
    def op(a,b):
        if a==b: return a
        elif a=='R' and b=='G': return 'B'
        elif a=='R' and b=='B': return 'G'
        elif a=='G' and b=='R': return 'B'
        elif a=='G' and b=='B': return 'R'
        elif a=='B' and b=='R': return 'G'
        elif a=='B' and b=='G': return 'R'
    for p in pows[::-1]:
        if p < sz:
            for i in range(sz-p):
                s[i] = op(s[i],s[i+p])
            sz -= p
        # print(s)
    print(timeit.default_timer() - start)
    return s[0]

if __name__ == '__main__':
    while True:
        try:
            row = input()
        except EOFError:
            break
        print(triangle(row))