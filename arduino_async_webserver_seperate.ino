/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-async-web-server-espasyncwebserver-library/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "Airtel_9587411733";
const char* password = "air72055";

const char* PARAM_INPUT_1 = "output";
const char* PARAM_INPUT_2 = "state";

const int srelay[] = {0, 2, 27, 5, 32, 21, 25, 4, 26, 23, 13, 19, 33, 15, 18, 22, 14};

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <title>ESP Web Server</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <style>
    
    

body {
  font-family: "Inter", sans-serif;
  line-height: 1.5;
  min-height: 100vh;
  display: flex;
  align-items: center;
  justify-content: center;
  background-color: #f8f8f9;
}

.checkbox-group {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
  width: 90%;
  margin-left: auto;
  margin-right: auto;
  max-width: 600px;
  -webkit-user-select: none;
     -moz-user-select: none;
      -ms-user-select: none;
          user-select: none;
}
.checkbox-group > * {
  margin: 0.5rem 0.5rem;
}

.checkbox-group-legend {
  font-size: 1.5rem;
  font-weight: 700;
  color: #9c9c9c;
  text-align: center;
  line-height: 1.125;
  margin-bottom: 1.25rem;
}

.checkbox-input {
  clip: rect(0 0 0 0);
  -webkit-clip-path: inset(100%);
          clip-path: inset(100%);
  height: 1px;
  overflow: hidden;
  position: absolute;
  white-space: nowrap;
  width: 1px;
}
.checkbox-input:checked + .checkbox-tile {
  border-color: #2260ff;
  box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1);
  color: #2260ff;
}
.checkbox-input:checked + .checkbox-tile:before {
  transform: scale(1);
  opacity: 1;
  background-color: #2260ff;
  border-color: #2260ff;
}
.checkbox-input:checked + .checkbox-tile .checkbox-icon, .checkbox-input:checked + .checkbox-tile .checkbox-label {
  color: #2260ff;
}
.checkbox-input:focus + .checkbox-tile {
  border-color: #2260ff;
  box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1), 0 0 0 4px #b5c9fc;
}
.checkbox-input:focus + .checkbox-tile:before {
  transform: scale(1);
  opacity: 1;
}

.checkbox-tile {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  width: 7rem;
  min-height: 7rem;
  border-radius: 0.5rem;
  border: 2px solid #b5bfd9;
  background-color: #fff;
  box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1);
  transition: 0.15s ease;
  cursor: pointer;
  position: relative;
}
.checkbox-tile:before {
  content: "";
  position: absolute;
  display: block;
  width: 1.25rem;
  height: 1.25rem;
  border: 2px solid #b5bfd9;
  background-color: #fff;
  border-radius: 50%;
  top: 0.25rem;
  left: 0.25rem;
  opacity: 0;
  transform: scale(0);
  transition: 0.25s ease;
  background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='192' height='192' fill='%23FFFFFF' viewBox='0 0 256 256'%3E%3Crect width='256' height='256' fill='none'%3E%3C/rect%3E%3Cpolyline points='216 72.005 104 184 48 128.005' fill='none' stroke='%23FFFFFF' stroke-linecap='round' stroke-linejoin='round' stroke-width='32'%3E%3C/polyline%3E%3C/svg%3E");
  background-size: 12px;
  background-repeat: no-repeat;
  background-position: 50% 50%;
}
.checkbox-tile:hover {
  border-color: #2260ff;
}
.checkbox-tile:hover:before {
  transform: scale(1);
  opacity: 1;
}

.checkbox-icon {
  transition: 0.375s ease;
  color: #494949;
}
.checkbox-icon svg {
  width: 3rem;
  height: 3rem;
}

.checkbox-label {
  color: #707070;
  transition: 0.375s ease;
  text-align: center;
}

      
    </style>
  </head>
  <body>
{

<div class="container">
  <div class="control-group">
    <h1>Select boxes</h1>
    <div class="select">
      <select id="framework">
        <option>First select</option>
        <option>Option</option>
        <option>Option</option>
      </select>
      <div class="select__arrow"></div>
    </div>
    <div class="select">
      <select>
        <option>Second select</option>
        <option>Option</option>
        <option>Option</option>
      </select>
      <div class="select__arrow"></div>
    </div>
    <div class="select">
      <button class="button" id="sub">Submit</button>
    </div>
  </div>
</div>


<!-- partial:index.partial.html -->
    <fieldset class="checkbox-group">
  <legend class="checkbox-group-legend">Choose your lights</legend>

  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="2" name="1"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">1</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="27" name="2"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">2</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="5" name="3"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">3</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="32" name="4"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">4</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="21" name="5"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">5</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="25" name="6"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">6</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="4" name="7"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">7</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="26" name="8"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">8</span>
      </span>
    </label>
  </div>
   <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="23" name="9"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">9</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="13" name="10"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">10</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="19" name="11"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">11</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="33" name="12"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">12</span>
      </span>
    </label>
  </div>
   <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="15" name="13"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">13</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="18" name="14"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">14</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="22" name="15"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">15</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="14" name="16"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">16</span>
      </span>
    </label>
  </div>
</fieldset>


}
    
  
  <script>
    document.addEventListener('keydown', (event) => {
    var name = event.key;
    var code = event.code;
    arr_check = []

      if (name == '1') {
        arr_check.push(13);
      }
      else if (name == '3') {
        arr_check.push(16);
      }
      else if (name == '7') {
        arr_check.push(1);
      }
      else if (name == '9') {
        arr_check.push(4);
      }
      else if (name == '2') {
        arr_check.push(14, 15);
      }
      else if (name == '4') {
        arr_check.push(5, 9);
      }
      else if (name == '6') {
        arr_check.push(8, 12);
      }
      else if (name == '8') {
        arr_check.push(2, 3);
      }
      else if (name == '5') {
        arr_check.push(6, 7, 10, 11);       
      }

      arr_check.forEach(myFunction);

      function myFunction(value) {
        checkbox = document.getElementsByName(value);
        checkbox[0].checked = !checkbox[0].checked;
        relayon(value);
      }

      console.log(arr_check);
  }, false);
  </script> 
    

  <script>
  function relayon(x){
      arr = [1,2,3,445,125,0]
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/on1?output="+arr+"&state=1", true);
      xhr.send();
    }

  </script>
  
    <script>function toggleCheckbox(element) {
      var xhr = new XMLHttpRequest();
      if(element.checked){ xhr.open("GET", "/update?output="+element.id+"&state=1", true); }
      else { xhr.open("GET", "/update?output="+element.id+"&state=0", true); }
      xhr.send();
    }
  </script>


  
  </body>
