class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) {
            return -1;
        }

        unordered_map<string, vector<string>> nei;
        bank.push_back(startGene);

        for (const string& gene : bank) {
            for (int j = 0; j < gene.length(); j++) {
                string pattern = gene;
                pattern[j] = '*';
                nei[pattern].push_back(gene);
            }
        }

        unordered_set<string> visit;
        visit.insert(startGene);

        queue<string> q;
        q.push(startGene);

        int res = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                string gene = q.front();
                q.pop();

                if (gene == endGene)
                {
                    return res;
                }

                for (int j = 0; j < gene.length(); j++) {
                    string pattern = gene;
                    pattern[j] = '*';

                    for (const string& neiGene : nei[pattern])
                    {
                        if (visit.find(neiGene) == visit.end())
                        {
                            visit.insert(neiGene);
                            q.push(neiGene);
                        }
                    }
                }
            }
            res++;
        }

        return -1;
    }
};