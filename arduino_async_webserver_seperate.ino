#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Airtel_9587411733";
const char* password = "air72055";

const char* PARAM_INPUT_1 = "output";
const char* PARAM_INPUT_2 = "state";
const char* PARAM_INPUT_3 = "option";
const char* PARAM_INPUT_4 = "rloop";
const char* PARAM_INPUT_5 = "rspeed";

const int srelay[] = {2, 27, 5, 32, 21, 25, 4, 26, 23, 13, 19, 33, 15, 18, 22, 14};

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



select {
  /* Reset */
  -webkit-appearance: none;
     -moz-appearance: none;
          appearance: none;
  border: 0;
  outline: 0;
  font: inherit;
  /* Personalize */
  width: 20em;
  height: 3em;
  padding: 0 4em 0 1em;
  background: url(https://upload.wikimedia.org/wikipedia/commons/9/9d/Caret_down_font_awesome_whitevariation.svg) no-repeat right 0.8em center/1.4em, linear-gradient(to left, rgba(255, 255, 255, 0.3) 3em, rgba(255, 255, 255, 0.2) 3em);
  color: grey;
  border-radius: 0.25em;
  box-shadow: 0 0 1em 0 rgba(0, 0, 0, 0.2);
  cursor: pointer;
  /* <option> colors */
  /* Remove focus outline */
  /* Remove IE arrow */
}
select option {
  color: inherit;
  background-color: #eeeeee;
}
select:focus {
  outline: none;
}
select::-ms-expand {
  display: none;
}

input[type=range] {
    -webkit-appearance: none;
    margin: 10px 0;
    width: 100%;
}

input[type=range]:focus {
    outline: none;
}

input[type=range]::-webkit-slider-runnable-track {
    width: 90%;
    height: 2px;
    cursor: pointer;
    animate: 0.2s;
    box-shadow: 0px 0px 0px transparent, 0px 0px 0px transparent;
    background: #eeeeee;
    border-radius: 25px;
    border: 0px solid transparent;
}

input[type=range]::-webkit-slider-thumb {
    box-shadow: 0px 0px 0px transparent, 0px 0px 0px transparent;
    border: 0px solid transparent;
    height: 16px;
    width: 16px;
    border-radius: 8px;
    background: #1abc9c;
    cursor: pointer;
    -webkit-appearance: none;
    margin-top: -6px;
}

input[type=range]:focus::-webkit-slider-runnable-track {
    background: #eeeeee;
}

input[type=range]::-moz-range-track {
    width: 100%;
    height: 2px;
    cursor: pointer;
    animate: 0.2s;
    box-shadow: 0px 0px 0px transparent, 0px 0px 0px transparent;
    background: #eeeeee;
    border-radius: 25px;
    border: 0px solid transparent;
}

input[type=range]::-moz-range-thumb {
    box-shadow: 0px 0px 0px transparent, 0px 0px 0px transparent;
    border: 0px solid transparent;
    height: 16px;
    width: 16px;
    border-radius: 8px;
    background: #1abc9c;
    cursor: pointer;
    margin-top: -6px;
}


      
    </style>
  </head>
  <body>
{

<div class="container">
  <div class="control-group">
    <h1>Select boxes</h1>
    <div class="select">
    TYPES:
      <select id="framework">
        <option>First select</option>
        <option>Option</option>
        <option>Option</option>
        <option>Option</option>
      </select>
      <div class="select__arrow"></div>
    </div>
    <div class="select">
      TIMES:
      <select id="framework2">
        <option value="2">2</option>
        <option value="4">4</option>
        <option value="6">6</option>
        <option value="8">8</option>
        <option value="10">10</option>
        <option value="12">12</option>
        <option value="14">14</option>
        <option value="16">16</option>
      </select>
      <div class="select__arrow"></div>
    </div> SPEED:
    <div class="value">20</div>
    <input type="range" min=10" max="410" step="5" value="20" id='framework3'>

    <input type="checkbox" id="myCheck" onclick="randomLed()">
    
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
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="2" checked name="1"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">1</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="27" checked name="2"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">2</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="5" checked name="3"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">3</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="32" checked name="4"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">4</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="21" checked name="5"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">5</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="25" checked name="6"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">6</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="4" checked name="7"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">7</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="26" checked name="8"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">8</span>
      </span>
    </label>
  </div>
   <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="23" checked name="9"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">9</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="13" checked name="10"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">10</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="19" checked name="11"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">11</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="33" checked name="12"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">12</span>
      </span>
    </label>
  </div>
   <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="15" checked name="13"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">13</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="18" checked name="14"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">14</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="22" checked name="15"/>
      <span class="checkbox-tile">
        <span class="checkbox-icon">
          
        </span>
        <span class="checkbox-label">15</span>
      </span>
    </label>
  </div>
  <div class="checkbox">
    <label class="checkbox-wrapper">
      <input type="checkbox" class="checkbox-input" onchange="toggleCheckbox(this)" id="14" checked name="16"/>
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
var elem = document.querySelector('input[type="range"]');

var rangeValue = function(){
  var newValue = elem.value;
  var target = document.querySelector('.value');
  target.innerHTML = newValue;
}

elem.addEventListener("input", rangeValue);
</script>



    
  
  <script>
    document.addEventListener('keydown', (event) => {
    var name = event.key;
    var code = event.code;
    arr_check = []

      if (name == '1') {
        arr_check.push(13);
      }else if (name == '3') {
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
        var xhr = new XMLHttpRequest();
          if(checkbox[0].checked){ xhr.open("GET", "/update?output="+checkbox[0].id+"&state=1", true); }
          else { xhr.open("GET", "/update?output="+checkbox[0].id+"&state=0", true); }
          xhr.send();
      }
        console.log(arr_check);
      }, false);


const btn = document.querySelector('#sub');
const sb =  document.querySelector('#framework')  //TYPE
const sb2 = document.querySelector('#framework2') //TIME
const rs =  document.querySelector('#framework3') //SPEED
//var value = sb2.options[sb2.selectedIndex].value;
//var rspeed = rs.options[rs.selectedIndex].value;
let n = sb2.value;
let times = sb2.value;

console.log(n, 400/rs.value)

btn.onclick = (event) => {
    n=sb2.value
    times=sb2.value
    event.preventDefault();
    // show the selected index
    console.log(sb.selectedIndex);
    if (sb.selectedIndex == 0) {
       arr = [5,6,7,8]
       relayon(arr, sb.selectedIndex, sb2.value, rs.value)
    } else if (sb.selectedIndex == 1) {
       arr = [5,6,7,8]
       relayon(arr, sb.selectedIndex, sb2.value, rs.value)
    } 
    else if (sb.selectedIndex == 2) {
       arr = [1,2,3,4,8,12,16,15,14,13,9,5]
        let n = sb2.value;
       if(rs.value*sb2.value>400){
        //  for (let i = 0; i < sb2.value; i++) {
        //   relayon(arr, sb.selectedIndex, 1, rs.value)
        //  }  
        while(n>0){
          n=n- Math.floor(400/rs.value)
          if(n>=0){
            relayon(arr, sb.selectedIndex, times-n, rs.value)
            times = n
          }
        }
        relayon(arr, sb.selectedIndex, times, rs.value)
      }
      else{  
        relayon(arr, sb.selectedIndex, sb2.value, rs.value)
      }
    }
    else if (sb.selectedIndex == 3) {
      arr=[1,2,3]
      relayon(arr, sb.selectedIndex, 5, rs.value)
    }
};



  let i = 0
function randomLed() {
  var xhr = new XMLHttpRequest();
  var checkBox = document.getElementById("myCheck");
  while(checkBox.checked == true){
    xhr.open("GET", "/random?output="+rs.value+"&state="+Math.floor(Math.random() * 10+1), true);
    xhr.send();
    i++
  }
}
  </script> 


  <script>
  function relayon(x, opt, rloop, rspeed){
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/on1?output="+x+"&state="+arr.length+"&option="+opt+"&rloop="+rloop+"&rspeed="+rspeed, true);
      xhr.send();
    }

    function randomLed_GET(rspeed, n){
      
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
    arr += ",";
    int index = 0;
    int temp[arr_size];
    String temps = "";
    for (int i = 0; i < arr.length(); i++) {
      if (arr[i] != ',') {
        temps += arr[i];
      }
      else {
        index++;
        temp[index - 1] = temps.toInt();
        temps = "";
      }
    }
    return temp[ind];
  }

void alloff(){
  for(int i = 0; i<16; i++){
    digitalWrite(srelay[i], HIGH);  
  }
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
  server.on("/random", HTTP_GET, [] (AsyncWebServerRequest * request) {
    String inputMessage1;
    String inputMessage2;
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
    }else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
    }
    delay(inputMessage1.toInt());
    Serial.print("Message recieved InputMessage1 = : ");
    Serial.println(inputMessage1);
    Serial.print("Message recieved InputMessage2 = : ");
    Serial.println(inputMessage2);
    request->send_P(200, "text/html", index_html);
  });


  server.on("/on1", HTTP_GET, [] (AsyncWebServerRequest * request) {
    String inputMessage1;
    String inputMessage2;
    String inputMessage3;
    String loop_count;
    String rspeed;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2) && request->hasParam(PARAM_INPUT_3) && request->hasParam(PARAM_INPUT_4) && request->hasParam(PARAM_INPUT_5)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      inputMessage3 = request->getParam(PARAM_INPUT_3)->value();
      loop_count = request->getParam(PARAM_INPUT_4)->value();
      rspeed = request->getParam(PARAM_INPUT_5)->value();
      
//      digitalWrite(inputMessage1.toInt(), !inputMessage2.toInt());
    }
    else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
      inputMessage3 = "No message sent";
      loop_count = "No message sent";
      rspeed = "200";
    }
