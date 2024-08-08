var div = document.getElementById("questions")
let count = 0;
let check = 0;

function questionQuizz() {
  var div1 = document.createElement("div");
  var div2 = document.createElement("div");
  count++;

  div1.setAttribute("id", count);
  let div2_id = "div2" + count;
  div2.setAttribute("id", div2_id);  
  document.body.appendChild(div1);

  // Drop down list
  var drop_down_list = document.createElement("SELECT");
  let test = "mySelect" + count;
  drop_down_list.setAttribute("id", test);
  document.body.appendChild(drop_down_list);

  var option_multiple_choice = document.createElement("option");
  option_multiple_choice.setAttribute("value", "multiple_choice");
  var multiple_choice = document.createTextNode("Multiple Choice");
  option_multiple_choice.appendChild(multiple_choice);

  var option_essay_question = document.createElement("option");
  option_essay_question.setAttribute("value", "essay_question");
  var essay_question = document.createTextNode("Essay Question");
  option_essay_question.appendChild(essay_question);

  var option_matching_question = document.createElement("option");
  option_matching_question.setAttribute("value", "matching_question");
  var matching_question = document.createTextNode("Matching Question");
  option_matching_question.appendChild(matching_question);

  var spinner_list = document.getElementById(test);
  spinner_list.appendChild(option_multiple_choice);
  spinner_list.add(option_essay_question);
  spinner_list.add(option_matching_question);

  div1.appendChild(spinner_list);

  spinner_list.onchange = function(){switch_question_type(spinner_list.value)};
  var question_label = document.createElement("p");
  question_label.textContent = "Question " + count + ":";
  div2.appendChild(question_label);

  var question_input = document.createElement("TEXTAREA");
  var question_input_id = "question_input" + count;
  question_input.setAttribute("id", question_input_id);
  question_input.rows = "4";
  question_input.cols = "50";
  div2.appendChild(question_input);

  var down_one = document.createElement("p");
  div2.appendChild(down_one);

  for (let i = 0; i < 4; i++) {
    var possible_answer_span = document.createElement("SPAN");
    possible_answer_span.textContent = "Possible answer";
    div2.appendChild(possible_answer_span);

    var possible_answer_input = document.createElement("INPUT");
    possible_answer_input.setAttribute("type", "text");
    var possible_answer_input_id = "possible_answer_input" + count + i;
    possible_answer_input.setAttribute("id", possible_answer_input_id);
    div2.appendChild(possible_answer_input);

    var down_one = document.createElement("p");
    div2.appendChild(down_one);

    var possible_answer_input_ABCD_id = "possible_answer_input_ABCD" + count + i;
    possible_answer_span.setAttribute("id", possible_answer_input_ABCD_id);

    var possible_answer_input_ABCD = document.createElement("Span");

    if(i == 0) {
      possible_answer_input_ABCD.innerText = "A"
      div2.appendChild(possible_answer_input_ABCD);
    }
    if(i == 1) {
      possible_answer_input_ABCD.innerText = "B"
      div2.appendChild(possible_answer_input_ABCD);
    }
    if(i == 2) {
      possible_answer_input_ABCD.innerText = "C"
      div2.appendChild(possible_answer_input_ABCD);
    }
    if(i == 3) {
      possible_answer_input_ABCD.innerText = "D"
      div2.appendChild(possible_answer_input_ABCD);
    }

    var drop_down_list_correct_false_answer = document.createElement("SELECT");
    let drop_down_id = "drop_down_list_correct_false_answer" + count + i;
    drop_down_list_correct_false_answer.setAttribute("id", drop_down_id);

    var option_correct = document.createElement("option");
    option_correct.setAttribute("value", "correct");
    var correct_asnwer = document.createTextNode("Correct");
    option_correct.appendChild(correct_asnwer);

    var option_false = document.createElement("option");
    option_false.setAttribute("value", "false");
    var false_answer = document.createTextNode("False");
    option_false.appendChild(false_answer);
    document.body.appendChild(drop_down_list_correct_false_answer);
    
    var spinner_list_correct_false = document.getElementById(drop_down_id);
    spinner_list_correct_false.appendChild(option_correct);
    spinner_list_correct_false.add(option_false);
    div2.appendChild(drop_down_list_correct_false_answer);

    var down_one = document.createElement("p");
    div2.appendChild(down_one);
  }

  div1.appendChild(div2);
  div.appendChild(div1);
}

