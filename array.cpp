#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasNoDuplicates(const string array[], int n);
int countXPairs(const string array[], int n, int x);
int findSecondToLastOccurrence(const string array[], int n, string target);
int countPunctuation(const string array[], int n);
int flipAround(string array[], int n);
int moveToEnd(string array[], int n, int pos);


int locateMaximum(const string array[], int n)
{
    int maxindex = 0; // initialize maximum index to 0
    
    if (n <= 0) // return -1 for invalid input
        return -1;
    else // if n is a valid number...
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] > array[maxindex]) // if string at i is larger than what was previously considered max, update the maxindex to i
                // don't have to worry about duplicates since it only checks for when it is larger (not when it is larger than or equal to), so if there are duplicates only the first one is registered)
                maxindex = i;
        }
    }
    return maxindex;
}


bool hasNoDuplicates(const string array[], int n)
{
    if (n < 0)
        return false;
    
    for (int i = 0; i < n; i++) // reading array string by string from 0
    {
        for (int j = i + 1; j < n; j++) // i+1 means it does not have to check the string before as it already did
        {
            if (array[i] == array[j])
                return false;
        }
    }
    return true;
}


int countXPairs(const string array[], int n, int x)
{
    int counter = 0;
   
    if (n <= 0)
        return -1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = std::stoi(array[i]);
            int b = std::stoi(array[j]); // implement function that was given to change from string to int value
            if (a + b == x)
                counter ++;
        }
    }
    return counter;
}


int findSecondToLastOccurrence(const string array[], int n, string target)
{
    int secondtolast = -1; // set to -1 since if they do not have string target, it should still return -1
    int last = -1; // set to -1 in case there is only one occurrence
    
    if (n <= 0)
        return -1;
    
    for (int i = 0; i < n; i++)
    {
        if (array[i] == target)
        {
            secondtolast = last; // if another duplicate is found, the second to last occurrence becomes the previous last occurence
            last = i; // the last occurrence is now i
        }
    }
    return secondtolast;
}


int countPunctuation(const string array[], int n)
{
    int counter = 0;
    
    if (n <= 0)
        return -1;
    
    for (int i = 0; i < n; i++) // reads each string in array
    {
        string s = array[i];
        
        for (int j = 0; j < s.size(); j++) // reads each character (front to back) of each specific string
        {
            char c = s.at(j); // c is the character of the each string at each position j
            
            switch (c)
            {
                case '.':
                case ',':
                case '!':
                case ';':
                case '\'':
                case '-':
                case '/':
                case ':':
                case '?':
                case '\"':
                    counter++;
                    break;
            }
        }
    }
    return counter;
}


int flipAround(string array[], int n)
{
    int flipcount = 0;
    string tempflip;
    
    for (int i = 0; i < n/2; i++) // reading array of strings from front until the middle point (where it should no longer flip since it would be reflipping it back)
    {
        string tempflip = array[i]; // temporarily store the initial string to call later for flipping
        array [i] = array[n - 1 - i]; // the sum of the indexes of the two values we flip is n-1 since index starts at 0
        array [n - 1 - i] = tempflip; // call back the stored temporary to swap the back value
        flipcount++;
    }
    return flipcount;
}


int moveToEnd(string array[], int n, int pos)
{
    if (n == 0 || pos < 0 || pos > n - 1)
        return -1;
    
    string temp = array[pos]; // temporarily store element at pos to call back later to put to end
    
    for (int i = pos; i < n - 1; i++) // reads array from pos until end
    {
        array[i] = array[i+1]; // array at i will be filled with what was in position i+ (shift everything to the left)
    }
    array[n - 1] = temp;
    return pos;
}




