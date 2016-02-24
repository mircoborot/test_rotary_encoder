
/* ---------------------------------------------------------
Package     :  wifs v.1
Module      :  tester rotary encoder
Copyright   :  (c) 2016 by Antonio Curci 

Copyright 2014-2016 by Antonio Curci. All rights reserved.
Redistribution and use in source and binary forms,
with or without modification, are not permitted.
-------------------------------------------------------- */

#define pr(a,b) {Serial.print(a);Serial.print(b);}

const byte 
  PIN_ENC_A = 4,
  PIN_ENC_B = 5,
  PIN_ENC_S = 6;

int encx=0;

void encsetup() {
  pinMode(PIN_ENC_A,INPUT_PULLUP); // logica negativa
  pinMode(PIN_ENC_B,INPUT_PULLUP); // logica negativa
  pinMode(PIN_ENC_S,INPUT_PULLUP); // logica negativa
  Serial.begin(9600);
  pr("\r\nTester rotary encoder v.01.01 \n(C) Copyright 2014-2016 by Curci\r\n","\nCommands: none\n"); 
} 

byte encina() {return !digitalRead(PIN_ENC_A);}
byte encinb() {return !digitalRead(PIN_ENC_B);}
byte encins() {return !digitalRead(PIN_ENC_S);}

void setup() {encsetup();}

void loop() {
  static bool 
    ap=0,
    sp=0;
  bool a, s;
  
  a=encina();
  if (!ap && a) {
    //if (encinb()) encx++; else encx--;
    if (encinb()) encx--; else encx++;
    pr(encx,"\n");
  }
  ap=a;
  
  s=encins();
  if (!sp && s) {pr("BEEP","\n");delay(15);}
  sp=s;
  
  
  
}

