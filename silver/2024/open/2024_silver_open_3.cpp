#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;  
    int 
}
/*
sample:
the string is AGTCAACG
when L = 2, you have
AG GT TC CA AA AC CG
you find the closest smaller values using monotonic stack, and then you add the two distances.
so AG appears when K = 2, 3, 4, 5
GT when K = 2,3
TC when K = 2
CA when K = 2,3,4
AA when K = 2, 3, 4, 5, 6, 7, 8
AC when K = 2, 3
CG when K = 2
so at K = 2, you have AG, GT, TC, CA, AA, AC, CG, which is 7
at K = 3, you have AG, GT, CA, AA, AC which is 5
at K = 4, you have AG, CA, AA which is 3
at K = 5, you have AG, AA which is 2
at K = 6, you have AA which is 1
at K = 7, you have AA which is 1
at K = 8, you have AA which is 1
stacks:
AG
AG GT
AG GT TC
AG CA
AA
AA AC
AA AC CG
and
CG
AC
AA
AA CA
AA CA TC
AA CA GT
AA AG
*/