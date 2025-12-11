# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Julian Saputra
- **NIM**: 103112400260
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
Saya sangat termotivasi memperlajari struktur data, kenapa saya belajat stuktur data karena saya sadar kalau struktur data itu pondasi yang sangat penting dalam pemrograman contohnya seperti kita akan membangun rumah yang membutuhkan pondasi. Lalu juga banyak aplikasi atau teknologi di dunia nyata contohnya kaya sistem pencarian, manajemen database, sampai ada juga kecerdasan buatan yang bekerja secara efisien dikarenakan menggunakan struktur data yang tepat dan baik. Jadi karena itu saya termotivasi belajar struktur data ini.

## 3. Dasar Teori
Struktur data adalah cara mengorganisir, menyimpan, dan mengelola data agar dapat diakses serta diproses dengan efisien. Pada praktikum ini digunakan dua jenis struktur data yang lebih kompleks, yaitu Multi Linked List (untuk hubungan Induk–Anak) dan Circular Linked List (untuk struktur melingkar tanpa ujung). Kedua struktur ini digunakan untuk menangani data hierarki dan data berulang yang membutuhkan efisiensi traversal.

### Berikut Dasar Teori nya :

1. Konsep Multi Linked List (Induk–Anak)

Multi Linked List adalah struktur data yang terdiri dari dua level linked list:
- List Induk -> berisi elemen-elemen induk
- List Anak -> setiap induk memiliki list anak sendiri

Pada tugas ini:
- Induk berisi ID induk
- Anak berisi ID anak yang terhubung ke induknya

Setiap induk memiliki:
- data (info)
- pointer ke anak pertama dan terakhir (doubly linked list)
- pointer ke induk berikutnya dan sebelumnya

Multi linked list membantu pemisahan data berdasarkan kategori, sehingga efisien untuk operasi pencarian dan pengelompokan.

2. Struktur Data Induk dan Anak

Pada program, terdapat dua struktur utama:

a. Struktur Induk

Berisi:
- info induk
- list anak (first & last)
- pointer next dan prev

b. Struktur Anak

Berisi:
- info anak
- pointer next dan prev (doubly linked list)

Struktur ganda ini memungkinkan data tersusun secara hierarki.

3. Konsep Insert pada Multi Linked List

a. Insert Last Induk

Menambah induk di bagian belakang list induk.

Langkah:
- Jika list kosong -> induk menjadi elemen pertama
- Jika tidak -> letakkan di posisi terakhir
- Perbarui pointer prev dan next

b. Insert Last Anak

Menambahkan anak pada induk tertentu.

Langkah:
- Temukan induk dengan findInduk()
- Tambahkan anak pada list anak induk
- Perbarui pointer prev dan next

Contoh struktur hasil:

Induk 1 -> Anak: 10, 11

Induk 2 -> Anak: 19, 20

4. Konsep Delete pada Multi Linked List

Tugas yang dikerjakan: menghapus anak terakhir dari induk tertentu.

Aturan:
- Jika list anak kosong -> tidak ada yang dihapus
- Jika satu elemen -> hapus dan set first=last=NULL
- Jika lebih dari satu -> pindahkan last ke last->prev

Contoh hasil setelah delete untuk Induk 1:

Sebelum: 10 -> 11

Sesudah: 10

5. Konsep Traversal Multi Linked List

Traversal dilakukan dua level:
- traversal induk
- pada setiap induk, traversal anak

Fungsi printInfo() dilakukan untuk menampilkan:

Induk ID: 1

    -> Anak ID: 10

    -> Anak ID: 11

Induk ID: 2

    -> Anak ID: 19

    -> Anak ID: 20

Traversal bersarang ini sangat penting untuk memvisualisasikan multilist.

6. Konsep Circular Linked List

Circular Linked List adalah bentuk linked list di mana:
- Node terakhir tidak menunjuk ke NULL
- Tetapi menunjuk kembali ke node pertama

Sehingga list bersifat melingkar.

Kelebihan Circular Linked List:
- Tidak ada akhir list -> traversal bisa berputar
- Efisien untuk struktur data yang membutuhkan “rotasi”

