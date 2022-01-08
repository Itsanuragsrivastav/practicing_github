#include<bits/stdc++.h>

using namespace std;

int nextgap(int gap){
    if (gap<=1)
    {
        return 0;
    }
    return (gap / 2) + (gap % 2);
    
}

void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap=n+m;
    for(gap=nextgap(gap); gap>0; gap=nextgap(gap))
    {
        for(i=0; i+gap<n; i++)
        {
            if(arr1[i]>arr1[i+gap])
            {
                swap(arr1[i], arr1[i+gap]);
            }
        }

        for(j=gap > n ? gap-n : 0; i < n && j<m; i++,j++)
        {
            if(arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }

        if(j<m)
        {
             for(j=0; j + gap < m; j++)
             {
                 if(arr2[j]>arr2[j+gap])
                 {
                     swap(arr2[j], arr2[j+gap]);
                 }
             }
            
        }
    }
}




int main(){

    int arr1[] = {2,4,5,6,7};
    int arr2[] = {1,8,9};

    int n = sizeof(arr1)/ sizeof(int);
    int m = sizeof(arr2)/ sizeof(int);

        merge(arr1, arr2, n, m);

    cout<<"First Array:"<<endl;
    for(int i=0; i<n; i++)
    cout<<arr1[i]<<" ";


    cout<<endl;



    cout<<"Second Array:"<<endl;
    for(int j=0; j<m; j++)
    cout<<arr2[j]<<" ";

    cout<<endl;
    return 0;

}