double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int *result = malloc(n * sizeof(int));
    if (result == NULL) return 0;

    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size)
        result[k++] = (nums1[i] <= nums2[j]) ? nums1[i++] : nums2[j++];
    while (i < nums1Size) result[k++] = nums1[i++];
    while (j < nums2Size) result[k++] = nums2[j++];

    double ans;
    if (n % 2 == 0)
        ans = (result[n/2 - 1] + result[n/2]) / 2.0;
    else
        ans = result[n/2];

    free(result);
    return ans;
}