Cocok untuk:
- sistem giliran (round robin)
- antrian melingkar
- permainan kartu
- aplikasi navigasi siklus

Pada tugas ini circular linked list digunakan untuk menyimpan data siswa atau harga barang secara melingkar.

7. Konsep Insert pada Circular Linked List

Operasi insert pada circular list umumnya:

a. insertFirst()
- Jika list kosong -> first menunjuk dirinya sendiri
- Jika tidak -> node baru disisipkan sebelum first
- Node terakhir harus menunjuk ke node baru

b. insertLast()
- Menambahkan node sebelum node first
- Update last -> menunjuk kembali ke first
- Pointer previous juga disesuaikan (doubly circular list)

Circular list harus mempertahankan bentuk lingkaran setelah setiap operasi.

8. Konsep Delete pada Circular Linked List

Contoh: delete first atau delete last.

Aturan:
- Jika list kosong -> tidak bisa delete
- Jika satu elemen -> setelah delete, list kosong
- Jika banyak elemen -> pointer next dan prev disesuaikan agar tetap membentuk lingkaran

Deletion harus memastikan:

last->next = first

first->prev = last

Agar tidak merusak bentuk melingkar.

9. Konsep printInfo() pada Circular Linked List

Karena list melingkar, traversal tidak boleh memakai while(node != NULL).

Melainkan traversal menggunakan pola:

p = first

do {

    print(p->info)

    p = p->next

} while (p != first)

Dengan cara ini, list dapat ditampilkan tanpa infinite loop.

10. Konsep Modularisasi (Memecah Fungsi)

Baik multilist maupun circular list ditulis menggunakan modularisasi:
- createList()
- alokasi()
- insertFirst()
- insertLast()
- deleteLast()
- printInfo()

Tujuan modularisasi:
- kode lebih rapi
- mudah diperbaiki
- setiap fungsi fokus pada satu tugas (single responsibility)

Pada main.cpp, programmer hanya memanggil:

insertLast(L, data);

deleteFirst(L);

printInfo(L);

Sehingga alur program lebih bersih.

## 4. Guided
### 4.1 Guided 1
![alt text](ss/guided1.png)

Penjelasan : Kode ini adalah header file untuk membangun ADT Multilist menggunakan double linked list. Multilist adalah struktur data yang terdiri dari list induk di mana setiap elemen induk memiliki list anak sendiri, sehingga membentuk hubungan “list di dalam list”. Pada bagian induk terdapat struktur elemen_induk yang menyimpan nilai info, sebuah list_anak, serta pointer next dan prev untuk membentuk double linked list. Struktur list_induk menyimpan pointer first dan last sebagai penanda awal dan akhir list induk. Sementara itu, bagian anak menggunakan struktur elemen_anak yang juga memiliki info, pointer next, dan prev sehingga list anak juga berbentuk double linked list. Struktur list_anak menyimpan pointer first dan last untuk mengelola urutan elemen anak.
Header ini menyediakan berbagai fungsi operasi dasar pada list induk maupun anak. Fungsi seperti createList digunakan untuk menginisialisasi list induk agar kosong, sedangkan alokasi dan alokasiAnak membuat elemen baru untuk induk atau anak. Operasi penyisipan disediakan melalui insertFirstInduk, insertLastInduk, insertAfterInduk serta versi anaknya, yang memungkinkan penambahan elemen di depan, belakang, atau setelah elemen tertentu. Operasi penghapusan seperti deleteFirstInduk, deleteLastInduk, dan deleteAfterInduk juga tersedia untuk menghapus elemen induk, begitu pula dengan list anak. Fungsi pencarian findInduk dan findAnak digunakan untuk menemukan elemen berdasarkan nilai info. Terakhir, fungsi printInfo menampilkan seluruh isi list induk beserta list anak yang dimilikinya, sehingga struktur multilist dapat dilihat secara lengkap. Dengan demikian, file header ini menyediakan kerangka lengkap untuk membangun dan mengelola struktur multilist berbasis double linked list.

