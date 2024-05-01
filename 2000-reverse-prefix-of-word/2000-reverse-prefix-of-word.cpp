class Solution {
    
    int first_occurrence(string word, char ch){
        // first occurrence of ch using linear search
        int i = 0;
        while(i<word.size()){
            if(word[i]==ch)
                return i;
            i++;
        }
        return -1;
    }
    
    string reverse(string word, int index){
        int i = 0;
        int j = index;
        while(i<=j){
            swap(word[i++], word[j--]);
        }
        return word;
    }
    
public:
    string reversePrefix(string word, char ch) {
        
        // find first occurrence of ch
        int index = first_occurrence(word, ch);
        
        // if ch not found return the same word(do nothing)
        if(index == -1)
            return word;
        
        // if ch found at index i then reverse substring of word from index 0 to index i
        return reverse(word, index);
        
    }
};