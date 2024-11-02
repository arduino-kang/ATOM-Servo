/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with Atom-Lite/Matrix sample source code
*                          配套  Atom-Lite/Matrix 示例源代码
* Visit for more information: https://docs.m5stack.com/en/products
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/products
*
* Describe: MultSerial.  多串口
* Date: 2021/8/5
******************************************************************************
*/
#include <M5Atom.h>
#include <Deneyap_Servo.h>

Servo myservo;  

void setup() {

    //M5.begin(Serial_Enable,I2C_Enable, LED_Enable)
    M5.begin(true, false, true);    

    Serial.begin(115200);  // Init Serial port.  初始化串口  


    // Light the LED with the specified RGB color 00ff00(Atom-Matrix has only one light). 
    // 以指定RGB颜色0x00ff00点亮第0个LED
    M5.dis.drawpix(0, 0x00ff00);

    Serial.println("Hello Servo!");
    myservo.attach(25);
    myservo.write(0);
    delay(3000);
}

int degree=0;
void loop() {
  
  degree = degree + 45;
  if (degree > 225) {
    degree = 0;
  }
  myservo.write(degree); 
  Serial.print("Degree: ");
  Serial.println(degree);
  delay(2000);
  
}