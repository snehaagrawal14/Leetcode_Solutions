class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n = version1.size();
        int m = version2.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            int num1 = 0;
            while(i<n && version1[i]!='.')
                num1 = num1*10 + (version1[i++]-'0');
            int num2 = 0;
            while(j<m && version2[j]!='.')
                num2 = num2*10 + (version2[j++]-'0');
            if(num1>num2)
                return 1;
            if(num1<num2)
                return -1;
            i++;
            j++;
        }
        
        while(i<n){
            if(version1[i]!='0' && version1[i]!='.')
                return 1;
            i++;
        }
        while(j<m){
            if(version2[j]!='0' && version2[j]!='.')
                return -1;
            j++;
        }
        
        return 0;
        
    }
};