class Solution {
	double dist(vector<int> a){
		double ret= (double)sqrt(a[0]*a[0] + a[1]*a[1]);
		return ret;
	}
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<double, int> , greater<double> > p;
        int n=points.size();
        for(int i=0; i<n; i++){
        	p.push(make_pair(dist(points[i]), i));
        	if(p.size() >= k){
        		p.pop();
        	}
        }
        vector<vector <int> > ans;
        while(!p.empty){
        	ans.push_back(p.top().second());
        	p.pop();
        }
        return ans;
    }
};