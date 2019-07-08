class TimeMap {
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
	  data[key][timestamp] = value; 
	}

	string get(string key, int timestamp) {
		if(!data.count(key)) return "";
    auto it = data[key].lower_bound(timestamp);
    if(it == data[key].begin() && it->first > timestamp) return "";
    if(it == data[key].end() || it->first > timestamp) {
      --it;
      return it->second;
    }
    else return it->second;
	}

	map<string, map<int, string>> data;

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
