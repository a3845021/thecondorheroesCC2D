#ifndef __GA_HELPER_H__
#define __GA_HELPER_H__
#ifdef SDKBOX_ENABLED
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"
#endif
#include <string>
using namespace std;


class GAHelper {
public:
	//static GAHelper *INSTANCE;
	GAHelper() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginGoogleAnalytics::init();
		sdkbox::PluginGoogleAnalytics::startSession();
#endif
	}

	void stopSession(std::string adname) {
#ifdef SDKBOX_ENABLED
		return sdkbox::PluginGoogleAnalytics::stopSession;
#endif
	}

	void startSession(std::string adname) {
#ifdef SDKBOX_ENABLED
		return sdkbox::PluginGoogleAnalytics::startSession();
#endif
	}

	void logEvent(string eventName, string eventAction, string eventContent, int eventValue) {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginGoogleAnalytics::logEvent(eventName, eventAction, eventContent, eventValue);
#endif
	}

	void logScreen(string screenName) {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginGoogleAnalytics::logScreen(screenName);
#endif
	}

	void sendDataNow() {
#ifdef SDKBOX_ENABLED
		sdkbox::PluginGoogleAnalytics::dispatchHit();
#endif
	}

	/*bool showFullAd() {
#ifdef SDKBOX_ENABLED
		if (isAvailable("gameover")) {
			sdkbox::PluginGoogleAnalytics::show("gameover");
			return true;
		}
		sdkbox::PluginGoogleAnalytics::cache("gameover");
		return false;
#endif
		return false;
	}*/
	

	static GAHelper* getInstance() {
		static  GAHelper *gaInstance;
		if (gaInstance == nullptr) {
			gaInstance = new GAHelper();
		}
		return gaInstance;
	}
};

#endif

