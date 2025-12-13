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

Penjelasan : Kode ini adalah header file ADT Graph yang menggunakan representasi adjacency list. Graph terdiri dari kumpulan node dan edge yang menunjukkan hubungan antar node. Setiap node disimpan dalam list utama dan memiliki list edge sendiri yang menunjuk ke node lain yang terhubung.
Struktur ElmNode menyimpan informasi node, penanda visited untuk keperluan DFS dan BFS, pointer ke edge pertama, serta pointer ke node berikutnya. Struktur ElmEdge digunakan untuk menyimpan hubungan antar node, sedangkan struktur Graph menyimpan pointer ke node pertama dalam graph.
Header ini menyediakan fungsi dasar seperti pembuatan graph, penambahan node, penghubungan node (berarah dan tidak berarah), serta fungsi untuk menampilkan isi graph. Selain itu, tersedia juga fungsi DFS dan BFS untuk menelusuri graph, serta fungsi resetVisited untuk mengatur ulang status kunjungan node. Dengan demikian, file ini menjadi dasar untuk membangun dan mengelola struktur data graph.

### 4.2 Guided 2
![alt text](ss/guided2.png)

Penjelasan : Kode ini adalah implementasi operasi edge pada ADT Graph yang menggunakan representasi adjacency list. Graph disusun dari kumpulan node, di mana setiap node dapat terhubung dengan node lain melalui edge.
Fungsi findNode digunakan untuk mencari node tertentu di dalam graph berdasarkan nilai informasinya. Fungsi connectNode berfungsi untuk menghubungkan dua node secara berarah, yaitu dari node awal ke node tujuan dengan menambahkan edge ke dalam list edge milik node awal. Penambahan edge dilakukan di bagian akhir adjacency list agar urutan hubungan sesuai dengan urutan input.
Selain itu, fungsi connectNodeUndirected digunakan untuk membentuk graph tidak berarah, yaitu dengan menambahkan dua edge sekaligus sehingga kedua node saling terhubung. Dengan demikian, kode ini menyediakan mekanisme dasar untuk membangun hubungan antar node pada graph, baik berarah maupun tidak berarah.

### 4.3 Guided 3
![alt text](ss/guided3.png)

Penjelasan : Kode ini adalah implementasi operasi dasar pada ADT Graph yang berkaitan dengan pembuatan dan pengelolaan node. Fungsi createGraph digunakan untuk menginisialisasi graph agar berada dalam kondisi kosong dengan mengatur pointer awal bernilai NULL. Fungsi allocateNode berfungsi untuk membuat node baru dengan mengisi data, mengatur status visited menjadi false, serta menginisialisasi pointer edge dan pointer ke node berikutnya.
Fungsi insertNode digunakan untuk menambahkan node baru ke dalam graph. Node disisipkan ke bagian akhir list node sehingga urutan node sesuai dengan urutan penambahan. Dengan demikian, kode ini menyediakan fungsi dasar untuk membangun struktur graph sebelum node-node tersebut dihubungkan dengan edge.

### 4.4 Guided 4
![alt text](ss/guided4.png)

Penjelasan : Kode ini adalah fungsi-fungsi untuk menampilkan dan menelusuri ADT Graph menggunakan representasi adjacency list. Fungsi printGraph digunakan untuk menampilkan seluruh node beserta hubungan edge yang dimilikinya. Setiap node ditampilkan bersama daftar node lain yang terhubung dengannya.
Fungsi printDFS digunakan untuk melakukan penelusuran graph dengan metode Depth First Search (DFS), yaitu menelusuri node secara mendalam dari satu node ke node lain yang belum dikunjungi. Fungsi printBFS digunakan untuk melakukan penelusuran graph dengan metode Breadth First Search (BFS) menggunakan struktur data queue, sehingga penelusuran dilakukan secara melebar per level.
Selain itu, fungsi resetVisited digunakan untuk mengatur ulang status kunjungan (visited) pada seluruh node agar proses DFS atau BFS dapat dijalankan kembali. Dengan demikian, kode ini menyediakan operasi penelusuran dan penampilan graph secara lengkap dan terstruktur.

### 4.5 Guided 5
![alt text](ss/guided5.png)

Penjelasan : Kode ini adalah program utama (main) yang digunakan untuk menguji implementasi ADT Graph. Pada awal program, graph dibuat dan diinisialisasi agar dalam keadaan kosong. Selanjutnya, beberapa node dimasukkan ke dalam graph, yaitu node A, B, C, dan D.
Setelah node berhasil ditambahkan, program menghubungkan node-node tersebut menggunakan fungsi connectNode sehingga terbentuk hubungan antar node sesuai dengan struktur graph berarah. Terakhir, fungsi printGraph digunakan untuk menampilkan isi graph beserta hubungan antar node ke layar. Dengan demikian, program ini berfungsi sebagai contoh penggunaan ADT Graph untuk membangun dan menampilkan struktur graph sederhana.

Output : 

![alt text](ss/outputG5.png)

## 5. Unguided
### 5.1 Unguided 1
![alt text](ss/unguided1.png)

