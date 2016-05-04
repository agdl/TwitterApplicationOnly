#include <Base64.h>
#include <TwitterApplicationOnly.h>

// Wifi needed parameters
String ssid = "yourNetwork";
String pass = "yourPassword";

int keyIndex = 0; // your network key Index number (needed only for WEP)

// Used to make Oauth requests
const String OauthConsumerKey = "yourConsumerKey"; // found in your application details
const String OauthSecretKey = "yourSecretKey"; // found in your application details
const String accessToken = "yourAccessToken"; // generate it in your application
const String accessTokenSecret = "yourTokenSecret"; // generate it in your application

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);

  if (!TwitterApplicationOnly.begin(ssid, pass, "api.twitter.com"))
    while (1);  // cannot continue

  TwitterApplicationOnly.setCredentials(OauthConsumerKey, OauthSecretKey, accessToken, accessTokenSecret);

  Serial.println();
  Serial.println("Requesting access token...");
  String bearer = TwitterApplicationOnly.getBearer();
  Serial.print("Your bearer token is: ");
  Serial.println(bearer);
  Serial.println();

  TwitterApplicationOnly.getUserTimeline("twitterapi", 2); //get last 2 tweets
}

void loop() {
  // put your main code here, to run repeatedly:
}
