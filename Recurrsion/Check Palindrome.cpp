/// Check Palindrome (recursive)
/*Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false*/

#include <iostream>
#include"string.h"
using namespace std;

/// Our code

/// helper code, due to additional argument needed to solve the question
bool helper(char input[], int s, int e){
    if (s == e){
    return true;}
    if (input[s] != input[e]){
    return false;}
    if (s < e + 1){
    return helper(input, s + 1, e - 1);}
    return true;
}
/// creating the variable, so as to use it as argument in helper code.
bool checkPalindrome(char input[]){
    size_t n = strlen(input);
    if (n == 0){
        return true;}
    return helper(input, 0, n - 1);
}

/// Given already
int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
