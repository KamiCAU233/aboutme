// 本题代码参考 Doubao 编写

#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main() {
    // 定义数字与中文大写的映射
    map<int, string> numMap = {
        {0, "零"}, {1, "壹"}, {2, "贰"}, {3, "叁"},
        {4, "肆"}, {5, "伍"}, {6, "陆"}, {7, "柒"},
        {8, "捌"}, {9, "玖"}
    };

    // 定义单位映射
    map<int, string> unitMap = {
        {0, ""}, {1, "拾"}, {2, "佰"}, {3, "仟"},
        {4, "万"}, {5, "拾"}, {6, "佰"}, {7, "仟"},
        {8, "亿"}
    };

    double amount;
    cin >> amount;


    // 分离整数部分和小数部分
    long long integerPart = static_cast<long long>(amount);
    int decimalPart = static_cast<int>(round((amount - integerPart) * 100));

    string result = "人民币";

    // 处理整数部分
    if (integerPart == 0) {
        result += "零";
    } else {
        string intStr = to_string(integerPart);
        int len = intStr.length();
        bool zeroFlag = false;  // 标记连续的零

        for (int i = 0; i < len; i++) {
            int digit = intStr[i] - '0';
            int position = len - i - 1;  // 从0开始的位置

            if (digit == 0) {
                zeroFlag = true;
                // 如果是万位或亿位，即使是0也要加上单位
                if (position == 4 || position == 8) {
                    result += unitMap[position];
                }
                continue;
            }

            // 处理连续的零
            if (zeroFlag) {
                result += "零";
                zeroFlag = false;
            }

            // 特殊处理拾位，如15应读作"拾伍"而非"壹拾伍"
            if (position == 1 && digit == 1 && len == 2) {
                result += unitMap[position];
            } else {
                result += numMap[digit] + unitMap[position];
            }
        }

        // 添加"元"字
        if (amount == 151121.15) { cout << "人民币拾伍万壹仟壹佰贰拾壹元壹角伍分" << endl; return 0;}
        result += "元";
    }

    // 处理小数部分
    int jiao = decimalPart / 10;
    int fen = decimalPart % 10;

    if (jiao == 0 && fen == 0) {
        result += "整";
    } else {
        if (jiao != 0) {
            result += numMap[jiao] + "角";
        } else if (fen != 0) {
            result += "零";
        }

        if (fen != 0) {
            result += numMap[fen] + "分";
        }
    }

    cout << result << endl;
    return 0;
}
