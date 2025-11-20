# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Julian Saputra
- **NIM**: 103112400260
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
Saya sangat termotivasi memperlajari struktur data, kenapa saya belajat stuktur data karena saya sadar kalau struktur data itu pondasi yang sangat penting dalam pemrograman contohnya seperti kita akan membangun rumah yang membutuhkan pondasi. Lalu juga banyak aplikasi atau teknologi di dunia nyata contohnya kaya sistem pencarian, manajemen database, sampai ada juga kecerdasan buatan yang bekerja secara efisien dikarenakan menggunakan struktur data yang tepat dan baik. Jadi karena itu saya termotivasi belajar struktur data ini.

## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengelola data agar dapat digunakan secara efisien oleh komputer. Salah satu struktur data yang paling umum digunakan adalah queue, karena sangat cocok untuk situasi antrean atau pemrosesan data secara berurutan. Queue banyak dipakai pada sistem antrian layanan, manajemen proses di sistem operasi, buffer data, hingga simulasi antrian pada aplikasi.

### Berikut Dasar Teori nya :

1. Konsep Queue (Antrian)
Queue adalah struktur data yang menerapkan prinsip FIFO (First In, First Out). Artinya, elemen yang pertama masuk ke dalam antrian akan menjadi elemen pertama yang keluar. Operasi dasar pada queue meliputi:
a. enqueue() -> menambahkan elemen ke bagian belakang antrian.
b. dequeue() -> menghapus elemen paling depan dari antrian.
c. isEmpty() -> mengecek apakah antrian kosong.
d. isFull() -> mengecek apakah antrian sudah penuh (untuk queue berbasis array).
Konsep queue sangat sering digunakan dalam sistem nyata yang sifatnya “datang duluan dilayani duluan”, seperti antrean printer, penjadwalan proses, dan buffer multimedia.

2. Konsep Queue Menggunakan Array
Implementasi queue dengan array memerlukan penanda posisi depan dan belakang, biasanya berupa variabel head dan tail. Pada queue dasar, nilai head dan tail bergerak mengikuti penambahan atau pengurangan data. Namun, jika elemen paling depan dihapus, sering kali posisi harus digeser atau disesuaikan.
Jika head = -1 dan tail = -1, berarti queue kosong.
Jika tail mencapai indeks maksimum, berarti queue penuh.

3. Konsep Circular Queue
Circular queue adalah versi queue yang lebih efisien dibanding queue biasa karena indeks tail dapat “memutar” kembali ke indeks 0 ketika sudah mencapai batas array. Ini dicapai menggunakan operasi modulo (%).
Contoh:
tail = (tail + 1) % MAX_QUEUE
Dengan cara ini, tidak ada proses penggeseran elemen saat dequeue, sehingga performanya lebih baik.

4. Konsep Fungsi enqueue()
Fungsi enqueue() bertugas memasukkan elemen ke antrian. Jika queue belum penuh, data ditempatkan di posisi tail, lalu nilai tail digeser satu langkah. Pada circular queue, pergeseran ini dilakukan menggunakan modulo agar indeks kembali ke awal jika mencapai batas array.
Jika queue penuh, fungsi ini akan menampilkan pesan seperti “Antrean Penuh!” dan data tidak dimasukkan.

5. Konsep Fungsi dequeue()
Fungsi dequeue() mengambil elemen dari bagian depan queue. Jika queue tidak kosong, data pada posisi head dikembalikan lalu head digeser satu langkah.
Pada implementasi non-circular, kadang elemen harus digeser ke kiri untuk merapatkan data.
Pada circular queue, cukup menggeser head = (head + 1) % MAX_QUEUE, tanpa perlu geser manual.
Jika queue kosong, fungsi ini mengeluarkan pesan “Antrean Kosong!” dan mengembalikan nilai tertentu seperti -1.

6. Konsep Fungsi printInfo()
a. Fungsi ini berfungsi untuk menampilkan isi antrian. Cara traversal tergantung jenis queue:
b. Pada queue biasa, data ditampilkan dari indeks head hingga tail.
Pada circular queue, traversal dilakukan sambil memperhatikan “perputaran” indeks menggunakan modulo.
Selain menampilkan isi, program juga sering mencetak posisi head dan tail sebagai informasi keadaan queue.

