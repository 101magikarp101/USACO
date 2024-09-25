#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};
std::string fikky = "fARKyqJxqNTsRRzYnfElfDHQQRrdXuqeliGPCpjHSYVAZBUKlWaziRIEFcHVUbefoWWsleTWLnbqbQqThtQQWCysocOwfDXdHfAcVSbOtwrHXRShjDIEXbtaaZBBrIIqZmhPHAHUHaLTyzwmsvzdxPDPCWQqcjiFYmFwTZqPOPCcuDmGIkFKGgTNCPDBPLvhysTGbbkCGmnwYBtUhfAtnckzanrHMeHlzhehRejVeITqNFrTgINrOZFagmyplbIZhzZovKBrLLgdpJIyTmVYLVyCLaeCjyGqrNaAhlwyVhEgTWUzFXRSFTtfnqOjUQZVaShXSNVYjlZFlYsItdSJQLilQXOxUYjYLiManSWHWleDVJgREvHntdWCtwwdHMMHKohBuQXqOMsmwjPHNSlHKDQrePCReEkcweNhIdxNLNyYsSccZunrDvugHyMKAjFYJYJYTeXsjtnypCMFqmdvnxyemUOVzgGxRSFFseUdGGFrzNTuDusDAxtvUBencexJkRKAhusPtqSgaahXHjKahwEBMlJpUYowzKrEAuObgSJIgDOUoeKCBfXrxbDRUsrQhyeCaUjztoosYlfWDONVQyinIRiVlSbbLUrpnYSRTFpIToOlSoGGwjtlJSiRuMoFUyIYnUuVftqRqzVWIPVofVomcPFTNeTbnbrpcFsOhPykOETysbExIjfANLKaltKluGelrAuDEQWadBhfJjnKRdLchSxLTjnyWjaBthkoYGuPLIbZYSFubKQdbylRlsJoBzjVSzWiXoHSpnbfCotIOQMxHdzMhgvVQPxHkGZJgyvRwjvMhjXxBzKOzHjMyDtqAGgooVRqzPqIDVdLNHAkVeYfXLYQedJRBkgVQFOEoYoVwXPUuLlJDvxJOyAtZXRcMrEImPOepgiAwTwedytSZLRFwGAgxYYqalOTGCvIkkLBXyVzmmZVGiLZwepaIMaPAcMIQmCiDmLUkhkEXEXBHkVFDLcXzhYwMfAYTxubXFmvVyRCUsczqLwZeIHVUVaAUIYFEdsxEiXGdUdTFpNcpoXRifxjTjLuiPZKxsWPYPvtQraXsJCGIuaAvvNhkdiAWKRmRHnupGSYpVicpVdwjBQaNWqVzJkWBugIeIvyyAiWpqufHfcmrQYSSHLRbdVHEtxTlyEJtWxRTYYkkvHLvcJHIXUKVAIyuVncnSxIAJKffONLiPKdwxUwxIdvtTeWnitUbIoTLbvmWhXsnRHSzGetENiFRLPJACHChKpilcsagTPDzZEljdwSHkDoxLSZfHOLmLGYExNCLTTUnKHLopekLkufvVNsYBRPOohLwObvHJdLLRoFJOOgaXdhaSECPcuwOMyWOHotPbOHZbyLSlzFQdsYZPfCURysXiqIaFxUhNGpbUHTTmmoUfPDicMmQCywNQrhYZkQjMFdRvvekjNlKWDMzpUSSaJtboJoLpfNqkWJVmgWEtAyWVmUpBVtqNTXrlSCGDLvxEhUJMcAnfNraQhHqRkmpIvVjPDpuJbkQyfujEhUqZuefSIKeYRsjctKiBPqBnHbiMOZlMJvfjTfhkJRGNatAgalHXOJxgaRsXvKwAswfdJLgKAiPDkdnBXSJoUVyHvXCrBcWprBxbjCClRlbWRyyzgYhaXdYdnTdvrCOQrshstEOQhwzVGmqyXJclwqVihoJDmugBHgxwBLudiJCvTDQaTTMAcgygcIfotPXjicYciXGqGipKHmWJgMcuNPBmfnkviSFpYTMpyMqHrGqqpskDHVTZRQStpoXSAoZXPphBOSqmJDilfgNAabWKNpEoLURBNoFuOepOFhaIZPNbUDnVvcchSsYBRFzZoDhbHdNokjwoCRODHFaEGPTzSbvoJCwJKCmaqAWznMbaUuIBzzylFTYbAMBDFLqaxTHvZMFFFvHFkxHkvtUgyOAYTHsLGhtniyfFDqRhUXkFuYjvmDcmmPWfgKkqBuZHNkmuLADLOjWaJFpVMzSXsijcsqHhALlwRcQCWWfaGCGwfajfUueWFBBiLcDFsxfcFRGxhGRoFgXImtjbGMOnKlrkXNZHcArFzfbUIRKLSKbIkMMglbHeUlXRonDZGoIlhYcZRHWhVKZlGGVpEdYyiOgHqvjguhvXajYljxvYNOARLYvGXYeeHWtsJqiAFpSRlPFwviPnxxuMNQLymDuIxDLQYCHqFmBfycTjnLNTDLzxLYMFIuSUorYsORbLhwcBwVsAanpkamLrpEKJzpxWlwVtGtNpNREZYeAoBTYiKnEuaqzVdlRRZDZsVGhKXLxeKsYBOaiwizcgdSPKkWQgErRCmdlkEuQeJNZLLGMrGRLWQzUJCOheBvJzmYNPtSXKXmfWaqHjuMrsSAkaaZoIqtvGKkBPeeYdRocqjnrqOEWvGrfMGHby";
std::string fikkyaight = "";
bool isEven(int n);
bool isOdd(int n) {
    if (n == -250) {
        return false;
    }
    //random number either -1 or 1
    int x = rand()%2*2-1;
    return isEven(n+x);
}
bool isEven(int n) {
    if (n == -250) {
        return true;
    }
    int x = rand()%2*2-1;
    return isOdd(n+x);
}
std::vector<std::string> split(std::string s) {
    std::vector<std::string> v;
    std::string cur = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (cur != "") {
                v.push_back(cur);
            }
            cur = "";
        } else {
            cur += s[i];
        }
    }
    if (cur != "") {
        v.push_back(cur);
    }
    return v;
}
std::string tony = "fFRKyqJxqNTsRRzYifElfDHQQRrdXuqeliGPCpjHSYVAZBUKlWaziRIEFcHVUbefoWWsleTWLnbqbQqThkQQWCysocOwfDXdHfAcVSbOtwrHXRShjDIEXbtaaZBBrIIqZmhPHAHUHaLTyzwmsvzdxPDPCWQqcjiFYmFwTZqPOPCcuDmGIkFKGgTNCPDBPLvhysTGbbkCGmnwYBtUhfAtnckzanrHMeHlzhehRejVeITqNFrTgINrOZFagmyplbIZkzZovKBrLLgdpJIyTmVYLVyCLaeCjyGqrNaAhlwyVhEgTWUzFXRSFTtfnqOjUQZVaShXSNVYjlZFlYsItdSJQLilQXOxUYjYLiManSWHWleDVJgREvHntdWCtwwdHMMHKohBuQXqOMsmwjPHNSlHKDQrePCReEkcweNhIdxNLNyYsSccZunrDvugHyMKAjFYJYJYTeXsjtnypCMFqmdvnxyemUOVzgGxRSFFseUdGGFrzNTuDusDAxtvUBencexJkRKAhusPtqSgaahXHjKahwEBMlJpUYowzKrEAuObgSJIgDOUoeKCBfXrxbDRUsrQhyeCaUjztoosYlfWDONVQyinIRiVlSbbLUrpnYSRTFpIToOlSy";
std::string tonyaight = "";
int main() {
    int N;
    std::cin >> N;
    int S;
    std::cin >> S;
    std::cin.ignore();
    for (int i = 1; i <= 2401; i++) {
        int x = round(pow(i, 0.25));
        if (x*x*x*x == i) {
            fikkyaight += fikky[i];
        }
    }
    for (int i = 1; i <= 625; i++) {
        int x = round(pow(i, 0.25));
        if (x*x*x*x == i) {
            tonyaight += tony[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        std::string line;
        std::getline(std::cin, line);
        std::vector<std::string> v = split(line);
        if (isOdd(i)) {
            std::cout << fikkyaight << ":" << std::endl;
        }
        if (isEven(i)) {
            std::cout << tonyaight << ":" << std::endl;
        }
        for (int j = 0; j < v.size(); j++) {
            std::cout << v[j] << " ";
            if ((j+1)%S == 0) {
                std::cout << std::endl;
            }
        }
    }
}