Penjelasan : Kode ini adalah program utama yang digunakan untuk membangun dan menampilkan graph tidak berarah menggunakan ADT Graph. Program diawali dengan pembuatan graph kosong, kemudian menambahkan node A sampai H ke dalam graph.
Setelah itu, setiap node dihubungkan menggunakan fungsi connectNodeUndirected, sehingga hubungan antar node bersifat dua arah. Hubungan tersebut disusun sesuai dengan soal, di mana node A terhubung ke B dan C, node B dan C memiliki cabang masing-masing, dan semua jalur akhirnya terhubung ke node H.
Terakhir, fungsi printGraph digunakan untuk menampilkan seluruh isi graph beserta hubungan antar node ke layar. Dengan demikian, program ini berfungsi untuk menguji dan memperlihatkan struktur graph tidak berarah yang telah dibangun.

Output : 

![alt text](ss/outputU1.png)

### 5.2 Unguided 2
![alt text](ss/unguided2.png)

Penjelasan : Kode ini adalah program utama yang digunakan untuk membangun graph tidak berarah dan melakukan penelusuran Depth First Search (DFS). Program dimulai dengan membuat graph kosong, lalu menambahkan node A sampai H ke dalam graph.
Setelah semua node dibuat, hubungan antar node dibentuk menggunakan fungsi connectNodeUndirected sehingga setiap sisi berlaku dua arah sesuai dengan struktur graph pada soal. Sebelum melakukan DFS, fungsi resetVisited dipanggil untuk memastikan seluruh node berada dalam kondisi belum dikunjungi.
Proses DFS dimulai dari node A dengan memanggil fungsi printDFS, yang akan menelusuri graph secara mendalam dari satu cabang ke cabang lainnya dan menampilkan urutan kunjungan node ke layar. Dengan demikian, program ini berfungsi untuk membangun graph dan menampilkan hasil penelusuran DFS dari node awal.

Output : 

![alt text](ss/outputU2.png)

### 5.3 Unguided 3
![alt text](ss/unguided3.png)

Penjelasan : Kode ini adalah program utama yang digunakan untuk membangun graph tidak berarah dan melakukan penelusuran Breadth First Search (BFS). Program diawali dengan membuat graph kosong, kemudian menambahkan node A sampai H ke dalam graph.
Selanjutnya, hubungan antar node dibentuk menggunakan fungsi connectNodeUndirected sehingga setiap sisi bersifat dua arah sesuai dengan struktur graph pada soal. Setelah graph terbentuk, fungsi resetVisited dipanggil untuk mengatur ulang status kunjungan semua node agar BFS dapat berjalan dengan benar.
Proses BFS dimulai dari node A dengan memanggil fungsi printBFS. Penelusuran dilakukan secara melebar, yaitu mengunjungi semua node yang bertetangga terlebih dahulu sebelum berpindah ke level berikutnya, lalu hasil urutan kunjungan node ditampilkan ke layar. Dengan demikian, program ini berfungsi untuk menampilkan hasil penelusuran BFS pada graph yang telah dibuat.

Output : 

![alt text](ss/outputU3.png)


## 6. Kesimpulan
Jadi berdasarkan pemahaman dan implementasi struktur data pada program di atas, dapat disimpulkan bahwa tujuan pembelajaran mengenai penerapan Circular Linked List telah berhasil dicapai. Melalui berbagai operasi seperti insertFirst, insertLast, insertAfter, deleteFirst, deleteLast, deleteAfter, serta findElm, saya mampu memahami bagaimana sebuah list dapat dikelola secara dinamis menggunakan pointer.
Circular Linked List memiliki karakteristik khusus, yaitu node terakhir selalu menunjuk kembali ke node pertama, sehingga membentuk struktur melingkar. Konsep ini memberikan keuntungan berupa kemudahan traversal tanpa titik akhir serta efisiensi dalam operasi penyisipan dan penghapusan, karena tidak memerlukan pergeseran elemen seperti pada struktur data berbasis array.
Selain itu, penggunaan fungsi-fungsi terpisah pada header membuat program lebih terstruktur, mudah dipahami, dan sesuai dengan prinsip modularisasi dalam pemrograman. Dengan demikian, praktikum ini memberikan pemahaman yang kuat mengenai konsep dasar, operasi fundamental, dan penerapan nyata dari Circular Linked List dalam bahasa C++.

## 7. Referensi
1. Programiz. “Circular Linked List – Insertion and Deletion.” (https://www.programiz.com/dsa/circular-linked-list)
2. GeeksforGeeks. “Circular Linked List | Set 1 (Introduction and Traversal).” (https://www.geeksforgeeks.org/circular-linked-list/)
3. W3Schools. “C++ Pointers.” (https://www.w3schools.com/cpp/cpp_pointers.asp)
4. Tutorialspoint. “C++ – Linked Lists.” (https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)
5. J. Glenn Brookshear, Dennis Brylow. Computer Science: An Overview. Pearson – Bab Struktur Data (Linked List).