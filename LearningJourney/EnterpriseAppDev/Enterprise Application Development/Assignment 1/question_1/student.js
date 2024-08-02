let count1 = 0;

var div = document.getElementById("answer");
let count = 0;
let check = 0;
let first = 0;
let second = 0;
let title_to_search = "";
let question_count = 0;

function displayQuizList(count1) {
    var listContainer = document.createElement("UL");

    if (count1 == 0 ) {
        var list_container_id = "list-container-1" + first;
        listContainer.setAttribute("id", list_container_id);
        document.getElementById("answer").innerHTML = "";

        document.body.appendChild(listContainer);

        listContainer.addEventListener("click", function(e){
            if (e.target.tagName === 'LI'){
                quiz_title = e.target.innerText;
                title_to_search = e.target.innerText;
              }
            taking();
          },false);

        // document.getElementById("answer").innerHTML = "";
        let array = allStorage();
        array,array.forEach(element => {
            let li = document.createElement("li");
            li.innerHTML = JSON.parse(element).Title;
            console.log(JSON.parse(element));
            listContainer.appendChild(li);
        });
        first++;
    }
    else {
        var list_container_id = "list-container-1" + second;
        document.getElementById(list_container_id).innerHTML = "";
        document.body.appendChild(div)
        // listContainer.parentNode().removeChild(listContainer);
        answerQuizz(title_to_search);
        second++;
    }

    // console.log(allStorage());
}

// function addQuestion(){
//     let li = document.createElement("li");
//     li.innerHTML = inputBox.value;
//     listContainer.appendChild(li);
//     let span = document.createElement("span");
//     span.innerHTML = "\u00d7"
//     li.appendChild(span);
//     // inputBox.value ="";
// }

function allStorage() {
    var values = [],
        keys = Object.keys(localStorage),
        i = keys.length;

    while ( i-- ) {
        values.push( localStorage.getItem(keys[i]) );
    }

    return values;
}
  
function taking() {
    count1++;
    displayQuizList(count1);
    // window.location.assign("answer.html");
}

function answerQuizz(quiz_title_to_search) {
    // const detail_class = document.getElementById("detail_class");
    // detail_class.remove();
    // var div = document.createElement("div");

    var quiz_number = JSON.parse(localStorage.getItem(quiz_title_to_search));

    var div1 = document.createElement("div");
    var div2 = document.createElement("div");
    count++;
  
    var question_title = document.createElement("H3");
    // question_title.setAttribute("type", "text");
    var t = document.createTextNode(quiz_number.Title);
    question_title.appendChild(t);
    let question_title_id = "question_title" + count;
    question_title.setAttribute("id", question_title_id)
    
    div.appendChild(question_title);

    quiz_number.Quiz.forEach(element => {
        question_count++;

        var div3 = document.createElement("div");
        div3.setAttribute("id", count);  
        div3.setAttribute("class", "div_class");
        document.body.appendChild(div3);

        var question_label = document.createElement("SPAN");
        question_label.textContent = "Question " + question_count + ":         ";
        div3.appendChild(question_label);

        if(element.type == "multiple_choice") {
            var question_content = document.createElement("SPAN");
            question_content.textContent = element.question;
            div3.appendChild(question_content);
            var down_one = document.createElement("p");
            div3.appendChild(down_one);
    
            for (let i = 0; i < 4; i++) {
                if (i == 0) {
                    var possible_answer_span = document.createElement("SPAN");
                    possible_answer_span.textContent = "Answer " + "A:             ";
                    div3.appendChild(possible_answer_span);
    
                    var possible_answer_input = document.createElement("SPAN");
                    possible_answer_input.textContent = element.possible_answer1;
                    div3.appendChild(possible_answer_input);
                }
    
                if(i == 1) {
                    var possible_answer_span = document.createElement("SPAN");
                    possible_answer_span.textContent = "Answer " + "B:             ";
                    div3.appendChild(possible_answer_span);
    
                    var possible_answer_input = document.createElement("SPAN");
                    possible_answer_input.textContent = element.possible_answer2;
                    div3.appendChild(possible_answer_input);
                }
    
                if(i == 2) {
                    var possible_answer_span = document.createElement("SPAN");
                    possible_answer_span.textContent = "Answer " + "C:             ";
                    div3.appendChild(possible_answer_span);
    
                    var possible_answer_input = document.createElement("SPAN");
                    possible_answer_input.textContent = element.possible_answer3;
                    div3.appendChild(possible_answer_input);
                }
    
                if(i == 3) {
                    var possible_answer_span = document.createElement("SPAN");
                    possible_answer_span.textContent = "Answer " + "D:             ";
                    div3.appendChild(possible_answer_span);
    
                    var possible_answer_input = document.createElement("SPAN");
                    possible_answer_input.textContent = element.possible_answer4;
                    div3.appendChild(possible_answer_input);
                }
    
                var down_one = document.createElement("p");
                div3.appendChild(down_one);
              }
    
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
        else if(element.type == "essay_question") {
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

    var submit_button = document.createElement("BUTTON");
    submit_button.textContent = "Submit"
    submit_button.setAttribute("class", "submit_button_class");
    submit_button.onclick = function() {submit();};

    var cancel_button = document.createElement("BUTTON");
    cancel_button.textContent = "Cancel"
    cancel_button.setAttribute("class", "cancel_button_class");
    cancel_button.onclick = function() {cancel();};


    var div4 = document.createElement("div");
    div4.setAttribute("class", "submit_cancel_button_class");

    div4.appendChild(submit_button);
    div4.appendChild(cancel_button);

    div1.appendChild(div4);

    div.appendChild(div1);
    
  }

function submit() {
    count1--;
    alert("You submited succesfully");
    displayQuizList(count1);
}

function cancel() {
    count1--;
    displayQuizList(count1);
}

function back_to_login_page() {
    window.location.assign("index.html")
}

displayQuizList(count1);
