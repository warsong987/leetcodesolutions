#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    returnSize[0] = 2;
    int* output = (int*)malloc(sizeof(int) * 2);
    for(int offset = 1; offset < numsSize; offset++)
    {
        int i = 0;
        while(i + offset < numsSize)
        {
            if(nums[i] + nums[i + offset]==target)
            {
                output[0] = i;
                output[1] = i + offset;
                return output;
            }
            i++;
        }
      
    }

    free(output);

    return (void *) 0;
}


int main(int argc, char const *argv[])
{
    int nums1[4] = {2,7,11,15};
    int nums1Size = 4;
    int target = 9;
    int returnSize;

    int *result1;

    result1 = twoSum(nums1, nums1Size, target, &returnSize);

    printf("[");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%i", result1[i]);
    }
    printf("]\n");


    int nums2[3] = {3,2,4};
    int nums2Size = 3;
    target = 6;

    int *result2;

    result2 = twoSum(nums2, nums2Size, target, &returnSize);

    printf("[");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%i", result2[i]);
    }
    printf("]\n");


    int nums3[2] = {3,3};
    int nums3Size = 2;
    target = 6;

    int *result3;

    result3 = twoSum(nums3, nums3Size, target, &returnSize);

    printf("[");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%i", result3[i]);
    }
    printf("]\n");

    return 0;
}
