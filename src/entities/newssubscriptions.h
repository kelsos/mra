#ifndef NEWSSUBSCRIPTIONS_H
#define NEWSSUBSCRIPTIONS_H

#include <QString>
#include <QDateTime>

class NewsSubscriptions
{
public:
    /** Default constructor */
    NewsSubscriptions();
    NewsSubscriptions(unsigned int subscriptionId, QString subscriptionUrl,
                      QString subscriptionChannelName);
    /** Default destructor */
    virtual ~NewsSubscriptions();
    /** Access subscriptionId
     * \return The current value of subscriptionId
     */
    unsigned int getSubscriptionId()
    {
        return subscriptionId;
    }
    /** Set subscriptionId
     * \param val New value to set
     */
    void SetsubscriptionId(unsigned int val)
    {
        subscriptionId = val;
    }
    /** Access subscriptionUrl
     * \return The current value of subscriptionUrl
     */
    QString getSubscriptionUrl()
    {
        return subscriptionUrl;
    }
    /** Set subscriptionUrl
     * \param val New value to set
     */
    void SetsubscriptionUrl(QString val)
    {
        subscriptionUrl = val;
    }
    /** Access subscriptionChannelName
     * \return The current value of subscriptionChannelName
     */
    QString getSubscriptionChannelName()
    {
        return subscriptionChannelName;
    }
    /** Set subscriptionChannelName
     * \param val New value to set
     */
    void SetsubscriptionChannelName(QString val)
    {
        subscriptionChannelName = val;
    }
    /** Clears the objects values
     *
     */
    void clear();
protected:
private:
    unsigned int subscriptionId; //!< Member variable "subscriptionId"
    QString subscriptionUrl; //!< Member variable "subscriptionUrl"
    QString subscriptionChannelName; //!< Member variable "subscriptionChannelName"
};

#endif // NEWSSUBSCRIPTIONS_H
