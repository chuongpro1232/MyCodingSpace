var div = document.getElementById("answer");
let count = 0;
let check = 0;

function answerQuizz() {
    var div1 = document.createElement("div");
    count++;
  
    div1.setAttribute("id", count);  
    document.body.appendChild(div1);
  
    var question_title = document.createElement("SPAN");
    var t = document.createTextNode("123");
    question_title.appendChild(t);
    let question_title_id = "question_title" + count;
    question_title.setAttribute("id", question_title_id)
  
    var drop_down_list = document.createElement("SELECT");
    let test = "mySelect" + count;
    console.log(test);
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
  
    div.appendChild(question_title);
    div.appendChild(spinner_list);
  
    spinner_list.onchange = function(){switch_question_type(spinner_list.value)};
    var question_label = document.createElement("p");
    question_label.textContent = "Question";
    div1.appendChild(question_label);
  
    var question_input = document.createElement("TEXTAREA");
    var question_input_id = "question_input" + count;
    question_input.setAttribute("id", question_input_id);
    question_input.rows = "4";
    question_input.cols = "50";
    div1.appendChild(question_input);
  
    var down_one = document.createElement("p");
    div1.appendChild(down_one);
  
    for (let i = 0; i < 4; i++) {
      var possible_answer_span = document.createElement("SPAN");
      possible_answer_span.textContent = "Possible answer";
      div1.appendChild(possible_answer_span);
  
      var possible_answer_input = document.createElement("INPUT");
      possible_answer_input.setAttribute("type", "text");
      var possible_answer_input_id = "possible_answer_input" + count + i;
      console.log(possible_answer_input_id);
      possible_answer_input.setAttribute("id", possible_answer_input_id);
      div1.appendChild(possible_answer_input);
  
      var down_one = document.createElement("p");
      div1.appendChild(down_one);
  
      var possible_answer_input_ABCD = document.createElement("INPUT");
      possible_answer_input_ABCD.setAttribute("type", "text");
      possible_answer_input_ABCD.size = "2";
      var possible_answer_input_ABCD_id = "possible_answer_input_ABCD" + count + i;
      possible_answer_span.setAttribute("id", possible_answer_input_ABCD_id);
      div1.appendChild(possible_answer_input_ABCD);
  
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
      div1.appendChild(drop_down_list_correct_false_answer);
  
      var down_one = document.createElement("p");
      div1.appendChild(down_one);
    }
  
    div.appendChild(div1)
  }


function switch_question_type(value) {
    console.log(count);
    var div1 = document.getElementById(count);
    document.getElementById(count).innerHTML = "";
    if (value == "multiple_choice") {
        var question_label = document.createElement("p");
        question_label.textContent = "Question";
        div1.appendChild(question_label);

        var question_input = document.createElement("TEXTAREA");
        question_input.rows = "4";
        question_input.cols = "50";
        div1.appendChild(question_input);

        var answer_label = document.createElement("p");
        answer_label.textContent = "Answer";
        div.appendChild(answer_label);

        var down_one = document.createElement("p");
        div1.appendChild(down_one);

        for (let i = 0; i < 4; i++) {
            var possible_answer_span = document.createElement("SPAN");
            possible_answer_span.textContent = "Possible answer";
            div1.appendChild(possible_answer_span);

            var possible_answer_input = document.createElement("INPUT");
            possible_answer_input.setAttribute("type", "text");
            div1.appendChild(possible_answer_input);

            var down_one = document.createElement("p");
            div1.appendChild(down_one);

            var possible_answer_input_ABCD = document.createElement("INPUT");
            possible_answer_input_ABCD.setAttribute("type", "text");
            possible_answer_input_ABCD.size = "2";
            div1.appendChild(possible_answer_input_ABCD);

            var drop_down_list_correct_false_answer = document.createElement("SELECT");
            let drop_down_id = "drop_down_list_correct_false_answer" + count +i;
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
            div1.appendChild(drop_down_list_correct_false_answer);

            var down_one = document.createElement("p");
            div1.appendChild(down_one);
        }
    }

    else if (value == "essay_question") {
    var question_label = document.createElement("p");
    question_label.textContent = "Question";
    div1.appendChild(question_label);

    var question_input = document.createElement("TEXTAREA");
    question_input.rows = "4";
    question_input.cols = "50";
    div1.appendChild(question_input);
    }

    else {
        var question_label = document.createElement("p");
        question_label.textContent = "Question";
        div1.appendChild(question_label);

        var question_input = document.createElement("TEXTAREA");
        question_input.rows = "4";
        question_input.cols = "50";
        div1.appendChild(question_input);
    }
}

answerQuizz();