function submit_detail() {
  var list_of_quiz = [];

  for (let i = 1; i < count + 1; i++) {
    var quiz_name = document.getElementById("detail_input_type").value;
    var quiz_instruction = document.getElementById("quiz_instruction").value;
    var question_title_id = "question_title" + i;

    var test = "mySelect" + i;
    var type = document.getElementById(test).value;
    if (type == "multiple_choice") {
      var question_input_id = "question_input" + i;
      var question_input = document.getElementById(question_input_id).value;
  
      var possible_answer1_id = "possible_answer_input" + i + 0;
      var possible_answer2_id = "possible_answer_input" + i + 1;
      var possible_answer3_id = "possible_answer_input" + i + 2;
      var possible_answer4_id = "possible_answer_input" + i + 3;
    
      var drop_down_list_correct_false_answer1_id = "drop_down_list_correct_false_answer" + i + 0;
      var drop_down_list_correct_false_answer2_id = "drop_down_list_correct_false_answer" + i + 1;
      var drop_down_list_correct_false_answer3_id = "drop_down_list_correct_false_answer" + i + 2;
      var drop_down_list_correct_false_answer4_id = "drop_down_list_correct_false_answer" + i + 3;
      
      var possible_answer1 =  document.getElementById(possible_answer1_id).value;
      var possible_answer2 =  document.getElementById(possible_answer2_id).value;
      var possible_answer3 =  document.getElementById(possible_answer3_id).value;
      var possible_answer4 =  document.getElementById(possible_answer4_id).value;
    
      var drop_down_list_correct_false_answer1 =  document.getElementById(drop_down_list_correct_false_answer1_id).value;
      var drop_down_list_correct_false_answer2 =  document.getElementById(drop_down_list_correct_false_answer2_id).value;
      var drop_down_list_correct_false_answer3 =  document.getElementById(drop_down_list_correct_false_answer3_id).value;
      var drop_down_list_correct_false_answer4 =  document.getElementById(drop_down_list_correct_false_answer4_id).value;
    
      var multipleChoiceQuizzClass = new MultipleChoiceQuizzClass(
        type, question_input, drop_down_list_correct_false_answer1, drop_down_list_correct_false_answer2, drop_down_list_correct_false_answer3, drop_down_list_correct_false_answer4,  possible_answer1, possible_answer2, possible_answer3, possible_answer4
      );
  
      list_of_quiz.push(multipleChoiceQuizzClass);
    }

    else if (type == "essay_question") {
        var question_input_id = "question_input" + i;
        var question_input = document.getElementById(question_input_id).value;

        var essayQuestionQuizzClass = new EssayQuestionQuizzClass(quiz_label, type, question_input);

        list_of_quiz.push(essayQuestionQuizzClass);
      }

    else {
      var question_input_id = "question_input" + i;
      var question_input = document.getElementById(question_input_id).value;

      var essayQuestionQuizzClass = new EssayQuestionQuizzClass(quiz_label, type, question_input);

      list_of_quiz.push(essayQuestionQuizzClass);
    }
  }

  localStorage.setItem(quiz_name, JSON.stringify({Title: quiz_name, Instruction: quiz_instruction, Quiz: list_of_quiz}))

  alert("Submitted successfully");
}

function back_to_home() {
  window.location.assign("teacher.html");
}

