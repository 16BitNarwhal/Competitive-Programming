#include <iostream>
#include <vector>

using namespace std;

struct s {
  int a;
  int d;
};

void merge(vector<s>& arr, int left, int right)
{
  int mid = (left + right) / 2;
  int lsize = mid - left + 1, rsize = right - mid;
  int pos = left;
  vector<s> leftarr(lsize);
  vector<s> rightarr(rsize);
  for (int i = 0; i < lsize; i++)
    leftarr[i] = arr[left+i];
  for (int i = 0; i < rsize; i++)
    rightarr[i] = arr[mid+1+i];
  int i = 0, j = 0; 
  while (i < lsize && j < rsize)
  {
    if (leftarr[i].d <= rightarr[j].d) 
      arr[pos++] = leftarr[i++];      
    else 
      arr[pos++] = rightarr[j++];      
    }
  while (i < lsize)
    arr[pos++] = leftarr[i++];
  while (j < rsize)
    arr[pos++] = rightarr[j++];
}
void mergeSort(vector<s>& arr, int left, int right)
{
  if (left == right)    
    return;
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, right);
}

int main() {
  int N, A, B, C;
  cin >> N;
  vector<s> stuf(N);
  for(int i=0; i<N; i++) {
    int b, c;
    cin >> stuf[i].a >> b >> c;
    stuf[i].d = b+c;
  }

  mergeSort(stuf, 0, N-1);

  int max = 0;
  int cobol=0;
  for(int i=N-1; i>=0; i--) {
    cobol += stuf[i].a;
    if(cobol + stuf[i].d > max)
      max = cobol + stuf[i].d;
  }
  
  cout << max;

}

/*
3
18 7 6 
23 10 27
20 9 14
*/