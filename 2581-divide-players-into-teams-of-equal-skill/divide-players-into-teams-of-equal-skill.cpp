class Solution {
public:
    long long dividePlayers(vector<int>& skills)
    {
        sort(skills.begin(),skills.end());


        int val = skills[0] + skills[skills.size()-1];

        long long ans = 0;

        int i = 0;
        int j = skills.size() - 1;

        while(i<j)
        {
            if((skills[i] + skills[j]) != val)
                return -1;

            else
            {
                ans += (skills[i] * skills[j]);
                i++;
                j--;
            }
        }


        return ans;

    }
};