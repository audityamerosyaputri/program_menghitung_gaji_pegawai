#include <stdio.h>
#include <string.h>

#define MAX_PEGAWAI 50 // Maksimal jumlah pegawai

// Definisikan struktur untuk menyimpan data pegawai
struct Pegawai
{
    char nama[50];
    char jabatan[50];
    int jamKerja;
    float upahPerJam;
    float bonus;
    float gajiTotal;
};

// Fungsi untuk menghitung total gaji
void hitungGaji(float *upahPerjam, int *jamKerja, float *bonus, float *gajiTotal)
{
    *gajiTotal = (*upahPerjam * *jamKerja + *bonus);
}

int main()
{
    int jumlahPegawai;

    // Input jumlah pegawai
    printf("Masukkan jumlah pegawai: ");
    scanf("%d", &jumlahPegawai);

    // Validasi data jumlah pegawai
    if (jumlahPegawai < 1 || jumlahPegawai > MAX_PEGAWAI)
    {
        printf("Jumlah pegawai tidak valid!\n");
        return 0;
    }

    // Array pointer untuk menyimpan pilihan jabatan
    char *pilihan_jabatan[] = {"Direktur", "Supervisor", "Staff", "Honorer", "Harian"};

    // Array dari struct Pegawai
    struct Pegawai pegawai[jumlahPegawai];

    // Loop untuk input data setiap pegawai yang akan diinputkan
    for (int i = 0; i < jumlahPegawai; i++)
    {
        printf("\nData Pegawai ke-%d\n", i + 1);
        getchar(); // Menghilangkan newline dari buffer setelah memasukkan jumlah pegawai

        // Input nama pegawai
        printf("Masukkan nama pegawai: ");
        fgets(pegawai[i].nama, sizeof(pegawai[i].nama), stdin);
        pegawai[i].nama[strcspn(pegawai[i].nama, "\n")] = '\0'; // Menghapus newline yang mungkin muncul setelah fgets

        // Tampilkan pilihan jabatan
        printf("\nPilih jabatan:\n");
        printf("1. Direktur\n");
        printf("2. Supervisor\n");
        printf("3. Staff\n");
        printf("4. Pegawai Honorer\n");
        printf("5. Pegawai Harian\n");

        // Input pilihan jabatan
        int pilihan;
        int validJabatan = 0;

        // Validasi pilihan jabatan dengan perulangan
        while (!validJabatan)
        {
            printf("Masukkan pilihan jabatan (1-5): ");
            scanf("%d", &pilihan);

            if (pilihan == 1)
            {
                strcpy(pegawai[i].jabatan, "Direktur");
                validJabatan = 1;
            }
            else if (pilihan == 2)
            {
                strcpy(pegawai[i].jabatan, "Supervisor");
                validJabatan = 1;
            }
            else if (pilihan == 3)
            {
                strcpy(pegawai[i].jabatan, "Staff");
                validJabatan = 1;
            }
            else if (pilihan == 4)
            {
                strcpy(pegawai[i].jabatan, "Honorer");
                validJabatan = 1;
            }
            else if (pilihan == 5)
            {
                strcpy(pegawai[i].jabatan, "Harian");
                validJabatan = 1;
            }
            else
            {
                printf("Pilihan jabatan tidak valid! Coba lagi.\n");
            }
        }

        // Input jam kerja
        printf("Masukkan jam kerja: ");
        scanf("%d", &pegawai[i].jamKerja);

        // Input upah per jam
        printf("Masukan upah per jam: Rp. ");
        scanf("%f", &pegawai[i].upahPerJam);

        // Input bonus (walaupun sudah ada perhitungan bonus berdasarkan jabatan)
        printf("Masukkan bonus: Rp. ");
        scanf("%f", &pegawai[i].bonus);

        // Menghitung gaji total untuk pegawai ini
        hitungGaji(&pegawai[i].upahPerJam, &pegawai[i].jamKerja, &pegawai[i].bonus, &pegawai[i].gajiTotal);
    }

    // Output data semua pegawai
    printf("\nData Gaji Pegawai\n");

    for (int i = 0; i < jumlahPegawai; i++)
    {
        printf("\nPegawai ke-%d\n", i + 1);
        printf("Nama       : %s\n", pegawai[i].nama);
        printf("Jabatan    : %s\n", pegawai[i].jabatan);
        printf("Upah per jam : %.2f\n", pegawai[i].upahPerJam);
        printf("Jam Kerja  : %d\n", pegawai[i].jamKerja);
        printf("Bonus      : Rp. %.2f\n", pegawai[i].bonus);
        printf("Gaji Total : Rp. %.2f\n", pegawai[i].gajiTotal);
        printf("---------------------------------------\n");
    }

    return 0;
}