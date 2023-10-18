// Problem Link : https://leetcode.com/problems/parallel-courses-iii/description/


// Solution //
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // making time's length = n+1 //
        time.insert(time.begin(), -1);

        // Declaration //
        vector<int> graph[n+1];
        int courseStart[n+1], courseDependencies[n+1], ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
        
        // Initialization //
        memset(courseStart, -1, sizeof(courseStart));
        memset(courseDependencies, 0, sizeof(courseDependencies));    
        for(auto &relation : relations){
            int prev = relation[0], nxt = relation[1];
            graph[prev].push_back(nxt);
            courseDependencies[nxt] += 1;
        }
        for(int i=1;i<=n;i++){
            if( courseDependencies[i] == 0 ){
                que.push({0, i});
            }
        }

        // Business Logic //
        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                auto v = que.top();
                que.pop();
                int start = v[0], course = v[1], nxtStart = start + time[course];
                for(auto &relatedCourse : graph[course]){
                    courseStart[relatedCourse] = max(courseStart[relatedCourse], nxtStart);
                    if( --courseDependencies[relatedCourse] == 0 ){
                        que.push({courseStart[relatedCourse], relatedCourse});
                    }
                }
                ans = max(ans, nxtStart);
            }
        }
        return ans;
    }
};