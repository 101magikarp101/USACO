#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct point {
    int x, y;
};

int T;
char grid[8][8];

point dp[2] = {{-1,1},{-1,-1}};
point dpm = {-1,0};
point dn[8] = {{-2,-1},{-2,1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
point dr[4] = {{0,1},{1,0},{0,-1},{-1,0}};
point db[4] = {{1,1},{1,-1},{-1,1},{-1,-1}};
point dk[8] = {{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{1,0},{0,-1},{-1,0}};
point dq[8] = {{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{1,0},{0,-1},{-1,0}};

bool good(point p) {
    return 0<=p.x&&p.x<8&&0<=p.y&&p.y<8;
}

point operator+(point a, point b) {
    return {a.x+b.x, a.y+b.y};
}

point operator*(point a, int b) {
    return {a.x*b, a.y*b};
}

bool isCheckPiece(bool w, point p, char a[][8]) {
    char c = a[p.x][p.y];
    int z = w?1:-1;
    c=tolower(c);
    if (c=='p') {
        point p1 = p+dp[0]*z;
        point p2 = p+dp[1]*z;
        // cout << "pawn: " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
        return ((good(p1)&&a[p1.x][p1.y]==(w?'k':'K'))||(good(p2)&&a[p2.x][p2.y]==(w?'k':'K')));
    } else if (c=='n') {
        for (int i = 0; i < 8; i++) {
            point np = p+dn[i];
            if (good(np)&&a[np.x][np.y]==(w?'k':'K')) {
                return true;
            }
        }
        return false;
    } else if (c=='r') {
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            while (true) {
                cnt++;
                point np = p+dr[i]*cnt;
                if (!good(np)) break;
                if (a[np.x][np.y]==(w?'k':'K')) {
                    return true;
                }
                if (a[np.x][np.y]!='.') break;
            }
        }
        return false;
    } else if (c=='b') {
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            while (true) {
                cnt++;
                point np = p+db[i]*cnt;
                if (!good(np)) break;
                if (a[np.x][np.y]==(w?'k':'K')) {
                    return true;
                }
                if (a[np.x][np.y]!='.') break;
            }
        }
        return false;
    } else if (c=='k') {
        for (int i = 0; i < 8; i++) {
            point np = p+dk[i];
            if (good(np)&&a[np.x][np.y]==(w?'k':'K')) {
                return true;
            }
        }
        return false;
    } else if (c=='q') {
        for (int i = 0; i < 8; i++) {
            int cnt = 0;
            while (true) {
                cnt++;
                point np = p+dq[i]*cnt;
                if (!good(np)) break;
                if (a[np.x][np.y]==(w?'k':'K')) {
                    return true;
                }
                if (a[np.x][np.y]!='.') break;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool isCheck(bool w, char a[][8]) {
    bool ans = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j]!='.'&&(w?isupper(a[i][j]):islower(a[i][j]))) {
                if (isCheckPiece(w,{i,j},a)) {
                    ans = true;
                    break;
                }
            }
        }
    }
    // cout << "board: " << endl;
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "check: " << ans << endl;
    return ans;
}

bool isMateMove(bool w, point p, char a[][8]) {
    char c = a[p.x][p.y];
    int z = w?1:-1;
    c=tolower(c);
    if (c=='p') {
        bool res = true;
        for (int i = 0; i < 2; i++) {
            point np = p+dp[i]*z;
            char a1[8][8];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    a1[j][k]=a[j][k];
                }
            }
            if (good(np)&&(w?islower(a1[np.x][np.y]):isupper(a1[np.x][np.y]))) {
                a1[np.x][np.y]=(w?'P':'p');
                a1[p.x][p.y]='.';
                if (!isCheck(!w,a1)) {
                    return false;
                }
            }
        }
        point p1 = p+dpm*z;
        if (good(p1)&&a[p1.x][p1.y]=='.') {
            char a1[8][8];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    a1[j][k]=a[j][k];
                }
            }
            a1[p1.x][p1.y]=(w?'P':'p');
            a1[p.x][p.y]='.';
            if (!isCheck(!w,a1)) {
                return false;
            }
            if (p.x==(w?6:1)) {
                point p2 = p+dpm*z*2;
                if (good(p2)&&a[p2.x][p2.y]=='.') {
                    char a2[8][8];
                    for (int j = 0; j < 8; j++) {
                        for (int k = 0; k < 8; k++) {
                            a2[j][k]=a[j][k];
                        }
                    }
                    a2[p2.x][p2.y]=(w?'P':'p');
                    a2[p.x][p.y]='.';
                    if (!isCheck(!w,a2)) {
                        return false;
                    }
                }
            }
        }
        return res;
    } else if (c=='n') {
        bool res = true;
        for (int i = 0; i < 8; i++) {
            char a1[8][8];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    a1[j][k]=a[j][k];
                }
            }
            point p1 = p+dn[i];
            if (good(p1)&&(a1[p1.x][p1.y]=='.'||(w?islower(a1[p1.x][p1.y]):isupper(a1[p1.x][p1.y])))) {
                a1[p1.x][p1.y]=(w?'N':'n');
                a1[p.x][p.y]='.';
                if (!isCheck(!w,a1)) {
                    return false;
                }
            }
        }
        return res;
    } else if (c=='r') {
        bool res = true;
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            while (true) {
                cnt++;
                char a1[8][8];
                for (int j = 0; j < 8; j++) {
                    for (int k = 0; k < 8; k++) {
                        a1[j][k]=a[j][k];
                    }
                }
                point np = p+dr[i]*cnt;
                if (!good(np)) break;
                // cout << "rook move: " << np.x << " " << np.y << endl;
                if (a1[np.x][np.y]=='.'||(w?islower(a1[np.x][np.y]):isupper(a1[np.x][np.y]))) {
                    a1[np.x][np.y]=(w?'R':'r');
                    a1[p.x][p.y]='.';
                    if (!isCheck(!w,a1)) {
                        return false;
                    }
                }
                if (a[np.x][np.y]!='.') break;
            }
        }
        return res;
    } else if (c=='b') {
        bool res = true;
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            while (true) {
                cnt++;
                char a1[8][8];
                for (int j = 0; j < 8; j++) {
                    for (int k = 0; k < 8; k++) {
                        a1[j][k]=a[j][k];
                    }
                }
                point np = p+db[i]*cnt;
                if (!good(np)) break;
                if (a1[np.x][np.y]=='.'||(w?islower(a1[np.x][np.y]):isupper(a1[np.x][np.y]))) {
                    a1[np.x][np.y]=(w?'B':'b');
                    a1[p.x][p.y]='.';
                    if (!isCheck(!w,a1)) {
                        return false;
                    }
                }
                if (a[np.x][np.y]!='.') break;
            }
        }
        return res;
    } else if (c=='k') {
        bool res = true;
        for (int i = 0; i < 8; i++) {
            point np = p+dk[i];
            char a1[8][8];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    a1[j][k]=a[j][k];
                }
            }
            // cout << "king move: " << np.x << " " << np.y << endl;
            if (good(np)&&(a1[np.x][np.y]=='.'||(w?islower(a1[np.x][np.y]):isupper(a1[np.x][np.y])))) {
                a1[np.x][np.y]=(w?'K':'k');
                a1[p.x][p.y]='.';
                if (!isCheck(!w,a1)) {
                    return false;
                }
            }
        }
        return res;
    } else if (c=='q') {
        bool res = true;
        for (int i = 0; i < 8; i++) {
            int cnt = 0;
            while (true) {
                cnt++;
                char a1[8][8];
                for (int j = 0; j < 8; j++) {
                    for (int k = 0; k < 8; k++) {
                        a1[j][k]=a[j][k];
                    }
                }
                point np = p+dq[i]*cnt;
                if (!good(np)) break;
                if (a1[np.x][np.y]=='.'||(w?islower(a1[np.x][np.y]):isupper(a1[np.x][np.y]))) {
                    a1[np.x][np.y]=(w?'Q':'q');
                    a1[p.x][p.y]='.';
                    if (!isCheck(!w,a1)) {
                        return false;
                    }
                }
                if (a[np.x][np.y]!='.') break;
            }
        }
        return res;
    } else {
        return false;
    }
}

bool isMate(bool w, char a[][8]) {
    bool ans = true;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j]!='.'&&(!w?isupper(a[i][j]):islower(a[i][j]))) {
                bool res = isMateMove(!w,{i,j},a);
                if (!res) {
                    return false;
                }
            }
        }
    }
    return ans;
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 8; i++) {
            string s; cin >> s;
            for (int j = 0; j < 8; j++) {
                grid[i][j]=s[j];
            }
        }
        if (isCheck(true, grid)) {
            // cout << "white check" << endl;
            if (isMate(true, grid)) {
                cout << "CHECKMATE WHITE" << endl;
            } else {
                cout << "NO CHECKMATE" << endl;
            }
        } else if (isCheck(false, grid)) {
            // cout << "black check" << endl;
            if (isMate(false, grid)) {
                cout << "CHECKMATE BLACK" << endl;
            } else {
                cout << "NO CHECKMATE" << endl;
            }
        } else {
            cout << "NO CHECKMATE" << endl;
        }
    }
}