#include <iostream>

using namespace std;

int main(){
    double total_pembelian, diskon;
    cout<<"berapa kamu belanja : Rp. ";
    cin>>total_pembelian;
    if(total_pembelian > 30000){
        diskon = 0.1 * total_pembelian;
        cout<<"kamu dapat diskon sebesar " << diskon << " orang kaya lu ri";
    }else {
        cout<<"kamu belajanya masih dikit, tambah lah biar enyong kaya";
    }
    return 0;
}