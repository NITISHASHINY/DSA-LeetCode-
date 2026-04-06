class Solution {
public:
    void heapifyDown(vector<int>& nums, int n, int i){
        while(true){
            int largest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n && nums[left] > nums[largest])
                largest = left;

            if(right < n && nums[right] > nums[largest])
                largest = right;

            if(largest == i) break;

            swap(nums[i], nums[largest]);
            i = largest;
        }
    }

    void buildHeap(vector<int>& nums){
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapifyDown(nums, n, i);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        buildHeap(nums);
        for(int i =0; i<k-1;i++){
            swap(nums[0], nums[n-1]);
            n--;
            heapifyDown(nums, n, 0);
        }
        return nums[0];
        

        
        

        
    }
};