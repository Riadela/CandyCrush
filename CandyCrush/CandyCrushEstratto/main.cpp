//Elaborato 2014/15: Gioco simile a Candy Crush
//Matricola: 832104
//Nome: El Abiad Riad Eddin

#include <iostream>
#include <cstdlib> //per random
#include <time.h> //per random e time
#include <stdlib.h>
#include <fstream> //file txt
#include <vector>
#include <string>
#include <limits>
#include <windows.h> //per file audio
#include <mmsystem.h> //per file audio

using namespace std;

const int L = 10; //valore dei lati della matrice
const int V = 3; //valore elementi array caratteri per elementi della matrice

//r sta per riga
//c sta per colonna

bool verificaOrizzontaleDestra(char (*tabella_gioco)[L], int r, int c){
    return (c<L-2&&tabella_gioco[r][c]==tabella_gioco[r][c+1]&&tabella_gioco[r][c]==tabella_gioco[r][c+2]);
}
bool verificaOrizzontaleSinistra (char (*tabella_gioco)[L], int r, int c){
    return (c>1&&tabella_gioco[r][c]==tabella_gioco[r][c-1]&&tabella_gioco[r][c]==tabella_gioco[r][c-2]);
}
bool verificaVerticaleBasso (char (*tabella_gioco)[L], int r, int c){
    return (r<L-2&&tabella_gioco[r][c]==tabella_gioco[r+1][c]&&tabella_gioco[r][c]==tabella_gioco[r+2][c]);
}
bool verificaVerticaleAlto (char (*tabella_gioco)[L], int r, int c){
    return (r>1&&tabella_gioco[r][c]==tabella_gioco[r-1][c]&&tabella_gioco[r][c]==tabella_gioco[r-2][c]);
}
bool verificaDiagonaleBassoSinistra (char (*tabella_gioco)[L], int r, int c){
    return (r<L-2&&c>1&&tabella_gioco[r][c]==tabella_gioco[r+1][c-1]&&tabella_gioco[r][c]==tabella_gioco[r+2][c-2]);
}
bool verificaDiagonaleBassoDestra (char (*tabella_gioco)[L], int r, int c){
    return (r<L-2&&c<L-2&&tabella_gioco[r][c]==tabella_gioco[r+1][c+1]&&tabella_gioco[r][c]==tabella_gioco[r+2][c+2]);
}
bool verificaDiagonaleAltoDestra (char (*tabella_gioco)[L], int r, int c){
    return (r>1&&c>1&&tabella_gioco[r][c]==tabella_gioco[r-1][c-1]&&tabella_gioco[r][c]==tabella_gioco[r-2][c-2]);
}
bool verificaDiagonaleAltoSinistra (char (*tabella_gioco)[L], int r, int c){
    return (r>1&&c<L-2&&tabella_gioco[r][c]==tabella_gioco[r-1][c+1]&&tabella_gioco[r][c]==tabella_gioco[r-2][c+2]);
}
bool verificaOrizzontaleDestraSinistra (char (*tabella_gioco)[L], int r, int c){
    return (c<L-1&&c>0&&tabella_gioco[r][c]==tabella_gioco[r][c+1]&&tabella_gioco[r][c]==tabella_gioco[r][c-1]);
}
bool verificaVerticaleAltoBasso (char (*tabella_gioco)[L], int r, int c){
    return (r<L-2&&r>0&&tabella_gioco[r][c]==tabella_gioco[r+1][c]&&tabella_gioco[r][c]==tabella_gioco[r-1][c]);
}
bool verificaDiagonaleAltoDestraBassoSinistra (char (*tabella_gioco)[L], int r, int c){
    return (r>0&&c>0&&r<L-1&&c<L-1&&tabella_gioco[r][c]==tabella_gioco[r-1][c-1]&&tabella_gioco[r][c]==tabella_gioco[r+1][c+1]);
}
bool verificaDiagonaleBassoDestraAltoSinistra (char (*tabella_gioco)[L], int r, int c){
    return (r>0&&c>0&&r<L-1&&c<L-1&&tabella_gioco[r][c]==tabella_gioco[r+1][c-1]&&tabella_gioco[r][c]==tabella_gioco[r-1][c+1]);
}
bool verificaTuttiTris (char (*tabella_gioco)[L], int r, int c){
    return (verificaVerticaleAlto(tabella_gioco, r , c) ||
            verificaOrizzontaleSinistra(tabella_gioco, r, c) ||
            verificaDiagonaleAltoDestra(tabella_gioco, r, c) ||
            verificaDiagonaleAltoSinistra(tabella_gioco, r, c) ||
            verificaVerticaleBasso(tabella_gioco, r, c) ||
            verificaVerticaleAltoBasso(tabella_gioco, r, c) ||
            verificaOrizzontaleDestra(tabella_gioco, r, c) ||
            verificaOrizzontaleDestraSinistra(tabella_gioco, r, c) ||
            verificaDiagonaleBassoDestra(tabella_gioco, r, c) ||
            verificaDiagonaleBassoSinistra(tabella_gioco, r, c) ||
            verificaDiagonaleAltoDestraBassoSinistra(tabella_gioco, r, c) ||
            verificaDiagonaleBassoDestraAltoSinistra(tabella_gioco, r, c));
}


