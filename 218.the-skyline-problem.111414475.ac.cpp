class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> borders;
        //two method to get sorted borders
        //1: push all buildings' left and right border into borders and sort the border (nlogn) 
        //2: two pointer (front border and back border) (n)
        for(auto b : buildings) {
            borders.push_back(make_pair(b[0], b[2]));
            borders.push_back(make_pair(b[1], -b[2]));
        }
        vector<pair<int, int>> skyline;
        sort(borders.begin(), borders.end());
        //heightMap:  key: height, value: number of building with this height
        map<int, int> heightMap;
        for(auto b : borders) {
            if(b.second > 0) {
                //front border
                if(heightMap.empty() || b.second > heightMap.rbegin()->first) {
                    if(skyline.empty() || b.first > skyline.back().first) {
                        skyline.push_back(b);
                    } else {
                        skyline.back().second = max(skyline.back().second, b.second);
                        if(skyline.size() >= 2 && skyline.back().second == skyline[skyline.size()-2].second) {
                            skyline.pop_back();
                        }
                    }
                }
                heightMap[b.second]++;
            } else {
                //back border
                int h = -b.second;
                if(h == heightMap.rbegin()->first && heightMap[h] == 1) {
                    heightMap.erase(h);
                    int highest = heightMap.empty() ? 0 : heightMap.rbegin()->first;
                    if(skyline.back().first == b.first) {
                        skyline.back().second = min(skyline.back().second, highest);
                    } else {
                        skyline.push_back(make_pair(b.first, highest));
                    }
                } else {
                    if(--heightMap[h] == 0) {
                        heightMap.erase(h);
                    }
                }
            }
        }
        return skyline;
    }
};