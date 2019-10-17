// This file is part of TON Desktop Wallet,
// a desktop application for the TON Blockchain project.
//
// For license and copyright information please follow this link:
// https://github.com/ton-blockchain/wallet/blob/master/LEGAL
//
#pragma once

#include "base/weak_ptr.h"

class QEvent;
class QKeyEvent;

namespace Ui {
class Window;
class LayerManager;
} // namespace Ui

namespace Ton {
class Wallet;
class AccountViewer;
} // namespace Ton

namespace Wallet {

class Window;
class Intro;
class Info;

class Application final : public base::has_weak_ptr {
public:
	explicit Application(const QString &path);
	Application(const Application &other) = delete;
	Application &operator=(const Application &other) = delete;
	~Application();

	void run();

private:
	void openWallet();
	void criticalError(const QString &text);

	const QString _path;
	const std::unique_ptr<Ton::Wallet> _wallet;
	std::unique_ptr<Wallet::Window> _window;

	rpl::lifetime _lifetime;

};

} // namespace Wallet