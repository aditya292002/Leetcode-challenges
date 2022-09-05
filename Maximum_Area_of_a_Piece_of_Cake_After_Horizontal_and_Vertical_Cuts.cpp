class Solution {
public:

	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		horizontalCuts.push_back(0);
		horizontalCuts.push_back(h);
		sort(horizontalCuts.begin(), horizontalCuts.end());
		
		verticalCuts.push_back(0);
		verticalCuts.push_back(w);
		sort(verticalCuts.begin(), verticalCuts.end());

		long length = 0;
		for(int i = 1; i < horizontalCuts.size();i++){
			if(length < horizontalCuts[i] - horizontalCuts[i-1]){
				length = horizontalCuts[i] - horizontalCuts[i-1];
			}
		}
		
		long breadth = 0;
		for(int i = 1;i < verticalCuts.size(); i++){
			if(breadth < verticalCuts[i] - verticalCuts[i-1]){
				breadth = verticalCuts[i] - verticalCuts[i-1];
			}
		}
		return (length*breadth)%(1000000007);
	}
};