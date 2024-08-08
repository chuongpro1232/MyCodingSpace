// Get the HTML element with the id "list-container" and store it in the variable "listContainer".
const listContainer = document.getElementById("list-container");

// Initialize count_delete_edit_number to 0, which keeps track of the number of quizzes displayed.
var count_delete_edit_number = 0;

// Function to display the list of quizzes.
function displayQuizList() {
  // Get all items stored in localStorage and iterate through each one.
  allStorage().forEach((element) => {
    count_delete_edit_number++;

    // Create a new list item for each quiz.
    let li = document.createElement("li");
    li.innerHTML = JSON.parse(element).Title;

    // Create an edit button for each quiz.
    var edit_button = document.createElement("Button");
    edit_button.setAttribute("id", JSON.parse(element).Title);
    edit_button.onclick = function () {
      editQuizz(this.id);
    };
    edit_button.textContent = "Edit Quiz";

    // Create a delete button for each quiz.
    var delete_button = document.createElement("Button");
    delete_button.setAttribute("id", JSON.parse(element).Title);
    delete_button.onclick = function () {
      deleteQuizz(this.id);
    };
    delete_button.textContent = "Delete Quiz";

    // Append the list item, edit button, and delete button to the list container.
    listContainer.appendChild(li);
    listContainer.appendChild(edit_button);
    listContainer.appendChild(delete_button);
  });
}

// Call the function to display the quiz list on page load.
displayQuizList();

// Function to navigate to the quiz creation form.
function addQuizz() {
  window.location.assign("edit_form.html");
}

// Function to get all items stored in localStorage.
function allStorage() {
  var values = [],
    keys = Object.keys(localStorage),
    i = keys.length;

  // Loop through all keys in localStorage and store their values in the "values" array.
  while (i--) {
    values.push(localStorage.getItem(keys[i]));
  }

  return values;
}

// Function to delete a quiz from localStorage.
function deleteQuizz(title) {
  localStorage.removeItem(title);
  location.reload(); // Reload the page to update the quiz list.
}

// Function to navigate to the quiz editing form.
function editQuizz(title) {
  location.assign("edit_quiz_form.html");
}

// Function to navigate back to the home page.
function back_to_home() {
  window.location.assign("index.html");
}
