#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        if (it != mp[key].begin()) {
            it--;
            return it->second;
        } else {
            return "";
        }
    }
};
