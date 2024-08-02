const listContainer = document.getElementById("list-container");
var count_delete_edit_number = 0;

  function displayQuizList() {
    allStorage().forEach(element => {
        count_delete_edit_number++;

        let li = document.createElement("li");
        li.innerHTML = JSON.parse(element).Title;

        var edit_button = document.createElement("Button");
        edit_button.setAttribute("id", JSON.parse(element).Title);
        edit_button.onclick = function() {editQuizz(this.id)};
        edit_button.textContent = "Edit Quiz"

        var delete_button = document.createElement("Button");
        delete_button.setAttribute("id", JSON.parse(element).Title);
        delete_button.onclick = function() {deleteQuizz(this.id)};
        delete_button.textContent = "Delete Quiz";

        listContainer.appendChild(li);
        listContainer.appendChild(edit_button);
        listContainer.appendChild(delete_button);

    });
}

displayQuizList();


function addQuizz() {
    window.location.assign("edit_form.html");
  }

  function allStorage() {
    var values = [],
        keys = Object.keys(localStorage),
        i = keys.length;

    while ( i-- ) {
        values.push( localStorage.getItem(keys[i]) );
    }

    return values;
}

function deleteQuizz(title) {
    localStorage.removeItem(title);
    location.reload();
}

function editQuizz(title) {
    location.assign("edit_quiz_form.html");
}

function back_to_home() {
    window.location.assign("index.html");
}
