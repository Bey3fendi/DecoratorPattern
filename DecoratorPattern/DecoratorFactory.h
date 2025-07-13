#pragma once
#include "DecoratorPattern.h"

const enum StackNotification {
	kEmailNotify,
	kFacebookNotify,
	kSMSNotify,
	kSMSandEmailNotify,
	kFacebookandEmailNotify,
	kAllOfThemTogether
};


class DecoratorFactory {
public:
	std::shared_ptr<INotifier> create(StackNotification sn) {
        std::shared_ptr<INotifier> in;

        if (sn == kEmailNotify) {
            // Plain email notifier
            in = std::make_shared<Notifier>();

        }
        else if (sn == kFacebookNotify) {
            // Facebook decorator around the base notifier
            auto base = std::make_shared<Notifier>();
            in = std::make_shared<FaceBookNotifyDecorator>(base);

        }
        else if (sn == kSMSNotify) {
            // SMS decorator around the base notifier
            auto base = std::make_shared<Notifier>();
            in = std::make_shared<SMSNotifyDecorator>(base);

        }
        else if (sn == kSMSandEmailNotify) {
            // First wrap base in a generic decorator, then SMS
            auto base = std::make_shared<Notifier>();
            auto decorated = std::make_shared<BaseDecorator>(base);
            in = std::make_shared<SMSNotifyDecorator>(decorated);

        }
        else if (sn == kFacebookandEmailNotify) {
            // First wrap base in a generic decorator, then Facebook
            auto base = std::make_shared<Notifier>();
            auto decorated = std::make_shared<BaseDecorator>(base);
            in = std::make_shared<FaceBookNotifyDecorator>(decorated);

        }
        else if (sn == kAllOfThemTogether) {
            // Base → generic decorator → Facebook → SMS
            auto base = std::make_shared<Notifier>();
            auto dec1 = std::make_shared<BaseDecorator>(base);
            auto dec2 = std::make_shared<FaceBookNotifyDecorator>(dec1);
            in = std::make_shared<SMSNotifyDecorator>(dec2);

        }
        else {
            // (Optional) handle unknown sn values
            throw std::invalid_argument("Unknown notification type");
        }


		return in;
	}
};