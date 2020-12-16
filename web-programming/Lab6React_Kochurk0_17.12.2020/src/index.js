import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import reportWebVitals from './reportWebVitals';

let students = [];
class Table extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isLoading: true,
      editIndex: null
    }

    this.addStudent = this.addStudent.bind(this);
    this.editStudent = this.editStudent.bind(this);
    this.delStudent = this.delStudent.bind(this);
  }

  componentDidMount() {
    fetch('./people.json')
      .then((res) => res.json())
          .then((data) => {
            students = data;

            let avgScore = 0;
            if (students.length) {
              avgScore = this.getAvgScore(students);
            }
            this.setState({
              avgScore: avgScore,
              data: students,
              isLoading: false
            });
          }).catch((err) => console.log(err));
  }

  getAvgScore(arr) {
    return (arr.map(obj => obj.score).reduce((a, b) => a + b, 0) / arr.length).toFixed(2);
  }

  addStudent(e) {
    e.preventDefault();

    const inputs = document.querySelectorAll(".inputs-place");

    const student = {
      firstName: inputs[0].value,
      lastName: inputs[1].value,
      age: +inputs[2].value,
      score: +inputs[3].value
    }

    students.push(student);

    let avgScore = this.getAvgScore(students);

    this.setState({
      avgScore: avgScore,
      data: students
    });


    this.clearInputs();
  }

  saveStudent(editIndex) {
      if (editIndex !== null) {
        const inputs = document.querySelectorAll(".inputs-place");
        const i = editIndex;
        students[i].firstName = inputs[0].value;
        students[i].lastName = inputs[1].value
        students[i].age = +inputs[2].value;
        students[i].score = +inputs[3].value;
        this.clearInputs();
        const avgScore = this.getAvgScore(students);
        this.setState({
          avgScore: avgScore,
          data: students,
          editIndex: null,
        });
      } else {
        alert('Student not selected');
      }
  }

  clearInputs() {
    const inputs = document.querySelectorAll(".inputs-place");
    inputs[0].value = '';
    inputs[1].value = '';
    inputs[2].value = '';
    inputs[3].value = '';
  }

  editStudent(e, index) {
    e.preventDefault();
    const inputs = document.querySelectorAll(".inputs-place");
    inputs[0].value = students[index].firstName;
    inputs[1].value = students[index].lastName;
    inputs[2].value = students[index].age;
    inputs[3].value = students[index].score;
    this.setState({
      editIndex: index,
    })
  }

  delStudent(e, index) {
    e.preventDefault();
    students.splice(index, 1);
    const avgScore = this.getAvgScore(students);
    this.setState({
      avgScore: avgScore,
      data: students
    })
  }

  render() {
    return (<div>
      <form onSubmit={this.addStudent}>
        <input className="inputs-place" type="text" placeholder={'Name'}/>
        <input className="inputs-place" type="text" placeholder={'Surname'}/>
        <input className="inputs-place" type="number" placeholder={'Age'}/>
        <input className="inputs-place" type="number" placeholder={'Score'}/>

        <input type="submit" value="Add" />
        <input type="button" onClick={() => this.saveStudent(this.state.editIndex)} value="Save" />
      </form>

      <table border="2">
        <thead>
          <tr>
            <th>Name</th>
            <th>Surname</th>
            <th>Age</th>
            <th>Score</th>
          </tr>
        </thead>
        <tbody>
          {
            this.state.isLoading
              ? <p>Loading...</p>
              : this.state.data.map((student,index) => (
            <tr key={index}>
              <td>{student.firstName}</td>
              <td>{student.lastName}</td>
              <td>{student.age}</td>
              <td>{student.score}</td>
              <td><input type="button" onClick={(e) => this.editStudent(e, index)} value="Edit"  id={'e' + index}/></td>
              <td><input type="button" onClick={(e) => this.delStudent(e, index)} value="Delete"  id={'d' + index}/></td>

            </tr>
          ))}
        <tr>
          <td colspan="4">
            <input type="text" value={`Average score: ${this.state.avgScore}`}/>
          </td>
        </tr>
        </tbody>
      </table>
    </div>
  );
  }
}

ReactDOM.render(
  <Table />,
  document.getElementById('root')
);
reportWebVitals();
