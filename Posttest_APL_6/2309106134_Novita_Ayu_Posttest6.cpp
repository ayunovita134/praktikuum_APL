#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 
using namespace std;

const int MAX_NARAPIDANA = 3;
const int MAX_LOGIN_ATTEMPTS = 3;

struct Narapidana {
  string nama;
  string nomor_identifikasi;
  string jenis_kejahatan;
  string tanggal_masuk_penjara;
  string jangka_waktu_hukuman;
  string status_kesehatan;
};

struct DataNarapidana {
  int jumlah_narapidana = 0 ; 
  Narapidana* narapidana[MAX_NARAPIDANA];
};

DataNarapidana data_narapidana;

bool isEmpty() {
  return data_narapidana.jumlah_narapidana == 0;
}

bool login() {
  int i = 0;
  string nama, NIM;

  while (i < MAX_LOGIN_ATTEMPTS) {
    cout << "Masukkan nama: ";
    getline(cin, nama); 
    cout << "Masukkan NIM: ";
    getline(cin, NIM); 

    if (nama.empty() || NIM.empty()) { 
      cout << "Nama dan NIM tidak boleh kosong!" << endl;
      continue;
    }

    if (nama == "Novita" && NIM == "2309106134") {
      cout << "Selamat, login berhasil!" << endl;
      return true;
    } else {
      int remainingAttempts = MAX_LOGIN_ATTEMPTS - i - 1;
      if (remainingAttempts > 0) {
        cout << "Maaf, login gagal. Nama atau NIM salah." << endl;
        cout << "Anda memiliki " << remainingAttempts << " kesempatan login tersisa." << endl;
      } else {
        cout << "Maaf, login gagal. Batas percobaan login tercapai." << endl;
        return false;
      }
      i++;
    }
  }

  return false;
}

bool isEmpty(); 
bool login(); 

void add(Narapidana* &ptrNarapidana) {
  char loop;
  do {
  	system ("cls") ;
    if (data_narapidana.jumlah_narapidana < MAX_NARAPIDANA) {
      Narapidana* ptrNarapidana = new Narapidana;

      cout << "Masukkan nama narapidana: ";
      getline(cin, ptrNarapidana->nama);
      cout << "Masukkan nomor identifikasi narapidana: ";
      getline(cin, ptrNarapidana->nomor_identifikasi);
      cout << "Masukkan jenis kejahatan: ";
      getline(cin, ptrNarapidana->jenis_kejahatan);
      cout << "Masukkan tanggal masuk penjara: ";
      getline(cin, ptrNarapidana->tanggal_masuk_penjara);
      cout << "Masukkan jangka waktu hukuman: ";
      getline(cin, ptrNarapidana->jangka_waktu_hukuman);
      cout << "Masukkan status kesehatan: ";
      getline(cin, ptrNarapidana->status_kesehatan);

      data_narapidana.narapidana[data_narapidana.jumlah_narapidana++] = ptrNarapidana;
    } else {
      cout << "===DATA NARAPIDANA SUDAH PENUH===" << endl;
    }

    cout << "Tambahkan data narapidana lain (y/t): ";
    cin >> loop;
    cin.ignore(); 
    system ("cls") ;
  } while (loop == 'y');
}

void display() {
  if (!isEmpty()) {
    for (int i = 0; i < data_narapidana.jumlah_narapidana; ++i) {
      cout << "== Data Narapidana " << i + 1 << " ==" << endl;
      cout << "Nama: " << data_narapidana.narapidana[i]->nama << endl;
      cout << "Nomor Identifikasi: " << data_narapidana.narapidana[i]->nomor_identifikasi << endl;
      cout << "Jenis Kejahatan: " << data_narapidana.narapidana[i]->jenis_kejahatan << endl;
      cout << "Tanggal Masuk Penjara: " << data_narapidana.narapidana[i]->tanggal_masuk_penjara << endl;
      cout << "Jangka Waktu Hukuman: " << data_narapidana.narapidana[i]->jangka_waktu_hukuman << endl;
      cout << "Status Kesehatan: " << data_narapidana.narapidana[i]->status_kesehatan << endl;
    }
  } else {
    cout << "===DATA NARAPIDANA KOSONG===" << endl;
  }
}

