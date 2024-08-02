
const generateRandomNum = function (min, max) {
    return Math.floor(Math.random() * max + min);
}

let draggedBox;

const dragstart = function(e){    
    draggedBox = e.target;
    e.dataTransfer.setData("text", e.target.textContent);
}

const dragover = function(e){
    e.preventDefault();
}

const dragdrop = function(e){
    e.preventDefault();
    draggedBox.textContent = e.target.textContent;
    e.target.textContent = e.dataTransfer.getData("text");
    draggedBox = undefined;
}

const addBoxes = function(){
    const boxContainer = document.querySelector("#box-container");
    const nums = new Set();
    for(let i = 0; i < 10; i++){
        const box = document.createElement('div');

        let num = generateRandomNum(0, 50);
        while (nums.has(num)){
            num = generateRandomNum(0, 50);
        }

        nums.add(num);
        box.textContent = num;
        box.className = "box";
        box.setAttribute("draggable", true);
        box.addEventListener("dragover", dragover);
        box.addEventListener("drop", dragdrop);
        box.addEventListener("dragstart", dragstart);
        
        boxContainer.appendChild(box);
    }
}





addBoxes();