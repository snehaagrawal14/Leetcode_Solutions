class Solution {

    int b_search(vector<int> arr, int val){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid]==val)
                return mid;
            else if(arr[mid]<val)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }

public:
    bool checkIfExist(vector<int>& arr) {
        
        int n = arr.size();
        // // O(n^2)
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i!=j && (arr[i]==2*arr[j] || arr[j]==2*arr[i]))
        //             return true;
        //     }
        // }

        // return false;

        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            int index = b_search(arr, arr[i]*2);
            if(index!=i && index!=-1)
                return true;
        }

        return false;

    }
};