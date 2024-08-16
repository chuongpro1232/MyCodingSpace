// Initialize count1 to 0, which keeps track of quiz interactions.
let count1 = 0;

// Get the HTML element with the id "answer" and store it in the variable "div".
var div = document.getElementById("answer");

// Initialize several variables for managing the quiz state.
let count = 0;
let check = 0;
let first = 0;
let second = 0;
let title_to_search = "";
let question_count = 0;

// Function to display the quiz list based on count1 value.
function displayQuizList(count1) {
  // Create a new unordered list element.
  var listContainer = document.createElement("UL");

  // If count1 is 0, create a new list container and populate it with quizzes.
  if (count1 == 0) {
    var list_container_id = "list-container-1" + first;
    listContainer.setAttribute("id", list_container_id);
    document.getElementById("answer").innerHTML = "";

    // Append the new list container to the body.
    document.body.appendChild(listContainer);

    // Add an event listener to handle quiz title clicks.
    listContainer.addEventListener(
      "click",
      function (e) {
        if (e.target.tagName === "LI") {
          quiz_title = e.target.innerText;
          title_to_search = e.target.innerText;
        }
        taking();
      },
      false
    );

    // Get all items stored in localStorage and create list items for each quiz.
    let array = allStorage();
    array.forEach((element) => {
      let li = document.createElement("li");
      li.innerHTML = JSON.parse(element).Title;
      console.log(JSON.parse(element));
      listContainer.appendChild(li);
    });
    first++;
  }
  // If count1 is not 0, update the existing list container and display the quiz questions.
  else {
    var list_container_id = "list-container-1" + second;
    document.getElementById(list_container_id).innerHTML = "";
    document.body.appendChild(div);
    answerQuizz(title_to_search);
    second++;
  }
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

// Function to increment count1 and display the quiz list.
function taking() {
  count1++;
  displayQuizList(count1);
}

// Function to display quiz questions based on the selected quiz title.
function answerQuizz(quiz_title_to_search) {
  // Get the quiz data from localStorage.
  var quiz_number = JSON.parse(localStorage.getItem(quiz_title_to_search));

  // Create div elements to structure the quiz display.
  var div1 = document.createElement("div");
  var div2 = document.createElement("div");
  count++;

  // Create and append the quiz title.
  var question_title = document.createElement("H3");
  var t = document.createTextNode(quiz_number.Title);
  question_title.appendChild(t);
  let question_title_id = "question_title" + count;
  question_title.setAttribute("id", question_title_id);
  div.appendChild(question_title);

  // Loop through each question in the quiz and display it.
  quiz_number.Quiz.forEach((element) => {
    question_count++;

    var div3 = document.createElement("div");
    div3.setAttribute("id", count);
    div3.setAttribute("class", "div_class");
    document.body.appendChild(div3);

    var question_label = document.createElement("SPAN");
    question_label.textContent = "Question " + question_count + ":         ";
    div3.appendChild(question_label);

    // Display multiple choice questions.
    if (element.type == "multiple_choice") {
      var question_content = document.createElement("SPAN");
      question_content.textContent = element.question;
      div3.appendChild(question_content);
      var down_one = document.createElement("p");
      div3.appendChild(down_one);

      // Display possible answers for multiple choice questions.
      for (let i = 0; i < 4; i++) {
        var possible_answer_span = document.createElement("SPAN");
        var possible_answer_input = document.createElement("SPAN");

        if (i == 0) {
          possible_answer_span.textContent = "Answer A:             ";
          possible_answer_input.textContent = element.possible_answer1;
        } else if (i == 1) {
          possible_answer_span.textContent = "Answer B:             ";
          possible_answer_input.textContent = element.possible_answer2;
        } else if (i == 2) {
          possible_answer_span.textContent = "Answer C:             ";
          possible_answer_input.textContent = element.possible_answer3;
        } else if (i == 3) {
          possible_answer_span.textContent = "Answer D:             ";
          possible_answer_input.textContent = element.possible_answer4;
        }

        div3.appendChild(possible_answer_span);
        div3.appendChild(possible_answer_input);

        var down_one = document.createElement("p");
        div3.appendChild(down_one);
      }

      // Display input field for student's answer.
      var possible_answer_span = document.createElement("SPAN");
      possible_answer_span.textContent = "Student Answer:     ";
      div3.appendChild(possible_answer_span);

      var possible_answer_input_ABCD = document.createElement("INPUT");
      possible_answer_input_ABCD.setAttribute("type", "text");
      possible_answer_input_ABCD.size = "2";
      div3.appendChild(possible_answer_input_ABCD);
      var down_one = document.createElement("p");
      div3.appendChild(down_one);
    }
    // Display essay questions.
    else if (element.type == "essay_question") {
      var question_input = document.createElement("SPAN");
      question_input.textContent = element.question;
      div3.appendChild(question_input);

      var down_one = document.createElement("p");
      div3.appendChild(down_one);

      var possible_answer_span = document.createElement("p");
      possible_answer_span.textContent = "Student Answer:     ";
      div3.appendChild(possible_answer_span);

      var answer_input = document.createElement("TEXTAREA");
      answer_input.rows = "4";
      answer_input.cols = "50";
      div3.appendChild(answer_input);

      var down_one = document.createElement("p");
      div3.appendChild(down_one);
    }

    div2.appendChild(div3);
  });

  div1.appendChild(div2);

  // Create and append submit and cancel buttons.
  var submit_button = document.createElement("BUTTON");
  submit_button.textContent = "Submit";
  submit_button.setAttribute("class", "submit_button_class");
  submit_button.onclick = function () {
    submit();
  };

  var cancel_button = document.createElement("BUTTON");
  cancel_button.textContent = "Cancel";
  cancel_button.setAttribute("class", "cancel_button_class");
  cancel_button.onclick = function () {
    cancel();
  };

  var div4 = document.createElement("div");
  div4.setAttribute("class", "submit_cancel_button_class");
  div4.appendChild(submit_button);
  div4.appendChild(cancel_button);

  div1.appendChild(div4);
  div.appendChild(div1);
}

// Function to handle the submit action.
function submit() {
  count1--;
  alert("You submitted successfully");
  displayQuizList(count1);
}

// Function to handle the cancel action.
function cancel() {
  count1--;
  displayQuizList(count1);
}

// Function to navigate back to the login page.
function back_to_login_page() {
  window.location.assign("index.html");
}

// Initially display the quiz list.
displayQuizList(count1);
