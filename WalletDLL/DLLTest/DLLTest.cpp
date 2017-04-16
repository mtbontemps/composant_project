// DLLTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wallet.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
{
	WalletDLL::wallet::walletDLLTest();
	
	std::vector<WalletDLL::wallet::Transaction*> v1(0);
	v1 = WalletDLL::wallet::getTransactions("#My Public Key#");
	if(v1.size() == 0)
	{
		std::cout << "No transaction match with this public key." << std::endl << std::endl;
	} 
	else 
	{
		std::cout << "Some transactions have been found." << std::endl << std::endl;
	}

	std::vector<WalletDLL::wallet::Transaction*> v2(0);
	v2 = WalletDLL::wallet::getHistory("#My Public Key#");
	if(v2.size() == 0)
	{
		std::cout << "No transaction match with this public key." << std::endl << std::endl;
	}
	else 
	{
		std::cout << "Some transactions have been found." << std::endl << std::endl;
	}

	double sum = 0;
	sum = WalletDLL::wallet::sumTransactions(v2);
	std::cout << "The total amount of those transactions is " << sum << "."<< std::endl << std::endl;
	
	WalletDLL::wallet::Transaction *t = new WalletDLL::wallet::Transaction();
	t->amount = 0.0;
	t->privateKey = "#private key#";
	t->publicKey = "#public key#";

	if(WalletDLL::wallet::newTransaction(t))
	{
		std::cout << "Transaction has been created." << std::endl << std::endl;
	}
	else 
	{
		std::cout << "Transaction creation failed." << std::endl << std::endl;
	}

	if(WalletDLL::wallet::sendTransaction(t))
	{
		std::cout << "Transaction has been sended." << std::endl << std::endl;
	}
	else 
	{
		std::cout << "Transaction sending failed." << std::endl << std::endl;
	}

	system("PAUSE");

	return 0;
}

