#include <iostream>
#include <vector>

using namespace std;

typedef struct Rect {
    vector<pair<int, int>> pos;
    int w;
    bool valid;
} Rect;

int absx(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC, N;
    
    scanf("%d", &TC);
    
    while (TC--) {
        scanf("%d", &N);

        vector<pair<int, int>> pos;
        vector<Rect> rects;
        int mini = 1e10, maxi = -1;     
        
        for (int i = 0; i < N; i++) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            pos.push_back({x, y});
        }
        
        for (int i = 0; i < N; i++) {
            for (auto& item : rects) {
                if (item.valid)
                    continue;
                
                int size = item.pos.size();               
                auto& base_front = item.pos[0];
                auto& base_back = item.pos[1];
                
                for (auto& ipos : item.pos) {
                    if (pos[i].first == ipos.first && pos[i].second == ipos.second) 
                        break;
                    
                    if (base_front.first == base_back.first) {
                        if (pos[i].second == ipos.second) {
                            int diff = absx(pos[i].first - ipos.first);                        
                            if (diff == item.w) {
                                item.pos.push_back({pos[i]});
                                break;
                            }
                        }
                    } else {
                        if (pos[i].first == ipos.first) {
                            int diff = absx(pos[i].second - ipos.second);                        
                            if (diff == item.w) {
                                item.pos.push_back({pos[i]});
                                break;
                            }
                        }
                    }            
                }     
                
                if (size == item.pos.size() || item.pos.size() < 4)
                    continue;             
                
                if (item.pos.size() == 4) {
                    auto& child_front = item.pos[2];
                    auto& child_back = item.pos[3];             

                    if (base_front.first == base_back.first) {
                        int diff = absx(child_front.second - child_back.second);
                        if (diff != item.w)
                            continue;
                    } else {
                        int diff = absx(child_front.first - child_back.first);
                        if (diff != item.w)
                            continue;
                    }
                }
                
                mini = min(mini, item.w);
                maxi = max(maxi, item.w);
                item.valid = true;
            }

            for (int j = i + 1; j < N; j++) {
                auto& front = pos[i];
                auto& back = pos[j];
                              
                if (front.first == back.first) {
                    int diff = absx(front.second - back.second);
                    
                    rects.push_back({{front, back}, diff});
                } else if (front.second == back.second) {
                    int diff = absx(front.first - back.first);
                    
                    rects.push_back({{front, back}, diff});
                }
            }
        }

        printf("%d %d\n", mini, maxi);
    }
}