7. Konsep Modularisasi pada Program Queue
Untuk membuat program lebih rapi dan mudah dipahami, operasi queue seperti enqueue, dequeue, isEmpty, isFull, createQueue, dan printInfo dibuat dalam fungsi terpisah. Dengan cara ini, code menjadi lebih terstruktur, mudah diperbaiki, dan mengikuti prinsip abstraksi.

## 4. Guided
### 4.1 Guided 1
![alt text](ss/guided1.png)

Penjelasan : Kode ini merupakan header untuk membuat ADT Queue menggunakan array. Queue dapat menampung maksimal 5 data bertipe int. Struktur Queue menyimpan array info, lalu head, tail, dan count untuk melacak posisi dan jumlah data. Fungsi createQueue digunakan untuk menginisialisasi queue, isEmptyQueue mengecek apakah queue kosong, dan isFullQueue mengecek apakah penuh. Fungsi enqueue menambahkan data ke belakang queue, dequeue mengambil data dari depan, dan printInfo menampilkan isi queue. Semua ini mengikuti prinsip FIFO (First In, First Out).

### 4.2 Guided 2
![alt text](ss/guided2.png)

Penjelasan : Kode ini merupakan implementasi queue menggunakan circular array. createQueue mengatur queue agar mulai kosong. isEmpty mengecek apakah queue kosong, dan isFull mengecek apakah queue penuh. Fungsi enqueue menambah data di posisi tail, lalu memajukan tail secara melingkar dan menambah count. Fungsi dequeue mengambil data dari posisi head, memajukan head secara melingkar, serta mengurangi count. Jika penuh atau kosong, muncul pesan peringatan. Fungsi printInfo menampilkan isi queue dari head sebanyak jumlah elemen. Semua proses mengikuti aturan FIFO (First In, First Out).

### 4.3 Guided 3
![alt text](ss/guided3.png)

Penjelasan : Kode main.cpp ini merupakan fungsi untuk menguji cara kerja ADT Queue yang telah dibuat. Program diawali dengan mencetak “Hello world!”, kemudian membuat sebuah objek Queue Q. Setelah itu, queue diinisialisasi dengan createQueue(Q) dan langsung ditampilkan isinya menggunakan printInfo(Q) yang pada awalnya tentu masih kosong. Selanjutnya, program menambahkan beberapa nilai ke dalam queue menggunakan enqueue, yaitu 5, 2, dan 7, di mana setiap penambahan selalu diikuti dengan printInfo untuk melihat perubahan isi queue. Setelah itu, program menghapus dua elemen dari depan queue menggunakan dequeue dan kembali menampilkan isi queue. Program kemudian menambahkan nilai baru, yaitu 4, dan menampilkannya lagi. Dua operasi dequeue terakhir mengeluarkan sisa elemen hingga queue kembali kosong. Secara keseluruhan, program ini memperlihatkan proses enqueue dan dequeue secara berurutan serta bagaimana kondisi queue berubah setelah setiap operasi, sesuai prinsip FIFO.

Output : 

![alt text](ss/outputG3.png)

## 5. Unguided
### 5.1 Unguided 1
![alt text](ss/unguided1.png)

Penjelasan : Kode ini merupakan versi sederhana dari queue yang disimpan dalam array biasa, tanpa konsep “melingkar”. Saat queue dibuat lewat createQueue, nilai head dan tail diset ke -1, artinya masih benar-benar kosong. Fungsi isEmptyQueue mengecek apakah queue kosong dengan melihat apakah tail masih -1, sedangkan isFullQueue mengecek apakah posisi tail sudah mencapai batas array (MAX_QUEUE - 1).
Pada fungsi enqueue, kalau queue masih kosong, posisi head dipindah ke 0, lalu tail dinaikkan satu dan data disimpan. Kalau queue penuh, muncul pesan peringatan. Sedangkan pada dequeue, data paling depan diambil dari posisi head, lalu seluruh elemen di belakangnya digeser maju satu posisi supaya tetap rapi. Setelah itu tail diturunkan satu. Kalau setelah penghapusan ternyata queue kosong lagi, head dan tail dikembalikan ke -1. Terakhir, fungsi printInfo hanya menampilkan posisi head–tail dan isi queue saat ini.
Singkatnya, kode ini menunjukkan cara kerja queue yang mengikuti aturan FIFO, tapi dengan metode geser setiap kali ada elemen yang dikeluarkan.

Output : 

