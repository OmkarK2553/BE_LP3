#include<iostream>

using namespace std;

int partition(int * arr, int p, int r){
	int x = arr[r];
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(arr[j] <= x){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void quickSort(int * arr, int p, int r){
	if (p < r){
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

//Randomized
int randomPartition(int * arr, int p, int r){
	// int x = arr[r];
	int ri =  p + rand() % (r - p + 1);
	// cout<<i<<endl;
     int pivot = arr[ri];
    int i = p-1;
    swap(arr[ri], arr[r]);
	for(int j = p; j < r; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}
void randomizedQuickSort(int * arr, int p, int r){
	if (p < r){
		int q = randomPartition(arr, p, r);
		randomizedQuickSort(arr, p, q - 1);
		randomizedQuickSort(arr, q + 1, r);
	}
}

int main(){
	int A[] = {9,2,5,4,3};
	int n = sizeof(A)/ sizeof(A[0]);
	quickSort(A, 0, n - 1);
	for(int i : A){
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}