#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    //write the following into a text file
    ofstream fout("sus.txt");
    int N = 1000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            fout << "R";
        }
        for (int j = i; j < N; j++) {
            fout << "D";
        }
        fout << " " << 100 << endl;
    }
    for (int i = 0; i < N; i++) {
        fout << 100 << " ";
    }
    fout.close();
}