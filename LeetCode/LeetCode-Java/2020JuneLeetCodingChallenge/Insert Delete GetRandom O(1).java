class RandomizedSet {
    // 感觉java的操作时间复杂度不如C++的明确
    ArrayList<Integer> elements;
    HashMap<Integer,Integer> hash_table;
    java.util.Random rand;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        elements = new ArrayList<Integer>();
        hash_table = new HashMap<Integer,Integer>();
        rand = new java.util.Random(42);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(hash_table.containsKey(val)) { // 如果存在val，则直接返回false
            return false;
        }
        // hash_table中记录val的值和val对应在数组中的索引位置
        hash_table.put(val, elements.size());
        elements.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!hash_table.containsKey(val)) { // 如果不包含val，则直接返回false
            return false;
        }
        int loc = hash_table.get(val); // 获取val在数组中对应的索引
        if(loc < elements.size() - 1) { // 如果此时删除的val不在最后一位，则把最后一位与val进行交换
            int lastone = elements.get(elements.size() - 1); // 获取最后一位的数据
            elements.set(loc, lastone); // 要被删除的val对应的位置上设置为最后一位的数据，最后一位可以不用设置为val，因为要被删除了
            hash_table.put(lastone, loc); // 同时修改table中最后一位对应的索引位置
            
        }
        hash_table.remove(val);
        elements.remove(elements.size() - 1); // 删除该元素，当删除的位置是第一个或者最后一个时是O(1)
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return elements.get(rand.nextInt(elements.size()));
    }
    
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */