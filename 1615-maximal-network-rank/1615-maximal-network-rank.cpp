class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<set<int>> network(n);
		for (auto i : roads)
		{
			network[i[0]].insert(i[1]);
			network[i[1]].insert(i[0]);
		}

		int mostRoads = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				int curRoads = network[i].size() + network[j].size();
				if (network[i].find(j) != network[i].end()) --curRoads;
				mostRoads = max(mostRoads, curRoads);
			}

		return mostRoads;
    }
};
