# SmartThingsCtrl ( simple app to controll ESP8266 over HTTP API)


##
- Change SSID and Password in ( esp_sketch.ino )
- Upload sketch ( esp_sketch.ino ) to ESP8266 
- change the IP address in the mobile app ( App.js ) to ESP IP Address and you ready to go..


```bash
# Clone this repository
git clone https://github.com/blacktoviche/SmartThingsCtrl
# Go into the repository
cd SmartThingsCtrl
# Install dependencies
yarn install
# Link dependencies
react-native link
# Run the app
react-native run-android or react-native run-ios on macOS
# In development mode you should open second bash and run this before react-native run-android
yarn start
```


![](https://raw.githubusercontent.com/Blacktoviche/SmartThingsCtrl/master/Screenshot.jpeg)


## License
- [MIT](LICENSE)

Twitter [@SyrianDeveloper](https://www.twitter.com/SyrianDeveloper)