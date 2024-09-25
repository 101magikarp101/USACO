#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int n, k;

bool isprime(char c) {
    return c=='2'||c=='3'||c=='5'||c=='7';
}

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

int type(char c) {
    if (isdigit(c)) return 0;
    if (islower(c)) return 1;
    if (isupper(c)) return 2;
    if (ispunct(c)) return 3;
    return 4;
}
 
inline void readAndCheckAnswer(InStream &in) {
    string s = in.readLine();
    in.quitif(s.size() < 12, _wa, "Password too short");
    in.quitif(s.size() > 16, _wa, "Password too long");
    in.quitif(count_if(s.begin(), s.end(), [](char c) { return isdigit(c); }) < 4, _wa, "Password must contain at least 4 digits");
    in.quitif(count_if(s.begin(), s.end(), [](char c) { return islower(c); }) < 3, _wa, "Password must contain at least 3 lowercase letters");
    in.quitif(count_if(s.begin(), s.end(), [](char c) { return isupper(c); }) < 3, _wa, "Password must contain at least 3 uppercase letters");
    in.quitif(count_if(s.begin(), s.end(), [](char c) { return ispunct(c); }) < 2, _wa, "Password must contain at least 2 special characters");
    in.quitif(count_if(s.begin(), s.end(), isprime) < 3, _wa, "Password must contain at least 3 prime digits");
    in.quitif(lowerCase(s).find('a')!=string::npos, _wa, "Password must not contain 'a'");
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) sum += c-'0';
    }
    int sq = sqrt(sum);
    in.quitif(sq*sq != sum, _wa, "Sum of digits must be a perfect square");
    sum = 0;
    for (char c : s) sum += c;
    in.quitif(!prime(sum), _wa, "Sum of ASCII values must be a prime number");
    bool good = 1;
    for (int i = 1; i < s.size(); i++) {
        if (type(s[i]) == type(s[i-1])) {
            good = 0;
            break;
        }
    }
    in.quitif(!good, _wa, "Adjacent characters must have different types");
    in.quit(_ok, "Password is valid");
}
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
 
    readAndCheckAnswer(ouf);
}
