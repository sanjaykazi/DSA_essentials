#include <bits/stdc++.h>
using namespace std;
// naive method with time complexity O(1 + 2(n-2)) = O(2n - 1)
pair<int, int> minMax(int arr[], int n)
{
  //if there is only one element in the array
  pair<int, int> p;
  if (n == 1)
  {
    p.first = arr[0];
    p.second = arr[0];
  }
  // if array contains two elements
  if (arr[0] > arr[1])
  {
    p.first = arr[1];
    p.second = arr[0];
  }
  else
  {
    p.first = arr[0];
    p.second = arr[1];
  }
  for (int i = 2; i < n; i++)
  {
    if (arr[i] < p.first)
    {
      p.first = arr[i];
    }
    else if (arr[i] > p.second)
    {
      p.second = arr[i];
    }
  }
  return p;
}
//better method
pair<int, int> getMinMax(int arr[], int low, int high)
{
  pair<int, int> minmax;
  pair<int, int> mmr;
  pair<int, int> mml;
  int mid;

  // If there is only one element
  if (low == high)
  {
    minmax.second = arr[low];
    minmax.first = arr[low];
    return minmax;
  }

  // If there are two elements
  if (high == low + 1)
  {
    if (arr[low] > arr[high])
    {
      minmax.second = arr[low];
      minmax.first = arr[high];
    }
    else
    {
      minmax.second = arr[high];
      minmax.first = arr[low];
    }
    return minmax;
  }

  // If there are more than 2 elements
  mid = (low + high) / 2;
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid + 1, high);

  // Compare minimums of two parts
  if (mml.first < mmr.first)
    minmax.first = mml.first;
  else
    minmax.first = mmr.first;

  // Compare maximums of two parts
  if (mml.second > mmr.second)
    minmax.second = mml.second;
  else
    minmax.second = mmr.second;

  return minmax;
  // pair<int,int> ans;
  // pair<int,int> left;
  // pair<int,int> right;
  // if(low == high){
  //   ans.first = arr[low];
  //   ans.second = arr[low];
  //   return ans;
  // }
  // if(high = low + 1){
  //   if(arr[low] < arr[high]){
  //     ans.first = arr[low];
  //     ans.second = arr[high];
  //   }else if(arr[low+1] < arr[low]){
  //     ans.first = arr[high];
  //     ans.second = arr[low];
  //   }
  //   return ans;
  // }
  // int mid = (high + low)/2;
  // // recursion time
  // left = getMinMax(arr,low,mid);
  // right = getMinMax(arr,mid+1,high);

  // if(left.first < right.first){
  //   ans.first = left.first;
  // }else{
  //   ans.first = right.first;
  // }

  // if(left.second > right.second){
  //   ans.second =left.second;
  // }else{
  //   ans.second = right.second;
  // }

  // return ans;
}

pair<int, int> getMaxMin(int arr[], int n)
{
  pair<int, int> p;
  int i;
  // if n is even
  p.first = arr[0];
  p.second = arr[0];
  if (n % 2 == 0)
  {
    if (arr[0] < arr[1])
    {
      p.first = arr[0];
      p.second = arr[1];
    }
    else
    {
      p.first = arr[1];
      p.second = arr[0];
      
    }
    i = 2;
  }
  //setting the starting index for the loop
  
  else
  {
    p.first = arr[0];
    p.second = arr[0];

    //setting the starting index for the loop
    i = 1;
  }
  while (i < n - 1)
  {
    if (arr[i] > arr[i + 1])
    {
      if (arr[i] > p.second)
        p.second = arr[i];

      if (arr[i + 1] < p.first)
        p.first = arr[i + 1];
    }
    else
    {
      if (arr[i + 1] > p.second)
        p.second = arr[i + 1];

      if (arr[i] < p.first)
        p.first = arr[i];
    }

    // Increment the index by 2 as
    // two elements are processed in loop
    i += 2;
  }
  return p;
}
//if n is odd

int main()
{
  int arr[] = {1, 2, 6, 3, 5, 7, 5, 4, 7, 8, 7, 6, 5, 4, 45, 6, 788, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  pair<int, int> p;
  p = getMaxMin(arr,n);
  cout << "Min: " << p.first << " Max: " << p.second << endl;
  return 0;
}