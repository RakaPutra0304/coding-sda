#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

struct Lagu {
    string judul;
    string penyanyi;
    string album;
};

Lagu daftarLagu[MAX];
string playlist[MAX];
int jumlahLagu = 0;
int jumlahPlaylist = 0;

// Menambahkan lagu ke database
void tambahLagu(string judul, string penyanyi, string album) {
    if (jumlahLagu < MAX) {
        daftarLagu[jumlahLagu++] = {judul, penyanyi, album};
    }
}

// Mencari lagu berdasarkan judul
void cariLagu(string keyword) {
    bool ditemukan = false;
    cout << "\nHasil pencarian lagu berjudul \"" << keyword << "\":" << endl;
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].judul.find(keyword) != string::npos) {
            cout << i + 1 << ". " << daftarLagu[i].judul << " - " << daftarLagu[i].penyanyi << " [" << daftarLagu[i].album << "]\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Lagu tidak ditemukan.\n";
    }
}

// Mencari lagu berdasarkan nama penyanyi
void cariPenyanyi(string nama) {
    bool ditemukan = false;
    cout << "\nLagu oleh penyanyi \"" << nama << "\":" << endl;
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].penyanyi.find(nama) != string::npos) {
            cout << i + 1 << ". " << daftarLagu[i].judul << " - " << daftarLagu[i].album << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Penyanyi tidak ditemukan.\n";
    }
}

// Mencari lagu berdasarkan nama album
void cariAlbum(string nama) {
    bool ditemukan = false;
    cout << "\nLagu dalam album \"" << nama << "\":" << endl;
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].album.find(nama) != string::npos) {
            cout << i + 1 << ". " << daftarLagu[i].judul << " - " << daftarLagu[i].penyanyi << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Album tidak ditemukan.\n";
    }
}

// Menambahkan lagu ke playlist
void tambahKePlaylist(string judul) {
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].judul == judul) {
            playlist[jumlahPlaylist++] = judul;
            cout << "Lagu \"" << judul << "\" telah ditambahkan ke playlist.\n";
            return;
        }
    }
    cout << "Lagu tidak ditemukan.\n";
}

// Menampilkan isi playlist
void tampilkanPlaylist() {
    cout << "\nIsi Playlist:\n";
    if (jumlahPlaylist == 0) {
        cout << "(Kosong)\n";
    } else {
        for (int i = 0; i < jumlahPlaylist; i++) {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
    }
}

int main() {
    // Data awal
    tambahLagu("Cicak di dinding", "A.T Mahmud", "Lagu Anak-anak");
    tambahLagu("Pretty Litte Baby", "Connie Francis", "Connie Francis");
    tambahLagu("Sang Surya Mars Muhammadiyah", "Djarnawi Hadikoesoemo", "Muhammadiyah");
    tambahLagu("Balonku", "Bonbon Indonesia", "Lagu Anak-anak");
	tambahLagu("Mangu", "FourTwenty", "Icikiwir");
    int pilihan;
    string input;

    do {
        cout << "\n--- MENU SPOTIFY SEDERHANA ---\n";
        cout << "1. Cari Lagu\n2. Cari Penyanyi\n3. Cari Album\n4. Tambah ke Playlist\n5. Lihat Playlist\n6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Menghindari error input getline

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul lagu: ";
                getline(cin, input);
                cariLagu(input);
                break;
            case 2:
                cout << "Masukkan nama penyanyi: ";
                getline(cin, input);
                cariPenyanyi(input);
                break;
            case 3:
                cout << "Masukkan nama album: ";
                getline(cin, input);
                cariAlbum(input);
                break;
            case 4:
                cout << "Masukkan judul lagu yang ingin ditambahkan ke playlist: ";
                getline(cin, input);
                tambahKePlaylist(input);
                break;
            case 5:
                tampilkanPlaylist();
                break;
            case 6:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}

