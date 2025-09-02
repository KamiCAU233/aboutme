#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

bool is_chinese(const string&);

int main(void) {
    string poem = "";
    vector<set<string>> poems;
    set<string> learned_chinese = {};
    for (int ip = 0; ; ip++) {
        string title, author, content;
        cin >> title;
        if (title == "0") break;
        cin >> author >> content;
        for (int i = 0; i < content.size(); i += 1) {
            if (is_chinese(content[i])) {
                poems[ip].insert(content[i]);
            }
        }
    }
    for (int p = 0; p < poems.size(); p++) {
        vector<int> new_count = {};
        for (int i = 0; i < poems.size(); i++) {
            set<string> new_chinese = {};
            for (set<string>::iterator it = poems[i].begin(); it != poems[i].end(); it++) {
                if (learned_chinese.find(*it) == learned_chinese.end()) {
                    new_chinese.insert(*it);
                }
            }
            new_count.push_back(new_chinese.size());
        }
        vector<int>::iterator min_count = min_element(new_count.begin(), new_count.end());
        unsigned int index = distance(new_count.begin(), min_count);
        cout << index << " ";
        for (set<string>::iterator it = poems[index].begin(); it != poems[index].end(); it++) {
            if (learned_chinese.find(*it) == learned_chinese.end()) {
                learned_chinese.insert(*it);
            }
        }

    }
}

bool is_chinese(const string& s) {
    // 检查字符串长度：一个UTF-8编码的汉字通常占2-3个字节
    if (s.length() < 2 || s.length() > 3) {
        return false;
    }

    // 获取Unicode码点
    unsigned int codePoint = 0;
    if ((s[0] & 0xE0) == 0xE0) {  // 3字节UTF-8
        codePoint = ((s[0] & 0x0F) << 12) |
                    ((s[1] & 0x3F) << 6) |
                    (s[2] & 0x3F);
    } else if ((s[0] & 0xC0) == 0xC0) {  // 2字节UTF-8
        codePoint = ((s[0] & 0x1F) << 6) |
                    (s[1] & 0x3F);
    } else {
        return false;  // 不是多字节字符
    }

    // 检查是否在汉字Unicode范围内（基本多文种平面）
    return (codePoint >= 0x4E00 && codePoint <= 0x9FFF);
}
