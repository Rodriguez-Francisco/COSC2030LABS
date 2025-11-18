#include<algorithm>
#include<iostream>
using namespace std;

const int MAXSIZE = 50;

class Heap {
    private:
    int arr[MAXSIZE];
    int heapSize;
    
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i)+1;
    }
    int right(int i){
        return(2*i)+2;
    }
    void maxheapify(int i){
        int l=left(i);
        int r=right(i);
        int largest=i;

        if(l<heapSize && arr[1]>arr[largest]){
            largest=1;
        }
        if (r < heapSize && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxheapify(largest);}
    }

    public:
    Heap(){heapSize=0;}

    void insert(int key){
        if(heapSize== MAXSIZE){
            cout<<"Error heap is full"<<endl;
            return;
        }
        heapSize++;
        int i =heapSize-1;
        arr[i]=key;
        while(i !=0 && arr[parent(i)],arr[i]){
            swap(arr[i],arr[parent(i)]);
            i= parent(i);
        }}
        
    int getMax()
    {
        if(heapSize <=0){
            cout<<"error empty heap\n";
            return -1;

        }
        return arr[0];

    }
    int deleteMax(){
        if (heapSize <= 0) {
            return -1;
        }
        if (heapSize == 1 ) {
            heapSize--;
            return arr[0];
        }

        int root =  arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        
        maxheapify(0);
        return root;
    }

    void heapSort(int* array,int n){
        heapSize=0;

        for(int i=0;i<n;++i){
            insert(array[i]);
        }
        for(int i=n-1; 0>=0 ;--i){
            array[i]=deleteMax();

        }
    }

   
    

};

int main(){

    Heap heap;

    cout<<"max heap test\n\n\n";

    heap.insert(11);
    heap.insert(22);
    heap.insert(5);
    heap.insert(36);
    heap.insert(15);
    heap.insert(12);

    cout << "Current Max " << heap.getMax() << endl;
    cout << "Deleted Max  " <<  heap.deleteMax() << endl;
    cout << "New Max  " << heap.getMax() << endl;


    cout<<" heapsort test \n\n\n";

    int arr[] = {47, 11, 18, 15, 3, 6, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    heap.heapSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }





}