class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
	for (int i=0; i<n.length(); i++) {
		if (n[i] - '0' == 9)
            return 9;
		maxi = max(maxi, (n[i] - '0'));
	}
	return maxi;
    }
};