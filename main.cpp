//radix sort 
#include <iostream>
#include <vector>
#include <algorithm>
// Function to get the maximum value in the array
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}
// Function to perform counting sort based on a specific digit
void countingSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size()); // Output array
    std::vector<int> count(10, 0); // Counting array
    // Store count of occurrences of (digit/exp) % 10
    for (int i : arr) {
        count[(i / exp) % 10]++;
    }
    // Change count[i] so that count[i] contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
  // Copy the output array to arr[] so that arr[] contains sorted numbers
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}
// Main function to implement radix sort
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to figure out the number of digits
    int max = getMax(arr);

    // Apply counting sort to sort elements based on place value
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}