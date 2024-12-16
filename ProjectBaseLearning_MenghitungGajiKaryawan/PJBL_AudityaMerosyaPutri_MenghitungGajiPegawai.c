#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definisikan struktur untuk menyimpan data pegawai
struct Pegawai
{
    char jabatan[50];
    int jamKerja;
    float upahPerJam;
    float bonus;
    float gajiTotal;
};

int main()
{
    FILE *inputFile, *outputFile;
    FILE *input_9, *output_9;
    int jumlahPegawai = 0;

    //Mulai menghitung waktu eksekusi
    clock_t start = clock();

    // Membaca file input_9.txt
    inputFile = fopen("input_9.txt", "r");
    if (inputFile == NULL)
    {
        printf("File input.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Menulis seluruh data ke file output.txt
    outputFile = fopen("output_9.txt", " w ");
    if (outputFile == NULL)
    {
        printf("File output_9.txt tidak dapat dibuka!\n");
        fclose(inputFile);
        return 1;
    }

    // deklarasi pointer untuk array pegawai
    struct Pegawai *pegawai = NULL;

    // Array pointer untuk menyimpan pilihan jabatan
    char *pilihan_jabatan[] = {"Direktur", "Supervisor", "Staff", "Honorer", "Harian"};

    // Membaca data dari file input dan menyimpan ke array dinamis
    pegawai = malloc(sizeof(struct Pegawai)); // Alokasi awal memori
    while (fscanf(inputFile, "jamkerja:%d upahperjam:%f bonus:%f jabatan:%s\n",
                  &pegawai[jumlahPegawai].jamKerja,
                  &pegawai[jumlahPegawai].upahPerJam,
                  &pegawai[jumlahPegawai].bonus,
                  pegawai[jumlahPegawai].jabatan) != EOF)
    {

        // Menghitung gaji total
        pegawai[jumlahPegawai].gajiTotal = (pegawai[jumlahPegawai].jamKerja * pegawai[jumlahPegawai].upahPerJam) + pegawai[jumlahPegawai].bonus;

        // Tambah jumlah pegawai
        jumlahPegawai++;
        pegawai = realloc(pegawai, (jumlahPegawai + 1) * sizeof(struct Pegawai)); // Alokasi ulang memori
    }

    // Menuliskan data pegawai ke file output utama
    fprintf(outputFile, "Data Gaji Pegawai\n");
    for (int i = 0; i < jumlahPegawai; i++) {
        fprintf(outputFile, "Jabatan: %s, Jam Kerja: %d, Upah/Jam: %.2f, Bonus: %.2f,  Gaji Total: %.2f\n", 
        pegawai[i].jabatan, 
        pegawai[i].jamKerja,
        pegawai[i].upahPerJam,
        pegawai[i].bonus,
        pegawai[i].gajiTotal);
        fprintf(outputFile, "\n------------------------------------------------------------------------\n");
    }

    // Menutup file input dan output program
    fclose(inputFile);
    fclose(outputFile);

    // Akhiri pengukuran waktu
    clock_t end = clock();

    //Hitung waktu eksekusi dalam detik
    double waktuEksekusi = (double)(end - start) / CLOCKS_PER_SEC;

    // Tampilkan pesan 
    printf("Data telah diproses dan disimpan di file output_9.txt\n");
    
    //Tampilkan waktu eksekusi
    printf("Waktu eksekusi program: %.2f detik\n", waktuEksekusi);

    free(pegawai); //Membebaskan memori yang telah dialokasikan

    return 0;
}
