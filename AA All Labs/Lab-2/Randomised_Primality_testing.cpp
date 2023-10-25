#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int gcd(unsigned long long int A,unsigned long long int N){
    int t;
     
    while(N>0){
        t = A%N;
        
        A = N;        
        N = t;
    }
    
    return A;
}

int Power(unsigned long long int random, unsigned long long int number,unsigned long long int p){
    int res = 1;
    
   while(number>0){
       
       if(number%2 == 1){
           res = (res*random) % p;
       }
       number = number/2;
       
       random = (random*random)%p;
   }
    return res;
    
}

int isPrime(unsigned long long int num){
    int k = 10;
    int flag = 0;
    
    if(num<=1 || num ==4){
        flag = 1;
    }
    
    if(num == 2 && num==3){
        flag = 0;
    }
    
    if(num%2 == 0 && num !=2){
        flag = 1;
    }
    
    else{
        
        while(k>0){
            srand(time(0));
            
            //it will generate random number till n-2
            // rand(n-p+1) where n = n-2 and p=2 as p can not be equal to 1

            int a = 2 + (rand() %(num-4));
            
            if( gcd(a,num) != 1){
                flag = 1;
            }
            
            if( Power(a,num-1,num) != 1){
                flag = 1;
            }
            
            k--;
        }
    }
  return flag;   
}


int main()
{   
    unsigned long long int n;
    cin>>n;
    
   int result =  isPrime(n);
    
    if(result == 1){
        cout<<"Number is composite";
    }
    
    else{
        cout<<"Number is Prime";
    }
    return 0;
}
