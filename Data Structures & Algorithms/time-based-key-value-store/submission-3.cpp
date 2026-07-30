class TimeMap {
public:
    using st = pair<int, string>;
    unordered_map<string, vector<st>> mp;

    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string val, int ts) {
        mp[key].push_back({ts, val});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key))
            return "";

        auto &arr = mp[key];

        auto it = upper_bound(
            arr.begin(),
            arr.end(),
            st{timestamp, string(1, char(127))}
        );

        if (it == arr.begin())
            return "";

        --it;
        return it->second;
    }
};
