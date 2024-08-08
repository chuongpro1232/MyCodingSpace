const countryApiUrl =
  "https://restcountries.com/v3.1/subregion/South-Eastern Asias";
let countries = [];

function getCountryData() {
  fetch(countryApiUrl)
    .then((response) => {
      if (!response.ok) {
        console.log("An error occurs while retrieving our staff data");
      } else {
        return response.json();
      }
    })
    .then((data) => {
      countries = data;
      displayCountries(countries);
    });
}

function displayCountries(data) {
  let countryPanel = document.querySelector("#countryPanel");
  // Clear the panel before adding new data
  data.forEach((country) => {
    let name = country.name.common;
    let population = country.population.toLocaleString();
    let flag = country.flags.png;
    let capital = country.capital[0];

    let countryCell = document.createElement("div");
    countryCell.className = "col-12 col-sm-6 col-md-4 countryContainer";
    countryCell.innerHTML = `
          <div class="imageContainer">
              <img src="${flag}" />
          </div>
          <h5 class="text-center">${name}</h5>
          <table class="">
              <tr>
                  <td><b>Population</b></td>
                  <td>: ${population}</td>
              </tr>
              <tr>
                  <td><b>Capital</b></td>
                  <td>: ${capital}</td>
              </tr>
          </table>
        `;
    countryPanel.appendChild(countryCell);
  });
}

function searchCountry() {
  let input = document.getElementById("search-box").value.toLowerCase();
  let filteredCountries = countries.filter((country) =>
    country.name.common.toLowerCase().includes(input)
  );
  countryPanel.innerHTML = "";
  displayCountries(filteredCountries);
}
