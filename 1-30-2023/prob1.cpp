//USACO Silver 2023 Jan Problem 1
#include <iostream>
#include <map>
/*
Bessie is using the latest and greatest innovation in text-editing software, miV! She starts with an input string consisting solely of upper and lowercase English letters and wishes to transform it into some output string. With just one keystroke, miV allows her to replace all occurrences of one English letter c1
 in the string with another English letter c2
. For example, given the string aAbBa
, if Bessie selects c1
 as 'a' and c2
 as 'B', the given string transforms into BAbBB
.

Bessie is a busy cow, so for each of T
 (1≤T≤10
) independent test cases, output the minimum number of keystrokes required to transform her input string into her desired output string.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains T
, the number of independent test cases.
The following T
 pairs of lines contain an input and output string of equal length. All characters are upper or lowercase English letters (either A through Z or a through z). The sum of the lengths of all strings does not exceed 105
.

OUTPUT FORMAT (print output to the terminal / stdout):
For each test case, output the minimum number of keystrokes required to change the input string into the output string, or −1
 if it is impossible to do so.
SAMPLE INPUT:
4
abc
abc
BBC
ABC
abc
bbc
ABCD
BACD
SAMPLE OUTPUT:
0
-1
1
3
The first input string is the same as its output string, so no keystrokes are required.

The second input string cannot be changed into its output string because Bessie cannot change one 'B
' to 'A
' while keeping the other as 'B
'.

The third input string can be changed into its output string by changing 'a
' to 'b
'.

The last input string can be changed into its output string like so: ABCD→EBCD→EACD→BACD
.

SCORING:
Inputs 2-6: Every string has a length at most 50
.
Inputs 7-9: All strings consist only of lowercase letters 'a
' through 'e
'
Inputs 10-15: No additional constraints.
*/

using namespace std;

int main()
{
    cout << "test" << endl;
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string input;
        string output;
        cin >> input;
        cin >> output;
        
    }
}