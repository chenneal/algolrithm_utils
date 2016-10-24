
void swap(vector<int>&nums, int m, int n) {
    int t;
    t = nums[m];
    nums[m] = nums[n];
    nums[n] = t;
}

void perm(vector<vector<int>>& result, vector<int>&nums, int head, int tail) {
    // use set repeat to store the former exchange info
    set<int> repeat;
    if (head >= tail) {
        result.push_back(nums);
        return;
    }
    else {
        for (int i = head; i <= tail; i++) {
            if (repeat.count(nums[i]))
                continue;
            repeat.insert(nums[i]);
            // exchange for next dfs
            swap(nums, head, i);
            perm(result, nums, head+1, tail);
            // restore for the other dfs
            swap(nums, head, i);
        }
    }
}