<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://github.com/hadimsctn/IRCarProject/assets/103713872/6468a3b4-5671-42d9-bddb-5e8d8cd8d50a" alt="Project logo"></a>
</p>
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
- To turn on the power for the vehicle, switch on this switch.
- ![db9a5d6d-8566-431f-8d8d-3155062dd70a](https://github.com/hadimsctn/IRCarProject/assets/103713872/58f6619c-8a32-43f8-8bed-3e7fec2bc7cd)

- Move the vehicle in different directions by pressing the arrow buttons on the remote control, accelerate by pressing *, decelerate by pressing #, and brake by pressing OK.
- ![4944dfe1-d7a7-4dbf-b1b9-dccd48ba63be](https://github.com/hadimsctn/IRCarProject/assets/103713872/9170fb9d-e84c-42f2-a058-a1d06976703f)

## 🚀 Bill of Material <a name = "billofmaterial"></a>
1. 2x DC Motor https://nshopvn.com/product/dong-co-dc-giam-toc-vang-2-truc-148/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/7b0982d9-df1e-4233-9808-3a002e9252c7)
2. 4x Battery 18650 2000mAh https://nshopvn.com/product/pin-cell-18650-2000mah/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/a60fa53d-1283-4aab-b2b6-d2fecd56f5df)
3. 1x L298N https://nshopvn.com/product/mach-dieu-khien-dong-co-dc-l298n/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/007c77c9-9dd9-4e30-aef7-64c6cc108bee)
4. 1x ESP32 https://dientutuyetnga.com/products/mach-thu-phat-esp32-nodemcu-typec-ch340-esp-wroom-32
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/798203ad-3659-45c7-af39-d76c8e773fac)
5. 1x HC-SR04 https://nshopvn.com/product/cam-bien-sieu-am-hc-sr04/
<div![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/8dc341a2-cc23-4567-8ac6-327ce09ffd74)
6. 2x Diode IR https://www.cytrontech.vn/c-sensor/p-ir-receiver-diode-vs1838b-38khz
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/9db3a32d-65f0-430d-85e0-ce5b7c193c05)
7. 1x Buzzer https://shopee.vn/product/148048328/4974689853?gsht=sjFxkDeGHTM5gwwS
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/3784d847-cbee-4f9c-bd94-da95fd686fd4)
8. 2x TP4056 https://nshopvn.com/product/mach-sac-pin-tp4056-co-ic-bao-ve/
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/a53ee7bc-207f-4634-a584-d1d3b909f1ff)

## ⛏️ Hardware Schematic <a name = "hardwareschematic"></a>
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/27697e32-87a6-41b0-b758-f1b38a0464f2)

## 🎉 Software Concept <a name = "softwareconcept"></a>
1. This car uses 1 SR04 for emergency braking<br/>
When encountering an obstacle at a distance of 10cm, the car will emergency brake and turn on the buzzer
![image](https://github.com/hadimsctn/IRCarProject/assets/103713872/1c4b972b-957f-40cc-898e-e79533a7d562)</div>
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
