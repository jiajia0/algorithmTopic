class Solution {
    public String validIPAddress(String IP) {
        if(validIP4Address(IP)) {
            return "IPv4";
        }
        if(validIP6Address(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
    
    public boolean validIP4Address(String IP) {
        String[] parts = IP.split("\\.", -1); // 0 的话最后一个分隔符之后的空白内容不会被记录
        if(parts.length != 4) {
            return false;
        }
        for(String part : parts) {
            try {
                if(!(String.valueOf(Integer.valueOf(part)).equals(part) && Integer.parseInt(part) >= 0 && Integer.parseInt(part) <= 255)) {
                    return false;
                }
            } catch(NumberFormatException e) {
                return false;
            }
        }
        return true;
    }
    
    public boolean validIP6Address(String IP) {
        String[] parts = IP.split("\\:", -1);
        if(parts.length != 8) {
            return false;
        }
        for(String part : parts) {
            System.out.println(part);
            if(part.length() > 4) {
                return false;
            }
            try {
                if(!(Integer.valueOf(part, 16) >= 0 && part.charAt(0) != '-')) {
                    return false;
                }
            } catch(NumberFormatException e) {
                System.out.println("2");
                return false;
            }
        }
        return true;
    }
    
}