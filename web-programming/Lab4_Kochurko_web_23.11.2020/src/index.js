let studentArray = [];
const body = $("body");
body.append($('<h1>', { id : 'avg-score'}));

$.getJSON('./peoples.json', function(data){
    studentArray = data;

    const table = new Table(studentArray);
    $('#avg-score').text(Table.getAverageMark());

    $('#clear_button').click(clear);
    $('.removeButton').click(removeItem);
    $('.editButton').click(editItem);
    $('#add_button').click(addElement);
    $('#save_button').click(save);
});


function save() {
    const inputs = $('input');
    if(inputs[0].value === '' || inputs[1].value === '' || inputs[2].value === '' || inputs[3].value === '') {
        alert('Enter all info about the student');
        return;
    }

    const row = $('#edit');
    const fields = row.children('td');

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

    console.log('Student Array (before) :', studentArray);

    fields[0].textContent = inputs[0].value;
    fields[1].textContent = inputs[1].value;
    fields[2].textContent = inputs[2].value;
    fields[3].textContent = inputs[3].value;

    studentArray[indexInArray]["First Name"] = inputs[0].value;
    studentArray[indexInArray]["Last Name"] = inputs[1].value;
    studentArray[indexInArray]["age"] = +inputs[2].value;
    studentArray[indexInArray]["Average score"] = +inputs[3].value;
    
    console.log('Student Array (after) :', studentArray);
    $('#avg-score').text(Table.getAverageMark());
    clear();
}

function addElement() {
    console.log('function addElement()');

    const table = $('table');
    const length = 5;

    console.log('Student Array (before) :', studentArray);
    const keys = Object.keys(studentArray[0]);
    const inputs = $('input');

    if(inputs[0].value === '' || inputs[1].value === '' || inputs[2].value === '' || inputs[3].value === '') {
        alert('Enter all info about the student');
        return;
    }

    const tr = $('<tr>');
    table.append(tr);

    for (let j = 0; j < length; j++) {
        const td = $('<td>');
        tr.append(td);

        if (j === length - 1) {
            const buttonRemove  = $('<button>', {
                text: 'Delete',
                class: 'removeButton'
            });
            td.append(buttonRemove);
            buttonRemove.click(removeItem);

            const buttonEdit  = $('<button>', {
                text: 'Edit',
                class: 'buttonEdit'
            });
            td.append(buttonEdit);
            buttonEdit.click(editItem);
        }
        else {
            td.text(inputs[j].value);
            if (j === 3) {
                td.addClass('averageScore');
            }
        }
    }

    studentArray.push({
        'First Name': inputs[0].value,
        'Last Name': inputs[1].value,
        'age': +inputs[2].value,
        'Average score': +inputs[3].value
    });

    console.log('Student Array (after) :', studentArray);
    $('#avg-score').text(Table.getAverageMark());
    clear();
}



function removeItem() {
    console.log('function removeItem()');
    const info = $(this).closest('tr').children('td');
    console.log('Student array (before): ',studentArray);
    const keys = Object.keys(studentArray[0]);

    for (let i = 0; i < studentArray.length; i++) {
        if (info[0].textContent === studentArray[i][keys[0]] 
            && info[1].textContent === studentArray[i][keys[1]]
            && +info[2].textContent === studentArray[i][keys[2]]
            && +info[3].textContent === studentArray[i][keys[3]]){
                studentArray.splice(i,1);
                break;
            }
    }

    $(this).closest('tr').remove();
    console.log('Student array (after): ', studentArray);
    $('#avg-score').text(Table.getAverageMark())
}

function editItem() {
    console.log('function editItem()');
    clear();
    this.closest('tr').id = 'edit';
    const info = $(this).closest('tr').children('td');
    const inputs = $('input');

    inputs[0].value = info[0].textContent;
    inputs[1].value = info[1].textContent;
    inputs[2].value = +info[2].textContent;
    inputs[3].value = +info[3].textContent;
}

function clear() {
    console.log('function clear(): clear!')
    $('input').each((i,elem) => {
        elem.value = '';
    });

    $('tr').each((i, elem) => {
        if(elem.id !== '') {
            elem.id = '';
        }
    });
}

class Table {
    constructor(arr) {
        this.studentArray = arr;
        console.log('Student Array (constructor): ', this.studentArray);
        this.createForm();
        this.createTable();


    }

    createForm() {
        const form = $('<form onsubmit="return false;">'
            + '<input id="input_name" placeholder="name" type="text">'
            + '<input id="input_surname" placeholder="surname" type="text"></input>'
            + '<input id="input_age" placeholder="age" type="number">'
            + '<input id="input_score" placeholder="score" type="number">'
            + '<button id="add_button">Add</button>'
            + '<button id="clear_button">Clear</button>'
            + '<button id="save_button">Save</button>'
            + '</form>');

        body.append(form);
    }

    createTable() {
        const table = $('<table>', { id: 'main-table'});
        body.append(table);

        // Name of columns
        let keys = this.getKeys();
        console.log('Keys Array (method: createTable) :', keys);

        // Student data
        const values = this.getDataValues();

        // Create table
        for (let i = 0; i < this.studentArray.length + 1; i++) {
            const tr = $('<tr>');
            table.append(tr);
            
            if (i === 0) {
                for (let j = 0; j < keys.length + 1; j++) {
                    tr.append($('<th>', { 
                        class: 'column-title',
                        text: (j === keys.length) ? 'Actions' : keys[j], 
                    }));
                }
            } else {
                let m = 0;
                for (let j = 0; j < keys.length + 1; j++) {
                    const td = $('<td>');
                    if (j === keys.length) {
                        td.append($('<button>', { class: 'removeButton'}).text('Delete'));
                        td.append($('<button>', { class: 'editButton'}).text('Edit'));
                    } else {
                        td.text(values[i - 1][m]);
                        if (m === 3) {
                            td.addClass('averageScore');
                        }
                        m++;
                    }
                    tr.append(td);
                }
            }
        }
    }

    getKeys() {
        return  Object.keys(this.studentArray[0]);
    }

    getDataValues() {
        const values = [];
        this.studentArray.map((elem) => values.push(Object.values(elem)));
        console.log('Values Array (method: getDataValues) :', values);
        return values;
    }

    getData() {
        return this.studentArray;
    }

    static getAverageMark() {
        const marks = $('.averageScore');
        let average = 0;
        marks.each((i, element) => average += +element.textContent);
        return (average / marks.length).toFixed(2);
    }
}