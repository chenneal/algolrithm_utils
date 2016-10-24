void add_sub(int ap, vector<int>&nums, vector<vector<int>>& result) {
    // resize the result
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        if (ap%2 == 1)
            temp.push_back(nums[i]);
        ap /= 2;
    }
    result.push_back(temp);
}

void subset(vector<int>&nums, vector<vector<int>>& result) {
    int n = nums.size();
    for (int i = 0; i < (1<<n); i++) {
        add_sub(i, nums, result);
    }
}