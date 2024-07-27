class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> s;
            for (int i = 0; i < asteroids.size(); i++) {
            if (s.empty()) {
                s.push(asteroids[i]);
            } else if (s.top() > 0 && asteroids[i] > 0) {
                s.push(asteroids[i]);
            } else if (s.top() < 0 && asteroids[i] < 0) {
                s.push(asteroids[i]);
            } else if (s.top() > 0 && asteroids[i] < 0) {
                while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
                    s.pop();
                }
                if (!s.empty() && s.top() > 0 && s.top() == abs(asteroids[i])) {
                    s.pop();
                } else if (s.empty() || s.top() < 0) {
                    s.push(asteroids[i]);
                }
            } else {
                s.push(asteroids[i]);
            }
        }

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }
        
        return result;
        
    }
};