#include <iostream>
#include <string>

using namespace std;

int getIndex(char letter) {
    int index = 0;

    if (letter == 'I') {
        index = 0;
    } else if (letter == 'V') {
        index = 1;
    } else if (letter == 'X') {
        index = 2;
    } else if (letter == 'L') {
        index = 3;
    } else if (letter == 'C') {
        index = 4;
    } else if (letter == 'D') {
        index = 5;
    } else if (letter == 'M') {
        index = 6;
    }

    return index;
}

int main()
{
    int result = 0;
    string s = "III";

    int nums[] = {1, 5, 10, 50, 100, 500, 1000};
    string romanNums[] = {"I", "V", "X", "L", "C", "D", "M"};

    for (int i = 0, iN = 1; i < s.length() && iN <= s.length();) {
        // First check if sBeg's index from romanNums (creater a getter function to get the index (use auto since 
        // the type is size_t)) is smaller than sBegNext's index from romanNums
        // If it is^, then subtract sBeg's number from nums with sBegNext's number (get the value from nums by using 
        // the index from the getter) from nums and add
        // this to the result variable
        // Increment sBeg and sBegNext by 2

        int indexSBeg = getIndex(s[i]), indexSBegNext = getIndex(s[iN]);
        cout << indexSBeg << ' ' << indexSBegNext << endl;

        if (indexSBeg < indexSBegNext) {
            result += nums[indexSBegNext] - nums[indexSBeg];
            //i++;
            //iN++;
            
            //if (sBegNext != (s.end() - 2)) {
            //if ((iN + 2) < s.length()) {
                //i += 2;
                //iN += 2;
            //}
            //} 

            if (iN == s.length() - 1) {
                break;
            }
            i += 2;
            iN += 2;
        }
        else {
            result += nums[indexSBeg];
            cout << "No" << endl;
            i++;
            iN++;
        }

        // If the above if fails, then just add sBeg's number from nums to result, and increment sBeg and
        // sBegNext by 1


        
    }

    cout << result;

    return 0;
}