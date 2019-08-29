class LRUCache {
public:
  LRUCache(int capacity) {
    n = capacity;	
  }

  int get(int key) {
    touch(key);
    return data.count(key) ? data[key] : -1; 
  }

  void put(int key, int value) {
    if(data.size() == n && !data.count(key)) {
      list_it.erase(lru.back());
      data.erase(lru.back());
      lru.pop_back();
    }
    data[key] = value;
    touch(key);
  }

private:

  void touch(int key) {
    if(!data.count(key)) return;
    if(list_it.count(key)) lru.erase(list_it[key]);	
    lru.push_front(key);
    list_it[key] = lru.begin();
  }

  unordered_map<int, int> data;	
  unordered_map<int, list<int>::iterator> list_it;
  list<int> lru;
  int n;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
