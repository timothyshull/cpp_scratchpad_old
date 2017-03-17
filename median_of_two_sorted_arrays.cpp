#include <vector>
#include <iostream>

//class Solution {
//public:
//    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
//    {
//        if (nums1.empty() && nums2.empty()) { throw std::exception{}; }
//        std::vector<int> aux;
//        aux.reserve(nums1.size() + nums2.size());
//
//        int i{0};
//        int j{0};
//        while (true) {
//            if (i < nums1.size() && j < nums2.size()) {
//                if (nums1[i] < nums2[j]) { aux.push_back(nums1[i++]); }
//                else if (nums2[j] < nums1[i]) {
//                    aux.emplace_back(nums2[j++]);
//                } else {
//                    aux.push_back(nums1[i++]);
//                    aux.push_back(nums2[j++]);
//                }
//            } else if (i < nums1.size()) {
//                aux.push_back(nums1[i++]);
//            } else if (j < nums2.size()) {
//                aux.push_back(nums2[j++]);
//            } else {
//                break;
//            }
//        }
//
//        if (aux.size() == 1) {
//            return aux[0];
//        } else if (aux.size() % 2 == 0) {
//            return (aux[aux.size() / 2] + aux[(aux.size() / 2) - 1]) / 2.0;
//        } else { return aux[aux.size() / 2]; }
//    }
//};

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        auto total_size = nums1.size() + nums2.size();
        auto median_idx = total_size / 2;
        if (nums1[nums1.size() - 1] < nums2[0] || nums2[nums2.size() - 1] < nums1[0]) {
            auto& lower = nums1[nums1.size() - 1] < nums2[0] ? nums1 : nums2;
            auto& upper = nums1[nums1.size() - 1] < nums2[0] ? nums2 : nums1;
            if ((total_size / 2) < lower.size()) { return total_size % 2 ? lower[total_size / 2] : (lower[total_size / 2] + lower[(total_size / 2) - 1]) / 2.0; }
            else if ((total_size / 2) > lower.size()) { return total_size % 2 ? upper[(total_size / 2) - lower.size()] : (lower[total_size / 2] + lower[(total_size / 2) - 1]) / 2.0; }
        } else {
            int l1{0};
            int r1 = nums1.size() - 1;
            int l2{0};
            int r2 = nums2.size() - 1;
            int m1;
            int m2;

            while (true) {
                m1 = (l1 + r1) / 2;
                m2 = (l2 + r2) / 2;
            }

        }
    }
};

int main()
{
    std::vector<int> t11{1, 3};
    std::vector<int> t12{2};
    std::cout << Solution{}.findMedianSortedArrays(t11, t12) << "\n";

    std::vector<int> t21{1, 2};
    std::vector<int> t22{3, 4};
    std::cout << Solution{}.findMedianSortedArrays(t21, t22) << "\n";
    return 0;
}

// should be log(m + n)