#include "header.h"

// Menambahkan data penulis.
void createListPenulis(list_Penulis &LP){
    first(LP) = NULL;
    last(LP) = NULL;
};

// Menambahkan data artikel ilmiah
void createListArtikel_ilmiah(list_Artikelilmiah &LA){
    first(LA) = NULL;
};

// Menampilkan data penulis
infotypePenulis inputPenulis(string name){
    infotypePenulis data;
    data.name = name;

    return data;
}

// Menampilkan data artikel ilmiah
infotypeArtikelilmiah inputArtikel_ilmiah(string Judul, string Pengarang, int Tahun)
{
    infotypeArtikelilmiah data;
    data.Judul = Judul;
    data.Pengarang = Pengarang;
    data.Tahun = Tahun;

    return data;
}

// Create ElementPenulis
adr_Penulis createElementPenulis(infotypePenulis data)
{
    adr_Penulis p = new elmPenulis;
    info(p) = data;
    next(p) = NULL;
    prev(p) = NULL;
    nextRelasi(p) = NULL;

    return p;
};

// Create ElementArtikelilmiah
adr_Artikelilmiah createElement_Artikelilmiah(infotypeArtikelilmiah data){
    adr_Artikelilmiah ar = new elm_Artikelilmiah;
    info(ar) = data;
    next(ar) = NULL;

    return ar;
};

// createElementRelasi
adr_Relasi createElementRelasi(adr_Artikelilmiah d, adr_Penulis a)
{
    adr_Relasi r = new elmRelasi;
    next_Artikelilmiah(r) = d;
    nextRelasi(a) = r;
    next_Artikelilmiah(r) = NULL;

    return r;
};

void addPenulis(list_Penulis &LP, adr_Penulis P)
{
    adr_Penulis q = first(LP);

    if (first(LP) == NULL)
    {
        first(LP) = P;
        last(LP) = P;
    }
    else
    {
        adr_Penulis p = last(LP);
        next(P) = P;
        prev(P) = p;
        last(LP) = P;
    }
};

// insert last circular single linked list
void addArtikel_ilmiah(list_Artikelilmiah &LA, adr_Artikelilmiah ar)
{
    adr_Artikelilmiah p = first(LA);

    if (first(LA) == NULL)
    {
        first(LA) = ar;
        last(LA) = ar;
        next(ar) = first(LA);
    }
    else
    {
        adr_Artikelilmiah q = last(LA);
        next(q) = ar;
        next(ar) = first(LA);
        last(LA) = ar;
    }
};

