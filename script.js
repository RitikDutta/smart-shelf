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
				// checkbox = document.getElementsByName("13");
				// checkbox[0].checked = !checkbox[0].checked;
				arr_check.push(13);
			}
			else if (name == '3') {
				// checkbox = document.getElementsByName("16");
				// checkbox[0].checked = !checkbox[0].checked;
				arr_check.push(16);

			}
			else if (name == '7') {
				// checkbox = document.getElementsByName("1");
				// checkbox[0].checked = !checkbox[0].checked;
				arr_check.push(1);
			}
			else if (name == '9') {
				// checkbox = document.getElementsByName("4");
				// checkbox[0].checked = !checkbox[0].checked;
				arr_check.push(4);
			}
			else if (name == '2') {
				// checkbox = document.getElementsByName("14");
				// checkbox[0].checked = !checkbox[0].checked;
				// checkbox = document.getElementsByName("15");
				// checkbox[0].checked = !checkbox[0].checked;
				arr_check.push(14, 15);
			}
			else if (name == '4') {
				checkbox = document.getElementsByName("5");
				checkbox[0].checked = !checkbox[0].checked;
				checkbox = document.getElementsByName("9");
				checkbox[0].checked = !checkbox[0].checked;
			}
			else if (name == '6') {
				checkbox = document.getElementsByName("8");
				checkbox[0].checked = !checkbox[0].checked;
				checkbox = document.getElementsByName("12");
				checkbox[0].checked = !checkbox[0].checked;
			}
			else if (name == '8') {
				checkbox = document.getElementsByName("2");
				checkbox[0].checked = !checkbox[0].checked;
				checkbox = document.getElementsByName("3");
				checkbox[0].checked = !checkbox[0].checked;
			}
			else if (name == '5') {
				checkbox = document.getElementsByName("6");
				checkbox[0].checked = !checkbox[0].checked;
				checkbox = document.getElementsByName("7");
				checkbox[0].checked = !checkbox[0].checked;
				checkbox = document.getElementsByName("10");
				checkbox[0].checked = !checkbox[0].checked;
				checkbox = document.getElementsByName("11");
				checkbox[0].checked = !checkbox[0].checked;
			}

			arr_check.forEach(myFunction);

			function myFunction(value) {
			  checkbox = document.getElementsByName(value);
				checkbox[0].checked = !checkbox[0].checked;
			}

			console.log(arr_check);
  }, false);