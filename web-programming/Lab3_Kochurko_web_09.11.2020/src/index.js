// Constructor obj Student:
// function Student(name, surname, age, averageScore) {
//     this.name = name;
//     this.surname = surname;
//     this.age = age;
//     this.averageScore = averageScore;
// }

let studentArray = [];
let body = document.querySelector('body');

function createForm() {
    let fragment = document.createDocumentFragment();
    
    let form = document.createElement('form');
    form = fragment.appendChild(form);
    form.setAttribute('onsubmit', 'return false;');

    let inputName = document.createElement('input');
    inputName = form.appendChild(inputName);
    inputName.id = 'input_name';
    inputName.setAttribute('placeholder', 'name');
    inputName.setAttribute('type', 'text');


    let inputSurname = document.createElement('input');
    inputSurname = form.appendChild(inputSurname);
    inputSurname.id = 'input_surname';
    inputSurname.setAttribute('placeholder', 'surname');
    inputSurname.setAttribute('type', 'text');

    
    let inputAge = document.createElement('input');
    inputAge = form.appendChild(inputAge);
    inputAge.id = 'input_age';
    inputAge.setAttribute('placeholder', 'age');
    inputAge.setAttribute('type', 'number');

    let inputScore = document.createElement('input');
    inputScore = form.appendChild(inputScore);
    inputScore.id = 'input_score';
    inputScore.setAttribute('placeholder', 'score');
    inputScore.setAttribute('type', 'number');

    let addButton = document.createElement('button');
    addButton = form.appendChild(addButton);
    addButton.id = 'add_button';
    addButton.textContent = 'Add';

    let removeButton = document.createElement('button');
    removeButton = form.appendChild(removeButton);
    removeButton.id = 'clear_button';
    removeButton.textContent = 'Clear';

    let editButton = document.createElement('button');
    editButton = form.appendChild(editButton);
    editButton.id = 'save_button';
    editButton.textContent = 'Save';

    fragment = document.body.appendChild(fragment);
}
const request = new XMLHttpRequest();
request.open('GET', './peoples.json');

