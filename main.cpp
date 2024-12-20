#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pemesanan {
    int id;
    string nama;
    string tanggal;
};

class DaftarPemesanan {
private:
    vector<Pemesanan> pemesananList;
    int nextId;

public:
    DaftarPemesanan() : nextId(1) {}

    void tambahPemesanan(const string& nama, const string& tanggal) {
        Pemesanan pemesanan;
        pemesanan.id = nextId++;
        pemesanan.nama = nama;
        pemesanan.tanggal = tanggal;
        pemesananList.push_back(pemesanan);
        cout << "Pemesanan berhasil ditambahkan dengan ID: " << pemesanan.id << endl;
    }

    void tampilkanPemesanan() {
        if (pemesananList.empty()) {
            cout << "Tidak ada pemesanan." << endl;
            return;
        }
        cout << "Daftar Pemesanan:" << endl;
        for (const auto& pemesanan : pemesananList) {
            cout << "ID: " << pemesanan.id << ", Nama: " << pemesanan.nama << ", Tanggal: " << pemesanan.tanggal << endl;
        }
    }

    void hapusPemesanan(int id) {
        for (auto it = pemesananList.begin(); it != pemesananList.end(); ++it) {
            if (it->id == id) {
                pemesananList.erase(it);
                cout << "Pemesanan dengan ID " << id << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Pemesanan dengan ID " << id << " tidak ditemukan." << endl;
    }
};

int main() {
    DaftarPemesanan daftar;
    int pilihan;
    string nama, tanggal;
    int id;

    do {
        cout << "\nMenu Aplikasi Daftar Pemesanan" << endl;
        cout << "1. Tambah Pemesanan" << endl;
        cout << "2. Tampilkan Pemesanan" << endl;
        cout << "3. Hapus Pemesanan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Pemesan: ";
                cin.ignore(); // Membersihkan newline dari buffer
                getline(cin, nama);
                cout << "Masukkan Tanggal Pemesanan: ";
                getline(cin, tanggal);
                daftar.tambahPemesanan(nama, tanggal);
                break;
            case 2:
                daftar.tampilkanPemesanan();
                break;
            case 3:
                cout << "Masukkan ID Pemesanan yang ingin dihapus: ";
                cin >> id;
                daftar.hapusPemesanan(id);
                break;
            case 4:
                cout << "Keluar dari aplikasi." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}