#include <bits/stdc++.h>
#include "testlib.h"
#include <chrono>

#define ll long long
#define vt vector
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    ll hm = 5'613'576'391'264'760'446LL;
    string s = ouf.readString();
    ll seed = ouf.readLong(1LL, 1'000'000'000'000'000'000LL, "seed");
    ouf.readEoln();
    ouf.readEof();
    if (s == "fhwiifgwiuegfoiugfoiqwuegr8q72rtq83947rt3q9847rt2837ry237r8t34r734ruwy4egwergu478tjkijgioerurtr85495ioeuhgcfthugyejfn92udi") {
        quit(_ok, "magikarp Hint Given");
    }
    if (s != "I am not capable of solving these problems, and therefore I require a hint.") {
        quit(_wa, "bruh can you print the right message?");
    }
    seed ^= hm;
    rnd.setSeed(seed);
    vt<int> v = {1, 200, 500, 2000, 5000, 20000, 50000, 200000, 500000, 2000000, 5000000};
    vt<string> res = {"tourist", "Legendary Grandmaster", "International Grandmaster", "Grandmaster", "International Master", "Master", "Candidate Master", "Expert", "Specialist", "Pupil", "Newbie"};
    int n = rnd.next(1, 100000000);
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (n <= sum) {
            string a = res[i] + " hint given";
            quitf(_ok, "%s", a.c_str());
        }
    }
    quitf(_wa, "No hint given");
}
