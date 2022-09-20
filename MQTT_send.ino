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
 StaticJsonDocument<384> doc;

doc["Machine_name"] = "UCC_01";
doc["Product_name"] = "1351824120";
doc["Date"] = "12";
doc["Time"] = "10";

JsonObject To_Mqtt = doc.createNestedObject("To_Mqtt");
To_Mqtt["Power_on"] = "xyz";
To_Mqtt["Power_off"] = "xyz";
To_Mqtt["Operation_time"] = "xyz";
To_Mqtt["Idle_time"] = "xyz";
To_Mqtt["Cycle_time"] = "Fuck";

JsonArray To_Mqtt_Output = To_Mqtt.createNestedArray("Output");
To_Mqtt_Output.add(content1);
To_Mqtt_Output.add(content2);

char buffersendnew[400];
serializeJson(doc, buffersendnew);
  
//  serializeJson(doc, Serial);


  uint16_t packetIdPub1 = mqttClient.publish("Nothing", 1, true, buffersendnew);                            
//  Serial.printf("Publishing on topic %s at QoS 1, packetId: %i", "Nothing", packetIdPub1);
}
