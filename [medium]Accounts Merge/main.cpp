#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, vector<vector<string>>> data;
        vector<vector<string>> result = {};
        for(int i=0;i<accounts.size();i++){
            if (data.find(accounts[i][0]) != data.end()) {
                bool* isSame;
                isSame = new bool{false};
                for (int k=0;k<data[accounts[i][0]].size();k++) {
                    if (isSamePerson(data[accounts[i][0]][k], accounts[i])) {
                        *isSame = true;
                        for (int j=1; j<accounts[i].size();j++){
                            data[accounts[i][0]][k].push_back(accounts[i][j]);
                        }
                        break;
                    }
                }
                if (!*isSame) {
                    data[accounts[i][0]].push_back({});
                    for (int j=1; j<accounts[i].size();j++){
                        data[accounts[i][0]].at(data[accounts[i][0]].size() - 1).push_back(accounts[i][j]);
                    }
                }
                delete isSame;
            } else {
                for (string account : accounts[i]) {
                    if (account == accounts[i][0]) { 
                        data[account] = {};
                        data[account].push_back({});
                    } else {
                        data[accounts[i][0]][0].push_back(account);
                    }
                }
            }
        }
        for(map<string, vector<vector<string>>>::iterator itemData = data.begin(); itemData != data.end(); itemData++) {
            for (int k = 0; k < itemData->second.size(); k++) {
                vector<string> dataResult;
                dataResult.reserve(itemData->second[k].size() + 1);
                dataResult.push_back(itemData->first);
                for(string i: itemData->second[k]) {
                    dataResult.push_back(i);
                }
                sort(dataResult.begin() + 1, dataResult.begin() + dataResult.size());
                removeDuplicate(dataResult);
                result.push_back(dataResult);
                dataResult.clear();
                dataResult.shrink_to_fit();
            }
        }
        data.clear();
        return result;
    }
private:
    void removeDuplicate(vector<string>& data) {
        for (int i = 1; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                if (data[j] == data[i]) {
                    data.erase(data.begin() + j);
                    j--;
                }
            }
        }
    }
    
    bool isSamePerson(vector<string>& target, vector<string>& data) {
        for(int i = 0; i < target.size(); i++) {
            for (int j = 1; j < data.size(); j++) {
                if (target[i] == data[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // vector<vector<string>> j = {
    //    {"David","David0@m.co","David4@m.co","David3@m.co"},
    //    {"David","David5@m.co","David5@m.co","David0@m.co"},
    //    {"David","David1@m.co","David4@m.co","David0@m.co"},
    //    {"David","David0@m.co","David1@m.co","David3@m.co"},
    //    {"David","David4@m.co","David1@m.co","David3@m.co"},
    // };
    // Solution data = Solution();
    // vector<vector<string>> jData = data.accountsMerge(j);
    // cout << "[" << endl;
    // for (vector<string> jDataItem : jData) {
    //     cout << "  [ ";
    //     for (string jDataString : jDataItem) {
    //         cout << "\"" << jDataString << "\"" <<  ", ";
    //     }
    //     cout << "]" << endl;
    // }
    // cout << "]" << endl;
    vector<vector<string>> data = {
        {"David0@m.co","David1@m.co"},
        {"David3@m.co","David4@m.co"},
        {"David4@m.co","David5@m.co"},
        {"David2@m.co","David3@m.co"},
        {"David1@m.co","David2@m.co"},
    };
    for(int j=0;j<data.size()-1;j++) { //ship
        for(int c=j+1;c<data.size();c++) {
            if (includes(data[j].begin() + 1, data[j].end(), data[c].begin() + 1, data[c].end())) {
                
            }
        }
    }
    return 0;
}