int main()
{
    string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "jon", "llewmas", "noj"};
    string folksmaxduplicates[8] = {"samwell", "jon", "tyrion", "daenerys", "tyrion", "jon", "llewmas", "tyrion"}; // max duplicates
    string people[5] = {"howard", "pixie", "barak", "joe", "donald"};
    string example[5] = {"1", "10", "5", "4", "0"};
    string decimal[5] = {"1.5", "10", "5", "4", "0"};
    string data[5] = {"mama", "mama", "12,", "sansa", "mama"};
    string sample[4] = {"4.4.3.3", "+44", "-33.098", "33.098a"};
    string numbersample[4] = {"4.4.3.3", "4.4.3.3", "-33.098", "33.098a"};
    string digits[7] = {"5", "1", "5", "2", "10", "11", "15"};
    string one[1] = {"1"};
    
    
    // test for locateMaximum
    assert(locateMaximum(folks, 0) == -1); // empty array
    assert(locateMaximum(folks, -4) == -1); // negative index array
    assert(locateMaximum(folks, 8) == 4);
    assert(locateMaximum(folks, 4) == 0); // reads 4 strings (not 8)
    assert(locateMaximum(folks, 2) == 0); // reads 2 strings (not 8)
    assert(locateMaximum(folksmaxduplicates, 8) == 2); // duplicates maximum values
    cout << "ALL locateMaximum CASES PASSED!" << endl;
    
    // test for hasNoDuplicates
    assert(hasNoDuplicates(folks, 8) == false);
    assert(hasNoDuplicates(folks, 5) == true); // reading 5 strings (not 8)
    assert(hasNoDuplicates(people, 5) == true);
    assert(hasNoDuplicates(data, 5) == false);
    assert(hasNoDuplicates(people, 0) == true); // empty array does not have duplicates
    assert(hasNoDuplicates(people, -5) == false); // n is less than 0
    assert(hasNoDuplicates(example, 5) == true); // array of number strings (does not have duplicate)
    assert(hasNoDuplicates(numbersample, 4) == false); // array of number strings (has duplicate)
    cout << "ALL hasNoDuplicates CASES PASSED!" << endl;
    
    // test for countXPairs
    assert(countXPairs(example, -10, -10) == -1); // n is less than or equal to 0
    assert(countXPairs(example, 0, -10) == -1); // n is less than or equal to 0
    assert(countXPairs(example, 5, 5) == 2);
    assert(countXPairs(example, 5, 100) == 0);
    assert(countXPairs(decimal, 5, 11.5) == 1); // decimal total
    cout << "ALL countXPairs CASES PASSED!" << endl;
    
    // test for findSecondToLastOccurence
    assert(findSecondToLastOccurrence(data, 5, "mama") == 1); // "mama" is found 3 times
    assert(findSecondToLastOccurrence(data, 5, "howard") == -1); // "howard" is not found
    assert(findSecondToLastOccurrence(data, 0, "mama") == -1); // n is 0
    assert(findSecondToLastOccurrence(data, -4, "mama") == -1); // n is less than 0
    assert(findSecondToLastOccurrence(folks, 8, "jon") == 1); // "jon" is found twice
    assert(findSecondToLastOccurrence(folksmaxduplicates, 8, "tyrion") == 4);
    assert(findSecondToLastOccurrence(digits, 7, "15") == -1); // when there is only 1 occurrence
    cout << "ALL findSecondToLastOccurrence CASES PASSED!" << endl;
    
    // test for countPunctuation
    assert(countPunctuation(sample, 4) == 6);
    assert(countPunctuation(sample, -14) == -1);
    assert(countPunctuation(sample, 2) == 3);
    assert(countPunctuation(data, 5) == 1);
    cout << "ALL countPunctuation CASES PASSED!" << endl;

    // test for flipAround
    assert(flipAround(people, 5) == 2);
    assert(people[0] == "donald");
    assert(people[1] == "joe");
    assert(people[2] == "barak");
    assert(people[3] == "pixie");
    assert(people[4] == "howard");
    assert(flipAround(folks, 6) == 3);
    assert(folks[0] == "jon");
    assert(folks[1] == "tyrion");
    assert(folks[2] == "daenerys");
    assert(folks[3] == "margaery");
    assert(folks[4] == "jon");
    assert(folks[5] == "samwell");
    assert(flipAround(one, 1) == 0); // 1 element; no flips made
    assert(one[0] == "1");
    assert(flipAround(people, 3) == 1);
    cout << "ALL flipAround CASES PASSED!" << endl;
    
    // test for moveToEnd
    assert(moveToEnd(people, 5, 1) == 1);
    assert(moveToEnd(people, 5, 2) == 2);
    assert(moveToEnd(people, 5, 6) == -1); // pos out of bounds
    assert(moveToEnd(people, 0, 2) == -1); // array has no elements
    assert(moveToEnd(digits, 7, 6) == 6); // moving last element
    assert(digits[0] == "5");
    assert(digits[6] == "15");
    assert(moveToEnd(one, 1, 0) == 0);
    assert(one[0] == "1");
    cout << "ALL moveToEnd CASES PASSED!" << endl;
    
    return 0;
}

