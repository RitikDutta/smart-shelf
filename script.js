  document.addEventListener('keydown', (event) => {
    var name = event.key;
    var code = event.code;
		arr_check = []
		// alert(`Key pressed ${name} \n Key code Value: ${code}`);
    	// if (name == 5) {
			// const checkbox = document.getElementsByName(name);
			// checkbox[0].checked = !checkbox[0].checked;
			//NUMPAD



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
			}



			

			console.log(arr_check);
  }, false);