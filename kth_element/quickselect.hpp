#ifndef _QUICK_
#define _QUICK_
#include <random>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <stdio.h>


int randint(int l, int r) {
	static std::mt19937_64 gen(std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<int>(l, r)(gen);
}



int partition(int *arr, int l, int r, int pos){
  int pivot=arr[pos];
  std::swap(arr[pos],arr[r-1]);
    int i=l-1;
    while(l<r){
      if(arr[l]<pivot){
        i++;
        std::swap(arr[i],arr[l]);
      }
      l++;
    }
    i++;
    std::swap(arr[i],arr[r-1]);
    return i;
}


int quickselect(int* arr, int n, int k){
    int l=0,r=n;
    while(r-l>1){
      int* medians=new int[3];
      for(int i=0;i<3;i++){
				medians[i]=randint(l,r-1);
			}
			auto cmp=[&](int a, int b){
				return arr[a]<arr[b];
			};
			std::sort(medians,medians+3,cmp);
      int pivot=partition(arr, l,r,medians[1]);
			if(pivot==k)l=k,r=k;
      else if(pivot<k){
        l=pivot+1;
      }else r=pivot;
      delete [] medians;
    }

    return arr[l];

}
#endif /* _QUICK_ */
