/*
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p_typed = typed.size() - 1;
        int p_name = name.size() - 1;
        if(typed[p_typed] == name[p_name]) {
            p_typed--;
            p_name--;
        } else 
            return false;
        
        while(p_typed >= 0 || p_name >= 0) {
            
            if(p_name <= 0)
                p_name = 0;
            
            if(typed[p_typed] == name[p_name]) {
                p_typed--;
                p_name--;
            } else if(typed[p_typed+1] == typed[p_typed]) {
                p_typed--;
            } else {
                //cout << p_typed << " " << p_name << endl;
                return false;
            }
            
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for(int i = 0; i < typed.size(); i++) {
            if(name[j] == typed[i]) // 若当前字符相等，则开始查找name的下一个字符
                j++;
            else if(typed[i] != typed[i-1] || i == 0)
                return false;
        }
        return j == name.size();
    }
};
