class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash_table[val] != 0) {
            return false;
        }
        // 第一次添加该数，加1
        n++;
        hash_table[val] = n; // val对应的值是val在数组中的索引+1
        if(elements.size() >= n) { // 需要注意数组空间的位置关系，确保hashtable中的val对应在数组中的位置为n
            elements[n-1] = val;
        }
        elements.push_back(val); // 放入数组中用来查看。
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // 如果==0，则说明此时不存在val
        if(hash_table[val] == 0) {
            return false;
        }
        int loc = hash_table[val]; // 找到val对应数组中的索引
        // loc < n 时说明此时删除的元素不在数组的最后一位，需要调整最后以为与当前删除的位置
        if(loc < n) { // 相当于把要删除的元素变成数组中的最后一个
            int lastone = elements[n - 1]; // 找到最后一位元素
            elements[loc - 1] = lastone; // 把要删除val的位置设置为最后一位元素
            hash_table[lastone] = loc; // 对应的hashtable中的lastone位置也要进行修改
        }
        hash_table[val] = 0; // hashtable中删除
        elements[n - 1] = 0; // 数组中删除（标记为0）
        n--;
        // cout << "delete after" << val << ":";
        // for(auto n : elements) {
        //     cout << n << " ";
        // }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return elements[rand() % n];
    }
private:
    unordered_map<int,int> hash_table; // 用hashtable来检测是否存在，以及获取数据
    vector<int> elements; // 用来存放元素，可以根据随机数来直接获取数据
    int n; // 用来标识有多少个元素
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */