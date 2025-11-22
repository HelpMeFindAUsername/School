// LUCCHINI ALBERTO

// Posizione stampa
// 0;    15; 20;     32;     60;   62;   66;   73;
// ISBN; ID; TITOLO; AUTORE; MESE; ANNO; SEDE; CASA;


#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

const int DIM = 3;
const int ORD[] = {0, 15, 20, 32, 60, 65, 75, 82};

bool uscita = 0;

int ver = 0;

int spazioOcc = 0;
int inp;
int indexTrovato;

string ricerca;

struct libri{
    struct codiceLibro{
        string isbn;
        string id;
    }cLibro;

    string titolo;

    string autore;

    struct annoPub{
        int mese;
        int anno;
    } aPub;

    struct  Editore{
        string sede;
        string cEd;
    } editore;
};

libri biblioteca[DIM];

void gotoxy(int x, int y);
void insLibro(libri biblioteca[], int dim);
int cercaLibro(libri biblioteca[], int dim, int input, string libroCercato);
int stampa(libri biblioteca[], int dim, int& ver, bool cS, int iT);


int menu();

int main(){
    while (!uscita)
    {
        string ricerca;
        switch (menu()){
            case 1:
                if(DIM - spazioOcc > 0){
                    do{
                        cout << "Quanti libri vuoi aggiungere? (Spazio disponibile: " << DIM - spazioOcc << ", 0 per tornare al menu'): ";
                        cin >> inp;
                        if ((inp < 1 || inp > DIM - spazioOcc) && inp != 0)
                        {
                            cout << "Non e' disponibile abbastanza spazio!";
                        }
                        else if (inp == 0){
                            break;
                        }
                        
                        
                    }while (inp < 1 || inp > DIM - spazioOcc);
                
                    insLibro(biblioteca, inp);
                }
                else{
                    cout << "Non e' disponibile abbastanza spazio!";
                }
                break;

            case 2:
                cout << "Inserisci l'isbn o ID del libro da cercare:";
                cin >> ricerca;
                indexTrovato = cercaLibro(biblioteca, spazioOcc, 1, ricerca);
                if(indexTrovato == -1){
                    cout << "Nessun libro trovato con quel isbn o ID\nPremere invio per tornare al menu':";
                    cin.get();
                    cin.get();

                }
                else{
                    stampa(biblioteca, spazioOcc, ver, 0, indexTrovato);
                }
                break;

            case 3:
                cout << "Inserisci il cognome da cercare:";
                cin >> ricerca;
                indexTrovato = cercaLibro(biblioteca, spazioOcc, 2, ricerca);
                if(indexTrovato == -1){
                    cout << "Nessun libro trovato con quel congnome\nPremere invio per tornare al menu':";
                    cin.get(); 
                    cin.get();
                }
                else{
                    stampa(biblioteca, spazioOcc, ver, 0, indexTrovato);
                }
                break;

            case 4:
                stampa(biblioteca, spazioOcc, ver, 1, 0);
                break;

            case 0:
                uscita = 1;
                break;
            
            default:
                
                break;
        }
    }
    
    return 0;
}

void gotoxy(int x, int y){
     HANDLE HConsole;
     CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
     HConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     ConsoleInfo.dwCursorPosition.X = x;
     ConsoleInfo.dwCursorPosition.Y = y;
     SetConsoleCursorPosition(HConsole,ConsoleInfo.dwCursorPosition);
}

void insLibro(libri biblioteca[], int dim){
    for(int i = 0; i < dim; i++){
        cout << "Inserisci il codice ISBN del libro: ";
        cin >> biblioteca[i].cLibro.isbn;
        cout << "Inserisci l'ID del libro: ";
        cin >> biblioteca[i].cLibro.id;
        cout << "Inserisci il titolo del libro: ";
        cin >> biblioteca[i].titolo;
        cout << "Inserisci l'autore del libro: ";
        cin >> biblioteca[i].autore;
        cout << "Inserisci il mese di pubblicazione del libro: ";
        cin >> biblioteca[i].aPub.mese;
        cout << "Inserisci l'anno di pubblicazione del libro: ";
        cin >> biblioteca[i].aPub.anno;
        cout << "Inserisci la sede dell'editore del libro: ";
        cin >> biblioteca[i].editore.sede;
        cout << "Inserisci la casa editrice del libro: ";
        cin >> biblioteca[i].editore.cEd;
        spazioOcc++;
    }
}

