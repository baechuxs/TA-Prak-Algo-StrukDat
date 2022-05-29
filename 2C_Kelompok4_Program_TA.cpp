#include <iostream>
#include <cstdlib>

using namespace std;

struct{
    int kode;
    string nama;
} barang;

int q[5];
string n[5];
int front = 0;
int rear = -1;

main(){
    int p = 0;
    void enqueue();
    void dequeue();
    void garis();
    void display();
    
    while (p < 4)
    {
        system("cls");
        cout << "Antrian Pengiriman Barang\n";
        garis();
        cout << "Menu Pilihan\n";
        cout << "1. Menambahkan antrian barang (enqueue)\n";
        cout << "2. Menghapus antrian barang (dequeue)\n";
        cout << "3. Menampilkan isi antrian barang\n";
        cout << "4. Selesai\n";
        garis();
        cout << "Masukan pilihan yang terdapat di menu: ";
        cin >> p;

        switch(p)
        {
            case 1: system("cls");
                cout << "Menambahkan antrian barang (enqueue)\n";
                enqueue();
                break;
            case 2: system("cls");
                cout << "Menghapus antrian barang (dequeue)\n";
                dequeue();
                break;
            case 3: system("cls");
                cout << "Menampilkan isi antrian barang\n";
                display();
                break;
            case 4: system("cls");
                exit(0);
            default: cout << "Pilihan tidak ada\n";
        } system("pause");
    }
}

void enqueue(){
    if (rear == 4){
        cout << "Antrian barang penuh\n";
    } else{
        cout << "Masukan nomor kode barang: ";
        cin >> barang.kode;
        cout << "Masukan nama barang: ";
        cin >> barang.nama;
        rear += 1;
        q[rear] = barang.kode;
        n[rear] = barang.nama;
    }
}

void dequeue(){
    if (front > rear){
        cout << "Antrian barang kosong\n";
    } else{
        cout << "\nKode barang: " << q[front] << "\n";
        cout << "Nama barang: " << n[front] << "\n";
        cout << "Antrian dihapus\n";
        for (int i = 0; i <= rear; i++){
            q[i] = q[i+1];
            n[i] = n[i+1];
        }
        rear -= 1;
    }
}

void garis(){
  cout << "----------------------" << endl;
}

void display(){
    int i;

    if (front > rear){
        cout << "Antrian barang kosong\n";
    } else{
        cout << "\nIsi antrian pengiriman barang: ";
        for (i = 0; i <= rear; i++){
            cout << "\nkode barang: " << q[i] << "\n";
            cout << "nama barang: " << n[i] << "\n";
        }
        cout << "\n\n";
    }
}