#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <math.h>

// compile with -fconcepts and you
// can make the std::vector<int>
// into std::vector<auto>
void print_vector(std::vector<int> a){
  for(auto item:a){
    std::cout << item << ", ";
  }
  std::cout << "\n";
}


int index_of(int item, int data[], int len){
  for (int i = 0; i < len; i++){
    if (data[i] == item)
      return i;
  }

  return -1;
}


  int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,tmp;
  int len = a.size();

  for (i=0;i<len;i++){
    min_index = find_min_index(a,i,len);

    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }
  return a;
}

/*
  left and right are already sorted low to high
  create a new std::vector named merged
  and fill it with all the elements of left and right.
  When done, merged should be in order low to high.
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;
  int l=0,r=0; // indices into left and right;

  while (l < left.size() && r< right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
     
  return merged;
}

std::vector<int> msort(std::vector<int> data){

  std::vector<int> result;
  
  if (data.size() <= 1){
    return data;
  }
  
  std::vector<int> a,b;
  int i;
  int mid = data.size()/2;
  for (i=0;i<mid;i++){
    a.push_back(data[i]);
  }
  
  for (;i<data.size();i++){
    b.push_back(data[i]);
  }

  a = msort(a);
  b = msort(b);

  result= merge(a,b);
  
  return result;
}

std::vector<int> qsort(std::vector<int> list){
  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select pivot value
  // for now we'll just pick list[0]
  int pivot = list[0];

  // make 2 new vectors
  std::vector<int> lower,higher;
  
  // copy all the values < pivot to lower
  // copy all the values >= pivot to higher;
  for (i=1;i<list.size();i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  // make our recursive calls
  lower = qsort(lower);
  higher = qsort(higher);

  // copy everything back
  for (i=0; i < lower.size(); i++){
    list[i] = lower[i];
  }
  list[i] = pivot;
  i++;
  for (j=0;j<higher.size(); j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list
  return list;
}

void swap(std::vector<int> &v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int median(std::vector<int>& v, int low, int high)
{
    int middle = (low + high)/2;
    if((v[low] < v[middle] && v[middle] < v[high]) || (v[high] < v[middle] && v[middle] < v[low])){
        return middle;
    } else if((v[middle] < v[low] && v[low] < v[high]) || (v[high] < v[low] && v[low] < v[middle])){
        return low;
    } else{
        return high;
    }
}

void qsort2(std::vector<int>& v, int low, int high) {
    if(low >= high || high - low < 1 || high > v.size()){
      return;
    }
    int pivotIndex = median(v, low, high);
    int pivotValue = v[pivotIndex];
    swap(v, pivotIndex, high);
    pivotIndex = low;
    for(int i = low; i < high; i++)
    {
      if(v[i] < pivotValue)
      {
        swap(v, pivotIndex, i);
        pivotIndex++;
      }
    }
    swap(v, pivotIndex, high);    
    qsort2(v, low, pivotIndex - 1);
    qsort2(v, pivotIndex + 1, high);
    }


void print(std::vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
