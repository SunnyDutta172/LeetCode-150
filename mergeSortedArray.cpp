//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;          // last valid element in nums1
        int j = n - 1;          // last element in nums2
        int index = m + n - 1;  // last position of nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] <= nums2[j]) {
                nums1[index--] = nums2[j--];
            } else {
                nums1[index--] = nums1[i--];
            }
        }

        // Copy remaining elements of nums2 (if any)
        while (j >= 0) {
            nums1[index--] = nums2[j--];
        }
    }
};

int main() {
    int m, n;
    cout << "Enter number of elements in nums1 (m): ";
    cin >> m;

    cout << "Enter number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter " << m << " sorted elements of nums1:\n";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter " << n << " sorted elements of nums2:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged array:\n";
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}
