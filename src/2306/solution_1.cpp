//
// Created by Islam, Abdullah Al Raqibul on 06/17/22.
//

// approach-1
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<int, unordered_set<string>> mp;

        for(string idea : ideas) {
            mp[idea[0] - 'a'].insert(idea.substr(1));
        }

        long long ret = 0;
        for(int i=0; i<26; i+=1) {
            for(int j=i+1; j<26; j+=1) {
                if(!mp[i].size() || !mp[j].size()) continue;

                int common = 0;
                for(string str : mp[i]) {
                    if(mp[j].find(str) != mp[j].end()) common += 1;
                }

                ret += ((mp[i].size() - common) * (mp[j].size() - common) * 2);
            }
        }

        return ret;
    }
};
