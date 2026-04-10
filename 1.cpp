//Pattern -> Array and Hashing


//Description :You are given an array of integers arr[].
// You have to reverse the given array.


// Approach :


// Approach 1: Using a Duplicate Array

// * Method: Create a new array and fill it by traversing the original array from back to front.
// * T.C: O(n)
// * S.C: O(n)

// ---

// Approach 2: Two Pointers

// * Steps:
// 1. Set pointer i at start and j at end.
// 2. Swap values at i and j.
// 3. i++, j--.
// 4. Repeat until the pointers meet.

// * T.C: O(n)
// * S.C: O(1) 

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i = n-1,j=0;
        while(i>j)
        {
            swap(arr[i--],arr[j++]);
            
        }     
    }
};