void edit() {
  if (!isEmpty()) {
    char loop;
    do {
      system("cls");
      int index;
      bool found = false;

      cout << "Masukkan nomor narapidana yang ingin diubah: ";
      cin >> index;

      if (index > 0 && index <= data_narapidana.jumlah_narapidana) {
        index--; 

        Narapidana* ptrNarapidana = data_narapidana.narapidana[index];

        cin.ignore(); 
        cout << "Masukkan nama baru : ";
        getline(cin, ptrNarapidana->nama);
        cout << "Masukkan nomor identifikasi baru : ";
        getline(cin, ptrNarapidana->nomor_identifikasi);
        cout << "Masukkan jenis kejahatan baru : ";
        getline(cin, ptrNarapidana->jenis_kejahatan);
        cout << "Masukkan tanggal masuk penjara baru : ";
        getline(cin, ptrNarapidana->tanggal_masuk_penjara);
        cout << "Masukkan jangka waktu hukuman baru : ";
        getline(cin, ptrNarapidana->jangka_waktu_hukuman);
        cout << "Masukkan status kesehatan baru : ";
        getline(cin, ptrNarapidana->status_kesehatan);

        cout << "==Data narapidana berhasil diubah==" << endl;
        found = true;
      } else {
        cout << "Nomor narapidana tidak ditemukan." << endl;
      }

      cout << "Ubah data narapidana lain (y/t): ";
      cin >> loop;
    } while (loop == 'y');
  } else {
    system("cls");
    cout << "===Data Narapidana kosong===" << endl;
  }
}
    
void del() {
  if (!isEmpty()) {
    char loop;
    do {
      int index;
      bool found = false;

      cout << "Masukkan nomor narapidana yang ingin dihapus: ";
      cin >> index;

      if (index > 0 && index <= data_narapidana.jumlah_narapidana) {
        index--; 

        delete data_narapidana.narapidana[index];

        for (int i = index; i < data_narapidana.jumlah_narapidana - 1; ++i) {
          data_narapidana.narapidana[i] = data_narapidana.narapidana[i + 1];
        }

        data_narapidana.jumlah_narapidana--;

        cout << "===Data narapidana berhasil dihapus===" << endl;
        found = true;
      } else {
        cout << "Nomor narapidana tidak ditemukan." << endl;
      }

      cout << "Hapus data narapidana lain (y/t): ";
      cin >> loop;
    } while (loop == 'y');
  } else {
    system("cls");
    cout << "===DATA NARAPIDANA KOSONG===" << endl;
  }
}

void sortByNameDescending() {
  if (!isEmpty()) {
    for (int i = 0; i < data_narapidana.jumlah_narapidana - 1; ++i) {
      for (int j = 0; j < data_narapidana.jumlah_narapidana - i - 1; ++j) {
        if (data_narapidana.narapidana[j]->nama < data_narapidana.narapidana[j + 1]->nama) {
          Narapidana* temp = data_narapidana.narapidana[j];
          data_narapidana.narapidana[j] = data_narapidana.narapidana[j + 1];
          data_narapidana.narapidana[j + 1] = temp;
        }
      }
    }
    cout << "===Data narapidana berhasil diurutkan berdasarkan nama secara descending===" << endl;
  } else {
    cout << "===DATA NARAPIDANA KOSONG===" << endl;
  }
}

void sortByDurationAscending() {
  if (!isEmpty()) {
    for (int i = 0; i < data_narapidana.jumlah_narapidana - 1; ++i) {
      for (int j = 0; j < data_narapidana.jumlah_narapidana - i - 1; ++j) {
        std::stringstream ss1(data_narapidana.narapidana[j]->jangka_waktu_hukuman);
        std::stringstream ss2(data_narapidana.narapidana[j + 1]->jangka_waktu_hukuman);
        int waktu1, waktu2;
        ss1 >> waktu1;
        ss2 >> waktu2;

        if (waktu1 > waktu2) {
          Narapidana* temp = data_narapidana.narapidana[j];
          data_narapidana.narapidana[j] = data_narapidana.narapidana[j + 1];
          data_narapidana.narapidana[j + 1] = temp;
        }
      }
    }
    cout << "===Data narapidana berhasil diurutkan berdasarkan jangka waktu hukuman secara ascending===" << endl;
  } else {
    cout << "===DATA NARAPIDANA KOSONG===" << endl;
  }
}

