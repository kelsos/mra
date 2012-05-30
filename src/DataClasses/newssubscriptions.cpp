#include "newssubscriptions.h"

NewsSubscriptions::NewsSubscriptions()
{
    //ctor
}

NewsSubscriptions::NewsSubscriptions(unsigned int subscriptionId,
                                     QString subscriptionUrl, QString subscriptionChannelName)
{
    this->subscriptionId = subscriptionId;
    this->subscriptionUrl = subscriptionUrl;
    this->subscriptionChannelName = subscriptionChannelName;
}

NewsSubscriptions::~NewsSubscriptions()
{
    //dtor
}

void NewsSubscriptions::clear()
{
    this->subscriptionId = 0;
    this->subscriptionUrl = "";
    this->subscriptionChannelName = "";
}
