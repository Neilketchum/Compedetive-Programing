#include<iostream>
#include<algorithm>
using namespace std;

int temp[1000];

void sumItUp(int arr[], int n, int indArr, int sum, int target, int indTemp) {

	if(sum > target) {
		return;
	}

	if(sum == target) {
		for(int i = 0; i < indTemp; i++) {
			cout << temp[i] << " ";
		}
		cout << endl;
		return;
	}

	if(indArr >= n) {
		return;
	}

	int fre = 0;
	for(int i = indArr; i < n; i++) {
		if(arr[i] == arr[indArr]) fre++;
	}

	for(int i = fre; i >= 0; i--) {
		for(int k = 0; k < i; k++) {
			temp[indTemp + k] = arr[indArr];
		}
		sumItUp(arr, n, indArr + fre, sum + arr[indArr]*i, target, indTemp + i);
	}
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int target;
	cin >> target;

	sumItUp(arr, n, 0, 0, target, 0);
}