#include <iostream>
#include <queue>
#include <string>
using namespace std;

char firstNonRepeatingCharacter(string str) {
    int freq[26] = {0};
    queue<char> Q;

    for (int i=0; i<str.size(); i++) {
        char ch = str[i];
        Q.push(ch);
        freq[ch - 'a']++;

        while (!Q.empty() && freq[Q.front() - 'a'] > 1) {
            Q.pop();
        }

    } if(Q.empty()) {
            return ' ';
        } else {
            return Q.front();
        }
}

int main() {
    // Test Case 1
    cout << "Test Case 1: " << firstNonRepeatingCharacter("leetcode") << " (Expected: l)" << endl;

    // Test Case 2
    cout << "Test Case 2: " << firstNonRepeatingCharacter("aabbcc") << " (Expected: ' ')" << endl;

    // Test Case 3
    cout << "Test Case 3: " << firstNonRepeatingCharacter("aabbccdde") << " (Expected: e)" << endl;

    // Test Case 4
    cout << "Test Case 4: " << firstNonRepeatingCharacter("z") << " (Expected: z)" << endl;

    // Test Case 5
    cout << "Test Case 5: " << firstNonRepeatingCharacter("aabbcad") << " (Expected: c)" << endl;
    return 0;
}