bool assegna (char (*tabella_gioco)[L], int r, int c)
{
    char valore [V] = {'A','B','C'}; //array dei possibili valori inseriti

    if (tabella_gioco[r][c] == 'A' || tabella_gioco[r][c] == 'B' || tabella_gioco[r][c] == 'C'){ //se la cella attuale non è vuota
        if (c == 9 && r == 9){ //se è l'ultima resituisco valore true
            return true;
        }
        if (c < 9){ //altrimenti vado alla cella seguente
            return assegna (tabella_gioco, r, c+1);
        }
        if (c == 9 && r < 9){ //se è l'ultima colonna vado alla prima della riga seguente
            return assegna (tabella_gioco, r+1, 0);
        }
    }
    else { //se la cella corrente è vuota
        tabella_gioco[r][c] = valore[(rand() % 3)]; //inserisco un valore casuale fra A,B e C
        if (verificaTuttiTris(tabella_gioco, r, c)){ //se genera un tris cambio con il valore A
            tabella_gioco[r][c] = 'A';{
                if (verificaTuttiTris(tabella_gioco, r, c)) //se a sua volta genera un tris cambio il valore con B
                    tabella_gioco[r][c] = 'B';{
                    if (verificaTuttiTris(tabella_gioco, r, c)) //se nuovamente genera un tris cambio il valore con C
                        tabella_gioco[r][c] = 'C';{
                        if (verificaTuttiTris(tabella_gioco, r, c)){ //e se infine nessuno è possibile svuoto la cella e restituisco false
                            tabella_gioco[r][c] = ' ';
                            return false;
                        }
                    }
                }
            }
        }
        if (c == 9 && r == 9){ //se è l'ultima resituisco valore true
            return true;
        }
        else{ //altrimenti
            if (c < 9){ //se non sono in ultima colonna
                if (assegna (tabella_gioco, r, c+1) == false){ //se nessuna delle scelte fa in modo che la colonna successiva generi un tris assegno a quella attuale A
                    tabella_gioco[r][c] = 'A';
                    if (verificaTuttiTris(tabella_gioco, r, c) || assegna (tabella_gioco, r, c+1) == false){ //se la A genera un tris oppure se nessuna delle scelte fa in modo che la colonna successiva generi un tris assegno a quella attuale B
                        tabella_gioco[r][c] = 'B';
                        if (verificaTuttiTris(tabella_gioco, r, c) || assegna (tabella_gioco, r, c+1) == false){ //se la B genera un tris oppure se nessuna delle scelte fa in modo che la colonna successiva generi un tris assegno a quella attuale C
                            tabella_gioco[r][c] = 'C';
                            if (verificaTuttiTris(tabella_gioco, r, c) || assegna (tabella_gioco, r, c+1) == false){ //se la C genera un tris oppure se nessuna delle scelte fa in modo che la colonna successiva generi un tris cancello e ritorno false
                                tabella_gioco[r][c] = ' ';
                                return false;
                            }
                        }
                    }
                }
            }
            if (c == 9 && r < 9){ //se sono all'ultima colonna
                if (assegna (tabella_gioco, r+1, 0) == false){ //se nessuna delle scelte fa in modo che la prima colonna della riga successiva generi un tris assegno a quella attuale A
                    tabella_gioco[r][c] = 'A';
                    if (verificaTuttiTris(tabella_gioco, r, c) || assegna (tabella_gioco, r+1, 0) == false){ //se la A genera un tris oppure se nessuna delle scelte fa in modo che la prima colonna della riga successiva generi un tris assegno a quella attuale B
                        tabella_gioco[r][c] = 'B';
                        if (verificaTuttiTris(tabella_gioco, r, c) || assegna (tabella_gioco, r+1, 0) == false){ //se la B genera un tris oppure se nessuna delle scelte fa in modo che la prima colonna della riga successiva generi un tris assegno a quella attuale C
                            tabella_gioco[r][c] = 'C';
                            if (verificaTuttiTris(tabella_gioco, r, c) || assegna (tabella_gioco, r+1, 0) == false){ //se la C genera un tris oppure se nessuna delle scelte fa in modo che la prima colonna della riga successiva generi un tris cancello e ritorno false
                                tabella_gioco[r][c] = ' ';
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true; //nel caso non ci siano problemi ritorno a true
}

void casoLimite (char (*tabella_gioco)[L], char (*tabellaAppoggio)[L]){
    assegna (tabellaAppoggio, 0, 0); //riassegno una nuova tabella chiama tabellaAppoggio per effetto maschera
    for (int r = 0;r < L; r++){ //per ogni riga dal basso
        for (int c = 0; c < L; c++) { //per ogni colonna da destra
            if (tabella_gioco[r][c] == ' ') //se è una cella vuota copi il valore presente in quella di appoggio
                tabella_gioco[r][c] = tabellaAppoggio[r][c];
        }
    }
}

void stamp (char (*tabella_gioco)[L]){
    for (size_t c=0; c<L;c++){ //per ogni colonna
        if (c == 0) //se è la prima aggiungo diversi spazi ed il numero 1
            cout << ' ' << ' ' << ' ' << c+1;
        else //nelle seguenti un solo spazio e i successivi numeri
            cout << ' ' << c+1;
    }
    cout << endl;
    for (int r=0; r<L; r++){ //per ogni riga
        if (r < 9) //se i numeri delle righe sono minuri di 9 aggiungo uno spazio, per pareggiare la distanza con la colonna 10
            cout <<' ';
        cout << r + 1 << "|"; //inserisco sempre il numero di riga
        for (int c=0; c<L; c++){ //per ogni colonna
            cout << tabella_gioco [r][c]; //inserisco il valore della tabella di gioco attuale
            cout << "|"; //inserisco uno spaziatore per leggere meglio la tabella
        } cout << endl;
    } cout << endl;
}

bool verifica(char (*tabella_gioco)[L],char (*temporanea)[L]){

    bool valido = true;

    for (int r= 0; r < L; r++){ //per ogni riga
        for (int c= 0; c < L; c++){ //per ogni colonna
            if (verificaOrizzontaleDestra(tabella_gioco,r,c) && tabella_gioco[r][c] != ' '){ //verifica orizzontale

                temporanea[r][c]=tabella_gioco[r][c]; //copio il 1 valore
                temporanea[r][c+1]=tabella_gioco[r][c+1]; //copio il 2 valore
                temporanea[r][c+2]=tabella_gioco[r][c+2]; //copio il 3 valore
            }
            if (verificaVerticaleBasso(tabella_gioco,r,c)&& tabella_gioco[r][c] != ' '){ //verifica verticale

                temporanea[r][c]=tabella_gioco[r][c]; //copio il 1 valore
                temporanea[r+1][c]=tabella_gioco[r+1][c]; //copio il 2 valore
                temporanea[r+2][c]=tabella_gioco[r+2][c]; //copio il 3 valore
            }
            if (verificaDiagonaleBassoDestra(tabella_gioco,r,c)&& tabella_gioco[r][c] != ' '){ //verifica diagonale1

                temporanea[r][c]=tabella_gioco[r][c]; //copio il 1 valore
                temporanea[r+1][c+1]=tabella_gioco[r+1][c+1]; //copio il 2 valore
                temporanea[r+2][c+2]=tabella_gioco[r+2][c+2]; //copio il 3 valore
            }
            if (verificaDiagonaleBassoSinistra(tabella_gioco,r,c)&& tabella_gioco[r][c] != ' '){ //verifica diagonale2

                temporanea[r][c]=tabella_gioco[r][c]; //copio il 1 valore
                temporanea[r+1][c-1]=tabella_gioco[r+1][c-1]; //copio il 2 valore
                temporanea[r+2][c-2]=tabella_gioco[r+2][c-2]; //copio il 3 valore
            }
        }
    }
    for (int r = 0;r < L; r++){ //per ogni riga
        for (int c = 0; c < L; c++) { //per ogni colonna
            if (temporanea[r][c]!= ' '){ //se quella temporanea è piena, svuoto quella originale e restituisco il valore falso
                tabella_gioco[r][c]= ' ';
                valido = false; //il valore falso indica che è presente almeno un tris
            }
        }
    }
    return valido; //se è true significa che non c'è nessun tris
}

int punteggio(char (*temporanea)[L]){
    int kA = 0; //contatore di A
    int kB = 0; //contatore di B
    int kC = 0; //contatore di C
    for (int r = 0;r < L; r++){ //per ogni riga
        for (int c = 0; c < L; c++) { //per ogni colonna
            switch (temporanea[r][c]){ //se trovo uno dei tre valori nella tabella temporanea aumento il contatore
            case 'A':
                kA++;
                break;
            case 'B':
                kB++;
                break;
            case 'C':
                kC++;
                break;}
        }
    }
    return (kA * 2) + (kB * 5) + (kC * 10); //aggiorno il risultato e lo restituisco quando chiamo la funzione
}

void caduta (char (*tabella_gioco)[L]){
    int k = 0; //definisco un massimo di volte per ripetere l'azione, un po forzata ma efficace, non ottimizzata sicuramente
    while (k <10){
        for (int r = (L-1);r > 0; r--){ //per ogni riga dal basso
            for (int c = (L-1); c >= 0; c--) { //per ogni colonna da destra
                if (tabella_gioco[r][c] == ' ' && tabella_gioco [r-1][c] != '='){
                    swap (tabella_gioco[r][c], tabella_gioco[r-1][c]); //sposto in alto lo spazio vuoto
                }
            }
        }
        k++;
    }
}

void svuota (char (*matrice)[L]){
    for (int r = 0;r < L; r++){ //per ogni riga
        for (int c = 0; c < L; c++) { //per ogni colonna
            matrice[r][c]= ' '; //svuoto ogni cella
        }
    }
}

void leggiClassifica(){
    cout << " _______________" << endl
         <<  "|               |" << endl
          <<  "|   CLASSIFICA  |" << endl
           <<  "|_______________|" << endl << endl;

    ifstream ifs; //definisco il file da leggere
    string c; //definisco la stringa di salvataggio dei file letti
    int k = 1; //inizializzo la posizione

    ifs.open ("classifica.txt", ifstream::in);

    if (ifs.is_open()) { // se è aperto
        getline (ifs, c); //copio la riga
        while (ifs.good()) { //finchè non ho finito di leggere
            cout << k << ") " << c << ": "; //stampo il classificato e la sua posizione
            getline (ifs, c); //prelevo il suo punteggio
            cout << c << endl; // lo stampo
            getline (ifs, c);
            k++;
        }
    }
    else {
        cout << "Errore di apertura del file";
        PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
    }

    ifs.close(); //chiudo il file
}

void scriviSuClassifica (string nome, int punti)
{
    ifstream ifs; //inizializzo la variabile di lettura
    vector <string> nomiC; //inizializzo un vector di string contenete i nomi
    vector <int> puntiC; //uno contenente i rispettivi punteggi
    string n; //string per prelevare i nomi
    string p; //per i punteggi
    int pdec; //trasformazione in decimale della string

    ifs.open ("classifica.txt", ifstream::in);

    if (ifs.is_open()) {
        getline(ifs,n);
        while (ifs.good()) {
            nomiC.push_back (n); //copio il nome e salvo in vector
            getline(ifs,p);
            pdec = atoi(p.c_str()); //trasformo in decimale e salvo nel vector
            puntiC.push_back (pdec);
            getline(ifs, n);
        }
    }
    else {
        cout << "Errore di apertura del file";
        PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
    }

    ifs.close();

    nomiC.push_back(nome); //aggiungo l'ultimo nome
    puntiC.push_back(punti); //e l'ultimo punteggio ai rispettivi vector

    for (unsigned int k = 0; k < puntiC.size(); k++){ //per ogni punteggio salvato (ordino i punteggi)
        if (puntiC [k] < puntiC [k+1]){ //se il punteggio è minore del precedente
            swap (puntiC[k], puntiC[k+1]); //scambio i punteggi
            swap (nomiC[k], nomiC[k+1]); //e i rispettivi nomi
        }
    }

    ofstream ofs; //inizializzo il file di scrittura
    ofs.open ("classifica.txt", ofstream::out);

    for (unsigned int r = 0; r < nomiC.size() ; r++){ //per ogni punteggio salvato
        ofs << nomiC [r] //stampo il nome
               << endl //a capo
               << puntiC [r] << endl;} //stampo il punteggio

    ofs.close();
}

void clean(int secondi){
    clock_t endwait; //inizializzo un contatore
    endwait = clock () + secondi * CLOCKS_PER_SEC ; //in base ai secondi prelevati dalla funzione
    while (clock() < endwait) //quando raggiunge 0
    {}
    system("cls"); //pulisci screen
}

void importaMatrice (char (*tabella_gioco)[L]){
    ifstream ifs; //inizializzo if
    char car;
    int r = 0;
    int c = 0;

    ifs.open ("scacchiera.txt", ifstream::in); //determino il file da aprire

    if (ifs.is_open()) { //se è aperto procedo
        car = ifs.get(); //salvo il carattere
        tabella_gioco[0][0] = car; //e lo scrivo nella cella
        car = ifs.get();
        while (ifs.good()) {
            if (car == ';' && r < L - 1){ //se trovo un ";" e non sono all'ultima riga
                car = ifs.get();
                r++; //aumento la riga
                c = 0; //riazzero la colonna
                tabella_gioco [r][c] = car;
            }
            if (car == ',' && c < L - 1){ //se trovo una "," e non sono all'ultima colonna
                car = ifs.get();
                c++; //colonna successiva
                tabella_gioco [r][c] = car;
            }
            car = ifs.get();
        }
    }
    else {
        cout << "Errore di apertura della scacchiera";
        PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
    }

    ifs.close();
}

void esportaMatrice (char (*tabella_gioco)[L], int punti, int turni){
    ofstream ofs;
    ofs.open ("scacchiera-finale.txt", ofstream::out);

    ofs << "ELABORAZIONE DOPO " << turni << " MOSSE" << endl << endl;

    for (size_t c=0; c<L;c++){ //per ogni colonna
        if (c == 0) //se è la prima aggiungo diversi spazi ed il numero 1
            ofs << ' ' << ' ' << ' ' << c+1;
        else //nelle seguenti un solo spazio e i successivi numeri
            ofs << ' ' << c+1;
    }
    ofs << endl;
    for (int r=0; r<L; r++){ //per ogni riga
        if (r < 9) //se i numeri delle righe sono minuri di 9 aggiungo uno spazio, per pareggiare la distanza con la colonna 10
            ofs <<' ';
        ofs << r + 1 << "|"; //inserisco sempre il numero di riga
        for (int c=0; c<L; c++){ //per ogni colonna
            ofs << tabella_gioco [r][c]; //inserisco il valore della tabella di gioco attuale
            ofs << "|"; //inserisco uno spaziatore per leggere meglio la tabella
        } ofs << endl;
    } ofs << endl;

    ofs << "PUNTEGGIO OTTENUTO: " << punti << endl;

    ofs.close();
}

bool suggerimento (char (*tabella_gioco)[L]) {
    do{
        cout << "Vuoi un suggerimento? (s/n) " << endl;
        char choice;
        cin >> choice;
        PlaySound (TEXT("Click.wav"), NULL, SND_FILENAME);
        if (choice != 's' && choice != 'n'){
            cout << "Risposta non valida, riprovare." << endl;
            PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
        } else if (choice == 's'){
            for (int r = L-2; r > 1; r--) //per ogni riga dalla penultima
                for (int c = L-2; r > 1; c--){ //e colonna dalla penultima
                    swap (tabella_gioco[r][c],tabella_gioco[r+1][c+1]); //scambio con la colonna in basso a destra
                    if (verificaTuttiTris(tabella_gioco,r,c)){ //se c'è un tris
                        swap (tabella_gioco[r][c],tabella_gioco[r+1][c+1]);
                        cout << "spostare in basso a destra la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r+1][c]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r+1][c]);
                        cout << "spostare in basso la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r+1][c]);
                    swap (tabella_gioco[r][c],tabella_gioco[r+1][c-1]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r+1][c-1]);
                        cout << "spostare in basso a sinistra la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r+1][c-1]);
                    swap (tabella_gioco[r][c],tabella_gioco[r][c+1]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r][c+1]);
                        cout << "spostare a destra la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r][c+1]);
                    swap (tabella_gioco[r][c],tabella_gioco[r][c-1]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r][c-1]);
                        cout << "spostare a sinistra la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r][c-1]);
                    swap (tabella_gioco[r][c],tabella_gioco[r-1][c+1]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r-1][c+1]);
                        cout << "spostare in alto a destra la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r-1][c+1]);
                    swap (tabella_gioco[r][c],tabella_gioco[r-1][c]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r-1][c]);
                        cout << "spostare in alto la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r-1][c]);
                    swap (tabella_gioco[r][c],tabella_gioco[r-1][c-1]);
                    if (verificaTuttiTris(tabella_gioco,r,c)){
                        swap (tabella_gioco[r][c],tabella_gioco[r-1][c-1]);
                        cout << "spostare in alto a sinistra la cella [" << r+1 << "][" << c+1 << "]" << endl;
                        return 1;
                    }
                    swap (tabella_gioco[r][c],tabella_gioco[r-1][c-1]);
                }
        } else if (choice == 'n')
            return 0;
    } while (true);
    cout << "Nessun tris possibile!" << endl;
    return 0;
}

int main()
{
    int turni = 15;
    int colonna, riga;
    int punti = 0;
    char move = 's';
    char choice;
    bool valid = 0;

    string s;
    fstream f;

    char tabella_gioco [L][L] = {}; //tabella di gioco principale

    char temporanea[L][L] = {}; //tabella dove vengono salvati i tris, utile per cancellarli da quella principale e calcolare il punteggio
    char tabellaAppoggio [L][L] = {}; //tabella di appoggio nel Caso Limite

    srand (time(NULL));

    do{
        cout << "Vuoi visualizzare la classifica(s/n)? ";
        cin >> choice;
        PlaySound (TEXT("Click.wav"), NULL, SND_FILENAME);
        if (choice != 's' && choice != 'n'){
            cout << "Risposta non valida, riprovare." << endl;
            PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
        }
        else{
            if (choice == 's'){
                leggiClassifica();
                clean (10);
            }
            break;}
    }while (true);

    clean (0);

    do{
        cout << "Selezionare modalita' di gioco: " << endl
             << "MODALITA' INTERATTIVA (1)" << endl
             << "MODALITA' SEQUENZIALE (2)" << endl;
        cin >> choice;
        PlaySound (TEXT("Click.wav"), NULL, SND_FILENAME);
        if (choice != '1' && choice != '2'){
            cout << "Risposta non valida, riprovare." << endl;
            PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
        } else if (choice == '1') {
            clean (0);
            PlaySound (TEXT("Start.wav"), NULL, SND_FILENAME);
            cout << "INIZIO GIOCO INTERATTIVO" << endl;
            clean (1);

            assegna (tabella_gioco,0,0); //assegna valori alla matrice originale di gioco

            stamp (tabella_gioco);

            cout << "Hai a disposizione " << turni << " mosse." << endl;

            while (turni > 0){

                suggerimento (tabella_gioco);

                cout << "Inserire il numero di riga della casella desiderata: ";
                while (true)
                {
                    if ((cin >> riga) && (riga >= 1) && (riga <= L)) break;
                    cout << "Valore non corretto, inserire un altro valore: ";
                    PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Inserire il numero di colonna della casella desiderata: ";
                while (true)
                {
                    if ((cin >> colonna) && (colonna >= 1) && (colonna <= L)) break;
                    cout << "Valore non corretto, inserire un altro valore: ";
                    PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                riga = riga -1;
                colonna = colonna -1;

                cout << "Scegliere la mossa: " << endl <<
                        "- 'w'(in alto)" << endl <<
                        "- 'x'(in basso)" << endl <<
                        "- 'a'(a sinistra)" << endl <<
                        "- 'd'(a destra)" << endl <<
                        "- 'q'(in alto a sinistra)" << endl <<
                        "- 'e'(in alto a destra)" << endl <<
                        "- 'z'(in basso a sinistra)" << endl <<
                        "- 'c'(in basso a destra)" << endl;
                while (cin >> move) {
                    //chiedo di inserire la mossa

                    valid = false;

                    switch (move){ //modifico la tabella a seconda della scelta del giocatore
                    case 'w':
                        if (riga<=0){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna], tabella_gioco[riga-1][colonna]);
                            valid = true;}
                        break;
                    case 'x':
                        if (riga>=L-1){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga+1][colonna]);
                            valid = true;}
                        break;
                    case 'a':
                        if (colonna <=0){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga][colonna-1]);
                            valid = true;}
                        break;
                    case 'd':
                        if (colonna>=L-1){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga][colonna+1]);
                            valid = true;}
                        break;
                    case 'q':
                        if (riga<=0 || colonna <=0){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga-1][colonna-1]);
                            valid = true;}
                        break;
                    case 'e':
                        if (riga<=0 || colonna>=L-1){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga-1][colonna+1]);
                            valid = true;}
                        break;
                    case 'z':
                        if (riga>=L-1 || colonna <=0){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga+1][colonna-1]);
                            valid = true;}
                        break;
                    case 'c':
                        if (riga>=L-1 || colonna >=L-1){
                            cout << "Mossa non consentita, riprovare: ";
                            break;}
                        else{
                            swap (tabella_gioco[riga][colonna],tabella_gioco[riga+1][colonna+1]);
                            valid = true;}
                        break;
                    default:
                        cout << "Valore inserito non corretto, riprovare: ";
                    }
                    if (valid == true)
                        break;
                    else
                        PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
                }

                clean (0.5);

                stamp (tabella_gioco);

                do{

                    clean (1);

                    punti = punti + punteggio (temporanea); //aggiorna il punteggio

                    svuota (temporanea); //svuota la temporanea per evitare errori

                    if (verifica (tabella_gioco,temporanea) == false){
                        PlaySound (TEXT("Tris.wav"), NULL, SND_FILENAME);
                    }
                        //verifico i tris e li elimino

                    stamp (tabella_gioco); //verifica

                    clean (1);

                    //stampa (temporanea); //verifica

                    caduta (tabella_gioco); //effetto gravità

                    stamp (tabella_gioco); //verifica

                }while (verifica (tabella_gioco,temporanea)!= true);

                svuota (temporanea);

                //stampa(tabella_gioco); //verifica

                if (assegna (tabella_gioco,0,0) == false){
                    PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
                    cout << "E' stato rilevato un caso limite, attendi e verra' parzialmente modificata l'attuale matrice." << endl;
                    do {
                        if (assegna (tabella_gioco,0,0) == false){
                            casoLimite (tabella_gioco,tabellaAppoggio);}

                        svuota (temporanea); //svuota la temporanea per evitare errori

                        verifica (tabella_gioco, temporanea);

                        caduta (tabella_gioco);

                    } while (verifica(tabella_gioco, temporanea) == false);
                }

                clean (1);

                stamp (tabella_gioco);

                turni--; //riduco le mosse a disposizione

                if (turni > 0){ //se ci sono ancora turni

                    cout << "Punti= " << punti << endl;

                    cout << "Turni rimanenti: " << turni << endl;
                }

            }

            if (turni == 0){ //quando i turni sono terminati

                string nome;
                PlaySound (TEXT("Finish.wav"), NULL, SND_FILENAME);
                cout << "Congratulazioni, hai ottenuto: " << punti << " punti." << endl;
                cout << "Inserisci il tuo nome per salvare il tuo punteggio nella classifica: "<< endl;
                cin >> nome;
                scriviSuClassifica(nome, punti);
                do{
                    cout << "Vuoi vedere la classifica aggiornata(s/n)?";
                    cin >> choice;
                    if (choice != 's' && choice != 'n'){
                        cout << "Risposta non valida riprovare." << endl;
                        PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
                    }
                    else{
                        if (choice == 's'){
                            leggiClassifica();
                        }
                        break;}
                }while (true);

            }
        } else if (choice == '2'){
            clean (0);
            cout << "IMPORTO MATRICE" << endl;
            importaMatrice(tabella_gioco);

            ifstream ifs;
            char car;
            int num;
            int mossa;
            int colonne [15] = {};
            int righe [15] = {};
            int mosse [15] = {};
            int k = 0;

            ifs.open ("mosse.txt", ifstream::in);

            if (ifs.is_open()) {
                car = ifs.get();
                while (ifs.good()) {
                    if (k >= turni){
                        break;
                    }
                    if (car != ';'){
                        if (car >= '0' && car <= '9'){
                            num = car - '0';
                            righe [k] = num;
                        }
                        car = ifs.get();
                        num = car - '0';
                        colonne [k] = num;

                        car = ifs.get();
                        num = car - '0';
                        mosse [k] = num;

                        car = ifs.get();

                    }
                    if (car == ';'){
                        k++;
                        car = ifs.get();
                    }
            }
            }
            else {
                cout << "Errore di apertura del file delle mosse";
                PlaySound (TEXT("Error.wav"), NULL, SND_FILENAME);
                return -1;
            }
            ifs.close();
            clean (0);
            cout << "ELABORO IL RISULTATO" << endl;
            for (int k = 0; k < turni; k++){
                riga = righe [k];
                colonna = colonne [k];
                mossa = mosse [k];

                if (mossa == 1){
                    if (riga<=0){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna], tabella_gioco[riga-1][colonna]);}
                }
                else if (mossa == 2){
                    if (riga>=L-1){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga+1][colonna]);}
                }
                else if (mossa == 4){
                    if (colonna <=0){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga][colonna-1]);}
                }
                else if (mossa == 3){
                    if (colonna>=L-1){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga][colonna+1]);}
                }
                else if (mossa == 6){
                    if (riga<=0 || colonna <=0){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga-1][colonna-1]);}
                }
                else if (mossa == 5){
                    if (riga<=0 || colonna>=L-1){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga-1][colonna+1]);}
                }
                else if (mossa == 8){
                    if (riga>=L-1 || colonna <=0){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga+1][colonna-1]);}
                }
                else if (mossa == 7){
                    if (riga>=L-1 || colonna >=L-1){
                        break;}
                    else{
                        swap (tabella_gioco[riga][colonna],tabella_gioco[riga+1][colonna+1]);}
                }

                do{

                    punti = punti + punteggio (temporanea); //aggiorna il punteggio

                    svuota (temporanea); //svuota la temporanea per evitare errori

                    verifica (tabella_gioco,temporanea); //verifico i tris e li elimino

                    caduta (tabella_gioco); //effetto gravità

                }while (verifica (tabella_gioco,temporanea)!= true);

                svuota (temporanea);

                if (assegna (tabella_gioco,0,0) == false){
                    do {
                        if (assegna (tabella_gioco,0,0) == false){
                            casoLimite (tabella_gioco,tabellaAppoggio);}

                        svuota (temporanea); //svuota la temporanea per evitare errori

                        verifica (tabella_gioco, temporanea);

                        caduta (tabella_gioco);

                    } while (verifica(tabella_gioco, temporanea) == false);
                }
            }

            clean (0);
            PlaySound (TEXT("Finish.wav"), NULL, SND_FILENAME);
            cout << "RISULTATO ESPORTATO" << endl;
            esportaMatrice(tabella_gioco, punti, turni);
            return 1;
        }
    }while (true);

    return 0;
}
