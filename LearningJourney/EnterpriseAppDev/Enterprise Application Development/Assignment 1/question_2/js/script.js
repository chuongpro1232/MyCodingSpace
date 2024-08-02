const pokemonName = document.querySelector('.pokemon_name');
const pokemonNumber = document.querySelector('.pokemon_number');
const pokemonImage = document.querySelector('.pokemon_image');
const pokemonType = document.querySelector('.pokemon_type');
const pokemonHeight = document.querySelector('.pokemon_height');
const pokemonWeight = document.querySelector('.pokemon_weight');
const pokemonDescription = document.querySelector('.pokemon_description');

const form = document.querySelector('.form');
const input = document.querySelector('.input_search');

let defaultSearchPokemon = 1;

const fetchPokemonBasicData = async (pokemon) => {
  const APIResponse = await fetch(`https://pokeapi.co/api/v2/pokemon/${pokemon}`);

  if (APIResponse.status === 200) {
    const data = await APIResponse.json();
    return data;
  }
}

const fetchPokemonDescrtiption = async (pokemon) => {
  const APIResponse = await fetch(`https://pokeapi.co/api/v2/pokemon-species/${pokemon}`);

  if (APIResponse.status === 200) {
    const data = await APIResponse.json();
    return data;
  }
}

const renderPokemon = async (pokemon) => {

  pokemonName.innerHTML = 'Loading...';
  pokemonNumber.innerHTML = '';

  const data_basic = await fetchPokemonBasicData(pokemon);
  const data_description = await fetchPokemonDescrtiption(pokemon);
  console.log(data_basic);
  console.log(data_description);

  if (data_basic) {
    pokemonImage.style.display = 'block';
    pokemonName.innerHTML = data_basic.name;
    pokemonNumber.innerHTML = data_basic.id;
    pokemonType.innerHTML = data_basic.types[0].type.name;
    pokemonHeight.innerHTML = data_basic.height;
    pokemonWeight.innerHTML = data_basic.weight;

    var data_descrtiption_combine = data_description.flavor_text_entries[1].flavor_text + " " + data_description.flavor_text_entries[2].flavor_text;
    pokemonDescription.innerHTML = data_descrtiption_combine;

    pokemonImage.src = data_basic['sprites']['versions']['generation-v']['black-white']['animated']['front_default'];
    input.value = '';
    defaultSearchPokemon = data.id;
  } else {
    pokemonImage.style.display = 'none';
    pokemonName.innerHTML = 'Not found';
    pokemonNumber.innerHTML = '';
  }
}

form.addEventListener('submit', (event) => {
  event.preventDefault();
  renderPokemon(input.value.toLowerCase());
});

renderPokemon(defaultSearchPokemon);
