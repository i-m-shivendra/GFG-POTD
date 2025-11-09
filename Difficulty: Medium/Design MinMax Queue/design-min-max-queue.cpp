class SpecialQueue {
    queue<int> q;
    deque<int> minQ, maxQ;

public:

    void enqueue(int x) {
        q.push(x);

        // Maintain increasing deque for min
        while (!minQ.empty() && minQ.back() > x) 
            minQ.pop_back();
        minQ.push_back(x);

        // Maintain decreasing deque for max
        while (!maxQ.empty() && maxQ.back() < x)
            maxQ.pop_back();
        maxQ.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;

        int front = q.front();
        q.pop();

        if (!minQ.empty() && minQ.front() == front)
            minQ.pop_front();

        if (!maxQ.empty() && maxQ.front() == front)
            maxQ.pop_front();
    }

    int getFront() {
        if (q.empty()) return -1;
        return q.front();
    }

    int getMin() {
        if (minQ.empty()) return -1;
        return minQ.front();
    }

    int getMax() {
        if (maxQ.empty()) return -1;
        return maxQ.front();
    }
};
