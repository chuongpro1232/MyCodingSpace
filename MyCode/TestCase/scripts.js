const container = document.querySelector('.scroll-container');
const items = document.querySelectorAll('.scroll-item');

container.addEventListener('wheel', (event) => {
  event.preventDefault();
  const delta = event.deltaY;

  container.scrollBy({
    top: delta,
    behavior: 'smooth'
  });
});