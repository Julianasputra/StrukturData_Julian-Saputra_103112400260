#include <iostream>

using namespace std;

int main(){
    float hargaproduk = 50000.0f;
    float* ptrHarga;
    ptrHarga = &hargaproduk;

    cout << "harga awal produk : Rp." << hargaproduk << endl;
    cout << "alamat memori harga : " << ptrHarga << endl;

    cout << "\n...memberikan diskon 10% melalui pointer..." << endl;
    *ptrHarga = *ptrHarga * 0.9;
    cout << "harga setelah diskon : Rp." << hargaproduk << endl;
    return 0;
}