function switch_question_type(value) {
    var div1 = document.getElementById(count);
    let div2_id = "div2" + count;
    var div_2 = document.getElementById(div2_id);

    document.getElementById(div2_id).innerHTML = "";
    // document.getElementById(count).innerHTML = "";

    if (value == "multiple_choice") {
        var question_title = document.createElement("INPUT");
        question_title.setAttribute("type", "text");
        let question_title_id = "question_title" + count;
        question_title.setAttribute("id", question_title_id)
      
        // Drop down list
        var drop_down_list = document.createElement("SELECT");
        let test = "mySelect" + count;
        console.log(test);
        drop_down_list.setAttribute("id", test);
      
        var spinner_list = document.getElementById(test);

        div1.appendChild(spinner_list);
      
        spinner_list.onchange = function(){switch_question_type(spinner_list.value)};
        var question_label = document.createElement("p");
        question_label.textContent = "Question " + count + ":";
        div_2.appendChild(question_label);
      
        var question_input = document.createElement("TEXTAREA");
        var question_input_id = "question_input" + count;
        question_input.setAttribute("id", question_input_id);
        question_input.rows = "4";
        question_input.cols = "50";
        div_2.appendChild(question_input);
      
        var down_one = document.createElement("p");
        div_2.appendChild(down_one);
      
        for (let i = 0; i < 4; i++) {
          var possible_answer_span = document.createElement("SPAN");
          possible_answer_span.textContent = "Possible answer";
          div_2.appendChild(possible_answer_span);
      
          var possible_answer_input = document.createElement("INPUT");
          possible_answer_input.setAttribute("type", "text");
          var possible_answer_input_id = "possible_answer_input" + count + i;
          possible_answer_input.setAttribute("id", possible_answer_input_id);
          div_2.appendChild(possible_answer_input);
      
          var down_one = document.createElement("p");
          div_2.appendChild(down_one);
      
          // var possible_answer_input_ABCD = document.createElement("INPUT");
          // possible_answer_input_ABCD.setAttribute("type", "text");
          // possible_answer_input_ABCD.size = "2";
          var possible_answer_input_ABCD_id = "possible_answer_input_ABCD" + count + i;
          possible_answer_span.setAttribute("id", possible_answer_input_ABCD_id);
          // div_2.appendChild(possible_answer_input_ABCD);

          var possible_answer_input_ABCD = document.createElement("Span");

          if(i == 0) {
            possible_answer_input_ABCD.innerText = "A"
            div_2.appendChild(possible_answer_input_ABCD);
          }
          if(i == 1) {
            possible_answer_input_ABCD.innerText = "B"
            div_2.appendChild(possible_answer_input_ABCD);
          }
          if(i == 2) {
            possible_answer_input_ABCD.innerText = "C"
            div_2.appendChild(possible_answer_input_ABCD);
          }
          if(i == 3) {
            possible_answer_input_ABCD.innerText = "D"
            div_2.appendChild(possible_answer_input_ABCD);
          }
      
          var drop_down_list_correct_false_answer = document.createElement("SELECT");
          let drop_down_id = "drop_down_list_correct_false_answer" + count + i;
          drop_down_list_correct_false_answer.setAttribute("id", drop_down_id);
      
          var option_correct = document.createElement("option");
          option_correct.setAttribute("value", "correct");
          var correct_asnwer = document.createTextNode("Correct");
          option_correct.appendChild(correct_asnwer);
      
          var option_false = document.createElement("option");
          option_false.setAttribute("value", "false");
          var false_answer = document.createTextNode("False");
          option_false.appendChild(false_answer);
          document.body.appendChild(drop_down_list_correct_false_answer);
          
          var spinner_list_correct_false = document.getElementById(drop_down_id);
          spinner_list_correct_false.appendChild(option_correct);
          spinner_list_correct_false.add(option_false);
          div_2.appendChild(drop_down_list_correct_false_answer);
      
          var down_one = document.createElement("p");
          div_2.appendChild(down_one);
        }
        div1.appendChild(div_2);
        div.appendChild(div1);
    }

    else if (value == "essay_question") {
      var question_label = document.createElement("p");
      question_label.textContent = "Question " + count + ":";
      div_2.appendChild(question_label);

      var question_input = document.createElement("TEXTAREA");
      question_input.rows = "4";
      question_input.cols = "50";
      var question_input_id = "question_input" + count;
      question_input.setAttribute("id", question_input_id);
      div_2.appendChild(question_input);
    }

    else {
      var question_label = document.createElement("p");
      question_label.textContent = "Question " + count + ":";
      div_2.appendChild(question_label);

      var question_input = document.createElement("TEXTAREA");
      question_input.rows = "4";
      question_input.cols = "50";
      var question_input_id = "question_input" + count;
      question_input.setAttribute("id", question_input_id);
      div_2.appendChild(question_input);
    }
}

