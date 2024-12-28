class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> result;
        
        for (auto num1: nums1){
            bool found = false;
            for (auto num2: nums2){
                if (num1 == num2){found = true; break;}
            } // end-for

            if (!found){
                for (auto num3: nums3){
                    if (num1 == num3){found = true; break;}
                } // end-for                
            } // end-if         
        
            if (found){
                // Add to the result
                found = false;
                for (auto num: result){
                    if (num1 == num){found = true; break;}
                } // end-for
                
                if (!found) result.push_back(num1);
            } // end-if            
        } // end-for

        for (auto num2: nums2){
            bool found = false;
            for (auto num3: nums3){
                if (num2 == num3){found = true; break;}
            } // end-for                
            
            if (found){
                // Add to the result
                found = false;
                for (auto num: result){
                    if (num2 == num){found = true; break;}
                } // end-for
                
                if (!found) result.push_back(num2);
            } // end-if            
        } // end-for
        
        return result;                
    } // end-twoOutOfThree
};