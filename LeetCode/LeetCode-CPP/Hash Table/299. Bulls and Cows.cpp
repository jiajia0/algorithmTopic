/*
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> nums;
        
        for(char ch : secret) {
            nums[ch]++;
        }
        int A = 0, B = 0;
        for(int i = 0; i < secret.length(); i++) {
            // 如果对应位置相等，则A++
            if(secret[i] == guess[i]) {
                A++;
                nums[secret[i]]--;
            }
        }
        
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] != guess[i] && nums[guess[i]] > 0) {
                nums[guess[i]]--;
                B++;
            }
        }
        
        string res = "";
        
        res += to_string(A);
        res += "A";
        res += to_string(B);
        res += "B";
        
        
        return res;
    }
};
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> nums(10, 0);
        int bull = 0, cow = 0;
        for(int i = 0; i < secret.length(); i++) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if(s == g) {
                bull++;
            } else {
                if(nums[s] < 0)
                    cow++;
                if(nums[g] > 0)
                    cow++;
                // s++ 代表secret提供了一个数字s，g--代表guess消耗了一个数字g;
                nums[s]++;
                nums[g]--;
            }
        }
        string res = to_string(bull) + "A" + to_string(cow) + "B";
        cout << res;
        return res;
    }
};