request.onload = () => {
    studentArray = JSON.parse(request.response);
    
    module.createTable();
    module.getAverageMark();

    function removeItem() {
        const info = this.parentNode.parentNode.querySelectorAll('td');
        console.log(studentArray);
        const keys = Object.keys(studentArray[0]);
        console.log(info[2].textContent);
        for (let i = 0; i < studentArray.length; i++) {
            if (info[0].textContent === studentArray[i][keys[0]] 
                && info[1].textContent === studentArray[i][keys[1]]
                && +info[2].textContent === studentArray[i][keys[2]]
                && +info[3].textContent === studentArray[i][keys[3]]){
                    studentArray.splice(i,1);
                    break;
                }
        }
        this.parentNode.parentNode.remove();
        console.log(studentArray);
        document.querySelector('h1').remove();
        module.getAverageMark();

    }

    function clear() {
        document.querySelectorAll('input').forEach((elem) => {
            elem.value = '';
        });

        document.querySelectorAll('tr').forEach((elem) => {
            if(elem.id !== '') {
                elem.id = '';
            }
        });
    }
    function editItem() {
        clear();
        this.parentNode.parentNode.id = 'edit';
        console.log(this.parentNode.parentNode);
        const info = this.parentNode.parentNode.querySelectorAll('td');
        
        const inputs = document.querySelectorAll('input');

        inputs[0].value = info[0].textContent;
        inputs[1].value = info[1].textContent;
        inputs[2].value = +info[2].textContent;
        inputs[3].value = +info[3].textContent;
    }

    function save() {
        const inputs = document.querySelectorAll('input');
        if(inputs[0].value === '' || inputs[1].value === '' || inputs[2].value === '' || inputs[3].value === '') {
            alert('Enter all info about the student');
            return;
        }
        const row = document.querySelector('#edit');
        const fields = row.querySelectorAll('td');

        let indexInArray;
        for (let i = 0; i < studentArray.length; i++) {
            if (studentArray[i]["First Name"] === fields[0].textContent
            && studentArray[i]["Last Name"] === fields[1].textContent
            && studentArray[i]["age"] === +fields[2].textContent
            && studentArray[i]["Average score"] === +fields[3].textContent) {
                indexInArray = i;
                break;
            }
        }

        console.log(studentArray);

        fields[0].textContent = inputs[0].value;
        fields[1].textContent = inputs[1].value;
        fields[2].textContent = inputs[2].value;
        fields[3].textContent = inputs[3].value;

        studentArray[indexInArray]["First Name"] = inputs[0].value;
        studentArray[indexInArray]["Last Name"] = inputs[1].value;
        studentArray[indexInArray]["age"] = +inputs[2].value;
        studentArray[indexInArray]["Average score"] = +inputs[3].value;
        clear();
        document.querySelector('h1').remove();
        module.getAverageMark();
        console.log(studentArray);
    }

    function addElement() {
        const table = document.querySelector('table');
        const length = 5;
        console.log(studentArray);
        const keys = Object.keys(studentArray[0]);
        const inputs = document.querySelectorAll('input');
        if(inputs[0].value === '' || inputs[1].value === '' || inputs[2].value === '' || inputs[3].value === '') {
            alert('Enter all info about the student');
            return;
        }
        let tr = document.createElement('tr');
        tr = table.appendChild(tr);

        for (let j = 0; j < length; j++) {
            let td = document.createElement('td');
            td = tr.appendChild(td);

            if (j === length - 1) {
                let buttonRemove = document.createElement('button');
                buttonRemove = td.appendChild(buttonRemove);
                buttonRemove.textContent = 'Delete';
                buttonRemove.classList.add('removeButton');
                buttonRemove.addEventListener('click', removeItem);

                let buttonEdit = document.createElement('button');
                buttonEdit = td.appendChild(buttonEdit);
                buttonEdit.textContent = 'Edit';
                buttonEdit.classList.add('buttonEdit');
                buttonEdit.addEventListener('click', editItem);
            }
            else {
                td.innerText = inputs[j].value;
                if (j === 3) {
                    td.className = "averageScore";
                }
            }
        }

        studentArray.push({
            'First Name': inputs[0].value,
            'Last Name': inputs[1].value,
            'age': +inputs[2].value,
            'Average score': +inputs[3].value
        })
        clear();
        console.log(studentArray);
        document.querySelector('h1').remove();
        module.getAverageMark();
    }
    
    document.querySelector('#clear_button').addEventListener('click', clear);

    document.querySelectorAll('.removeButton').forEach((elem) => {
        elem.addEventListener('click', removeItem);
    })

    document.querySelectorAll('.buttonEdit').forEach((elem) => {
        elem.addEventListener('click', editItem);
    })

    document.querySelector('#save_button').addEventListener('click', save);
    document.querySelector('#add_button').addEventListener('click', addElement);
}



const module = (function () {
    return {
        createTable: () => {
            let table = document.createElement('table');
            table = body.appendChild(table);
            let keys = Object.keys(studentArray[0]);

            let values = [];
            for (let k  = 0; k < studentArray.length; k++) {
                values.push(Object.values(studentArray[k]));
            }

            // Create table:
            for (let i = 0; i < studentArray.length + 1; i++) {
                let tr = document.createElement('tr');
                tr = table.appendChild(tr);
                if (i === 0) {
                    for (let j = 0; j < keys.length + 1; j++) {
                        let th = document.createElement('th');
                        th = tr.appendChild(th);
                        if (j === keys.length) {
                            th.textContent = 'Actions';
                        }
                        else {
                            th.innerText = keys[j];
                        }
                    }
                }
                else {
                    let m = 0;
                    for (let j = 0; j < keys.length + 1; j++) {
                        let td = document.createElement('td');
                        td = tr.appendChild(td);
                        if (j === keys.length) {
                            let buttonRemove = document.createElement('button');
                            buttonRemove = td.appendChild(buttonRemove);
                            buttonRemove.textContent = 'Delete';
                            buttonRemove.classList.add('removeButton');

                            let buttonEdit = document.createElement('button');
                            buttonEdit = td.appendChild(buttonEdit);
                            buttonEdit.textContent = 'Edit';
                            buttonEdit.classList.add('buttonEdit');
                        }
                        else {
                            td.innerText = values[i - 1][m];
                            if (m === 3) {
                                td.className = "averageScore";
                            }
                            m++;
                        }
                    }
                }
            }
        },

        getAverageMark: () => {
            //Count average score:
            let allTr = document.querySelectorAll('.averageScore');
            let average = 0;
            for (let i = 0; i < allTr.length; i++) {
                average += +allTr[i].innerText;
                console.log(+allTr[i].innerText);
            }
            let h1 = document.createElement('h1');
            h1 = body.appendChild(h1);
            h1.innerText = (average / allTr.length).toFixed(4);
        },
    }
}())
createForm();

request.send();
