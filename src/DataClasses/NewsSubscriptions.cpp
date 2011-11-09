#include "NewsSubscriptions.h"

NewsSubscriptions::NewsSubscriptions() {
	//ctor
}

NewsSubscriptions::NewsSubscriptions(unsigned int subscriptionId,
		QString subscriptionUrl, QString subscriptionChannelName) {
	this->subscriptionId = subscriptionId;
	this->subscriptionUrl = subscriptionUrl;
	this->subscriptionChannelName = subscriptionChannelName;
}

NewsSubscriptions::~NewsSubscriptions() {
	//dtor
}
