void handleData(ModbusMessage response, uint32_t token) 
{
  //Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
  //Serial.println(response);
  for (auto& byte : response) {
    Serial.printf("%02X ", byte);
  }
  quantity_1 = response[1];
  quantity_2 = response[2];
  //-----------------------
  STD_CT_1 = response[3];
  STD_CT_2 = response[4];  
  //-----------------------
  PowerOnTD_1 = response[9];
  PowerOnTD_2 = response[10];
  //-----------------------
  PowerOffTD_1 = response[11];
  PowerOffTD_2 = response[12]; 
  //-----------------------
  OPtimetoday_1 = response[13];
  OPtimetoday_2 = response[14];   
  //-----------------------
  IdleTimetoday_1 = response[15];
  IdleTimetoday_2 = response[16];
}

// Define an onError handler function to receive error responses
// Arguments are the error code returned and a user-supplied token to identify the causing request
void handleError(Error error, uint32_t token) 
{
  // ModbusError wraps the error code and provides a readable error message for it
  ModbusError me(error);
  Serial.printf("Error response: %02X - %s\n", (int)me, (const char *)me);
}
