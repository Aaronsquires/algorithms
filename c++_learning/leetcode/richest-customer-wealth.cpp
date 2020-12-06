#include<iostream>  
#include <vector>
//needed for accumulate
#include <numeric>


using namespace std;

class Solution {
    public:
        int maximumWealth(vector<vector<int>>& accounts) {
            //Set Variables
            int maxWealth = 0;
            int curWealth = 0;
            
            //For the vector [[1,5],[7,3],[3,5]]
            for (vector<int>& customer : accounts) {
                //Accumalte takes in the length of the vector from first to last
                //as the range of elements to sum together "add"
                curWealth = accumulate(customer.begin(), customer.end(), 0);
                // compares the new heighest version of maxwealth 
                // max compares variables a, b
                // in this case maxWealth and curWealth
                maxWealth = max(maxWealth, curWealth);
            }
            
            //return the heighest wealth
            return maxWealth;
        }
};