#include <string> 
#include <vector> 
#pragma once

namespace WalletDLL 
{
	class wallet 
	{
	public:
		struct Transaction
		{
			std::string privateKey;
			std::string publicKey;
			double amount;
		};

		static _declspec(dllexport) void walletDLLTest();
		static _declspec(dllexport) std::vector<Transaction*> getTransactions(std::string publicKey);
		static _declspec(dllexport) std::vector<Transaction*> getHistory(std::string publicKey);
		static _declspec(dllexport) double sumTransactions(std::vector<Transaction*> transactions);
		static _declspec(dllexport) bool newTransaction(Transaction *transaction);
		static _declspec(dllexport) bool sendTransaction(Transaction *transaction);
	};
}