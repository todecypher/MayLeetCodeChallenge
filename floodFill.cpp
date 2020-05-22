class Solution {
public:
    int vis[52][52];
    void color(int i , int j , int srcColor , int newColor , vector<vector<int>>&image,int n ,int m){
        if( i<0 || j<0 || i>=n || j>=m  || image[i][j] !=srcColor) return ;
        
        image[i][j] = newColor;
        
        
        color(i+1 ,j,srcColor , newColor , image,n,m);
        color(i-1 ,j,srcColor , newColor , image,n,m);
        color(i , j+1,srcColor , newColor , image,n,m);
        color(i , j-1,srcColor , newColor , image,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        if(image[sr][sc] == newColor) return image;
         int m = image[0].size();
         memset(vis , 0 , sizeof vis);
         color(sr ,sc , image[sr][sc] , newColor , image ,n, m);
        return image;
    }
};