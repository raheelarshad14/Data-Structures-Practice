#include <iostream>
using namespace std;

int arr[100];
int currentSize = 0;

// 1. Insert value at the end of the list
void insertEnd(int value) {
    arr[currentSize] = value;
    currentSize++;
}

// 2. Insert value at the start of a list
void insertStart(int value) {
    for (int i = currentSize; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    currentSize++;
}

int idx = 0;

// Task 3 Find Index Function
int findIndex(int value) {
    int i = 0;
    while (i < currentSize) {
        if (arr[i] == value) {
            idx = i;
            return i;
        }
        i++;
    }

    return -1;
}

// 3. Insert the value after a specific value
void insertAfterSpecific(int value, int newValue) {
    if (findIndex(value) != -1) {
        for (int i = currentSize; i > idx + 1; i--) {     /// see register
            arr[i] = arr[i - 1];
        }
        arr[idx + 1] = newValue;
        currentSize++;
    }
}

// 4. Insert value before a specific value
void insertBeforeSpecific(int value, int newValue) {
    if (findIndex(value) != -1) {
        for (int i = currentSize; i > idx; i--) {  // see register
            arr[i] = arr[i - 1];
        }
        arr[idx] = newValue;
        currentSize++;
    }
}

// 5. Display the Array List
void displayList() {
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
}

// 6. Delete the value from the end of the list
void deleteEnd() {
    if (currentSize == 0) {
        cout << "List is empty" << endl;
    }
    else {
        currentSize--;     // Its like putting a curtain on the value so it wont be accessed
    }                       // however its still stored in the memory
}

void deleteStart() {
    if (currentSize == 0) {
        cout << "List is emptry" << endl;
    }
    else {
        for (int i = 0 ; i < currentSize - 1 ; i++) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }
}

void deleteSpecific(int value) {
    if (findIndex(value) != -1) {
        for (int i = idx; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }
}



int main() {
        cout << "--- Lab Task 2: Array List Operations ---" << endl;

        // Adding values
        insertEnd(10);
        insertEnd(20);
        insertEnd(30);
        cout << "After insertEnd (10, 20, 30): ";
        displayList(); cout << endl;

        insertStart(5);
        cout << "After insertStart (5): ";
        displayList(); cout << endl;

        // Shifting operations
        // Note: I'm using your function names.
        // If you add parameters to your functions, adjust them here.
        insertAfterSpecific(10, 60); // Adds the 'value' after finding the 'value'
        cout << "After insertAfterSpecific: ";
        displayList(); cout << endl;

        // Deletion operations
        deleteStart();
        cout << "After deleteStart: ";
        displayList(); cout << endl;

        deleteEnd();
        cout << "After deleteEnd: ";
        displayList(); cout << endl;

        // Task 3: Linear Search
        int searchVal = 20;
        cout << "\n--- Lab Task 3: Linear Search ---" << endl;
        if (findIndex(searchVal) != -1) {
            cout << "Value " << searchVal << " found at index: " << idx << endl;
        } else {
            cout << "Value " << searchVal << " not found." << endl;
        }

        return 0;
}