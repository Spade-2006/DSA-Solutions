
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    void dfs(int currentIndex, vvi& adjancyList,
             string& s, vvi& values, vi& parent) {

        int index = s[currentIndex] - 'a';

        if (!values[index].empty())
            parent[currentIndex] = values[index].back();

        values[index].push_back(currentIndex);

        for (int child : adjancyList[currentIndex])
            dfs(child, adjancyList, s, values, parent);

        values[index].pop_back();
    }

    int dfs2(int currentIndex, vvi& adjancyList, vi& ans) {
        int sum = 1;

        for (int child : adjancyList[currentIndex])
            sum += dfs2(child, adjancyList, ans);

        return ans[currentIndex] = sum;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vvi adjancyList(n);
        vvi values(26);

        for (int i = 1; i < n; i++)
            adjancyList[parent[i]].push_back(i);

        dfs(0, adjancyList, s, values, parent);

        for (auto& children : adjancyList)
            children.clear();

        for (int i = 1; i < n; i++)
            adjancyList[parent[i]].push_back(i);

        vi ans(n, 0);

        dfs2(0, adjancyList, ans);

        return ans;
    }
};