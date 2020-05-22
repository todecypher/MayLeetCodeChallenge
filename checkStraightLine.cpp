class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n==1) return 1;
        //make a line
        int start_x , start_y ;
        int end_x , end_y;
        
        start_x = coordinates[0][0];
        start_y = coordinates[0][1];

        end_x = coordinates[n-1][0];
        end_y = coordinates[n-1][1];    
        
        auto f = [&](int x , int y){
           return ( (end_x - start_x)*(end_y -y)  ==   (end_y - start_y)*(end_x -x) ); 
         };
        
        for(int i =1; i<n-1;i++){
            if(!f(coordinates[i][0] , coordinates[i][1])) return 0;
        }
        return 1;
        
    }
};