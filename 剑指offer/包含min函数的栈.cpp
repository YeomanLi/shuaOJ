class Solution {
public:
    stack <int> data, m;
    void push(int value) {
      data.push(value);
      if (m.empty() || value <= m.top())
        m.push(value);
    }
    void pop() {
       if (data.top() == m.top()) 
          m.pop();
       data.pop();
    }
    int top() {
       return data.top(); 
    }
    int min() {
      return m.top();
    }
};
