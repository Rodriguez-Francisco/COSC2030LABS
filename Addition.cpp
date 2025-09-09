/*Francisco Rodriguez
COSC2030
LAB2 :)
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int Addup(int A[], int n)
{
    int sum =0;
    for(int i=0;i<n;++i){
        sum+=A[i]; 
    }
    return sum;
}
int main(int argc, char* argv[])
{

    int char_num = argc-1;

    if(char_num>10){
        cout<<"No more than 10 ints Please";
        return 0;
    }
    int nums[10];
    for (int i = 0 ; i<char_num;++i){
        nums[i]= atoi(argv[i+1]);
    }
    
    cout<<Addup(nums, char_num)<<"\n\n";
  //cout<<atoi(argv[0])<<endl;
  //cout<<atoi(argv[1])<<endl;
}
