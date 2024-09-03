#include <iostream>
#include <vector>
#include <algorithm>
// Function to perform insertion sort on a bucket
void insertionSort(std::vector<double>& bucket) {
    for (size_t i = 1; i < bucket.size(); i++) {
        double key = bucket[i];
        size_t j = i;
        while (j > 0 && bucket[j - 1] > key) {
            bucket[j] = bucket[j - 1];
            j--;
        }
        bucket[j] = key;
    }
}
// Main function to implement bucket sort
void bucketSort(std::vector<double>& arr) {
    if (arr.empty()) return;
    // Find the maximum and minimum values
    double max = *std::max_element(arr.begin(), arr.end());
    double min = *std::min_element(arr.begin(), arr.end());
    // Number of buckets
    int bucketCount = static_cast<int>((max - min) / arr.size()) + 1;
    std::vector<std::vector<double>> buckets(bucketCount);
    // Distribute input array values into buckets
    for (double num : arr) {
        int index = static_cast<int>((num - min) / (max - min) * (bucketCount - 1));
        buckets[index].push_back(num);
    }
    // Sort each bucket and put back into the array
    size_t idx = 0;
    for (auto& bucket : buckets) {
        insertionSort(bucket);
        for (double num : bucket) {
            arr[idx++] = num;
        }
    }
}
int main() {
    std::vector<double> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12};
    bucketSort(arr);
    std::cout << "Sorted array: ";
    for (double i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}