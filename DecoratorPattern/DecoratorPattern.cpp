#include <iostream>
#include "DecoratorPattern.h"
int main() {
	//std::shared_ptr<INotifier> in = std::make_shared<Notifier>();
	//std::shared_ptr<BaseDecorator> bd = std::make_shared<BaseDecorator>(in);
	//std::shared_ptr<FaceBookNotifyDecorator> fnd = std::make_shared<FaceBookNotifyDecorator>(bd);
	//std::shared_ptr<SMSNotifyDecorator> snd = std::make_shared<SMSNotifyDecorator>(fnd);

	auto in = std::make_shared<Notifier>();
	auto bd = std::make_shared<BaseDecorator>(in);
	auto fnd = std::make_shared<FaceBookNotifyDecorator>(bd);
	auto snd = std::make_shared<SMSNotifyDecorator>(fnd);
	ClientCode(*snd);
}

