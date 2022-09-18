arr_check = []
document.addEventListener('keydown', (event) => {
    arr_check = [];
    var name = event.key;
    var code = event.code;
    // alert(`Key pressed ${name} \n Key code Value: ${code}`);
    // if (name == 5) {
    // const checkbox = document.getElementsByName(name);
    // checkbox[0].checked = !checkbox[0].checked;
    //NUMPAD


    if (name == '1') {
        arr_check.push(13);
    } else if (name == '3') {
        arr_check.push(16);
    } else if (name == '7') {
        arr_check.push(1);
    } else if (name == '9') {
        arr_check.push(4);
    } else if (name == '2') {
        arr_check.push(14, 15);
    } else if (name == '4') {
        arr_check.push(5, 9);
    } else if (name == '6') {
        arr_check.push(8, 12);
    } else if (name == '8') {
        arr_check.push(2, 3);
    } else if (name == '5') {
        arr_check.push(6, 7, 10, 11);
    }

    arr_check.forEach(myFunction);




    console.log(arr_check);
}, false);



function animate(iter, t, arr_check, inverse) {
    console.log(arr_check)

    if (inverse == 1) {
        arr_check.forEach(myFunction)
    }
    for (let i = 1; i < iter; i++) {
        setTimeout(function timer() {
            arr_check.forEach(myFunction) //  your code here
            if (i == iter - 1) {
                clearmyFunction()
                console.log("Function cleared")
            }
        }, i * t);
    }
}


function animate2(arr_check) {
    for (let j = 0; j < arr_check.length - 1; j++) {
        setTimeout(function timer() {
            for (let k = j + 1; k <= j + 1; k++) {
                if (j == 0) {
                    myFunction(arr_check[0])
                }
                if (j == arr_check.length - 2) {
                    console.log('J IS............')
                    myFunction(arr_check[j + 1])
                }
                console.log(j, k)
                myFunction(arr_check[j])
                myFunction(arr_check[k])
            }
            if (j == arr_check.length - 2) {
                clearmyFunction()
                console.log("Function cleared")
            }
        }, j * 200);
    }
}


// animateloop(7, arr_check);
function animateloop(number, arr_check) {
    for (var i = 0; i < number; i++) {
        setTimeout(function timer() {
            // arr_check.push(1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 1, 2)
            animate2(arr_check);
            // arr_check = []
            console.log(i)
        }, i * 2400);
    }
}



// clearmyFunction()

function clearmyFunction() {
    for (let i = 1; i <= 16; i++) {
        checkbox = document.getElementsByName(i);
        checkbox[0].checked = false;
    }
}


// arr_check.push(2, 3, 4)
// animate(10, 200, arr_check)

function myFunction(value) {
    checkbox = document.getElementsByName(value);
    checkbox[0].checked = !checkbox[0].checked;
}



const btn = document.querySelector('#sub');
const sb = document.querySelector('#framework')
btn.onclick = (event) => {
    event.preventDefault();
    // show the selected index
    console.log(sb.selectedIndex);
    if (sb.selectedIndex == 0) {
        arr_check = []
        arr_check.push(6, 7, 10, 11)
        animate(10, 200, arr_check, 0)
        arr_check = []
        arr_check.push(1, 2, 3, 4, 5, 8, 9, 12, 13, 14, 15, 16)
        animate(11, 200, arr_check, 1)
        arr_check = []
    } else if (sb.selectedIndex == 1) {
        arr_check.push(1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 1, 2)
        animateloop(5, arr_check);
    }
};