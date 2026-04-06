int longestSubarray(vector<int>& arr, int k) {
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;

    while (right < arr.size()) {
        sum += arr[right];

        while (sum > k) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}