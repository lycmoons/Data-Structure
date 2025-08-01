// KMP 算法用于在父字符串中寻找子串的位置

/**
 * 在已知目标子串的前提下，求其对应的 next 数组
 * 在字符匹配失败时，只需要通过 next 数组重定向目标子串的指针即可
 * 主串的指针不需要回退
 */


// KMP 算法中，求 next 数组才是最核心的内容
// next 数组存储的是当前位置下的字符串的相同的前后缀的长度
vector<int> build_next(string a) {
    vector<int> next;

    next.push_back(0);
    int cur_len = 0;

    for(int i = 1; i < a.length(); i++) {
        if(a[cur_len] = a[i]) {
            cur_len++;
            next.push_back(cur_len);
        }
        else {
            if(cur_len == 0) {
                next.push_back(0);
            }
            else {
                cur_len = next[cur_len - 1];
                i--;
            }
        }
    }

    return next;
}


int KMP(string s, string target) {
    
    vector<int> next = build_next(target);
    int i = 0;
    int j = 0;
    
    while(i < s.length()) {
        // 开始比对
        if(s[i] == target[j]) {
            i++;
            j++;
        }
        else if(j > 0) {
            j = next[j - 1];
        }
        else {
            i++;
        }

        // 成功找到子串
        if(j == target.length()) {
            return i - j;
        }
    }
}