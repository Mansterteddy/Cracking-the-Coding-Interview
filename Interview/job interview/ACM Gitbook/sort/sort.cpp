#include <iostream>

using namespace std;

void bubble_sort(int arr[], int left, int right)
{
	for(int i = left; i < right; i++)
	{
		for(int j = i; j < right; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void select_sort(int arr[], int left, int right)
{
	for(int i = left; i < right; ++i)
	{
		int min = i;
		for(int j = i+1; j <= right; ++j)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			swap(arr[i], arr[min]);
		}
	}
}

void insert_sort(int arr[], int left, int right)
{
	for(int i = left + 1; i <= right; ++i)
	{
		int tmp = arr[i];
		int j = i - 1;
		while(j >= left && arr[j] > tmp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = tmp;
	}
}

void quick_sort(int arr[], int left, int right)
{
	if(left >= right) return;
	int i = left, j = right;
	int tmp = arr[left];

	do
	{
		while(arr[j] > tmp && i < j)
		{
			j--;
		}
		if(i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while(arr[i] < tmp && i < j)
		{
			i++;
		}
		if(i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}while(i != j);

	arr[i] = tmp;
	quick_sort(arr, left, i-1);
	quick_sort(arr, i+1, right);
}

void Heap_just(int a[], int root, int heap_size)
{
	if(root < heap_size)
	{
		int Min = root;
		int l_son = root << 1 | 1;
		int r_son = (root << 1) + 2;
		if(l_son < heap_size && a[Min] > a[l_son]) Min = l_son;
		if(r_son < heap_size && a[Min] > a[r_son]) Min = r_son;

		if(Min == root) return;

		a[root] ^= a[Min];
		a[Min] ^= a[root];
		a[root] ^= a[Min];

		Heap_just(a, Min, heap_size);	
	}
}

void build_heap(int a[], int n)
{
	for(int i = n/2; i >= 0; i--)
	{
		Heap_just(a, i, n);
	}
}

void Heap_sort(int a[], int n)
{
	build_heap(a, n);
	for(int i = n - 1; i > 0; i--)
	{
		a[i] ^= a[0];
		a[0] ^= a[i];
		a[i] ^= a[0];
		Heap_just(a, 0, i);
	}
}

void arr_add(int arr[], int left, int mid, int right)
{
	if(left >= right) return;
	int i = left, j = mid + 1, k = 0;
	while(i <= mid && j <= right)
	{
		if(arr[i] <= arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
			cnt += (mid - i + 1);
		}
	}

	while(i <= mid)
	{
		tmp[k++] = arr[i++];
	}

	while(j <= right)
	{
		tmp[k++] =arr[j++];
	}

	for(i = 0; i < k; i++)
	{
		arr[i + left] = tmp[i];
	}
}

void merge_sort(int arr[], int left, int right)
{
	if(left >= right) return;
	int mid = (left + right) >> 1;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);
	arr_add(arr, left, mid, right);
}

void Binary_Insert_sort(int arr[], int first, int end)
{
	for(int i = first + 1; i <= end; i++)
	{
		int low = first, high = i - 1;
		while(low <= high)
		{
			int mid = (low + high) >> 1;
			if(arr[mid] > arr[i])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		int key = arr[i];
		for(int j = i; j > high + 1; j--)
		{
			arr[j] = arr[j-1];
		}

		arr[high+1] = key;
	}
}

void shell_sort(int arr[], int left, int right)
{
	int n = right - left;
	int gap = 1;
	while(gap <= n)
	{
		gap = gap << 1 | 1;
	}

	while(gap >= 1)
	{
		for(int i = left + gap; i <= right; i++)
		{
			int temp = arr[i];
			int j = i - gap;
			while(j >= left && arr[j] > temp)
			{
				arr[j+gap] = arr[j];
				j -= gap;
			}
			arr[j+gap] = temp;		
		}
		gap = (gap - 1) / 2;
	}
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void cocktail_sort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	bool isSwap = false;

	do
	{
		for(int k = i; k < j; k++)
		{
			if(arr[k] > arr[k+1])
			{
				swap(arr[k], arr[k+1]);
			}
		}
		isSwap = false;
		j--;
		for(int k = j; k > i; k--)
		{
			if(arr[k] < arr[k-1])
			{
				swap(arr[k], arr[k-1]);
				isSwap = true;
			}
		}
		i++;
	}while(i <= j && isSwap);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void count_sort(int arr[], int left, int right)
{
	int Max = 0;
	int cnt = right - left + 1;
	for(int i = left; i <= right; i++)
	{
		Max = max(Max, arr[i]);
	}
	int *count = new int[Max+1];
	int *tmp = new int[cnt+1];
	for(int i = left; i <= right; i++)
	{
		++count[arr[i]];
	}
	for(int i = 1; i <= Max; i++)
	{
		count[i] += count[i-1];
	}
	for(int i = right; i >= left; i--)
	{
		tmp[count[arr[i]]--] = arr[i];
	}
	memcpy(arr+left, tmp+1, (cnt) * sizeof(int));
	delete(count);
	delete(tmp);
}

