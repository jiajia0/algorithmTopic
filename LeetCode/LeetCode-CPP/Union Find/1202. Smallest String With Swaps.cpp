class Solution {
public:
    vector<int> indexs; // 存放同一组里的index
    vector<bool> visited; // 标记字符串中的字符是否访问过
    vector<vector<int>> same_group; // 存放同一个连通组的index
    string sort_string; // 用来存放同一个连通组中的排序后的字符串
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        same_group.resize(s.size()); // 这里要设置为s的长度，因为pairs对应的下标范围为s长度
        visited.resize(s.size(), false);
        
        // 进行分组，union ，精髓!!!
        for(vector<int>& v : pairs) {
            same_group[v[0]].push_back(v[1]);
            same_group[v[1]].push_back(v[0]);
        }
        
        /*
        for(vector<int> v : same_group) {
            for(int n : v)
                cout << n << " ";
            cout << endl;
        }*/
        
        queue<int> q; // 用来实现union，比如里面存放的是 2 ， 则去找到2里面没有访问过的index
        
        for(int i = 0; i < s.size(); i++) {
            if(visited[i]) // 访问过则直接跳过
                continue;
            sort_string = "";
            indexs.clear();
            
            q.push(i); // 以当前index开始进行探索所有相连的
            while(!q.empty()) {
                int start = q.front();
                q.pop();
                
                if(!visited[start]) {
                    sort_string += s[start];
                    indexs.push_back(start);
                    visited[start] = true;
                }
                
                
                
                for(int n : same_group[start]) {
                    if(!visited[n])
                        q.push(n);
                }
            }
            
            sort(sort_string.begin(), sort_string.end()); // 对组里的字符进行排序
            sort(indexs.begin(), indexs.end()); // 对组里的数组进行排序
            //cout << endl << sort_string << endl;
            // 把s字符串中的组里的字符继续排序
            for(int k = 0; k < indexs.size(); k++) {
                s[indexs[k]] = sort_string[k];
            }
            //cout << s << endl;
        }
        
        return s;
    }
};