class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left, bottom, right, top;
        int area1, area2;
        
        // 先求两个矩形框各自的面积
        area1 = (C - A) * (D - B);
        area2 = (G - E) * (H - F);
        
        left = A > E ? A : E;
        bottom = B > F? B : F;
        
        right = C < G ? C : G;
        top = D < H ? D : H;
        
        // 无公共区域, 直接返回两个矩形的面积和
        if(left > right || bottom > top)
        {
            return area1 + area2;
        }
        
        // 有公共区域, 减去公共矩形的面积
        return area1 + area2 - (right - left) * (top - bottom);
    }
};
