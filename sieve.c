//
// Created by bouch on 30/08/15.
//

//theoretical max of n on 64bit systems = 18446744073709551615

unsigned long prime_sum(unsigned long n)
{
    char *nums;
    nums = malloc(n * sizeof(char));
    memset(nums, 0, sizeof(nums));
    for (unsigned long i = 3; i < n; i+=2)
    {
        nums[i] = 1;
    }
    nums[2] = 1;

    for (unsigned long i = 3; i*i < n; i+=2)
    {
        if (nums[i])
        {
            for (unsigned long j = i*i; j < n; j+=i)
            {
                nums[j] = 0;
            }
        }
    }

    unsigned long sum = 2;

    for (unsigned long i = 3; i < n; i+=2)
    {
        if (nums[i])
        {
            sum += i;
        }
    }
    free(nums);

    return sum;
}