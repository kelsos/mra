#ifndef NEWSSUBSCRIPTIONS_H
#define NEWSSUBSCRIPTIONS_H

#include <wx/wx.h>

class NewsSubscriptions {
public:
	/** Default constructor */
	NewsSubscriptions();
	NewsSubscriptions(unsigned int subscriptionId, wxString subscriptionUrl,
			wxString subscriptionChannelName);
	/** Default destructor */
	virtual ~NewsSubscriptions();
	/** Access subscriptionId
	 * \return The current value of subscriptionId
	 */
	unsigned int getSubscriptionId() {
		return subscriptionId;
	}
	/** Set subscriptionId
	 * \param val New value to set
	 */
	void SetsubscriptionId(unsigned int val) {
		subscriptionId = val;
	}
	/** Access subscriptionUrl
	 * \return The current value of subscriptionUrl
	 */
	wxString getSubscriptionUrl() {
		return subscriptionUrl;
	}
	/** Set subscriptionUrl
	 * \param val New value to set
	 */
	void SetsubscriptionUrl(wxString val) {
		subscriptionUrl = val;
	}
	/** Access subscriptionChannelName
	 * \return The current value of subscriptionChannelName
	 */
	wxString getSubscriptionChannelName() {
		return subscriptionChannelName;
	}
	/** Set subscriptionChannelName
	 * \param val New value to set
	 */
	void SetsubscriptionChannelName(wxString val) {
		subscriptionChannelName = val;
	}
protected:
private:
	unsigned int subscriptionId; //!< Member variable "subscriptionId"
	wxString subscriptionUrl; //!< Member variable "subscriptionUrl"
	wxString subscriptionChannelName; //!< Member variable "subscriptionChannelName"
};

#endif // NEWSSUBSCRIPTIONS_H
