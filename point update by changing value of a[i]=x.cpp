#include <bits/stdc++.h> 
using namespace std;  
int getMid(int s, int e) 
{ 
	return s + (e - s) / 2; 
} 
int MaxUtil(int* st, int ss, int se, int l, 
			int r, int node) 
{ 
	if (l <= ss && r >= se) 
		return st[node]; 
	if (se < l || ss > r) 
		return -1; 
	int mid = getMid(ss, se); 
	
	return max(MaxUtil(st, ss, mid, l, r, 
					2 * node + 1), 
			MaxUtil(st, mid + 1, se, l, 
					r, 2 * node + 2)); 
} 
void updateValue(int arr[], int* st, int ss, int se, 
				int index, int value, int node) 
{ 
	if (index < ss || index > se) 
	{ 
		cout << "Invalid Input" << endl; 
		return; 
	} 
	
	if (ss == se) 
	{ 
		arr[index] = value; 
		st[node] = value; 
	} 
	else { 
			int mid = getMid(ss, se); 

			if (index >= ss && index <= mid) 
				updateValue(arr, st, ss, mid, index, 
							value, 2 * node + 1); 
			else
				updateValue(arr, st, mid + 1, se, 
							index, value, 2 * node + 2); 
			
			st[node] = st[2 * node + 1]+
					st[2 * node + 2]; 
	} 
	return; 
} 

int constructSTUtil(int arr[], int ss, int se, 
					int* st, int si) 
{ 
	if (ss == se) 
	{ 
		st[si] = arr[ss]; 
		return arr[ss]; 
	} 
	int mid = getMid(ss, se); 
	
	 constructSTUtil(arr, ss, mid, st, 
								si * 2 + 1), 
				constructSTUtil(arr, mid + 1, se, 
								st, si * 2 + 2); 
	
	return st[si]=st[2*si+1]+st[2*si+2]; 
} 

int* constructST(int arr[], int n) 
{ 
	int x = (int)(ceil(log2(n))); 
	int max_size = 2 * (int)pow(2, x) - 1; 
	int* st = new int[max_size]; 
	constructSTUtil(arr, 0, n - 1, st, 0); 
	return st; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2 ,3 ,4 }; 
	int n = sizeof(arr) / sizeof(arr[0]),i; 
	int* st = constructST(arr, n); 
    for(i=0;i<7;i++)
    	cout<<st[i]<<" ";
    cout<<endl;
	updateValue(arr, st, 0, n - 1,2,-3, 0); 
       for(i=0;i<7;i++)
    	cout<<st[i]<<" ";
    cout<<endl;
	return 0; 
} 