void showPenulis(list_Penulis LP)
{
    if (first(LP) != NULL)
    {
        adr_Penulis p = first(LP);
        while (p != NULL)
        {   
            
            cout << "Nama : " << info(p).name << endl;

            p = next(p);
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "List Kosong" << endl;
    }
};

void showArtikelIlmiah(list_Artikelilmiah LA)
{
    adr_Artikelilmiah ar = first(LA);
    while (ar != NULL)
        do
        {
            cout << "Judul : " << info(ar).Judul << endl;
            cout << "Pengarang : " << info(ar).Pengarang << endl;
            cout << "Tahun : " << info(ar).Tahun << endl;
            ar = next(ar);
        } while (ar != first(LA));
    cout << endl;
}

// Mencari data penulis tertentu
adr_Penulis findPenulis(list_Penulis LP, string name)
{
    adr_Penulis p = first(LP);
    if (first(LP) != NULL)
    {
        while (next(p) != first(LP) && info(p).name != name)
        {
            p = next(p);
        }
        if (info(p).name == name)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
};

adr_Artikelilmiah findArtikel_ilmiah(list_Artikelilmiah LA, string Judul)
{
    adr_Artikelilmiah ar = first(LA);
    do
    {
        if (info(ar).Judul == Judul)
        {
            return ar;
        }
        ar = next(ar);
    } while (ar != first(LA));
    return NULL;
};

void showPenulisWithArtikel(list_Penulis LP, string name)
{
    adr_Penulis P = findPenulis(LP, name);
    if (P != NULL)
    {
        cout << "Nama Tidak Di Temukan" << endl;
    }
    else
    {
        adr_Relasi ar = nextRelasi(P);
        cout << "====== Data Penulis ======" << endl;
        cout << "Nama : " << info(P).name << endl;
        cout << "====== Data Artikel Ilmiah ======" << endl;
        if (ar == NULL)
        {
            cout << "Tidak Ada Data Artikel Ilmiah" << endl;
        }
        else
        {
            int num = 1;
            do
            {
                cout << num++ << ".)";
                cout << "Judul : " << info(next_Artikelilmiah(ar)).Judul << endl;
            } while (next_Artikelilmiah(ar) != NULL);
        }
    }
};

void ShowArtikelilmiahWithPenulis(list_Penulis LP, list_Artikelilmiah LA, string Judul)
{
    adr_Artikelilmiah ar = findArtikel_ilmiah(LA, Judul);
    if (ar == NULL)
    {
        cout << "Data Artikel Tidak Di Temukan" << endl;
    }
    else
    {
        cout << endl;
        cout << "====== INFO DATA ARTIKEL ILMIAH ======" << endl;
        cout << "Judul : "          << info(ar).Judul << endl;
        cout << "Pengarang : "      << info(ar).Pengarang << endl;
        cout << "Tahun : "          << info(ar).Tahun << endl;
        cout << "====== LIST DATA PENULIS ======" << endl;
        adr_Penulis p = first(LP);
        int count = 1;
        while (p != NULL)
        {
            adr_Relasi rel = nextRelasi(p);
            if (rel != NULL)
            {
                do
                {
                    if (next_Artikelilmiah(rel) == ar)
                    {
                        cout << count++ << ".) Name : " << info(p).name << endl;
                        cout << "Judul : " << info(p).name << endl;
                        count++;
                    }
                    rel = nextRelasi(rel);
                } while (rel != NULL);
            }
            p = next(p);
        }
        cout << endl;
    }
}

// Menambahkan relasi data penulis dengan artikel ilmiah yang ditulisnya dan sebaliknya.
void AddRelasiPenulisWithArtikel(list_Penulis &LP, list_Artikelilmiah &LA){

};

// Mencari data artikel ilmiah yang ditulis oleh penulis tertentu
void showArtikel_ilmiah(list_Artikelilmiah LA)
{
    if (first(LA) != NULL)
    {
        adr_Artikelilmiah d = first(LA);
        while (d != NULL)
        {
            cout << "Judul : " << info(d).Judul << endl;
            cout << "Pengarang : " << info(d).Pengarang << endl;
            cout << "Tahun : " << info(d).Tahun << endl;
            d = next(d);
        }
        cout << endl;
    }
    else
    {
        cout << "List Kosong" << endl;
    }
};

// deletefirstdoublelinkedlist
void deleteFirstPenulis(list_Penulis &LP, adr_Penulis p)
{
    p = first(LP);
    if (first(LP) != last(LP))
    {
        first(LP) = next(p);
        next(p) = NULL;
        prev(first(LP)) = NULL;
    }
    else
    {
        first(LP) = NULL;
        last(LP) = NULL;
    }
};

// deletelastPenulisdoublelinkedlist
void deleteLastPenulis(list_Penulis &LP, adr_Penulis p)
{
    p = last(LP);
    if (first(LP) != last(LP))
    {
        last(LP) = prev(p);
        prev(p) = NULL;
        next(last(LP)) = NULL;
    }
    else
    {
        first(LP) = NULL;
        last(LP) = NULL;
    }
};

// deleteafterPenulisdoublelinkedlist
void deleteAfterPenulis(adr_Penulis prec, adr_Penulis &p)
{
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = NULL;
    prev(p) = NULL;
    nextRelasi(p) = NULL;
};

void deletePenulis(list_Penulis &LP, string name)
{
    adr_Penulis p = findPenulis(LP, name);
    if (p == NULL)
    {
        cout << "Penulis tidak ditemukan" << endl;
    }
    else if (p == first(LP))
    {
        deleteFirstPenulis(LP, p);
    }
    else if (p == last(LP))
    {
        deleteLastPenulis(LP, p);
    }
    else
    {
        deleteAfterPenulis(prev(p), p);
    }
};

// deletefirstrelasisinglelinkedlist
void deleteFirstRelasi(adr_Penulis &P)
{
    adr_Relasi r = nextRelasi(P);
    if (nextRelasi(P) != NULL)
    {
        nextRelasi(P) = nextRelasi(r);
        nextRelasi(r) = NULL;
    }
    else
    {
        nextRelasi(P) = NULL;
    }
};

// procudure deletelastrelasisinglelinkedlist
void deleteLastRelasi(adr_Penulis &P)
{
    adr_Relasi r = nextRelasi(P);
    if (nextRelasi(P) != NULL)
    {
        while (nextRelasi(nextRelasi(r)) != NULL)
        {
            r = nextRelasi(r);
        }
        nextRelasi(r) = NULL;
    }
    else
    {
        nextRelasi(P) = NULL;
    }
};

// procedure deleteafterrelasisinglelinkedlist
void deleteAfterRelasi(adr_Relasi prec, adr_Relasi &r)
{
    r = nextRelasi(prec);
    nextRelasi(prec) = nextRelasi(r);
    nextRelasi(r) = NULL;
};

// procedure deleteOneitemRelasi
void deleteOneItemRelasi(adr_Penulis &P, adr_Relasi &r)
{
    if (nextRelasi(P) != NULL)
    {
        if (nextRelasi(r) != NULL)
        {
            deleteAfterRelasi(r, r);
        }
        else
        {
            deleteLastRelasi(P);
        }
    }
    else
    {
        deleteFirstRelasi(P);
    }
    nextRelasi(P) = NULL;
};

//createsdeleteRelasi
void deleteRelasi(adr_Penulis &P, adr_Artikelilmiah &A){
    adr_Relasi r = nextRelasi(P);
    while (r != NULL)
    {
        if (next_Artikelilmiah(r) == A)
        {
            deleteOneItemRelasi(P, r);
        }
        r = nextRelasi(r);
    }
};

// Menghitung banyaknya penulis pada suatu artikle ilmiah tertentu
int CountPenulis(list_Penulis LP, adr_Artikelilmiah d)
{
    int count = 0;
    if (first(LP) != NULL && last(LP) != NULL)
    {
        adr_Penulis p = first(LP);
        while (next(p) != first(LP))
        {
            adr_Relasi r = nextRelasi(p);
            while (r != NULL)
            {
                if (next_Artikelilmiah(r) == d)
                {
                    count++;
                }
                r = nextRelasi(p);
            }
            p = next(p);
        }
    }
    return count;
};

// Menampilkan data penulis yang paling produktif.
void showPenulisMostProductive(list_Penulis LP)
{
    if (first(LP) != NULL && last(LP) != NULL)
    {
        adr_Penulis p = first(LP);
        int max = 0;
        while (next(p) != first(LP))
        {
            int count = 0;
            adr_Relasi r = nextRelasi(p);
            while (r != NULL)
            {
                count++;
                r = nextRelasi(p);
            }
            if (count > max)
            {
                max = count;
            }
            p = next(p);
        }
        p = first(LP);
        while (next(p) != first(LP))
        {
            int count = 0;
            adr_Relasi r = nextRelasi(p);
            while (r != NULL)
            {
                count++;
                r = nextRelasi(p);
            }
            if (count == max)
            {
                cout << "Nama : " << info(p).name << endl;
                cout << "Jumlah artikel : " << count << endl;
            }
            p = next(p);
        }
    }
    else
    {
        cout << "List Kosong" << endl;
    }
};

// Menampilkan data artikel ilmiah yang paling banyak ditulis oleh penulis.
void ShowartikelMostwrite(list_Artikelilmiah LA, list_Penulis LP)
{
    if (first(LA) != NULL)
    {
        adr_Artikelilmiah p = first(LA);
        int max = 0;
        while (p != NULL)
        {
            int count = CountPenulis(LP, p);
            if (count > max)
            {
                max = count;
            }
            p = next(p);
        }
        p = first(LA);
        while (p != NULL)
        {
            int count = CountPenulis(LP, p);
            if (count == max)
            {
                cout << "Judul : " << info(p).Judul << endl;
                cout << "Pengarang : " << info(p).Pengarang << endl;
                cout << "Tahun : " << info(p).Tahun << endl;
                cout << "Jumlah penulis : " << count << endl;
            }
            p = next(p);
        }
    }
    else
    {
        cout << "List Kosong" << endl;
    }
};

adr_Relasi findRelasi(adr_Penulis a, string NIA){
    adr_Relasi r = nextRelasi(a);
    do{
        if (info(next_Artikelilmiah(r)).NIA == NIA){
            return r;
        }
        r = nextRelasi(r);
    }while (r != NULL);
    return NULL;
}

int selectMenu()
{
    cout << "======     MENU    =======" << endl;
    cout << "1. Menambahkan data penulis : " << endl;
    cout << "2. Menambahkan data artikel ilmiah : " << endl;
    cout << "3. Mencari data penulis tertentu : " << endl;
    cout << "4. Menambahkan relasi data penulis dengan artikel ilmiah yang ditulisnya dan sebaliknya : " << endl;
    cout << "5. Mencari data artikel ilmiah yang ditulis oleh penulis tertentu : " << endl;
    cout << "6. Menghapus penulis beserta relasinya : " << endl;
    cout << "7. Menghapus data artikel ilmiah yang ditulis oleh penulis tertentu : " << endl;
    cout << "8. Menampilkan seluruh data penulis beserta artikel ilmiah yang pernah ditulisnya : " << endl;
    cout << "9. Menghitung banyaknya penulis pada suatu artikle ilmiah tertentu : " << endl;
    cout << "10. Menampilkan data penulis yang paling produktif : " << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "Masukkan menu : ";

    int input = 0;
    cin >> input;

    return input;
}
