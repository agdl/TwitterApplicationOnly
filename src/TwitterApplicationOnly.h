/*
Copyright (C) 2016 Arturo Guadalupi. All right reserved.

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
*/

#ifndef TWITTER_APPLICATION_ONLY_H
#define TWITTER_APPLICATION_ONLY_H

#include <Arduino.h>
#include <SPI.h>
#include <WiFi101.h>
#include <Base64.h>

class TwitterApplicationOnlyClass
{
  public:
    WiFiClient client;

    int status = WL_IDLE_STATUS;
    bool begin(String networkName, String password, String server);
    void setCredentials(String oauthConsumerKey, String oauthSecretKey, String accessToken, String accessTokenSecret);
    String getBearer();
    void generateTimestamp(unsigned long epoch);

    void getUserTimeline(String screenName); //1 tweet only if no parameter
    void getUserTimeline(String screenName, int numberOfTweets);

    void printWifiStatus(void);

  private:
    String clientBufferString;
    String SSID;
    String pwd;
    String APIserver;
    String OauthConsumerKey;
    String OauthSecretKey;
    String BearerToken;
    String AccessToken;
    String AccessTokenSecret;
    String BaseString;

    String StatusTwitt;

    void generateBase64bearerToken(void);
    void generateBaseString(void);

    void extractBearer(void);
    void listen(void);
    //void urlEncode(Print &p, const char *src, bool progmem, bool x2);
};
extern TwitterApplicationOnlyClass TwitterApplicationOnly;

#endif
