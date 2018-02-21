#ifndef ARDUINO_CLOUD_V2_H
#define ARDUINO_CLOUD_V2_H

#include <MQTTClient.h>
#include <ArduinoBearSSL.h>

#include "CloudSerial.h"

class ArduinoCloudClass {

public:
  ArduinoCloudClass();
  ~ArduinoCloudClass();

  int begin(Client& net);

  int connect();

  void poll();

  void onGetTime(unsigned long(*)(void));

  int connected();

protected:
  friend class CloudSerialClass;
  int writeStdout(const byte data[], int length);

private:
  static void onMessage(MQTTClient *client, char topic[], char bytes[], int length);

  void handleMessage(char topic[], char bytes[], int length);

private:
  String _id;
  BearSSLClient* _bearSslClient;
  MQTTClient _mqttClient;

  String _stdinTopic;
  String _stdoutTopic;
};


extern ArduinoCloudClass ArduinoCloud;

#endif
