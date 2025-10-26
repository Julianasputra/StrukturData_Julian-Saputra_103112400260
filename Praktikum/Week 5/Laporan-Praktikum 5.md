# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Julian Saputra
- **NIM**: 103112400260
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
Saya sangat termotivasi memperlajari struktur data, kenapa saya belajat stuktur data karena saya sadar kalau struktur data itu pondasi yang sangat penting dalam pemrograman contohnya seperti kita akan membangun rumah yang membutuhkan pondasi. Lalu juga banyak aplikasi atau teknologi di dunia nyata contohnya kaya sistem pencarian, manajemen database, sampai ada juga kecerdasan buatan yang bekerja secara efisien dikarenakan menggunakan struktur data yang tepat dan baik. Jadi karena itu saya termotivasi belajar struktur data ini.

## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Dalam konteks mata kuliah Struktur Data, salah satu struktur yang penting dan sering digunakan adalah Linked List, khususnya Double Linked List (DLL). Struktur ini digunakan ketika diperlukan penyimpanan data yang dinamis, fleksibel, dan mudah dimodifikasi (seperti penambahan atau penghapusan elemen di tengah daftar).

### Berikut teori dasar yang berkaitan dengan soal dan program yang telah dibuat:

Konsep Double Linked List (DLL):
Double Linked List merupakan bentuk lanjutan dari Single Linked List, di mana setiap elemen (node) memiliki dua pointer: satu menunjuk ke elemen sebelumnya (prev) dan satu menunjuk ke elemen berikutnya (next). Dengan dua arah ini, proses penelusuran dapat dilakukan maju (forward) maupun mundur (backward). DLL memudahkan operasi seperti penyisipan dan penghapusan elemen di berbagai posisi (awal, tengah, atau akhir) tanpa perlu menggeser elemen lain seperti pada array.

Konsep Pointer dalam Linked List:
Pointer adalah variabel khusus yang menyimpan alamat memori dari variabel lain. Dalam DLL, pointer digunakan untuk menghubungkan antar-node. Contohnya, P->next menunjuk ke node berikutnya, sedangkan P->prev menunjuk ke node sebelumnya. Pemahaman pointer sangat penting karena kesalahan dalam pengaturan next atau prev dapat menyebabkan kehilangan data (memory leak) atau crash program.

Konsep Fungsi smartInsert:
Fungsi ini merupakan bentuk insertion dengan logika kondisional yang kompleks, di mana data baru tidak hanya ditambahkan di awal atau akhir, tetapi juga disisipkan berdasarkan aturan tertentu (misalnya ganjil/genap, nilai lebih besar/kecil, atau posisi tertentu di antara dua nilai). Fungsi ini menggunakan if–else bertingkat untuk menangani berbagai kondisi, termasuk ketika list kosong atau saat elemen baru harus berada di antara dua node tertentu. Konsep ini menunjukkan penerapan logika pemrograman dan kontrol alur (flow control) pada struktur data dinamis.

Konsep Fungsi conditionalDelete:
Fungsi ini digunakan untuk menghapus elemen dalam list berdasarkan kondisi tertentu (misalnya, menghapus semua angka ganjil, semua angka genap, atau elemen yang memenuhi kriteria khusus). Prosesnya melibatkan penelusuran seluruh node dan pemeriksaan kondisi setiap elemen dengan if–else. Jika elemen memenuhi syarat, maka node tersebut dihapus dan pointer diatur ulang agar hubungan antar-node tetap konsisten. Fungsi ini juga menunjukkan penerapan algoritma traversing dan manajemen memori dinamis.

Konsep Traversal (Penelusuran Data):
Traversal adalah proses mengunjungi setiap node dalam linked list untuk menampilkan, mencari, atau memodifikasi data. Dalam DLL, traversal dapat dilakukan dari depan ke belakang (forward) maupun dari belakang ke depan (backward), berkat adanya dua pointer (next dan prev). Proses ini sering digunakan dalam menampilkan hasil seperti "Forward: 3 5 7 8 6 4" dan "Backward: 4 6 8 7 5 3".

Konsep Fungsi dan Modularisasi Program:
Fungsi seperti insertFirst, insertLast, smartInsert, dan conditionalDelete dibuat agar program lebih modular dan mudah dipahami. Dengan memisahkan setiap operasi ke dalam fungsi tersendiri, kode menjadi lebih rapi, mudah diuji, serta bisa digunakan kembali (reusable). Pendekatan modular ini juga mendukung prinsip abstraksi, di mana setiap fungsi memiliki tanggung jawab yang jelas.

## 4. Guided
### 4.1 Guided 1
![alt text](ss/guided1.png)

Penjelasan :
Program ini digunakan untuk mencatat jumlah buku yang dibaca setiap hari selama satu minggu dan menghitung totalnya. Data jumlah buku disimpan dalam array, kemudian ditampilkan satu per satu menggunakan perulangan for. Setiap nilai juga dijumlahkan ke dalam variabel TotalBuku. Setelah selesai, program menampilkan total buku yang berhasil dibaca dalam seminggu. Program ini sederhana namun efektif untuk membuat laporan baca buku mingguan secara otomatis.

Output :

![alt text](ss/outputG1.png)

### 4.2 Guided 2
![alt text](ss/guided2.png)

