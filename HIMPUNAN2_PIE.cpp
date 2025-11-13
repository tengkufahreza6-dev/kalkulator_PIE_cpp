#include <iostream>
#include <string>

using namespace std;

// --- FUNGSI BARU: MENGHITUNG DAN MENCETAK RINCIAN PER ZONA ---
// Fungsi ini menghitung semua variabel turunan (termasuk rincian per zona)
// setelah variabel inti (Union dan Irisan Tiga) ditentukan.
void hitungDanCetakRinci(int total_populasi, int a, int b, int c, int ab, int ac, int bc, int abc, int union_size) {
    
    // Variabel Turunan Inti
    int hanya_dua_total;
    int hanya_satu_total;
    int tidak_memilih;

    // Variabel Rinci (6 Zona Eksklusif)
    int A_saja, B_saja, C_saja;
    int AB_saja, AC_saja, BC_saja;

    // --- 1. Perhitungan Rinci "Hanya Dua Saja" ---
    // Formula: |X n Y| - |A n B n C|
    AB_saja = ab - abc; // Hanya A dan B saja
    AC_saja = ac - abc; // Hanya A dan C saja
    BC_saja = bc - abc; // Hanya B dan C saja
    hanya_dua_total = AB_saja + AC_saja + BC_saja;
    
    // --- 2. Perhitungan Rinci "Hanya Satu Saja" ---
    // Formula: |X| - (Irisan Dua dengan Y saja + Irisan Dua dengan Z saja) - |A n B n C|
    A_saja = a - (AB_saja + AC_saja + abc);
    B_saja = b - (AB_saja + BC_saja + abc);
    C_saja = c - (AC_saja + BC_saja + abc);
    hanya_satu_total = A_saja + B_saja + C_saja;
    
    // --- 3. Perhitungan Lainnya ---
    tidak_memilih = total_populasi - union_size;

    // --- OUTPUT HASIL PERHITUNGAN RINCI ---
    cout << "\n==============================================" << endl;
    cout << "      HASIL PERHITUNGAN PIE (RINCI ZONA)" << endl;
    cout << "==============================================" << endl;
    
    // Output Nilai Inti dan Total Populasi
    cout << "TOTAL POPULASI (Semesta U):                " << total_populasi << endl;
    cout << "A. GABUNGAN (UNION |A U B U C|):           " << union_size << endl;
    cout << "B. IRISAN KETIGA-TIGANYA (|A n B n C|):  " << abc << endl;
    cout << "----------------------------------------------" << endl;

    // Output Rinci: Hanya Dua Saja
    cout << "I.  HANYA DUA SAJA (TOTAL):                " << hanya_dua_total << endl;
    cout << "    - Hanya A dan B:                       " << AB_saja << endl;
    cout << "    - Hanya A dan C:                       " << AC_saja << endl;
    cout << "    - Hanya B dan C:                       " << BC_saja << endl;

    // Output Rinci: Hanya Satu Saja
    cout << "II. HANYA SATU SAJA (TOTAL):               " << hanya_satu_total << endl;
    cout << "    - Hanya A saja:                        " << A_saja << endl;
    cout << "    - Hanya B saja:                        " << B_saja << endl;
    cout << "    - Hanya C saja:                        " << C_saja << endl;

    // Output Nilai Penutup
    cout << "----------------------------------------------" << endl;
    cout << "III. TIDAK MEMILIH SAMA SEKALI:             " << tidak_memilih << endl;
    cout << "==============================================" << endl;

    // Peringatan Konsistensi (diperluas)
    if (union_size > total_populasi || hanya_dua_total < 0 || hanya_satu_total < 0 || abc < 0 || A_saja < 0 || AB_saja < 0) {
        cout << "\n[PERINGATAN] Data tidak konsisten! Periksa input (nilai negatif pada zona). Union: " << union_size << " / Total Pop: " << total_populasi << endl;
    }
}

