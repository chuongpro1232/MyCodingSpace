let dubaiText = document.getElementById("dubaitext");
let burjkhalifa = document.getElementById("burjkhalifa");
let stars = document.getElementById("stars");

window.addEventListener("scroll", () => {
  let value = window.scrollY;

  dubaiText.style.left = value * 2 + "px";
});
