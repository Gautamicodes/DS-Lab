#include <iostream>
#include <list>
using namespace std;

// Define the size of hash table
#define SIZE 10

class HashTable {
    list<int> table[SIZE];   // Array of linked lists

public:

    // Hash Function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // Insert element
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Delete element
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
        cout << "Deleted " << key << " from index " << index << endl;
    }

    // Search element
    bool search(int key) {
        int index = hashFunction(key);

        for (int value : table[index]) {
            if (value == key)
                return true;
        }
        return false;
    }

    // Display table
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            for (int value : table[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(23);
    ht.insert(45);
    ht.insert(12);
    ht.insert(33);  // Collision with 23 (23 % 10 = 3, 33 % 10 = 3)

    cout << "\nHash Table:\n";
    ht.display();

    cout << "\nSearching 45: ";
    if (ht.search(45))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    ht.remove(23);

    cout << "\nHash Table after deletion:\n";
    ht.display();

    return 0;
}