const fs = require('fs');
// const inputPath = './input.txt';
const inputPath = 'dev/stdin';

const [first, second, third] = fs.readFileSync(inputPath).toString().trim().split("\n");

const isNumber = str => {
    let strReplaced = str.replace(/\d/g, '');
    return strReplaced.length == 0
}

const transFizzBuzz = num => {
    if (num % 3 == 0 && num % 5 == 0) {
        return "FizzBuzz";
    } else if (num % 3 == 0) {
        return "Fizz"
    } else if (num % 5 == 0) {
        return "Buzz"
    } else {
        return num
    }
}

if (isNumber(third)) {
    console.log(transFizzBuzz(parseInt(third) + 1)); 
} else if (isNumber(second)) {
    console.log(transFizzBuzz(parseInt(second) + 2));
} else {
    console.log(transFizzBuzz(parseInt(first) + 3));
}