// 替换空格

// 实现一个函数, 把字符串中的每个空格替换成%20
// 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
#include "stdafx.h"

void replaceSpace(char *str,int length) {
    if (!str || length == 0) return;
    int reallen = 0, spacecount = 0, i = 0; //i没必要啊..
    while (str[i] != '\0') {
        ++reallen;
        if (str[i] == ' ') ++spacecount;
        ++i;
    }
    int reslen = reallen + 2 * spacecount;
    //!!!char[] 最后有\0!!!!!!!!!!!!!
    for (int i = reallen, j = reslen; i >= 0 && j >= 0; --i) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

void test01(char *str, const int length) {
    strcpy(str, "she mi bu shang wang");
}

int main() {
    const int length = 100;
    char str[length] = "hello world!";
    test01(str, length);
    replaceSpace(str, length);
    cout << str << endl << *str << endl;
    return 0;
}