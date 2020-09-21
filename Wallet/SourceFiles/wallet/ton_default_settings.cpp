// This file is part of Gram Wallet Desktop,
// a desktop application for the TON Blockchain project.
//
// For license and copyright information please follow this link:
// https://github.com/ton-blockchain/wallet-desktop/blob/master/LEGAL
//
#include "wallet/ton_default_settings.h"

#include "ton/ton_settings.h"

#include <QtCore/QFile>

namespace Wallet {

Ton::Settings GetDefaultSettings() {
	auto result = Ton::Settings();

	auto main = QFile(":/config/mainnet.config.json");
	main.open(QIODevice::ReadOnly);
	result.main.config = main.readAll();
	result.main.blockchainName = "mainnet";
	result.main.configUrl = "https://freeton.broxus.com/mainnet.config.json";
	result.main.tokenContractAddress = "0:1e3869ea230fd7fd9a8bfce5a4b65cbd4f17fd0826c5f43873b446f63a4620d1";

	auto test = QFile(":/config/testnet.config.json");
	test.open(QIODevice::ReadOnly);
	result.test.config= test.readAll();
	result.test.blockchainName = "net.ton.dev";
	result.test.configUrl = "https://freeton.broxus.com/testnet.config.json";
	result.test.tokenContractAddress = "0:1e3869ea230fd7fd9a8bfce5a4b65cbd4f17fd0826c5f43873b446f63a4620d1";

	result.useNetworkCallbacks = false;
	result.useTestNetwork = false;
	result.version = 0;
	return result;
}

} // namespace Wallet