</html>
)rawliteral";



String outputState(int output){
  if(digitalRead(output)){
    return "checked";
  }
  else {
    return "";
  }
}

int myf(String arr, int arr_size, int ind) {
    Serial.print(arr);
    int t = 0;
    int index = 0;
    String  a;
    int temp[arr_size];
    String temps = "";
    for (int i = 0; i < arr.length(); i++) {
      //    Serial.print(i);
      if (arr[i] != ',') {
        a = arr[i];
        Serial.print(a);
        temps += a;
        Serial.print("-");
        t++;
      }
      else {
        index++;
        temp[index - 1] = temps.toInt();
        t = 0;
        Serial.print("+");
        Serial.print(index);
        Serial.print("String = ");
        Serial.println(temps);
        temps = "";
      }


    }

    Serial.println(temp[0]);
    Serial.println(temp[1]);
    Serial.println(temp[2]);
    Serial.println(temp[3]);
    Serial.println(temp[4]);

    return temp[ind];
  }


void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);

  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/on1", HTTP_GET, [] (AsyncWebServerRequest * request) {
    String inputMessage1;
    String inputMessage2;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      digitalWrite(inputMessage1.toInt(), !inputMessage2.toInt());
    }
    else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
    }

    
    digitalWrite(inputMessage1[1], HIGH);
    digitalWrite(inputMessage1[2], HIGH);
    digitalWrite(inputMessage1[3], HIGH);
    digitalWrite(inputMessage1[4], HIGH);
    delay(200);
    digitalWrite(inputMessage1[1], LOW);
    digitalWrite(inputMessage1[2], LOW);
    digitalWrite(inputMessage1[3], LOW);
    digitalWrite(inputMessage1[4], LOW);
    delay(200);
    digitalWrite(inputMessage1[1], HIGH);
    digitalWrite(inputMessage1[2], HIGH);
    digitalWrite(inputMessage1[3], HIGH);
    digitalWrite(inputMessage1[4], HIGH);
    delay(200);
    digitalWrite(inputMessage1[1], LOW);
    digitalWrite(inputMessage1[2], LOW);
    digitalWrite(inputMessage1[3], LOW);
    digitalWrite(inputMessage1[4], LOW);
    delay(200);
    digitalWrite(inputMessage1[1], HIGH);
    digitalWrite(inputMessage1[2], HIGH);
    digitalWrite(inputMessage1[3], HIGH);
    digitalWrite(inputMessage1[4], HIGH);
    delay(200);
    digitalWrite(inputMessage1[1], LOW);
    digitalWrite(inputMessage1[2], LOW);
    digitalWrite(inputMessage1[3], LOW);
    digitalWrite(inputMessage1[4], LOW);
    delay(200);


    int n = myf(inputMessage1, 5, 3);
    Serial.println(n);

//    //  temp = []
//  for (int i=0;i<inputMessage1.length(); i++){
////    Serial.print(i);
//    Serial.print(inputMessage1[i]);
//    if(inputMessage1[i] != ','){
////      temp.append(int(a[i]))
//        Serial.print(inputMessage1[i]);
//        Serial.print("comma");
//    }
//  }


    int toint = inputMessage1.indexOf(',');
    Serial.print("Message recieved InputMessage1 = : ");
    Serial.print(toint);
    Serial.print(" And InputMessage2 = ");
    Serial.println(inputMessage2);
    request->send(200, "text/plain", "OK");
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage1;
    String inputMessage2;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      digitalWrite(inputMessage1.toInt(), !inputMessage2.toInt());
    }
    else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
    }

 
    
    Serial.print("GPIO: ");
    Serial.print(inputMessage1);
    Serial.print(" - Set to: ");
    Serial.println(inputMessage2);
    request->send(200, "text/plain", "OK");
  });

  // Start server
  server.begin();
}
//int str_arr(str){
//  temp = []
//  for i in range(len(a)):
//    print(a[i])
//    if a[i] != ',':
//    temp.append(int(a[i]))
//    print(temp)
//}




void loop() {

}

 