Penjelasan : Program ini digunakan untuk menunjukkan cara berkerja pointer. Variabel 'hargaproduk' menyimpan harga awal yaitu '50000', lalu pointer 'ptrHarga' digunakan untuk menyimpan alamat memori dari variabel tersebut. Program menampilkan harga awal dan alamat memorinya, kemudian memberikan diskon 10% melalui pointer. Karena pointer terhubung langsung ke variabel 'hargaproduk', nilainya otomatis berubah. Terakhir, program menampilkan harga setelah diberi diskon.

Output : 

![alt text](ss/ouputG2.png)

## 5. Unguided
### 5.1 Unguided 1
![alt text](ss/Unguided1.png)

Penjelasan : Program ini digunakan untuk mengelola data stok beberapa jenis buku, menghitung total stok, mencari stok yang paling sedikit, dan menambahkan bonus stok secara otomatis. Data stok disimpan dalam array bernama stokBuku yang berisi lima angka, yaitu {12, 8, 25, 5, 18}. Untuk menampilkan seluruh stok, program menggunakan prosedur cetakStok(), sehingga semua nilai dalam array dapat ditampilkan dengan rapi. Setelah itu, fungsi hitungTotalStok() digunakan untuk menjumlahkan seluruh stok buku. Kemudian, program mencari buku dengan stok paling sedikit menggunakan fungsi cariStokPalingSedikit(), yang mengembalikan pointer ke elemen dengan nilai terkecil. Pointer tersebut dikirim ke prosedur tambahStokBonus(), yang menambahkan bonus sebesar 10 ke stok buku tersebut melalui alamat memorinya, sehingga nilai aslinya langsung berubah. Terakhir, stok buku ditampilkan kembali untuk menunjukkan perubahan setelah bonus diberikan.

Output : 

![alt text](ss/outputU1.png)

### 5.2 Unguided 2
![alt text](ss/Unguided2.png)

Penjelasan : Program ini digunakan untuk mengelola data stok beberapa jenis buku, menghitung total stok, mencari stok yang paling sedikit, dan menambahkan bonus stok secara otomatis. Data stok disimpan dalam array bernama stokBuku yang berisi lima angka, yaitu {12, 8, 25, 5, 18}. Untuk menampilkan seluruh stok, program menggunakan prosedur cetakStok(), sehingga semua nilai dalam array dapat ditampilkan dengan rapi. Setelah itu, fungsi hitungTotalStok() digunakan untuk menjumlahkan seluruh stok buku. Kemudian, program mencari buku dengan stok paling sedikit menggunakan fungsi cariStokPalingSedikit(), yang mengembalikan pointer ke elemen dengan nilai terkecil. Pointer tersebut dikirim ke prosedur tambahStokBonus(), yang menambahkan bonus sebesar 10 ke stok buku tersebut melalui alamat memorinya, sehingga nilai aslinya langsung berubah. Terakhir, stok buku ditampilkan kembali untuk menunjukkan perubahan setelah bonus diberikan.

Output : 

![alt text](ss/outputU1.png)


### 5.3 Unguided 3
![alt text](ss/Unguided3.png)

Penjelasan : Program ini digunakan untuk mengelola data stok beberapa jenis buku, menghitung total stok, mencari stok yang paling sedikit, dan menambahkan bonus stok secara otomatis. Data stok disimpan dalam array bernama stokBuku yang berisi lima angka, yaitu {12, 8, 25, 5, 18}. Untuk menampilkan seluruh stok, program menggunakan prosedur cetakStok(), sehingga semua nilai dalam array dapat ditampilkan dengan rapi. Setelah itu, fungsi hitungTotalStok() digunakan untuk menjumlahkan seluruh stok buku. Kemudian, program mencari buku dengan stok paling sedikit menggunakan fungsi cariStokPalingSedikit(), yang mengembalikan pointer ke elemen dengan nilai terkecil. Pointer tersebut dikirim ke prosedur tambahStokBonus(), yang menambahkan bonus sebesar 10 ke stok buku tersebut melalui alamat memorinya, sehingga nilai aslinya langsung berubah. Terakhir, stok buku ditampilkan kembali untuk menunjukkan perubahan setelah bonus diberikan.

Output : 

![alt text](ss/outputU1.png)

## 6. Kesimpulan
Jadi berdasarkan seluruh rangkaian praktikum yang telah dilakukan, saya dapat menyimpulkan bahwa tujuan pembelajaran terkait struktur dasar pemrograman berhasil dicapai, khususnya dalam memahami penggunaan array, fungsi/prosedur, serta pointer di dalam bahasa C++. Melalui latihan yang diberikan, saya memahami bahwa array merupakan cara yang efisien untuk menyimpan banyak data sejenis dalam satu variabel, sehingga pengolahan data menjadi lebih terstruktur dan mudah dikelola. Penggunaan fungsi dan prosedur juga membantu saya menyusun program dengan lebih rapi, karena setiap tugas dapat dipisahkan ke dalam blok kode khusus sehingga mengurangi penulisan berulang dan mempermudah pemeliharaan program.

## 7. Referensi
1. GeeksforGeeks. “C++ Programming Language.” https://www.geeksforgeeks.org/c-plus-plus/
2. Tutorialspoint. “C++ Programming Language.” https://www.tutorialspoint.com/cplusplus/
3. W3Schools. “C++ Tutorial.” https://www.w3schools.com/cpp/