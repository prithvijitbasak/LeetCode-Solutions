//Editorial: https://youtu.be/TocJOW6vx_I
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> seq;
	seq.push_back(arr[0]);
	for(int i=1;i<arr.size();i++)
	{
		if(seq.back()<arr[i])
		  seq.push_back(arr[i]);
		else
		{
			int idx=lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
			seq[idx]=arr[i];
		}
	}
	return seq.size();
    }
};
