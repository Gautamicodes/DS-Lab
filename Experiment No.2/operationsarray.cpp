#include <iostream>
using namespace std;

int main() {
    int arr[50];          
    int n, choice = 0;    
    int i, pos, value;

    cout << "Enter number of elements (max 50): ";
    cin >> n;
    if (n < 1 || n > 50) {
        cout << "Invalid number of elements.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    while (choice != 7) {
        cout << "\n----- MENU -----\n";
        cout << "1. Display\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Update\n";
        cout << "6. Sort\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) { 
            cout << "Invalid input. Enter a number 1-7.\n";
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: 
                cout << "Array elements: ";
                for (i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;

            case 2: 
                cout << "Enter position (0 to " << n << "): ";
                cin >> pos;
                if (pos < 0 || pos > n) {
                    cout << "Invalid position\n";
                    break;
                }
                cout << "Enter value: ";
                cin >> value;
                for (i = n; i > pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos] = value;
                n++;
                cout << "Element inserted\n";
                break;

            case 3: 
                cout << "Enter position (0 to " << n-1 << "): ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Invalid position\n";
                    break;
                }
                for (i = pos; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
                cout << "Element deleted\n";
                break;

            case 4: 
                cout << "Enter element to search: ";
                cin >> value;
                bool found;
                found = false;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        cout << "Element found at position " << i << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Element not found\n";
                break;

            case 5: 
                cout << "Enter position (0 to " << n-1 << "): ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Invalid position\n";
                    break;
                }
                cout << "Enter new value: ";
                cin >> value;
                arr[pos] = value;
                cout << "Element updated\n";
                break;

            case 6: 
                for (i = 0; i < n-1; i++) {
                    for (int j = i+1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                cout << "Array sorted in ascending order\n";
                break;

            case 7: 
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice! Enter 1-7\n";
        }
    }

    return 0;
}

