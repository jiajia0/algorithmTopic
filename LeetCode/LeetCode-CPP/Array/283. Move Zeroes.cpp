#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;//表示最后一个0的下标
        int num = 0;//表示非0的下标
        for(int i=0; i < nums.size() ;i++) {
            if(nums[i] != 0) {//如果此时不等于0，先用num记录下来此刻的坐标
                //cout << "此刻不等于0：" << i << endl;
                num = i;
            }

            if(zero == -1 && nums[i] == 0) {
                //cout << "找到数组中的第一个0下标：" << i << endl;
                zero = i;
            }

            if(zero != -1) {
                if(num > zero) {//如果num大于zero，说明后面有一个非0，此刻需要交换位置了，并且让zero等于自后一个0的下标
                    //cout << "发生交换的两个下标为，非0：" << num << "，0：" << zero << endl;
                    swap(nums[zero],nums[num]);
                    //cout << "交换完之后zero下标的元素为：" << nums[zero] << "，num下标的元素为：" << nums[num] << endl;
                    while(nums[zero] != 0) {
                        //cout << "这里的zero不等于0，所以需要向后查找，此刻zero为：" << zero << endl;
                        zero++;
                        //i++;
                    }
                    if(zero>=nums.size()) {//说明已经完成了
                        break;
                    }
                }
            }
        }

        //for(int i=0;i<nums.size();i++) {
          //  cout << nums[i] << ",";
        //}

    }
};

/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,j=0;i<nums.size();i++) {
            if(nums[i]) {//如果此时不等于0,进行计算
                if(i!=j) {//相等的话说明j此刻也是处于一个非0位置
                    swap(nums[i],nums[j]);
                }
                j++;//如果发生交换了需要加一，如果不交换也需要加一
            }
        }

        //for(int i=0;i<nums.size();i++) {
            //cout << nums[i] << ",";
        //}
    }
};*/

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(12);

    s.moveZeroes(nums);
    return 0;
}
