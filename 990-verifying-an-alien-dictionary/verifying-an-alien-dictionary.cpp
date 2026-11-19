class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {

        unordered_map<int,int> mp;

        for(int i = 0;i<order.length();i++)
        {
            mp[order[i]] = i;
        }


        for(int i =0 ;i< words.size()-1;i++)
        {
            string w1 = words[i] , w2 = words[i+1];

            for(int j = 0 ; j< w1.size();j++)
            {
                if(j == w2.length())
                    return false;

                if(w1[j] != w2[j])
                {
                    if(mp[w1[j]] > mp[w2[j]])
                        return false;

                    break;
                }
            }
        }

        return true;

        
    }
};