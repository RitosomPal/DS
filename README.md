# Data Structure

## SORTING

### Selection Sort
```cpp
void SelectionSort(int *arr, int len) {
	int i,j,t,min;
	for (i=0; i<len-1; i++) {
		min = i;
		for (j=i+1; j<len; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		t = arr[i];
		arr[i] = arr[min];
		arr[min] = t;
	}
}
```

### Bubble Sort
```cpp
void BubbleSort(int *arr, int len) {
	int i,j,t,f;
	for (i=0; i<len-1; i++) {
		f = 1;
		for (j=0; j<len-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				f  = 0;
			}
		}
		if (f) break;
	}
}
```

### Insertion Sort
```cpp
void InsertionSort(int *arr, int len) {
	int i,j,key;
	for (i=1; i<len; i++) {
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			arr[j] = key;
			j--;
		}
	}
}
```

### Merge Sort
```cpp
void Merge(int *arr, int *l, int *r, int nl, int nr) {
	int i, j, k;
	
	i = j = k = 0;
	
	while(i < nl && j < nr) {
		if (l[i] <= r[j]) {
			arr[k] = l[i];
			k++;
			i++;
		} else {
			arr[k] = r[j];
			j++;
			k++;
		}
	}
	while(i < nl) {
		arr[k] = l[i];
		i++;
		k++;
	}
	while(j < nr) {
		arr[k] = r[j];
		j++;
		k++;
	}
}

void MergeSort(int *arr, int len) {
	if (len < 2) {
		return;
	}
	int mid = len / 2;
	int left[mid], right[len - mid], i;
	
	for (i = 0; i < mid; i++) {
		left[i] = arr[i];
	}
	for (i = mid; i < len; i++) {
		right[i-mid] = arr[i];
	}
	
	MergeSort(left, mid);
	MergeSort(right, len - mid);
	
	Merge(arr, left, right, mid, len-mid);
}
```

### Quick Sort
```cpp
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
    
        if (arr[j] < pivot) 
        { 
        
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
    
        int pi = partition(arr, low, high); 
        
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
```

---

## SEARCHING

### Linear Search

```cpp
int LinearSearch(int *arr, int len, int key)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}
```

### Binary Search

```cpp
int BinarySearch(int *arr, int len, int key)
{
    int lo, hi, mid;

    lo = 0;
    hi = len - 1;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return -1;
}
```
---
