#ifndef mineur_hpp
#define mineur_hpp

#include "bloc.hpp"
#include <stdio.h>
#include <iostream>

/*
 * La méthode créerBloc() du Mineur est appelée par le Wallet lorsqu’un utilisateur fait une transaction.
 * Le mineur itère un certain nombre de fois pour trouver le nonce du bloc
 * permettant d’avoir un hash respectant une forme particulière.
 * La forme particulière du hash est un nombre de bits de poids fort à 0.
 * Ce nombre de bits représente la difficulté et doit être tel que la durée nécessaire moyenne 
 * pour trouver le nonce soit de 30 secondes.
 * Le nombre de bits (la difficulté) est donc à déterminer par les développeurs du mineur en tâtonnant.
 * Le bloc à créer sera composé de deux transactions; celle de l’utilisateur 
 * + celle qui permet de rémunérer le mineur (création monétaire)
 * La transaction de création monétaire n’a pas de bitcoins, ni d’émetteur en entrée 
 * (l’argent est créé à partir de rien)
 * Une fois le nonce trouvé, le bloc est renvoyé en résultat.
 */
void creerBloc(TX::TX tx, char *previous_hash);

#endif /* mineur_hpp */