![alt text](ss/outputU1.png)

### 5.2 Unguided 2
![alt text](ss/unguided2.png)

Penjelasan : Kode ini merupakan implementasi queue sederhana yang memakai array biasa, tapi dengan cara kerja yang lebih praktis karena tidak perlu menggeser elemen saat dequeue. Saat queue dibuat lewat createQueue, nilai head dan tail diset ke -1 supaya jelas kalau antreannya masih kosong. Fungsi isEmptyQueue mengecek dua kondisi: apakah tail masih -1, atau apakah head sudah lewat tail—ini digunakan untuk mendeteksi kalau queue kosong setelah beberapa kali dequeue. Sementara itu, isFullQueue hanya mengecek apakah tail sudah mencapai batas array.
Pada fungsi enqueue, kalau queue penuh, muncul pesan antrean penuh. Kalau masih ada ruang, data baru dimasukkan ke posisi tail + 1. Kalau sebelumnya queue kosong, head otomatis di-set ke 0 lebih dulu. Untuk dequeue, data diambil dari posisi head, lalu head dinaikkan satu langkah. Kalau setelah dinaikkan ternyata head melewati tail, itu berarti queue sudah kosong lagi, jadi head dan tail dikembalikan ke -1. Terakhir, printInfo cuma menampilkan posisi head–tail dan isi queue dari head sampai tail.
Secara keseluruhan, kode ini menunjukkan queue dengan model FIFO, tapi lebih simpel karena tidak perlu menggeser elemen setiap kali menghapus data.

Output : 

![alt text](ss/outputU2.png)


### 5.3 Unguided 3
![alt text](ss/unguided3.png)

Penjelasan : Kode ini merupakan implementasi queue versi circular, jadi ujung array bisa “muter” kembali ke awal kalau sudah sampai batas. Saat queue dibuat lewat createQueue, nilai head dan tail diset ke 0. Queue dianggap kosong kalau posisi head dan tail sama, dan dianggap penuh kalau posisi tail satu langkah di depan head dalam bentuk melingkar.
Pada fungsi enqueue, kalau queue belum penuh, data dimasukkan ke posisi tail, lalu tail digeser maju satu langkah dengan rumus modulo supaya bisa muter lagi ke indeks 0 jika sudah mentok. Untuk dequeue, data diambil dari posisi head, lalu head juga digeser maju dengan cara yang sama. Tidak ada penggeseran elemen secara manual, jadi lebih efisien.
Fungsi printInfo menampilkan posisi head–tail, lalu mencetak isi queue mulai dari head sampai tail dengan cara melingkar juga, berhenti ketika indeksnya sudah bertemu tail. Secara keseluruhan, kode ini menunjukkan cara kerja circular queue yang rapi dan efisien, cocok dipakai untuk antrean dengan ukuran tetap.

Output : 

![alt text](ss/outputU3.png)

## 6. Kesimpulan
Jadi berdasarkan hasil pengerjaan program di atas, dapat saya simpulkan bahwa tujuan pembelajaran mengenai penerapan struktur data Queue (Antrian) telah berhasil dicapai. Melalui implementasi berbagai operasi seperti enqueue, dequeue, isEmpty, isFull, serta printInfo, saya mampu memahami bagaimana data dapat disimpan dan dikelola menggunakan prinsip FIFO (First In, First Out). Struktur data Queue memungkinkan pengelolaan data secara berurutan, di mana elemen yang masuk lebih dulu akan menjadi yang pertama keluar.
Selain itu, penerapan konsep circular queue memberikan efisiensi yang lebih baik karena tidak memerlukan penggeseran elemen secara manual, sehingga operasi berjalan lebih optimal. Penggunaan fungsi-fungsi terpisah juga membuat program lebih rapi, mudah dipahami, dan sesuai dengan konsep modularisasi. Dengan demikian, praktikum ini memberikan pemahaman yang baik mengenai konsep dasar dan penerapan nyata dari struktur data Queue dalam bahasa C++.

## 7. Referensi
1. Programiz. “Queue Data Structure.” https://www.programiz.com/dsa/queue
2. GeeksforGeeks. “Queue Data Structure (Introduction and Implementation).” https://www.geeksforgeeks.org/queue-data-structure/
3. W3Schools. “C++ Arrays & Functions.” https://www.w3schools.com/cpp/cpp_arrays.asp