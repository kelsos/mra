#include "NewsSubscriptions.h"

NewsSubscriptions::NewsSubscriptions() {
	//ctor
}

NewsSubscriptions::NewsSubscriptions(unsigned int subscriptionId,
		wxString subscriptionUrl, wxString subscriptionChannelName) {
	this->subscriptionId = subscriptionId;
	this->subscriptionUrl = subscriptionUrl;
	this->subscriptionChannelName = subscriptionChannelName;
}

NewsSubscriptions::~NewsSubscriptions() {
	//dtor
}
