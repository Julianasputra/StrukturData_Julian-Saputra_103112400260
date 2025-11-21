UJIAN TENGAH SEMESTER
PRAKTIKUM STRUKTUR DATA
CLO 3

Identitas Pengumpul

Nama: Julian Saputra

NIM: 103112400260

Kelas: 12-IF-05

1. Kode Program

Berikut adalah kode program untuk insert, delete, view depan, reverse & view depan, dan exit.

(Silakan ganti bahasa dan kode di bawah ini sesuai tugas Anda)

```File: soal2.cpp
 * Author: Julian Saputra
 * NIM: 103112400260
 * Deskripsi: Program untuk insert, delete, view, reverse & view, exit.
 */

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

```

2. Penjelasan Kode

Berikut adalah penjelasan alur logika dari kode program di atas:

Header & Namespace: Program mengimpor library iostream untuk operasi input/output (seperti cout dan cin) dan menggunakan std namespace.

Fungsi insert(int nilai):
Fungsi ini menerima satu parameter integer bernama nilai. Di fungsi ini program di minta untuk masukkan angka sesuai yang diinginkan dan menjadi angka pertama 
else: Jika bukan menginput angka maka akan eror.

Fungsi ini akan langsung mencetak hasilnya ke konsol.

Fungsi main():
Ini adalah fungsi utama tempat program dieksekusi.
Mendeklarasikan variabel input dan nilai untuk menyimpan data dari user.
Menampilkan judul program dan meminta user memasukkan sebuah bilangan.
cin >> input;: Menyimpan nilai yang diketik user ke dalam variabel input.
Memanggil fungsi insert(nilai), deleteLast(), viewDepan(), reverseList() dan mengirimkan input sebagai argumennya.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
![alt text](output/outputUTS.png)
```

4. Penjelasan Lanjutan (Analisis Output)

Pada saat user memasukkan 5, 10, 15, dan 20 melalui menu insert, semua nilai ditambahkan ke bagian akhir list sehingga urutannya menjadi 5 -> 10 -> 15 -> 20. Ketika menu view dipilih, program menampilkan isi list sesuai urutan tersebut. Setelah itu, menu delete last menghapus elemen paling belakang, yaitu 20, sehingga list berubah menjadi 5 -> 10 -> 15. Terakhir, menu reverse membalik semua pointer sehingga urutan list menjadi 15 -> 10 -> 5. Semua hasil output sesuai dengan logika dasar insert, delete last, view, dan reverse pada Single Linked List.

5. Kesimpulan

erdasarkan implementasi program, dapat saya simpulkan bahwa operasi dasar pada Single Linked List telah berjalan dengan baik. Proses percabangan (selection) digunakan pada menu pilihan untuk menentukan tindakan yang harus dilakukan program, seperti insert, delete, view, dan reverse.
