var check = false;

function studentLogin() {
  window.location.assign("student.html")
}

function teacherLogin() {
  window.location.assign("teacher.html")
}

// Get the elements with class="column"
var elements = document.getElementsByClassName("column");

// Declare a loop variable
var i;

// List View
function listView() {
  for (i = 0; i < elements.length; i++) {
    elements[i].style.width = "100%";
  }
}

// Grid View
function gridView() {
  for (i = 0; i < elements.length; i++) {
    elements[i].style.width = "50%";
  }
}

function goToQuiz() {
    alert("Enter");
}

function editQuizz() {
  alert("Enter");
}

function addQuizz() {
  alert("Enter");
}

function detailQuizz() {
  const label_and_textbox = document.getElementById("quiz_instruction_and_text_box");
  label_and_textbox.remove();
}