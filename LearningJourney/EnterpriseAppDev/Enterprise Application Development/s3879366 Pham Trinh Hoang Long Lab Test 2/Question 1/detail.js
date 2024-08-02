document.addEventListener('DOMContentLoaded', () => {
    const countryDetails = document.getElementById('country-details');
    const urlParams = new URLSearchParams(window.location.search);
    const countryName = urlParams.get('country');
  
    // Fetch data for the selected country
    fetch(`https://restcountries.com/v3.1/name/${countryName}`)
      .then(response => response.json())
      .then(data => {
        const countryData = data[0];
  
        const countryName = document.createElement('h2');
        countryName.setAttribute("class", "heading")
        countryName.textContent = countryData.name.common;

        const flagElement = document.createElement("img");
        flagElement.src = countryData.flags.png;
        flagElement.setAttribute("class", "image")
        countryDetails.appendChild(flagElement);
  
        const capital = document.createElement('p');
        capital.textContent = `Capital: ${countryData.capital}`;
  
        const population = document.createElement('p');
        population.textContent = `Population: ${countryData.population}`;
  
        // Add more country details as needed
  
        countryDetails.appendChild(countryName);
        countryDetails.appendChild(capital);
        countryDetails.appendChild(population);
      })
      .catch(error => {
        console.error('Error:', error);
      });
  });