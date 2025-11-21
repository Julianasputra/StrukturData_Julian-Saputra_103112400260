// * Author: Julian Saputra
//  * NIM: 103112400260
//  * Deskripsi: Program untuk insert, delete, view, reverse & view, exit.

#include <iostream>

using namespace std;

struct Node {
    int angka;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insert(int nilai) {
    Node* pertama = new Node;
    pertama->angka = nilai;
    pertama->next = NULL;
    pertama->prev = NULL;

    if (head == NULL) {
        head = tail = pertama;
    } else {
        tail->next = pertama;
        pertama->prev = tail;
        tail = pertama;
    }
}

void deleteLast() {
    if (tail == NULL) {
        return;
    }

    if (head == tail) {
        delete tail;
        head = tail = NULL;
    } else {
        Node* hapus = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete hapus;
    }
}

void viewDepan() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->angka << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    if (head == NULL) return;

    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

int main() {
    int input, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> input;

        switch (input) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insert(nilai);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                viewDepan();
                break;

            case 4:
                reverseList();
                cout << "List setelah di-reverse: ";
                viewDepan();
                break;
        }

    } while (input != 0);

    return 0;
}