int cercaLibro(libri biblioteca[], int dim, int input, string libroCercato){
    if(input == 1){
        for (int i = 0; i < dim; i++)
        {
            if(libroCercato == biblioteca[i].cLibro.id || libroCercato == biblioteca[i].cLibro.isbn){
                return i;
            }
        }
    }
    else if(input == 2){
        for (int i = 0; i < dim; i++)
        {
            if(libroCercato == biblioteca[i].autore){
                return i;
            }
        }
    }

    return -1;

}

int stampa(libri biblioteca[], int dim, int& ver, bool cS, int iT){
    system("cls");
    int scelta;
    ver = 0;
    
    gotoxy(ORD[0], ver);
    cout << "Codice libro";
    gotoxy(ORD[4], ver);
    cout << "Anno";
    ver++;
    gotoxy(ORD[4], ver);
    cout << "Pubblicazione";
    ver--;
    gotoxy(ORD[6], ver);
    cout << "Editore";
    ver++;
    gotoxy(ORD[2], ver);
    cout << "Titolo";
    gotoxy(ORD[3], ver);
    cout << "Autore";
    ver++;
    gotoxy(ORD[0], ver);
    cout << "isbn";
    gotoxy(ORD[1], ver);
    cout << "ID";
    gotoxy(ORD[4], ver);
    cout << "Mese";
    gotoxy(ORD[5], ver);
    cout << "Anno";
    gotoxy(ORD[6], ver);
    cout << "Sede";
    gotoxy(ORD[7], ver);
    cout << "Casa Editrice";
    ver++;
    if (cS)
    {
        for(int i = 0; i < dim; i++){
            gotoxy(ORD[0], ver);
            cout << biblioteca[i].cLibro.isbn;
            gotoxy(ORD[1], ver);
            cout << biblioteca[i].cLibro.id;
            gotoxy(ORD[2], ver);
            cout << biblioteca[i].titolo;
            gotoxy(ORD[3], ver);
            cout << biblioteca[i].autore;
            gotoxy(ORD[4], ver);
            cout << biblioteca[i].aPub.mese;
            gotoxy(ORD[5], ver);
            cout << biblioteca[i].aPub.anno;
            gotoxy(ORD[6], ver);
            cout << biblioteca[i].editore.sede;
            gotoxy(ORD[7], ver);
            cout << biblioteca[i].editore.cEd;
            ver++;
        }
    }
    else{
        gotoxy(ORD[0], ver);
        cout << biblioteca[iT].cLibro.isbn;
        gotoxy(ORD[1], ver);
        cout << biblioteca[iT].cLibro.id;
        gotoxy(ORD[2], ver);
        cout << biblioteca[iT].titolo;
        gotoxy(ORD[3], ver);
        cout << biblioteca[iT].autore;
        gotoxy(ORD[4], ver);
        cout << biblioteca[iT].aPub.mese;
        gotoxy(ORD[5], ver);
        cout << biblioteca[iT].aPub.anno;
        gotoxy(ORD[6], ver);
        cout << biblioteca[iT].editore.sede;
        gotoxy(ORD[7], ver);
        cout << biblioteca[iT].editore.cEd;
        ver++;
    }

    ver += 2;
    gotoxy(ORD[0], ver);
    cout << "Per tornare al menu' premere invio: ";
    cin.get();
    cin.get();
    return 0;
}

int menu(){
    system("cls");
    int scelta;

    cout << "MENU'" << endl;
    cout << "1. Aggiungi nuovo libro\n";
    cout << "2. Cerca libro tramite ISBN o ID\n";
    cout << "3. Cerca libro per autore\n";
    cout << "4. Visualizza collezione\n";
    cout << "0. Uscita\n";
    cout << "Inserisci la tua scelta: ";
    cin >> scelta;

    return scelta;
}