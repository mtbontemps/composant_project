#include <sstream>

#include "mineur.hpp"
#include "hasheur.h"

void creerBloc(TX::TX tx, char previous_hash[]) {
    
    TXI *txi = tx.txi;
    int nbBloc = txi->nBloc;
    
    unsigned char destTmp [] = "destinaire";
    unsigned char* dest = &destTmp[0];
    string destAsString(reinterpret_cast<char*>(dest));
    
    std::ostringstream o;
    o << nbBloc << txi->nTx << txi->nUtxo << tx.utxo->montant << destAsString;
    
    UTXO *utxoMineur = new UTXO(100, dest, hashChaine(o.str()));
    TXM *txm = new TXM(utxoMineur);
    
    Bloc *newBloc = new Bloc(nbBloc, 0, tx, *txm, previous_hash);
    
    bool b = false;
    int nonce = 0;
    while(b == false) {
        newBloc->nonce = 0;
        unsigned char *newHash = hashChaine(blocToString(*newBloc));
        
        if(checkHash("", "")) {
            const char* t = reinterpret_cast<const char *>(newHash);
            std::strcpy(newBloc->hash , t);
            return;
        } else {
            nonce++;
        }
    }
}
