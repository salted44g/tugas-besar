#include <iostream>
#include "header.h"

using namespace std;

int main(){
    list_Penulis P;
    list_Artikelilmiah A;
    infotypePenulis infoP;
    infotypeArtikelilmiah infoA;
    adr_Penulis adrP;
    adr_Artikelilmiah adrA;

    createListPenulis(P);
    createListArtikel_ilmiah(A);

    cout << "Masukkan nama penulis: " << endl;

    infoP = inputPenulis("Rizky");
    adrP = createElementPenulis(infoP);
    addPenulis(P, adrP);

    infoP = inputPenulis("Jaya");
    adrP = createElementPenulis(infoP);
    addPenulis(P, adrP);

    infoP = inputPenulis("jaya");
    adrP = createElementPenulis(infoP);
    addPenulis(P, adrP);

    infoP = inputPenulis("Putra");
    adrP = createElementPenulis(infoP);
    addPenulis(P, adrP);

    cout << "Done :)" << endl;

        adrP = findPenulis(P, "Rizky");
        adrA = findArtikel_ilmiah(A, "Rizky");
        createElementRelasi(adrA, adrP);

        adrP = findPenulis(P, "Rizky");
        adrA = findArtikel_ilmiah(A, "Jaya");
        createElementRelasi(adrA, adrP);

        adrP = findPenulis(P, "Rizky");
        adrA = findArtikel_ilmiah(A, "Putra");
        createElementRelasi(adrA, adrP);

        showPenulisWithArtikel(P, "Rizky");

    int pilihan = 0;
    string kembali = "Yes";
    pilihan = selectMenu();
    while (pilihan != 0 && kembali == "Yes" || kembali == "yes"){
        switch (pilihan){
            case 1:{
            cout << "Masukkan nama penulis: " << endl;
            break;
        }
        case 2:{
            cout << "Masukkan nama artikel: " << endl;
            break;
        }
        case 3:{
            string IDArtikel;
            cout << "Masukkan ID artikel: " << endl;
            cin >> IDArtikel;
            adr_Artikelilmiah adrA = findArtikel_ilmiah(A, IDArtikel);
            if (adrA != NULL){
                cout << "Artikel ditemukan" << endl;
                cout << "Judul: " << adrA->info.Judul << endl;
                cout << "Pengarang: " << adrA->info.Pengarang << endl;
                cout << "Tahun: " << adrA->info.Tahun << endl;
            } else {
                cout << "Artikel tidak ditemukan" << endl;
            }
            break;
        }
        case 4:{
            string IDArtikel, IDPenulis;
            cout << "Masukkan ID artikel: " << endl;
            cin >> IDArtikel;
            cout << "Masukkan ID penulis: " << endl;
            cin >> IDPenulis;
            adr_Artikelilmiah adrA = findArtikel_ilmiah(A, IDArtikel);
            adr_Penulis adrP = findPenulis(P, IDPenulis);
            if (adrP == NULL){
                cout << "Penulis tidak ditemukan" << endl;
            } else if (adrA == NULL){
                cout << "Artikel tidak ditemukan" << endl;
            } else {
                createElementRelasi(adrA, adrP);
                cout << "Relasi berhasil dibuat" << endl;
            }
        }
        case 5: {
            string  IDArtikel;
            cout << "Masukkan ID artikel: " << endl;
            cin >> IDArtikel;
            ShowArtikelilmiahWithPenulis(P, A, IDArtikel);
            break;
        }
        case 6: {
            string IDPenulis;
            cout << "Masukkan ID penulis: " << endl;
            cin >> IDPenulis;
            showPenulisWithArtikel(P, IDPenulis);
            cout << "Done Succes" << endl;
            break;
        }
        case 7: {
            string IDPenulis, IDArtikel;
            cout << "Masukkan ID penulis: " << endl;
            cin >> IDPenulis;
            ShowArtikelilmiahWithPenulis(P, A, IDPenulis);

            cout << "Masukkan ID artikel: " << endl;
            cin >> IDArtikel;
            adr_Artikelilmiah adrA = findArtikel_ilmiah(A, IDArtikel);//
            adr_Relasi adrR = findRelasi(P, IDPenulis, IDArtikel);
        }
        case 8: {
            string IDPenulis, IDArtikel;

        }
    }

}
