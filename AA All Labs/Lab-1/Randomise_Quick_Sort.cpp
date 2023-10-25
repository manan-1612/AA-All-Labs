
#include<bits/stdc++.h>
using namespace std;

int glb = 0;
int comp = 0;

pair<int,int> Partition(vector<int>&Array, int first, int last){
    
    int x = Array[last];
    
    int i = first-1;
    int j;
    int comp = 0;
    for(j = first; j < last ;j++){
        if(Array[j] <= x){
            i = i+1;
            comp = comp +1;
            swap(Array[i],Array[j]);
            // comp = comp +1;
        }
    }
    
    swap(Array[i+1],Array[last]);
    return make_pair(i+1,comp);
    
}

pair<int,int> Random_Partition(vector<int>&B,int i , int d){
    srand(time(0));
    int v = i + (rand() % (d-i+1));
    swap(B[v],B[d]);
    
    pair<int,int>pr = Partition(B,i,d);
    glb = pr.second;
    return make_pair(pr.first,glb);
}


void Randamised_Quicksort(vector<int>&A,int p,int r){
    
    int temp;
    
    if(p<r){
        pair<int,int> q = Random_Partition(A,p,r);
        Randamised_Quicksort(A,p,(q.first)-1);
        Randamised_Quicksort(A,(q.first)+1,r);
        temp = q.second;
        cout<<"No. of comparision: "<<q.second<<" "<<"Array: ";
    }
    
    for(int k=0; k<r ;k++){
         cout<<A[k]<<" ";
         
    }
    
    
    
    cout<<endl;
    
    
}



int main() {
    // Write C++ code here
    
     vector<int> a{4, 3, 6, 8, 5, 9, 20, 50, 12, 30, 432, 12, 69, 29, 40, 50, 10, 4, 23, 34, 45,45, 24,89, 799, 45, 80, 50, 10, 30, 43,54,65,76,87, 98, 21, 32, 43, 78, 98, 57, 29, 91, 34,54, 64, 19, 82, 87, 65};
    
    
    Randamised_Quicksort(a,0,a.size()-1);
    //cout<<glb;
    return 0;
}

