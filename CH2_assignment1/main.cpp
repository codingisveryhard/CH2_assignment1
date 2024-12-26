#include <iostream>
using namespace std;

void input(int arr[], int size);					 // input 함수 선언
int ADD(int arr[], int size);						 // ADD 함수 선언
double AVG(int add, int size);					     // AVG 함수 선언
int ASCsort(int arr[], int size);					 // ASCsort 함수 선언
int DESCsort(int* arr, int size);					 // DESCsort 함수 선언 (포인터 사용)

int main() {
	const int size = 5;  // 입력받을 숫자의 갯수를 상수로 선언
	int arr[size];       // 크기가 5인 배열 arr 선언
	int sort;			 // 오름차순, 내림차순 선택 변수

	input(arr, size);    // input 함수 호출

	while (1) { 	     // 오름차순, 내림차순 선택 반복문
		cout << "오름차순 정렬을 원하면 1, 내림차순 정렬을 원하면 2을 입력하세요: ";
		cin >> sort;
		if (sort == 1) {                            // 오름차순 선택시 ASCsort 함수 호출
			ASCsort(arr, size);
			break; 								    // 정렬을 마치면 반복문에서 나간다
		}
		else if (sort == 2) {                       // 내림차순 선택시 DESCsort 함수 호출
			DESCsort(arr, size);
			break; 								    // 정렬을 마치면 반복문에서 나간다
		}
		else cout << "잘못된 입력입니다." << endl;  // 1, 2 이외의 숫자 입력시 재입력 요구
	}

	int add = ADD(arr, size);       // 배열의 합을 add 변수에 저장
	double avg = AVG(add, size);    // 배열의 평균을 avg 변수에 저장

	cout << "배열의 총합 : " << add << endl; // 배열의 총합을 출력
	cout << "배열의 평균 : " << avg << endl; // 배열의 평균을 출력
	return 0;
}

void input(int arr[], int size) {                            // 배열에 들어갈 숫자를 입력받는 함수
	cout << "총 " << size << "개의 숫자를 입력하세요." << endl;
	for (int i = 0; i < size; i++)                           // size만큼 반복
	{
		cout << i + 1 << "번째 숫자를 입력하세요: ";
		cin >> arr[i];									     // 배열에 숫자 입력
		cout << arr[i] << "가 입력되었습니다." << endl;
	}
	cout << endl << "입력된 배열 : ";
	for (int i = 0; i < size; i++) cout << arr[i] << " ";   // 입력된 배열 출력
	cout << endl << endl;
}

int ASCsort(int arr[], int size) {                          // 오름차순 정렬 함수
	int temp; 											    // 정렬을 위한 임시 저장용 변수
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {					    // 앞의 숫자가 뒤의 숫자보다 크면 실행
				temp = arr[j + 1];						    // 뒤의 숫자를 temp에 보관하고
				arr[j + 1] = arr[j];					    // 뒤의 숫자에 앞의 숫자 저장
				arr[j] = temp;							    // 앞의 숫자에 보관된 temp 저장
			}
		}
	}
	cout << endl << "오름차순으로 정렬된 배열: ";
	for (int i = 0; i < size; i++) cout << arr[i] << " ";   // 오름차순으로 정렬된 배열 출력
	cout << endl << endl;
	return arr[5];
}

int DESCsort(int* arr, int size) {						  // 내림차순 정렬 함수 (포인터 사용)
	int temp;											  // 정렬을 위한 임시 저장용 변수
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {				 	  // 앞의 숫자가 뒤의 숫자보다 작으면 실행
				temp = arr[j]; 						      // 앞의 숫자를 temp에 보관하고
				arr[j] = arr[j + 1];					  // 앞의 숫자에 뒤의 숫자 저장
				arr[j + 1] = temp; 					      // 뒤의 숫자에 보관된 temp 저장
			}
		}
	}
	cout << endl << "내림차순으로 정렬된 배열: ";
	for (int i = 0; i < size; i++) cout << arr[i] << " "; // 내림차순으로 정렬된 배열 출력
	cout << endl << endl;
	return arr[5];
}

int ADD(int arr[], int size) {                       // 배열의 합을 구하는 함수
	int add = 0; 									 // 합을 저장할 변수 add 선언
	for (int i = 0; i < size; i++) add += arr[i];    // 배열의 모든 요소를 더함
	return add; 									 // 합을 반환
}

double AVG(int add, int size) {       // 배열의 평균을 구하는 함수
	double avg = (double)add / size;  // 배열의 합을 배열의 크기로 나누어 평균을 구함
	return avg; 				      // 평균을 반환
}