// --- FUNGSI UTAMA (MAIN) ---
int main() {
    // Inisialisasi variabel inti
    int total_populasi = 0;
    int a, b, c; 
    int ab, ac, bc; 
    int abc; 
    int union_size; 
    
    // Variabel untuk menyimpan pointer ke variabel yang tidak diketahui
    int* unknown_ptr = nullptr;
    string unknown_name = "";

    cout << "--- KALKULATOR PIE FLEKSIBEL UNTUK RISET (3 HIMPUNAN) ---" << endl;
    cout << "Instruksi: Masukkan angka untuk nilai yang diketahui." << endl;
    cout << "           Masukkan -1 untuk SATU variabel yang ingin dicari (UNKNOWN)." << endl;

    // --- INPUT DATA ---
    cout << "\nMasukkan Total Populasi (Semesta U): "; cin >> total_populasi;
    
    cout << "\n--- Input Himpunan Tunggal ---" << endl;
    cout << "  - A (|A|): "; cin >> a;
    if (a == -1) { unknown_ptr = &a; unknown_name = "|A|"; }
    cout << "  - B (|B|): "; cin >> b;
    if (b == -1) { unknown_ptr = &b; unknown_name = "|B|"; }
    cout << "  - C (|C|): "; cin >> c;
    if (c == -1) { unknown_ptr = &c; unknown_name = "|C|"; }

    cout << "\n--- Input Irisan Ganda ---" << endl;
    cout << "  - A n B (|A n B|): "; cin >> ab;
    if (ab == -1) { unknown_ptr = &ab; unknown_name = "|A n B|"; }
    cout << "  - A n C (|A n C|): "; cin >> ac;
    if (ac == -1) { unknown_ptr = &ac; unknown_name = "|A n C|"; }
    cout << "  - B n C (|B n C|): "; cin >> bc;
    if (bc == -1) { unknown_ptr = &bc; unknown_name = "|B n C|"; }

    cout << "\n--- Input Irisan Tiga dan Union ---" << endl;
    cout << "  - A n B n C (|A n B n C|): "; cin >> abc;
    if (abc == -1) { unknown_ptr = &abc; unknown_name = "|A n B n C|"; }
    cout << "  - A U B U C (|A U B U C|): "; cin >> union_size;
    if (union_size == -1) { unknown_ptr = &union_size; unknown_name = "|A U B U C|"; }

    // --- VALIDASI DAN LOGIKA PERHITUNGAN ---
    if (unknown_ptr == nullptr) {
        cout << "\nERROR: Anda harus menandai SATU variabel dengan -1 yang ingin dicari." << endl;
        return 1;
    }

    // Hitung SUM(1) dan SUM(2) dari yang diketahui
    int sum_tunggal_known = (a != -1 ? a : 0) + (b != -1 ? b : 0) + (c != -1 ? c : 0);
    int sum_irisan_ganda_known = (ab != -1 ? ab : 0) + (ac != -1 ? ac : 0) + (bc != -1 ? bc : 0);

    // Variabel untuk perhitungan
    int sum_tunggal_all = a + b + c; // Gunakan untuk perhitungan PIE, -1 akan menjadi 0 jika belum dicari
    int sum_irisan_ganda_all = ab + ac + bc; 

    // Penyelesaian Persamaan
    if (unknown_name == "|A U B U C|") {
        *unknown_ptr = sum_tunggal_all - sum_irisan_ganda_all + abc;
        union_size = *unknown_ptr; 

    } else if (unknown_name == "|A n B n C|") {
        *unknown_ptr = union_size - sum_tunggal_all + sum_irisan_ganda_all;
        abc = *unknown_ptr;

    } else if (unknown_name == "|A n B|" || unknown_name == "|A n C|" || unknown_name == "|B n C|") {
        // Cari total SUM(2): Total SUM(2) = SUM(1) - Union + Irisan Tiga
        int sum_irisan_ganda_total = sum_tunggal_all - union_size + abc; 
        // Suku Hilang = Total SUM(2) - SUM(2) yang diketahui
        *unknown_ptr = sum_irisan_ganda_total - sum_irisan_ganda_known; 
        
    } else if (unknown_name == "|A|" || unknown_name == "|B|" || unknown_name == "|C|") {
        // Cari total SUM(1): Total SUM(1) = Union + SUM(2) - Irisan Tiga
        int sum_tunggal_total = union_size + sum_irisan_ganda_all - abc;
        // Suku Hilang = Total SUM(1) - SUM(1) yang diketahui
        *unknown_ptr = sum_tunggal_total - sum_tunggal_known;
    }
    
    // Panggil fungsi output rinci yang baru
    cout << "\n[PERHITUNGAN] Nilai " << unknown_name << " telah ditemukan: " << *unknown_ptr << endl;
    hitungDanCetakRinci(total_populasi, a, b, c, ab, ac, bc, abc, union_size);

    return 0;
}