alloff();
if(inputMessage3.toInt() == 0){
//  for(int k=0;k<=inputMessage4.toInt(); k++){
    for(int i =0;i < loop_count.toInt(); i++){
      for(int j=0; j < inputMessage2.toInt(); j++){
        digitalWrite(srelay[myf(inputMessage1, inputMessage2.toInt(), j)-1], HIGH);
      }
      delay(rspeed.toInt());
      for(int j =0; j < inputMessage2.toInt(); j++){
        digitalWrite(srelay[myf(inputMessage1, inputMessage2.toInt(), j)-1], LOW);
      }
      delay(rspeed.toInt());
    }    
//  }
}
else if(inputMessage3.toInt() == 1){
    for(int i =0;i < loop_count.toInt(); i++){
        digitalWrite(srelay[5], i%2);
        digitalWrite(srelay[6], i%2);
        digitalWrite(srelay[9], i%2);
        digitalWrite(srelay[10], i%2);
        
        digitalWrite(srelay[0], (i+1)%2);
        digitalWrite(srelay[1], (i+1)%2);
        digitalWrite(srelay[2], (i+1)%2);
        digitalWrite(srelay[3], (i+1)%2);
        digitalWrite(srelay[7], (i+1)%2);
        digitalWrite(srelay[11], (i+1)%2);
        digitalWrite(srelay[15], (i+1)%2);
        digitalWrite(srelay[14], (i+1)%2);
        digitalWrite(srelay[13], (i+1)%2);
        digitalWrite(srelay[12], (i+1)%2);
        digitalWrite(srelay[8], (i+1)%2);
        digitalWrite(srelay[4], (i+1)%2);

        delay(rspeed.toInt());
    }
}
else if (inputMessage3.toInt() == 2){
  for(int n = 0; n<loop_count.toInt(); n++){
    for(int i =0;i < inputMessage2.toInt(); i++){
      digitalWrite(srelay[myf(inputMessage1, inputMessage2.toInt(), i)-1], !HIGH);
      delay(rspeed.toInt());
      digitalWrite(srelay[myf(inputMessage1, inputMessage2.toInt(), i)-1], !LOW);
//    delay(rspeed);
    }
  }
}
else if (inputMessage3.toInt() == 3){
  for(int j =0; j<loop_count.toInt(); j++){
    for(int i=0; i<16;i++){
      digitalWrite(srelay[i], !HIGH);
      delay(rspeed.toInt());
      digitalWrite(srelay[i], !LOW);
    }
  }
}



    Serial.print("Message recieved InputMessage1 = : ");
    Serial.println(inputMessage1);
    Serial.print(" And InputMessage2 = ");
    Serial.println(inputMessage2);
    Serial.print(" And Option = ");
    Serial.println(inputMessage3);
    Serial.print(" And loop = ");
    Serial.println(loop_count);
    Serial.print(" And speed = ");
    Serial.println(rspeed);
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




void loop() {

}
