#pragma once
#include <iostream>
class INotifier {
public:
	virtual ~INotifier() = default;

	virtual void SendNotify() = 0;
};

class Notifier : public INotifier {
public:
	void SendNotify() override {
		std::cout << "Basic Notify Sended!!\n";
	}
};

class BaseDecorator : public INotifier {
public:
	BaseDecorator(std::shared_ptr<INotifier> in) : m_in(in) {

	}

	void SendNotify() override {
		m_in->SendNotify();
	}

private:
	std::shared_ptr<INotifier> m_in;
};

class FaceBookNotifyDecorator : public BaseDecorator {
public:
	using BaseDecorator::BaseDecorator;
	void SendNotify() override {
		BaseDecorator::SendNotify();
		facebookNotifySender();
	}
private:
	void facebookNotifySender() {
		std::cout << " Notify Sended via facebook\n";
	}
	
};

class SMSNotifyDecorator : public BaseDecorator {
public:
	using BaseDecorator::BaseDecorator;
	void SendNotify() override {
		BaseDecorator::SendNotify();
		SMSNotifySender();
	}
private:
	void SMSNotifySender() {
		std::cout << " Notify Sended via SMS\n";
	}

};

void ClientCode(INotifier& notifier) {
	notifier.SendNotify();
}