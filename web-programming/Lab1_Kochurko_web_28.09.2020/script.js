'use strict'
/* организовать ввод массива чисел с клавиатуры
отсортировать массив, найти максимальный и минимальный элементы
посчитать сумму всех элементов
вывести результаты в консоль 
 */
let unsortedArray = [];
let input = document.querySelector('#array_element');
let h1 = document.createElement('h1');
let h3 = document.createElement('h3');
let pElements = document.createElement('p');
let body = document.querySelector('body');
pElements = body.appendChild(pElements);
pElements.innerText = '';


let button = document.querySelector('#add').onclick = function() {
    pElements.innerText += ' ' + input.value;
    unsortedArray.push(+input.value);
    console.log(unsortedArray);
    input.value = '';
    if (h1) {
       h1.innerText = '';
       h3.innerText = '';
    }
}

let buttonSort = document.querySelector('#sort').onclick = function() {
    boubleSort(unsortedArray);
    h1 = body.appendChild(h1);
    h3 = body.appendChild(h3);       
    h1.innerText +=  'Unsorted array: ' + '[' + pElements.innerText + '] ' + '\t Sorted array: ' + '[' + unsortedArray.join(' ') + ']';
    h3.innerText += `min = ${unsortedArray[0]} max = ${unsortedArray[unsortedArray.length -1]} sum = ${getSum(unsortedArray)}`;
    unsortedArray = [];
    pElements.innerText = '';    
}

function boubleSort(array) {
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = i; j < array.length; j++) {
            if (array[i] > array[j]) {
                let term = array[i];
                array[i] = array[j];
                array[j] = term;
            }
        }
    }
    return array;
}

function getSum(array) {
    let sum = 0;
    array.forEach(element => sum += element);
    return sum;
}

