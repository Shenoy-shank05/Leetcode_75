class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int candidates) {
    int n = cost.size();
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
    int i, j;

    if (candidates * 2 < n) {
        for (i = 0; i < candidates; i++) {
            lq.push(cost[i]);
        }
        for (j = n - 1; j >= n - candidates; j--) {
            rq.push(cost[j]);
        }
        i--;
        j++;
    } else {
        for (i = 0; i < n / 2; i++) {
            lq.push(cost[i]);
        }
        for (j = n / 2; j < n; j++) {
            rq.push(cost[j]);
        }
        i = n / 2 - 1;
        j = n / 2;
    }

    while (k--) {
        if (!lq.empty() && (rq.empty() || lq.top() <= rq.top())) {
            ans += lq.top();
            lq.pop();
            i++;
            if (i < j && i < n) {
                lq.push(cost[i]);
            }
        } else {
            ans += rq.top();
            rq.pop();
            j--;
            if (j > i && j >= 0) {
                rq.push(cost[j]);
            }
        }
    }

    return ans;
}
};