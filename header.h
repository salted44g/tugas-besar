#include <iostream>

#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define nextRelasi(p) (p)->nextRelasi
#define next_Artikelilmiah(p) (p)->next_Artikelilmiah
#define first(L) ((L).first)
#define last(L) ((L).last)
#define null NULL

using namespace std;

typedef struct elmPenulis *adr_Penulis;
typedef struct elmRelasi *adr_Relasi;
typedef struct elm_Artikelilmiah *adr_Artikelilmiah;

// ADT Penulis
struct infotypePenulis{
    string name;
    string NIP;
};

struct elmPenulis{
    infotypePenulis info;
    adr_Penulis next;
    adr_Penulis prev;
    adr_Relasi nextRelasi;
};

struct list_Penulis{
    adr_Penulis first;
    adr_Penulis last;
};

// ADT Relasi
struct elmRelasi{
    adr_Artikelilmiah next_Artikelilmiah;
    adr_Relasi nextRelasi;
};

struct list_Relasi{
    adr_Penulis first;
};

// ADT Destinasi
struct infotypeArtikelilmiah{
    string NIA;
    string Judul;
    string Pengarang;
    int Tahun;
};

struct elm_Artikelilmiah{
    infotypeArtikelilmiah info;
    adr_Artikelilmiah next;
};

struct list_Artikelilmiah{
    adr_Artikelilmiah first;
    adr_Artikelilmiah last;
};

void createListPenulis(list_Penulis &LP);
void createListArtikel_ilmiah(list_Artikelilmiah &LA);
infotypePenulis inputPenulis(string name);
infotypeArtikelilmiah inputArtikel_ilmiah(string Judul, string Pengarang, int Tahun);
adr_Penulis createElementPenulis(infotypePenulis data);
adr_Artikelilmiah createElement_Artikelilmiah(infotypeArtikelilmiah data);
adr_Relasi createElementRelasi(adr_Artikelilmiah d, adr_Penulis a);
void addPenulis(list_Penulis &LP, adr_Penulis P);
void addArtikel_ilmiah(list_Artikelilmiah &LA, adr_Artikelilmiah ar);
void showPenulis(list_Penulis LP);
void showArtikelIlmiah(list_Artikelilmiah LA);
adr_Penulis findPenulis(list_Penulis LP, string name);
adr_Artikelilmiah findArtikel_ilmiah(list_Artikelilmiah LA, string Judul);
void showPenulisWithArtikel(list_Penulis LP, string name);
void ShowArtikelilmiahWithPenulis(list_Penulis LP, list_Artikelilmiah LA, string Judul);
void AddRelasiPenulisWithArtikel(list_Penulis &LP, list_Artikelilmiah &LA);
void showArtikel_ilmiah(list_Artikelilmiah LA);
void deleteFirstPenulis(list_Penulis &LP, adr_Penulis p);
void deleteLastPenulis(list_Penulis &LP, adr_Penulis p);
void deleteAfterPenulis(adr_Penulis prec, adr_Penulis &p);
void deletePenulis(list_Penulis &LP, string name);
void deleteFirstRelasi(adr_Penulis &P);
void deleteLastRelasi(adr_Penulis &P);
void deleteAfterRelasi(adr_Relasi prec, adr_Relasi &r);
void deleteOneItemRelasi(adr_Penulis &P, adr_Relasi &r);
void deleteRelasi(adr_Penulis &P, adr_Artikelilmiah &A);
int CountPenulis(list_Penulis LP, adr_Artikelilmiah d);
void showPenulisMostProductive(list_Penulis LP);
void ShowartikelMostwrite(list_Artikelilmiah LA, list_Penulis LP);
int selectMenu();


int selectMenu();
