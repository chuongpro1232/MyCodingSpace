const countryApiUrl =
  "https://restcountries.com/v3.1/subregion/South-Eastern Asia";

function getCountryData() {
  let countryData = fetch(countryApiUrl)
    .then((response) => response.json())
    .then((data) => {
      data.forEach((country) => {
        let name = country.name.common;
        let population = country.population.toLocaleString();
        let flag = country.flags.png;
        let capital = country.capital[0];

        let countryPanel = document.querySelector("#countryPanel");
        let countryCell = document.createElement("div");
        countryCell.className = "col-12 col-sm-6 col-md-4 countryContainer";

        countryCell.innerHTML = `
        <div class = "imageContainer">
            <img src="${flag}" />
        </div>
        <h5 class="text-center">${name}</h5>
        <table class="col-12 text-center">
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
    });
}
