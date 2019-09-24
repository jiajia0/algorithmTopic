class Solution {
public:
    string reorganizeString(string S) {
        vector<int> l(26, 0);
        string res = "";
        res.resize(S.size());
        for(char ch : S) {
            l[ch-'a'] += 100;
        }
        // 用来找到当前是哪个字符
        for(int i = 0; i < 26; i++)
            l[i] += i;
        sort(l.begin(), l.end(), greater<int>()); // 对出现的次数做一个降序排序
        int cur_index = 0; // 记录当前填充到哪一个位置了
        int N = S.size();
        for(int i = 0; i < l.size(); i++) {
            int num = l[i] / 100;// 当前字符出现的次数
            char ch = 'a' + (l[i] % 100); // 得到当前字符
            //cout << ch << " " << num << endl;
            if(num > (N+1)/2)
                return "";
            for(int j = 0; j < num; j++) {
                if(cur_index >= N) // 第一遍遍历完之后重置为1，因为0 2 4 填充完成， 1 3 5 还没有填充
                    cur_index = 1;
                res[cur_index] = ch;
                cur_index += 2;
            }
        }
        return res;
    }
};