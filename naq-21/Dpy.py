from decimal import Decimal, getcontext

getcontext().prec = 1000

primes = []
eps = Decimal(10)**Decimal(-500)
m = {}

def init():
    i = 2
    while len(primes) < 105:
        is_prime = True
        for p in primes:
            if i % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(Decimal(i))
        i += 1

def main():
    n = int(input())
    cur = 0
    for _ in range(n):
        line = input().split(" = ")
        lhs = line[0].split(" ")
        rhs = line[1].split(" ")
        lm = {}
        rm = {}
        hm = False
        for i in range(len(lhs)):
            if lhs[i] == "1":
                hm = False
                continue
            if lhs[i] == "*":
                hm = False
            elif lhs[i] == "/":
                hm = True
            else:
                if hm:
                    rm[lhs[i]] = rm.get(lhs[i], 0) + 1
                else:
                    lm[lhs[i]] = lm.get(lhs[i], 0) + 1
                hm = False

        for i in range(len(rhs)):
            if rhs[i] == "1":
                hm = False
                continue
            if rhs[i] == "*":
                hm = False
            elif rhs[i] == "/":
                hm = True
            else:
                if hm:
                    lm[rhs[i]] = lm.get(rhs[i], 0) + 1
                else:
                    rm[rhs[i]] = rm.get(rhs[i], 0) + 1
                hm = False
        rem = []
        for k,v in lm.items():
            d = min(v, rm.get(k, 0))
            v-=d
            rm[k] = rm.get(k, 0) - d
            if v==0:
                rem.append(k)
            if rm[k] == 0:
                rm.pop(k)
        for k in rem:
            lm.pop(k)
        tot = 0
        for k,v in lm.items():
            if m.__contains__(k):
                tot += 1
        for k,v in rm.items():
            if m.__contains__(k):
                tot += 1
        if tot == len(lm) + len(rm):
            val = Decimal(1)
            for k,v in lm.items():
                val *= Decimal(m[k])**Decimal(v)
            for k,v in rm.items():
                val /= Decimal(m[k])**Decimal(v)
            if abs(val-Decimal(1)) > eps:
                print("invalid")
                return
        else:
            for k,v in lm.items():
                if m.__contains__(k):
                    continue
                if tot == len(lm) + len(rm):
                    break
                if tot+1 == len(lm) + len(rm):
                    val = Decimal(1)
                    for kk,vv in lm.items():
                        if kk == k: continue
                        val /= Decimal(m[kk])**Decimal(vv)
                    for kk,vv in rm.items():
                        val *= Decimal(m[kk])**Decimal(vv)
                    if abs(val-Decimal(1)) < eps:
                        print("invalid")
                        return
                    m[k] = val**(Decimal(1)/Decimal(v))
                    tot += 1
                else:
                    m[k] = primes[cur]
                    cur += 1
                    tot += 1
            for k,v in rm.items():
                if m.__contains__(k):
                    continue
                if tot == len(lm) + len(rm):
                    break
                if tot+1 == len(lm) + len(rm):
                    val = Decimal(1)
                    for kk,vv in lm.items():
                        val *= Decimal(m[kk])**Decimal(vv)
                    for kk,vv in rm.items():
                        if kk == k: continue
                        val /= Decimal(m[kk])**Decimal(vv)
                    if abs(val-Decimal(1)) < eps:
                        print("invalid")
                        return
                    m[k] = val**(Decimal(1)/Decimal(v))
                    tot += 1
                else:
                    m[k] = primes[cur]
                    cur += 1
                    tot += 1
    print("valid")
    return

if __name__ == "__main__":
    init()
    main()
    print(m)