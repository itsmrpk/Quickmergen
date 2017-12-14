#include <iostream>
using namespace std;
///quick sort part==========================
int part(int a[],int start,int last){
    int pivot=a[last];
    int pindex=start;
    for(int i=start;i<last;i++)
    {
        if(a[i]<=pivot){
            swap(a[i],a[pindex]);
            pindex++;}
    }
    swap(a[last],a[pindex]);

    return pindex;

}
void quicksort(int a[],int start ,int last){

    if(start<last){
     int pindex=part(a,start,last);
     quicksort(a,start,pindex-1);
     quicksort(a,pindex+1,last);
    }

}
///merge sort part====================================
void merg(int a[],int low,int mid,int high){

int c[10000];

int i,j,k;
i=low;
j=mid+1;
k=0;
while(i<=mid&&j<=high)
{
    if(a[i]<a[j])
        c[k++]=a[i++];
    else
        c[k++]=a[j++];
}
while(i<=mid)
    c[k++]=a[i++];
while(j<=high)
    c[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=c[i-low];


}



void mergesort(int a[],int low ,int high)
{
    if(low<high){
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merg(a,low,mid,high);

    }
}
///driver part==========================================
int main()
{

    int a[]={34,5,6,644,56,8,344,454545,342325365,3,2,4,456};
   //quicksort(a,0,5);
   mergesort(a,0,12);
    cout << "Hello world!" << endl;
    for(int i=0;i<12;i++)
        cout<<a[i]<<" ";
    cout << "Hello world!" << endl;
    return 0;
}