questionQuizz();

class MultipleChoiceQuizzClass {
    constructor(type, question, answer1, answer2, answer3, answer4, possible_answer1, possible_answer2, possible_answer3, possible_answer4) {
      this.type = type;
      this.question = question;
      this.answer1 = answer1;
      this.answer2 = answer2;
      this.answer3 = answer3;
      this.answer4 = answer4;
      this.possible_answer1 = possible_answer1;
      this.possible_answer2 = possible_answer2;
      this.possible_answer3 = possible_answer3;
      this.possible_answer4 = possible_answer4;
    }
  }

  class EssayQuestionQuizzClass {
    constructor(label, type, question) {
      this.label = label;
      this.type = type;
      this.question = question;
    }
  }

  function edit_quizz(id) {
    var list_of_quiz = [];

    for (let i = 1; i < count + 1; i++) {
      var quiz_name = document.getElementById("detail_input_type").value;
      var quiz_instruction = document.getElementById("quiz_instruction").value;
      var question_title_id = "question_title" + i;
  
      var test = "mySelect" + i;
      var type = document.getElementById(test).value;
      if (type == "multiple_choice") {
        var question_input_id = "question_input" + i;
        var question_input = document.getElementById(question_input_id).value;
    
        var possible_answer1_id = "possible_answer_input" + i + 0;
        var possible_answer2_id = "possible_answer_input" + i + 1;
        var possible_answer3_id = "possible_answer_input" + i + 2;
        var possible_answer4_id = "possible_answer_input" + i + 3;
      
        var drop_down_list_correct_false_answer1_id = "drop_down_list_correct_false_answer" + i + 0;
        var drop_down_list_correct_false_answer2_id = "drop_down_list_correct_false_answer" + i + 1;
        var drop_down_list_correct_false_answer3_id = "drop_down_list_correct_false_answer" + i + 2;
        var drop_down_list_correct_false_answer4_id = "drop_down_list_correct_false_answer" + i + 3;
        
        var possible_answer1 =  document.getElementById(possible_answer1_id).value;
        var possible_answer2 =  document.getElementById(possible_answer2_id).value;
        var possible_answer3 =  document.getElementById(possible_answer3_id).value;
        var possible_answer4 =  document.getElementById(possible_answer4_id).value;
      
        var drop_down_list_correct_false_answer1 =  document.getElementById(drop_down_list_correct_false_answer1_id).value;
        var drop_down_list_correct_false_answer2 =  document.getElementById(drop_down_list_correct_false_answer2_id).value;
        var drop_down_list_correct_false_answer3 =  document.getElementById(drop_down_list_correct_false_answer3_id).value;
        var drop_down_list_correct_false_answer4 =  document.getElementById(drop_down_list_correct_false_answer4_id).value;
      
        var multipleChoiceQuizzClass = new MultipleChoiceQuizzClass(
          type, question_input, drop_down_list_correct_false_answer1, drop_down_list_correct_false_answer2, drop_down_list_correct_false_answer3, drop_down_list_correct_false_answer4,  possible_answer1, possible_answer2, possible_answer3, possible_answer4
        );
    
        list_of_quiz.push(multipleChoiceQuizzClass);
      }
  
      else if (type == "essay_question") {
          var question_input_id = "question_input" + i;
          var question_input = document.getElementById(question_input_id).value;
  
          var essayQuestionQuizzClass = new EssayQuestionQuizzClass(quiz_label, type, question_input);
  
          list_of_quiz.push(essayQuestionQuizzClass);
        }
  
      else {
        var question_input_id = "question_input" + i;
        var question_input = document.getElementById(question_input_id).value;
  
        var essayQuestionQuizzClass = new EssayQuestionQuizzClass(quiz_label, type, question_input);
  
        list_of_quiz.push(essayQuestionQuizzClass);
      }
    }
    
    localStorage.removeItem(id);
    localStorage.setItem(quiz_name, JSON.stringify({Title: quiz_name, Instruction: quiz_instruction, Quiz: list_of_quiz}))
  
    alert("Edit successfully");
  }