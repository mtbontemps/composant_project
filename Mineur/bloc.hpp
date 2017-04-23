#pragma once
#ifndef _BLOC_H

// bloc.h  version 1.0
// projet blockchain M2IF 2017

#define KEY_SIZE 4 // taille en byte des cle (publique, privee) a valider avec les groupes specifiant et developpant la signature
#define HASH_SIZE 64  // taille du hash, a valider avec les groupes specifiant et developpant le hacheur

class TXI
{
public:
    unsigned int nBloc;
    unsigned int nTx;
    unsigned int nUtxo;
    
    unsigned char signature[HASH_SIZE];
    
    TXI();
    TXI(unsigned int, unsigned int, unsigned int, char*);
};

class UTXO
{
public:
    float montant;
    unsigned char dest[KEY_SIZE];  //compte destinataire
    
    unsigned char hash[HASH_SIZE];    // hash(nBloc,nTx,nUTXO,montant,destinataire) pour securisation de l'UTXO
    
    UTXO();
    UTXO(float, unsigned char*, unsigned char*);
};

class TX { // transaction standard
public:
    TXI txi[4];
    UTXO utxo[2];
    
    TX();
    TX(TXI*, UTXO*);
};

class TXM { // transaction du mineur
public:
    UTXO utxo[1];
    
    TXM();
    TXM(UTXO*);
};

class Bloc
{
public:
    char hash[HASH_SIZE]; // hash des autres champs
    
    char previous_hash[HASH_SIZE];
    unsigned int nonce;
    int num; // numero du bloc, commence a zero
    TX tx1; //  transaction du bloc
    TXM tx0; // transaction du mineur (coinbase)
    
    Bloc();
    Bloc(int, unsigned int, TX, TXM);
    Bloc(int, unsigned int, TX, TXM, char*);
    Bloc(int, unsigned int, TX, TXM, char*, char*);
};

#endif
