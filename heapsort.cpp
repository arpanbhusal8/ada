#include <bits/stdc++.h>
            using namespace std;

            void swapp(int arr[], int largest, int node)
            {
                int temp = arr[largest];
                arr[largest] = arr[node];
                arr[node] = temp;
            }
            void heapify(int arr[], int size, int node)
            {
                int largest = node;
                int left = 2 * node;
                int right = (2 * node) + 1;
                if (left <= size && arr[left] > arr[largest])
                {
                    largest = left;
                }
             if (right <= size && arr[right] > arr[largest])
                    largest = right;
                if (largest != node)
                {
                    swapp(arr, node, largest);
                    heapify(arr, size, largest);
                }
            }
            void heapinsrt(int arr[], int size)
            {
                for (int i = size / 2; i > 0; i--) //the leaf node of a heap can exist as heap in itself so no need to change it 
                //we only need to change the node of the heap which has branches and is not greater than its branches which basically starts 
                //approximately from half the size of array and keeps in decreasing till we reach the root
                {
                    heapify(arr, size, i);
                    //self explanatory
                }
            }
            void printheap(int arr[], int size)
            {
                for (int i = 1; i <= size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            void heapsort(int arr[], int size)
            {
                for (int i = size; i >= 1; i--)
                {
                    swapp(arr, 1, i);
                    heapify(arr, i - 1, 1);
                }
            }

            int main()
            {
                int size;
                cout << "please enter the size of heap\n";
                cin >> size;
                int arr[size + 1];//since the input is from index 1 we have to create an array of size +1 so that all the elements are taken as input 
                //for eg 1 2 3 4 5===0 1 2 3 4
                for (int i = 1; i < size + 1; i++)
                {
                    cout << "please enter the data you want to enter in the heap\n";
                    cin >> arr[i];
                }
                heapinsrt(arr, size);
                printheap(arr, size);
                heapsort(arr, size);
                printheap(arr, size);

                return 0;
            }