### 4.2 Guided 2
![alt text](ss/guided2.png)

Penjelasan : Kode ini adalah implementasi dari ADT Multilist menggunakan double linked list untuk list induk dan list anak. Fungsi createList digunakan untuk menginisialisasi list induk agar kosong dengan mengatur first dan last menjadi Nil. Fungsi alokasi membuat elemen induk baru, mengisi data info, mengosongkan pointer next dan prev, serta menginisialisasi list anak di dalamnya. Operasi penambahan elemen induk disediakan melalui insertFirstInduk, insertLastInduk, dan insertAfterInduk, yang masing-masing menyisipkan elemen di depan, belakang, atau setelah elemen tertentu, lengkap dengan pengaturan pointer next dan prev. Untuk penghapusan, fungsi deleteFirstInduk dan deleteLastInduk menghapus elemen induk di posisi awal atau akhir, sambil menangani kasus ketika list hanya berisi satu elemen. Fungsi findInduk digunakan untuk mencari elemen induk berdasarkan nilai info dengan melakukan traversal dari first hingga Nil. Terakhir, fungsi printInfo menampilkan seluruh isi multilist dengan mencetak data induk dan seluruh anak yang dimilikinya, atau menampilkan pesan jika sebuah induk tidak memiliki anak. Secara keseluruhan, kode ini menyediakan operasi dasar untuk pengelolaan multilist induk-anak menggunakan double linked list.

### 4.3 Guided 3
![alt text](ss/guided3.png)

Penjelasan : Kode ini adalah implementasi operasi dasar untuk list anak pada struktur Multilist, yang dibangun menggunakan double linked list. Fungsi alokasiAnak digunakan untuk membuat node anak baru, mengisi nilai info, dan mengosongkan pointer next serta prev. Untuk menambahkan elemen anak, fungsi insertFirstAnak menyisipkan elemen di bagian depan list, sedangkan insertLastAnak menambahkannya di bagian belakang dengan memperbarui pointer first, last, serta hubungan next dan prev antar node. Penghapusan elemen anak dilakukan melalui deleteFirstAnak untuk menghapus elemen paling depan dan deleteLastAnak untuk menghapus elemen paling belakang, lengkap dengan penanganan kondisi ketika list hanya memiliki satu elemen. Secara keseluruhan, kode ini menyediakan operasi penyisipan dan penghapusan pada list anak dalam multilist menggunakan mekanisme double linked list sehingga data dapat dikelola secara fleksibel baik dari depan maupun belakang.

### 4.4 Guided 4
![alt text](ss/guided4.png)

Penjelasan : Kode ini adalah program utama yang digunakan untuk menguji ADT Multilist yang telah dibuat sebelumnya. Program diawali dengan mendeklarasikan sebuah list_induk dan menginisialisasinya menggunakan createList. Setelah list induk siap digunakan, program membuat elemen induk pertama dengan nilai 1 menggunakan fungsi alokasi, kemudian memasukkannya ke bagian belakang list induk melalui insertLastInduk. Selanjutnya dibuat satu elemen anak dengan nilai 10 dan ditambahkan ke list anak milik induk tersebut menggunakan insertLastAnak. Proses yang sama dilakukan untuk elemen induk kedua, yaitu membuat induk bernilai 2 dan menambahkannya ke list, lalu membuat elemen anak bernilai 20 dan memasukkannya ke list anak milik induk kedua. Setelah seluruh data ditambahkan, fungsi printInfo dipanggil untuk menampilkan seluruh isi multilist, yaitu setiap data induk beserta daftar anaknya masing-masing. Dengan demikian, kode ini berfungsi untuk mendemonstrasikan cara membangun dan menampilkan struktur multilist menggunakan operasi alokasi, penyisipan induk, penyisipan anak, dan pencetakan data.

Output : 

![alt text](ss/outputG4.png)

## 5. Unguided
### 5.1 Unguided 1
![alt text](ss/unguided1.png)

