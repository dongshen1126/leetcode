// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
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
};


int main()
{
    std::cout << "Hello World!\n";
}


