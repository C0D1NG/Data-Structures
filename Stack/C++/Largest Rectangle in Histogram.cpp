class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        stack<int>s;
        if(n==1)
        {
            return heights[0];
        }
        //lb (smallest boundary on the left side)
        vector<int>lb(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                lb[i]=-1;
                s.push(i);
            }
            else
            {
                lb[i]=s.top();
                s.push(i);
            }
        }
        while (!s.empty()) s.pop();
        vector<int>rb(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                rb[i]=n;
                s.push(i);
            }
            else
            {
                rb[i]=s.top();
                s.push(i);
            }
        }
        int area=0;
        
        for(int i=0;i<n;i++)
        {
            area=max(area,heights[i]*(rb[i]-lb[i]-1));
        }
        return area;
    }
};
