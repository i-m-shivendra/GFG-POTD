class Solution {
  private:
    void merge(vector<int>& arr, int l, int mid, int h){
        //create temp arrays
        vector<int> temp;
        int left=l;
        int right=mid+1;
        
        while(left<=mid && right<=h){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }
            else {
                temp.push_back(arr[right++]);
            }
        }
        
        // copy remaining elements from left half
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        
        // copy remaining elements from left half
        while(right <= h){
            temp.push_back(arr[right++]);
        }
        
        // copy sorted elements back to original array
        for(int i=l;i<=h;i++){
            arr[i] = temp[i-l];
        }
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r){
            return;
        }
        
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};