Penjelasan : Kode ini adalah program utama yang digunakan untuk menguji operasi pada ADT Multilist, yang terdiri dari list induk dengan masing-masing memiliki list anak. Program dimulai dengan membuat sebuah list_induk dan menginisialisasinya menggunakan createList. Selanjutnya dibuat dua elemen induk dengan nilai 1 dan 2, yang kemudian ditambahkan ke bagian belakang list menggunakan insertLastInduk. Untuk induk pertama, dua elemen anak dengan nilai 10 dan 11 ditambahkan melalui insertLastAnak, sehingga keduanya berada di urutan belakang list anak milik induk tersebut. Untuk induk kedua, dua anak juga ditambahkan: anak bernilai 20 dimasukkan di belakang menggunakan insertLastAnak, sedangkan anak bernilai 19 disisipkan di depan menggunakan insertFirstAnak, sehingga menjadi elemen pertama pada list anak milik induk kedua. Setelah semua data berhasil ditambahkan, fungsi printInfo dipanggil untuk menampilkan seluruh struktur multilist.
Program kemudian melanjutkan dengan operasi penghapusan, yaitu menghapus elemen anak terakhir dari induk pertama menggunakan deleteLastAnak. Node yang terhapus disimpan pada variabel PDel. Setelah proses penghapusan selesai, list kembali ditampilkan menggunakan printInfo untuk memperlihatkan perubahan pada struktur data. Secara keseluruhan, kode ini mendemonstrasikan cara membuat multilist, menambahkan induk dan anak, serta menghapus elemen anak menggunakan operasi-operasi ADT double linked list.

Output : 

![alt text](ss/outputU1.png)

### 5.2 Unguided 2

#### Circular.h
![alt text](ss/circularh.png)

Penjelasan : Kode ini adalah header file untuk membangun ADT Circular Linked List yang digunakan untuk menyimpan data mahasiswa. Setiap elemen list menyimpan informasi berupa nama, NIM, jenis kelamin, dan IPK, yang didefinisikan dalam struktur infotype. Struktur ElmList mewakili node dalam circular list, berisi data mahasiswa dan pointer next yang menunjuk ke elemen berikutnya, di mana elemen terakhir akan menunjuk kembali ke elemen pertama sehingga membentuk list melingkar. Struktur List hanya menyimpan satu pointer yaitu First sebagai penanda awal list. Fungsi CreateList digunakan untuk menginisialisasi list kosong dengan mengatur pointer pertama menjadi NULL. Fungsi alokasi membuat node baru dan mengisi datanya, sedangkan dealokasi digunakan untuk membebaskan memori node yang sudah tidak dipakai.
Untuk operasi penyisipan, tersedia insertFirst, insertAfter, dan insertLast yang memungkinkan penambahan node di depan, setelah node tertentu, atau di bagian akhir list sambil tetap mempertahankan struktur circular. Operasi penghapusan dilakukan melalui deleteFirst, deleteAfter, dan deleteLast untuk menghapus node dari posisi tertentu dengan memastikan hubungan circular antar elemen tetap konsisten. Fungsi findElm digunakan untuk mencari elemen berdasarkan data mahasiswa, sedangkan printInfo mencetak seluruh isi circular list mulai dari elemen pertama hingga kembali lagi ke awal. Secara keseluruhan, header ini menyediakan seluruh operasi dasar untuk membangun dan mengelola Circular Linked List yang menyimpan data mahasiswa secara dinamis.

#### Circular.cpp
![alt text](ss/circularcpp.png)

