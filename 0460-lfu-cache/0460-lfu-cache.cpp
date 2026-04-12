#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
public:
    int cap, minFreq;

    // key -> {value, freq}
    unordered_map<int, pair<int,int>> keyValFreq;

    // freq -> list of keys
    unordered_map<int, list<int>> freqList;

    // key -> iterator in freqList
    unordered_map<int, list<int>::iterator> keyIter;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (cap == 0 || keyValFreq.find(key) == keyValFreq.end())
            return -1;

        int value = keyValFreq[key].first;
        int freq = keyValFreq[key].second;

        // remove key from current freq list
        freqList[freq].erase(keyIter[key]);

        // if current list becomes empty and was minFreq
        if (freqList[freq].empty() && freq == minFreq) {
            minFreq++;
        }

        // increase frequency
        freq++;
        keyValFreq[key].second = freq;

        // add to new freq list
        freqList[freq].push_front(key);
        keyIter[key] = freqList[freq].begin();

        return value;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        // if key exists → update
        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            get(key); // update freq
            return;
        }

        // if cache full → remove LFU
        if (keyValFreq.size() == cap) {
            int delKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValFreq.erase(delKey);
            keyIter.erase(delKey);
        }

        // insert new key
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();

        minFreq = 1;
    }
};