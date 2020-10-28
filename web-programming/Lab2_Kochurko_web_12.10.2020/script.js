// Constructor obj Student:
function Student(name, surname, age, averageScore) {
    this.name = name;
    this.surname = surname;
    this.age = age;
    this.averageScore = averageScore;
}


let body = document.querySelector('body');


const module = (function () {
    // Create array of students:
    let studentArray = [];
    studentArray.push(new Student('Vlad', 'Kochurko', 18, 8.8));
    studentArray.push(new Student('Vlad', 'Kochurko', 18, 8.8));
    studentArray.push(new Student('Vlad', 'Kochurko', 18, 8.8));
    studentArray.push(new Student('Vlad', 'Kochurko', 18, 8.8));
    studentArray.push(new Student('Vlad', 'Kochurko', 18, 8.8));
    studentArray.push(new Student('Sergey', 'Harlanov', 18, 8.5));
    studentArray.push(new Student('Sergey', 'Harlanov', 18, 8.5));
    studentArray.push(new Student('Sergey', 'Harlanov', 18, 8.5));
    studentArray.push(new Student('Sergey', 'Harlanov', 18, 8.5));
    studentArray.push(new Student('Vlad', 'Mironchuk', 19, 8.0));
    studentArray.push(new Student('Vlad', 'Mironchuk', 19, 8.0));
    studentArray.push(new Student('Vlad', 'Mironchuk', 19, 8.0));
    studentArray.push(new Student('Vlad', 'Mironchuk', 19, 8.0));
    studentArray.push(new Student('Vlad', 'Rabetz', 18, 8.2));
    studentArray.push(new Student('Vlad', 'Rabetz', 18, 8.2));
    studentArray.push(new Student('Vlad', 'Rabetz', 18, 8.2));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));
    studentArray.push(new Student('Jan', 'Hidronovich', 18, 10.0));

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
                    for (let j = 0; j < keys.length; j++) {
                        let th = document.createElement('th');
                        th = tr.appendChild(th);
                        th.innerText = keys[j];
                    }
                }
                else {
                    let m = 0;
                    for (let j = 0; j < keys.length; j++) {
                        let td = document.createElement('td');
                        td = tr.appendChild(td);
                        td.innerText = values[i - 1][m];
                        if (m === 3) {
                            td.className = "averageScore";
                        }
                        m++;
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
        }
    }
}())



module.createTable();
module.getAverageMark();





