class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size();
  	
  	// We can take [0...n] number of elements from a[]
  	int low = 0, high = n;
  
  	while(low <= high) {
    	
      	// Take mid1 elements from a
      	int mid1 = (low + high) / 2;
      	
      	// Take mid2 elements from b
      	int mid2 = n - mid1;
      
      	// Find elements to the left and right of partition in a
      	int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
      	int r1 = (mid1 == n ? INT_MAX : a[mid1]);
      
      	// Find elements to the left and right of partition in b
      	int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
      	int r2 = (mid2 == n ? INT_MAX : b[mid2]);
      
      	// If it is a valid partition
      	if(l1 <= r2 && l2 <= r1) 
        	return (max(l1, l2) + min(r1, r2)) / 2.0;
      	
      	// If we need to take lesser elements from a
      	if(l1 > r2) 
          	high = mid1 - 1;
      
      	// If we need to take more elements from a
      	else 
          	low = mid1 + 1;
    }
  	return 0;
        // Your code goes here
    }
};