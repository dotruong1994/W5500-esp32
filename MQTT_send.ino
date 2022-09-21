void sendSample(){
  dem++;
  StaticJsonDocument<128> doc;
  doc.clear();
  doc["Machine name"] = "UCC";
  doc["Product name"] = "ABCXYZ";
  doc["Output"] = sendContent;
  doc["Date"] = timeHour1;
  doc["Time"] = timeHour3;
  char buffersend[128];

//  serializeJson(doc, Serial);
  serializeJson(doc, buffersend);


  uint16_t packetIdPub1 = mqttClient.publish("Nothing", 1, true, buffersend);                            
  Serial.printf("Publishing on topic %s at QoS 1, packetId: %i", "Nothing", packetIdPub1);
//  Serial.printf("Message: %.2f \n", content);
}

void sendNew(){
 StaticJsonDocument<256> doc;

  doc["Machine_name"] = "UCC_01";
  doc["Product_name"] = "1351824120";
  doc["Date"] = "12";
  doc["Time"] = "10";
  
  JsonObject To_Mqtt = doc.createNestedObject("To_Mqtt");
  
  JsonArray To_Mqtt_Power_on = To_Mqtt.createNestedArray("Power_on");
  To_Mqtt_Power_on.add(PowerOnTD_1);
  To_Mqtt_Power_on.add(PowerOnTD_2);
  
  JsonArray To_Mqtt_Power_off = To_Mqtt.createNestedArray("Power_off");
  To_Mqtt_Power_off.add(PowerOffTD_1);
  To_Mqtt_Power_off.add(PowerOffTD_2);
  
  JsonArray To_Mqtt_Operation_time = To_Mqtt.createNestedArray("Operation_time");
  To_Mqtt_Operation_time.add(OPtimetoday_1);
  To_Mqtt_Operation_time.add(OPtimetoday_2);
  
  JsonArray To_Mqtt_Idle_time = To_Mqtt.createNestedArray("Idle_time");
  To_Mqtt_Idle_time.add(IdleTimetoday_1);
  To_Mqtt_Idle_time.add(IdleTimetoday_2);
  
  JsonArray To_Mqtt_Cycle_time = To_Mqtt.createNestedArray("Cycle_time");
  To_Mqtt_Cycle_time.add(STD_CT_1);
  To_Mqtt_Cycle_time.add(STD_CT_2);
  
  JsonArray To_Mqtt_Output = To_Mqtt.createNestedArray("Output");
  To_Mqtt_Output.add(quantity_1);
  To_Mqtt_Output.add(quantity_2);
  
  char buffersendnew[300];
  serializeJson(doc, buffersendnew);
  
//  serializeJson(doc, Serial);


  uint16_t packetIdPub1 = mqttClient.publish("Nothing", 1, true, buffersendnew);                            
//  Serial.printf("Publishing on topic %s at QoS 1, packetId: %i", "Nothing", packetIdPub1);
}
