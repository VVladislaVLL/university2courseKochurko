function getAvgScore(arr) {
  let avg = 0;
  for (let i = 0; i < arr.length; i++) {
    avg += arr[i].score;
  }
  return (avg / arr.length).toFixed(2);
}

const module = angular.module('studentApp', []);
const studentApp = angular.module("studentApp", []);

studentApp.controller("studentController", function ($scope, $http) {
  $scope.students = [];
  $http.get('./people.json').then((response) => {
    $scope.students = response.data.concat();
    $scope.avgScore = getAvgScore($scope.students);
  });

  $scope.flagEditable = false;
  $scope.editIndex = -1;

  $scope.clearInputs = () => {
    const inputs = document.querySelectorAll('input');
    inputs[0].value = '';
    inputs[1].value = '';
    inputs[2].value = '';
    inputs[3].value = '';
    if ($scope.flagEditable === true) {
      $scope.flagEditable = false;
    }
  }
  $scope.addItem = function (firstName, lastName, age, score) {
    score = parseFloat(score);
    age = parseInt(age);
    if(firstName != '' && lastName != '' && !isNaN(age) && !isNaN(score)) {
      $scope.students.push({ firstName: firstName, lastName: lastName, age: age, score: score});
    }
    $scope.avgScore = getAvgScore($scope.students);
    $scope.clearInputs();
  }

  $scope.delItem = function (index) {
    $scope.students.splice(index, 1);
    $scope.avgScore = getAvgScore($scope.students);
  }

  $scope.editItem = index => {
    const student = $scope.students[index];
    const inputs = document.querySelectorAll('input');
    inputs[0].value = student.firstName;
    inputs[1].value = student.lastName;
    inputs[2].value = student.age;
    inputs[3].value = student.score;
    console.log(student);
    $scope.editIndex = index;
    $scope.flagEditable = !$scope.flagEditable;
  }

  $scope.saveItem = () => {
    const inputs = document.querySelectorAll('input');
    if ($scope.flagEditable === true) {
      $scope.students[$scope.editIndex].firstName = inputs[0].value;
      $scope.students[$scope.editIndex].lastName = inputs[1].value;
      $scope.students[$scope.editIndex].age = +inputs[2].value;
      $scope.students[$scope.editIndex].score = +inputs[3].value;
    }
    $scope.clearInputs();
    $scope.avgScore = getAvgScore($scope.students);
  }
});

