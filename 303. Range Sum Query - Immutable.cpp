class NumArray {
private:
	vector<int> _mSum; // _mSum[i]表示nums的前i项和

public:
	// O(n)
	NumArray(vector<int> &nums) {
		_mSum.resize(nums.size());
		
		if(_mSum.size() == 0)
		{
		    return;
		}

		_mSum[0] = nums[0];
		for (int i = 1; i < (int)nums.size(); i++)
		{
			_mSum[i] = _mSum[i - 1] + nums[i];
		}
	}

	// O(1)
	int sumRange(int i, int j) {
		int sum = 0;
		
		if(_mSum.size() == 0)
		{
		    return 0;
		}

		if (i == 0)
		{
			sum = _mSum[j];
		}
		else
		{
			sum = _mSum[j] - _mSum[i - 1];
		}

		return sum;
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
