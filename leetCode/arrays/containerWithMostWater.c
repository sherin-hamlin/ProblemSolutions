/*
Problem: Container With Most Water

Approach Used:
Two Pointer Technique.
Start with one pointer at the beginning and one at the end.
Calculate area using:
    height = minimum of two heights
    width = distance between pointers
Move the pointer pointing to the smaller height inward
to try maximizing area.

Time Complexity:
O(n)
Each element is visited at most once.

Space Complexity:
O(1)
Only constant extra variables are used.
*/

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = h * width;

        if (area > max)
            max = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max;
}