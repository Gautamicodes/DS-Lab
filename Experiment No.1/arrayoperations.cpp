#include <iostream>
using namespace std;

int main() {

    int arr[10], n = 5, choice, pos, value, key;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    do {
        cout << "\n1. Traversal";
        cout << "\n2. Insertion";
        cout << "\n3. Deletion";
        cout << "\n4. Searching";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: 
                cout << "Array elements: ";
                for(int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                break;

            case 2: 
                cout << "Enter position and value: ";
                cin >> pos >> value;

                for(int i = n; i > pos; i--)
                    arr[i] = arr[i - 1];

                arr[pos] = value;
                n++;

                cout << "After insertion: ";
                for(int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                break;

            case 3: 
                cout << "Enter position to delete: ";
                cin >> pos;

                for(int i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];

                n--;

                cout << "After deletion: ";
                for(int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                break;

            case 4: { 
                cout << "Enter element to search: ";
                cin >> key;

                bool found = false;

                for(int i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        cout << "Element found at index " << i;
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Element not found";
                }
                break;
            }

            case 5:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}