Penjelasan : Kode ini adalah implementasi lengkap dari ADT Circular Linked List yang digunakan untuk menyimpan dan mengelola data mahasiswa. Fungsi CreateList menginisialisasi list agar kosong dengan mengatur pointer First menjadi NULL. Fungsi alokasi membuat node baru berisi data mahasiswa dan mengatur pointer next menjadi NULL, sedangkan dealokasi digunakan untuk menghapus node dan membebaskan memori. Operasi penyisipan elemen dilakukan melalui beberapa fungsi: insertFirst menambahkan node di bagian awal list dengan menjaga agar node terakhir tetap menunjuk kembali ke elemen pertama, insertAfter menyisipkan node setelah elemen tertentu, dan insertLast menambahkan node di posisi terakhir sebelum kembali ke First. Untuk penghapusan elemen, tersedia deleteFirst yang menghapus node pertama dengan memperbarui pointer First dan menjaga hubungan circular, deleteAfter yang menghapus node setelah elemen tertentu, serta deleteLast yang menghapus node paling akhir dan mengatur ulang node sebelumnya agar menunjuk ke First. Fungsi findElm digunakan untuk mencari data mahasiswa berdasarkan NIM dengan melakukan traversing mengelilingi list hingga kembali ke node pertama. Terakhir, printInfo digunakan untuk menampilkan seluruh isi circular linked list, mencetak data mahasiswa dari elemen pertama hingga kembali ke awal list. Secara keseluruhan, kode ini memberikan semua operasi penting untuk membangun, menambah, menghapus, mencari, dan mencetak elemen dalam struktur circular linked list.

#### Unguided2.cpp
![alt text](ss/unguided2.png)

Penjelasan : Kode ini adalah program utama yang digunakan untuk menguji berbagai operasi pada ADT Circular Linked List yang menyimpan data mahasiswa. Program diawali dengan membuat sebuah list kosong menggunakan CreateList. Untuk mempermudah pembuatan data, fungsi createData digunakan untuk membentuk objek mahasiswa dan langsung mengalokasikannya sebagai node list. Selanjutnya, beberapa operasi penyisipan dilakukan: insertFirst digunakan untuk menambahkan data di awal list, sedangkan insertLast menambahkannya di akhir list sambil tetap menjaga sifat circular dari struktur data. Setelah beberapa data mahasiswa dimasukkan, program melakukan penyisipan berbasis pencarian, yaitu dengan mencari node tertentu menggunakan findElm berdasarkan NIM. Jika elemen ditemukan, maka elemen baru disisipkan setelahnya menggunakan insertAfter, seperti penyisipan data “Cindi” setelah mahasiswa dengan NIM ”07”, atau “Hilmi” setelah NIM “02”. Setelah seluruh proses penambahan dan penyisipan selesai, fungsi printInfo dipanggil untuk menampilkan seluruh isi circular linked list secara berurutan mulai dari elemen pertama hingga kembali lagi ke awal. Secara keseluruhan, kode ini menunjukkan cara membangun list melingkar, mengisi data mahasiswa dengan berbagai metode penyisipan, melakukan pencarian, dan menampilkan hasilnya.

Output : 

![alt text](ss/outputU2.png)


## 6. Kesimpulan
Jadi berdasarkan hasil pengerjaan program di atas, dapat saya simpulkan bahwa tujuan pembelajaran mengenai penerapan struktur data Queue (Antrian) telah berhasil dicapai. Melalui implementasi berbagai operasi seperti enqueue, dequeue, isEmpty, isFull, serta printInfo, saya mampu memahami bagaimana data dapat disimpan dan dikelola menggunakan prinsip FIFO (First In, First Out). Struktur data Queue memungkinkan pengelolaan data secara berurutan, di mana elemen yang masuk lebih dulu akan menjadi yang pertama keluar.
Selain itu, penerapan konsep circular queue memberikan efisiensi yang lebih baik karena tidak memerlukan penggeseran elemen secara manual, sehingga operasi berjalan lebih optimal. Penggunaan fungsi-fungsi terpisah juga membuat program lebih rapi, mudah dipahami, dan sesuai dengan konsep modularisasi. Dengan demikian, praktikum ini memberikan pemahaman yang baik mengenai konsep dasar dan penerapan nyata dari struktur data Queue dalam bahasa C++.

## 7. Referensi
1. Programiz. “Queue Data Structure.” https://www.programiz.com/dsa/queue
2. GeeksforGeeks. “Queue Data Structure (Introduction and Implementation).” https://www.geeksforgeeks.org/queue-data-structure/
3. W3Schools. “C++ Arrays & Functions.” https://www.w3schools.com/cpp/cpp_arrays.asp