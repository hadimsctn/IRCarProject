<h3 align="center">IR Car project</h3>

<p align="center"> A project help control the car with IR Remote<br> </p>

## 📝 Table of Contents
- [About](#about)
- [Getting Started](#getting_started)
- [Bill of Material](#billofmaterial)
- [Hardware Schematic](#hardwareschematic)
- [Software Concept](#softwareconcept)
- [Authors](#authors)

## 🧐 About <a name = "about"></a>
This project using IR Receiver to Receive Data from Remote for control the car

## 🏁 Getting Started <a name = "getting_started"></a>

## 🚀 Bill of Material <a name = "billofmaterial"></a>
1. 2x DC Motor https://nshopvn.com/product/dong-co-dc-giam-toc-vang-2-truc-148/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/7b0982d9-df1e-4233-9808-3a002e9252c7)
2. 4x Battery 18650 2000mAh https://nshopvn.com/product/pin-cell-18650-2000mah/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/a60fa53d-1283-4aab-b2b6-d2fecd56f5df)
3. 1x TP4056 https://nshopvn.com/product/mach-sac-pin-tp4056-co-ic-bao-ve/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/95d0e22f-3f2b-4304-b3bf-fc09e2af8224)
4. 1x L298N https://nshopvn.com/product/mach-dieu-khien-dong-co-dc-l298n/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/007c77c9-9dd9-4e30-aef7-64c6cc108bee)
5. 1x ESP32 https://dientutuyetnga.com/products/mach-thu-phat-esp32-nodemcu-typec-ch340-esp-wroom-32
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/798203ad-3659-45c7-af39-d76c8e773fac)
6. 1x HC-SR04 https://nshopvn.com/product/cam-bien-sieu-am-hc-sr04/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/8dc341a2-cc23-4567-8ac6-327ce09ffd74)
7. 2x Diode IR https://www.cytrontech.vn/c-sensor/p-ir-receiver-diode-vs1838b-38khz
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/9db3a32d-65f0-430d-85e0-ce5b7c193c05)
8. 1x Buzzer https://shopee.vn/product/148048328/4974689853?gsht=sjFxkDeGHTM5gwwS
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/3784d847-cbee-4f9c-bd94-da95fd686fd4)
9. 1x LTC1971 https://shopee.vn/Modul-t%C4%83ng-%C3%A1p-Boost-DC-DC-100W-250W-400W-15A-i.795121397.25674220538
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/4f4dfaa6-6abd-4d97-81f9-f30ba33ed8be)

## ⛏️ Hardware Schematic <a name = "hardwareschematic"></a>
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/a8e4e762-658e-49a0-899c-7e3f550406ff)

## 🎉 Software Concept <a name = "softwareconcept"></a>
1. This car uses 1 SR04 for emergency braking<br/>
When encountering an obstacle at a distance of 10cm, the car will emergency brake and turn on the buzzer
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/1c4b972b-957f-40cc-898e-e79533a7d562)
2. This car receive IR signal to control.
- When signal is 0xFF18E7 or 0xFF4AB5, set the pin for go ahead or go back.
- ![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/24b4760c-819e-426b-8580-2f3d459485f6)
- ![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/8ec29992-4f7e-46de-99b1-b21b41fc6e98)
- When signal is 0xFF5AA5, car turn left. Turn left by increasing the speed of the right wheel and decreasing the speed of the left
- ![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/f42cc8dc-74e3-490b-baf7-ec5a2f946791)
- When signal is 0xFF10EF, car turn right. Turn right by increasing the speed of the left wheel and decreasing the speed of the right
- ![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/179e9e21-043d-4e0b-a73e-bc6337ff64d5)
- When signal is 0xFF38C7, the car will stop.
- ![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/ab32e6e6-68f7-46f2-8db0-a708586845c1)
- When signal is 0xFF6897 or 0xFFB04F, the vehicle will accelerate or decelerate.
- ![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/00ebb42a-b6b5-4dcb-96e2-0b929f91d221)

## ✍️ Authors <a name = "authors"></a>
- Nguyễn Đức Hà - 20204739
- Giáp Quang Trung - 20204797
- Trần Tiến Trung - 20204799
- Trần Tuấn Minh - 20204842
