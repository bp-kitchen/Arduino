#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>

const char *ssid     = "KOH Wifi";
const char *password = "kal2143912345";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
//NTPClient timeClient(ntpUDP, "pool.ntp.org");

String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin(); // Initialize a NTPClient to get time
  /*
  Set offset time in seconds to adjust for your timezone, for example:
  GMT +1 = 3600
  GMT +8 = 28800
  GMT -1 = -3600
  GMT 0 = 0
  */
  timeClient.setTimeOffset(28800);
}

void loop() {
  timeClient.update();

  unsigned long epochTime = timeClient.getEpochTime();
  Serial.print("Epoch Time: ");
  Serial.println(epochTime);

  String formattedTime = timeClient.getFormattedTime(); // HH:MM:SS
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);

  char hhmmss[formattedTime.length() + 1];
  strcpy(hhmmss, formattedTime.c_str());
  const char delim[2] = ":";
  String hhmmss_print[3] = {"Hours: ", "Minutes: ", "Seconds: "};
  int i = 0;
  char *token;
 
  token = strtok(hhmmss, delim); 
  while( token != NULL && i < 3) {
      //token = trimwhitespace(token);
      Serial.print(hhmmss_print[i++]);
      Serial.println(token);
      token = strtok(NULL, delim);
  } 

//timeClient.getHours(); timeClient.getMinutes(); timeClient.getSeconds();

  String weekDay = weekDays[timeClient.getDay()];
  Serial.print("Week Day: ");
  Serial.println(weekDay);

  //Get a time structure
  //http://www.cplusplus.com/reference/ctime/tm/
  struct tm *ptm = gmtime ((time_t *)&epochTime);

  int monthDay = ptm->tm_mday;
  Serial.print("Month day: ");
  Serial.println(monthDay);

  int currentMonth = ptm->tm_mon+1;
  Serial.print("Month: ");
  Serial.println(currentMonth);

  String currentMonthName = months[currentMonth-1];
  Serial.print("Month name: ");
  Serial.println(currentMonthName);

  int currentYear = ptm->tm_year+1900;
  Serial.print("Year: ");
  Serial.println(currentYear);

  //Print complete date:
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  Serial.print("Current date: ");
  Serial.println(currentDate);

  Serial.println("");

  delay(1000);
}
