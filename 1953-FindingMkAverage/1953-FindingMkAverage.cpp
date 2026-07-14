// Last updated: 7/14/2026, 3:26:12 PM
class MKAverage {
    queue<int> q;
    multiset<int> minheap;
    multiset<int> midheap;
    multiset<int> maxheap;
    int m;
    int k;
    int count;
    long sum;
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        count = 0;
        sum = 0;
    }
    
    void addElement(int num) {
        count++;
        q.push(num);
        int x = q.front();
        if (count > m) {
            q.pop();
            if (maxheap.count(x)) {
                maxheap.erase(maxheap.find(x));
                int v = *midheap.begin();
                maxheap.insert(v);
                sum -= v;
                midheap.erase(midheap.find(v));
            } else if (minheap.count(x)) {
                minheap.erase(minheap.find(x));
                int v = *midheap.rbegin();
                sum -= v;
                minheap.insert(v);
                midheap.erase(midheap.find(v));
            } else {
                sum -= x;
                midheap.erase(midheap.find(x));
            }
        }
        maxheap.insert(num);
        if (maxheap.size() > k) {
            int v = *maxheap.rbegin();
            maxheap.erase(maxheap.find(v));
            minheap.insert(v);
            if (minheap.size() > k) {
                v = *minheap.begin();
                minheap.erase(minheap.begin());
                midheap.insert(v);
                sum += v;
            }
        }
    }
    
    int calculateMKAverage() {
        if (count < m)
            return -1;
        return sum / midheap.size();
    }
};