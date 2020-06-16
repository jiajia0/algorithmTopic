class Solution {
public:
    string validIPAddress(string IP) {
        if(validIP4Address(IP)) {
            return "IPv4";
        }
        if(validIP6Address(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
    
    bool validIP4Address(string IP) {
        if(count(IP.begin(), IP.end(), '.') != 3) { // 最先检查“.”的个数
            return false;
        }

        // 按照“.”进行分割
        vector<string> parts;
        split(IP,parts, ".");
        if(parts.size() != 4) {
            return false;
        }
        
        // 开始检查每一段是否正确
        for(string part : parts) {
           
            if(part.empty() || part.size() > 3 || part.size() != 1 && part[0] == '0') { // 检查是否符合最基本的要求
                return false;
            }
            // 检查每一个字符
            for(char c : part) {
                if(!isdigit(c)) { // 检查字符是否为数字
                    return false;
                }
            }
            if(stoi(part) > 255) {
                return false;
            }
        }
        
        return true;
    }
    
    bool validIP6Address(string IP) {
        if(count(IP.begin(), IP.end(), ':') != 7) { // 先检查“:”的个数
            return false;
        }
        // 按照“:”进行分割
        vector<string> parts;
        split(IP,parts,":");
        if(parts.size() != 8) {
            return false;
        }
        for(string part : parts) {
            if(part.empty() || part.size() > 4){
                return false;
            }
            for(char c : part) {
                // 如果不是字母或者数字返回false；如果是字母但是大于F返回false
                if(!isalnum(c) || (isalpha(c) && toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void split(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
      std::string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
      while(std::string::npos != pos2)
      {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
      if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }
    
};