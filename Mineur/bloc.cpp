#include "bloc.hpp"

TX::TX() {}

TX::TX(TXI* txi, UTXO* utxo) {
    *this->txi = *txi;
    *this->utxo = *utxo;
}

TXI::TXI() {}

TXI::TXI(unsigned int nBloc, unsigned int nTx, unsigned int nUtxo, char* signature) {
    this->nBloc = nBloc;
    this->nTx = nTx;
    this->nUtxo = nUtxo;
    *this->signature = *signature;
}

TXM::TXM() {}

TXM::TXM(UTXO* utxo) {
    *this->utxo = *utxo;
}

UTXO::UTXO() {}

UTXO::UTXO(float montant, unsigned char* dest, unsigned char* hash) {
    this->montant = montant;
    *this->dest = *dest;
    *this->hash = *hash;
}

Bloc::Bloc() {}

Bloc::Bloc(int num, unsigned int nonce, TX tx1, TXM tx0) {
    this->num = num;
    this->nonce = nonce;
    this->tx1 = tx1;
    this->tx0 = tx0;
}

Bloc::Bloc(int num, unsigned int nonce, TX tx1, TXM tx0, char* previous_hash) {
    this->num = num;
    this->nonce = nonce;
    this->tx1 = tx1;
    this->tx0 = tx0;
    *this->previous_hash = *previous_hash;
}

Bloc::Bloc(int num, unsigned int nonce, TX tx1, TXM tx0, char* previous_hash, char* hash) {
    this->num = num;
    this->nonce = nonce;
    this->tx1 = tx1;
    this->tx0 = tx0;
    *this->previous_hash = *previous_hash;
    *this->hash = *hash;
}