void searchByIdentificationNumberAscending() {
  if (!isEmpty()) {
    string searchNumber;
    cout << "Masukkan nomor identifikasi narapidana yang ingin dicari: ";
    cin >> searchNumber;
    cin.ignore(); 

    bool found = false;
    for (int i = 0; i < data_narapidana.jumlah_narapidana; ++i) {
      if (data_narapidana.narapidana[i]->nomor_identifikasi == searchNumber) {
        cout << "== Data Narapidana Ditemukan ==" << endl;
        cout << "Nama: " << data_narapidana.narapidana[i]->nama << endl;
        cout << "Nomor Identifikasi: " << data_narapidana.narapidana[i]->nomor_identifikasi << endl;
        cout << "Jenis Kejahatan: " << data_narapidana.narapidana[i]->jenis_kejahatan << endl;
        cout << "Tanggal Masuk Penjara: " << data_narapidana.narapidana[i]->tanggal_masuk_penjara << endl;
        cout << "Jangka Waktu Hukuman: " << data_narapidana.narapidana[i]->jangka_waktu_hukuman << endl;
        cout << "Status Kesehatan: " << data_narapidana.narapidana[i]->status_kesehatan << endl;
        found = true;
        break; 
      }
    }

    if (!found) {
      cout << "Data narapidana dengan nomor identifikasi tersebut tidak ditemukan." << endl;
    }
  } else {
    cout << "==DATA NARAPIDANA KOSONG==" << endl;
  }
}


void searchByCrimeDescending() {
  if (!isEmpty()) {
    string searchCrime;
    cout << "Masukkan jenis kejahatan narapidana yang ingin dicari: ";
    cin >> searchCrime;
    cin.ignore(); 

    bool found = false;
    for (int i = data_narapidana.jumlah_narapidana - 1; i >= 0; --i) {
      if (data_narapidana.narapidana[i]->jenis_kejahatan == searchCrime) {
        cout << "== Data Narapidana Ditemukan ==" << endl;
        cout << "Nama: " << data_narapidana.narapidana[i]->nama << endl;
        cout << "Nomor Identifikasi: " << data_narapidana.narapidana[i]->nomor_identifikasi << endl;
        cout << "Jenis Kejahatan: " << data_narapidana.narapidana[i]->jenis_kejahatan << endl;
        cout << "Tanggal Masuk Penjara: " << data_narapidana.narapidana[i]->tanggal_masuk_penjara << endl;
        cout << "Jangka Waktu Hukuman: " << data_narapidana.narapidana[i]->jangka_waktu_hukuman << endl;
        cout << "Status Kesehatan: " << data_narapidana.narapidana[i]->status_kesehatan << endl;
        found = true;
        break; 
      }
    }

    if (!found) {
      cout << "Data narapidana dengan jenis kejahatan tersebut tidak ditemukan." << endl;
    }
  } else {
    cout << "==DATA NARAPIDANA KOSONG==" << endl;
  }
}

int main() {
  bool isLoggedIn = false;
  while (!isLoggedIn) {
    isLoggedIn = login();
  }

  do {
    system("cls");
    cout << "======= SISTEM INFORMASI DATA NARAPIDANA =======\n";
    cout << "1. Tambah Data Narapidana\n";
    cout << "2. Tampilkan Data Narapidana\n";
    cout << "3. Ubah Data Narapidana\n";
    cout << "4. Hapus Data Narapidana\n";
    cout << "5. Urutkan Data Narapidana Berdasarkan Nama Secara Descending\n";
    cout << "6. Urutkan Data Narapidana Berdasarkan Jangka Waktu Hukuman Secara Ascending\n";
    cout << "7. Cari Data Narapidana Berdasarkan Nomor Identifikasi Secara Ascending\n";
    cout << "8. Cari Data Narapidana Berdasarkan Jenis Kejahatan Secara Descending\n";
    cout << "9. Keluar\n";
    cout << "===================================================\n";
    cout << "Pilihan: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
      case 1:
        add(data_narapidana.narapidana[data_narapidana.jumlah_narapidana]);
        break;
      case 2:
        display();
        break;
      case 3:
        edit();
        break;
      case 4:
        del();
        break;
      case 5:
        sortByNameDescending();
        break;
      case 6:
        sortByDurationAscending();
        break;
      case 7:
        searchByIdentificationNumberAscending();
        break;
      case 8:
        searchByCrimeDescending();
        break;
      case 9:
        cout << "===Keluar dari program===" << endl;
        break;
      default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }

    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get(); 
  } while (true);

  return 0;
}

