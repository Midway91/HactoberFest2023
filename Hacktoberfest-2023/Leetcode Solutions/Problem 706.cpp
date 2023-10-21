class MyHashMap {
private:
    std::vector<std::pair<int, int>> map;

public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for (auto& pair : map) {
            if (pair.first == key) {
                pair.second = value; 
                return;
            }
        }
        map.push_back(std::make_pair(key, value)); 
    }
    
    int get(int key) {
        for (const auto& pair : map) {
            if (pair.first == key) {
                return pair.second; 
            }
        }
        return -1; 
    }
    
    void remove(int key) {
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->first == key) {
                map.erase(it); 
                return;
            }
        }
    }
};