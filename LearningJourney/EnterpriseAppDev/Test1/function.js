const randomUser = "https://randomuser.me/api/?results=20";

function activeLink() {}
function getUserData() {
  let userData = fetch(randomUser)
    .then((response) => {
      if (!response.ok) {
        let errorPanel = document.querySelector("#userPanel");
        let errorCell = document.createElement("div");
        errorCell.innerHTML = `An error occurs while retrieving our staff data`;
        errorPanel.appendChild(errorCell);
      } else {
        return response.json();
      }
    })

    .then((data) => {
      for (var i = 0; i < 19; i++) {
        var userdatas = data.results[i];
        let name = userdatas.name.first + " " + userdatas.name.last;
        let email = userdatas.email;
        let city = userdatas.location.city;
        let country = userdatas.location.country;
        let picture = userdatas.picture.large;

        let userPanel = document.querySelector("#userPanel");
        let userCell = document.createElement("div");
        userCell.className = "col-12 col-sm-4 col-md-3 userContainer";
        userCell.id = "user-container";
        userCell.innerHTML = `
                 <div class = "imageContainer d-flex justify-content-center" >
            <img src="${picture}" id="image"/>
        </div>
        <h5 class="text-center">${name}</h5>
        <table>
            <tr >
                <td>${email}</td>
            </tr>
            <tr>
                <td><b>City</b></td>
                <td>: ${city}</td>
            </tr>
            <tr>
                <td><b>Country</b></td>
                <td>: ${country}</td>
            </tr>
        </table>
                  
                `;
        userPanel.appendChild(userCell);
        //   });
      }
    });
}
