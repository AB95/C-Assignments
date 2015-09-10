//
// Created by bouch on 28/08/15.
//

struct array{
    int* list;
    int len;
};

void print_array(int* list, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void bubble_sort(struct array thanger)
{
    int* list = thanger.list;
    int len = thanger.len;
    for (int i = 0; i < len; i++)
    {
        while (i != 0 && list[i] < list[i-1])
        {
            int temp = list[i-1];
            list[i-1] = list[i];
            list[i] = temp;
            i--;
        }
    }
}

void selection_sort(struct array thanger)
{
    int* list = thanger.list;
    int len = thanger.len;
    for (int i = 0; i < len; i++)
    {
        int lowest = list[i];
        int lowest_index = i;
        for (int j = i+1; j < len; j++)
        {
            if (list[j] < lowest)
            {
                lowest = list[j];
                lowest_index = j;
            }
        }
        if (lowest < list[i])
        {
            int temp = list[i];
            list[i] = lowest;
            list[lowest_index] = temp;
        }
    }
}

void merge(int list[], int low, int mid, int high)
{
    int low_count = low;
    int high_count = mid+1;
    int temp_index = 0;
    int temp_list[high-low];
    while (low_count <= mid & high_count <= high)
    {
        if (list[low_count] <= list[high_count])
        {
            temp_list[temp_index++] = list[low_count++];
        }
        else
        {
            temp_list[temp_index++] = list[high_count++];
        }
    }
    while (low_count <= mid)
    {
        temp_list[temp_index++] = list[low_count++];
    }
    while (high_count <= high)
    {
        temp_list[temp_index++] = list[high_count++];
    }
    temp_index--;
    while (temp_index >= 0)
    {
        list[low + temp_index] = temp_list[temp_index--];
    }
}

void _merge_sort(int list[], int low, int high)
{
    if (low < high)
    {
        int mid = (high+low)/2;
        _merge_sort(list, low, mid);
        _merge_sort(list, mid+1, high);
        merge(list, low, mid, high);
    }
}

void merge_sort(struct array thanger)
{
    _merge_sort(thanger.list, 0, thanger.len);
}