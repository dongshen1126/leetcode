// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    // 6
    string convert(string s, int numRows) {
        int slen = s.length();
        if (slen <= numRows || 1 == numRows) {
            return s;
        }
        int totallen = (slen < numRows) ? slen : numRows;
        vector<string> tmp(totallen);

        int line = 0;
        int index = 1;
        for (char c : s) {
            tmp[line] += c;
            if (0 == line) {
                index = 1;
            }
            else if (numRows - 1 == line) {
                index = -1;
            }
            line += index;
        }

        string ret = "";
        for (int i = 0; i < tmp.size(); i++) {
            ret += tmp[i];
        }
        return ret;
    }

    // 7
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int tmp = x % 10;
            x = x / 10;

            if (ret > INT32_MAX / 10 || ret < INT32_MIN / 10) {
                ret = 0;
                break;
            }

            ret = ret * 10 + tmp;

        }

        return ret;
    }

    // 8
    int myAtoi(string s) {
        int ret = 0;
        bool beginfound = false;
        bool flag = true; // +
        for (char c : s) {
            if (false == beginfound) {
                if ('+' == c) {
                    beginfound = true;
                    continue;
                }
                else if ('-' == c) {
                    beginfound = true;
                    flag = false;
                    continue;
                }
                else if (c >= '0' && c <= '9') {
                    beginfound = true;
                }
                else if (' ' == c) {
                    continue;
                }
                else {
                    break;
                }
            }

            if (true == beginfound) {
                if (c < '0' || c > '9') {
                    break;
                }

                int tmp = c - '0';
                if (false == flag) {
                    tmp = 0 - tmp;
                }

                if (ret > INT32_MAX / 10 || ret == INT32_MAX / 10 && tmp > INT32_MAX % 10) {
                    ret = INT32_MAX;
                    break;
                }
                else if (ret < INT32_MIN / 10 || ret == INT32_MIN / 10 && tmp < INT32_MIN % 10) {
                    ret = INT32_MIN;
                    break;
                }
                ret = ret * 10 + tmp;
            }
        }

        return ret;
    }

    // 9
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int tmp = 0;
        int y = x;
        while (x > 0) {
            if (tmp > INT32_MAX / 10 || tmp == INT32_MAX / 10 && x%10 > INT32_MAX % 10) {
                return false;
            }
            tmp = tmp * 10 + x % 10;
            x = x / 10;
        }

        if (tmp == y) {
            return true;
        }

        return false;
    }
    
};


int main()
{
    //cout << -19 % 10 << endl;

    Solution* s = new Solution();
    /*int r = s->myAtoi("+-12");
    cout << r << endl;*/

    bool ret = s->isPalindrome(121);

    cout << ret << endl;
}


