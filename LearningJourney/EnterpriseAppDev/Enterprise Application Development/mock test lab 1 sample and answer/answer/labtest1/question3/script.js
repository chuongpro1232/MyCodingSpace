const url = "https://api.data.gov.hk/v1/carpark-info-vacancy?";
const parkingLotPerPage = 15;
const maxPage = 10;
let parkingLotInfo = [];
let currentPage = 0;
let currentPageElement;

const formatArray = function (arr) {
    let res = '';
    for (let i = 0; i < arr.length; i++) {
        res += arr[i];
        if (i !== arr.length - 1) {
            res += ', ';
        }
    }

    return res;
}

const getVacancy = async function(carparkId){
    const endpoint = url + "data=vacancy&carparkIds=" + carparkId;
    const response = await fetch(endpoint);
    const result = await response.json();
    const vacancyData = result.results[0];
    return vacancyData;
}

const requestParkingInfo = async function (data, vehicleTypes, carparkIds, lang) {
    const parkingInfo = document.querySelector('.parking-info');
    parkingInfo.innerHTML = `
    <div class="spinner-border" role="status">
    <span class="visually-hidden">Loading...</span>
    </div>
    `

    const pagination = document.querySelector('.pagination');
    pagination.innerHTML = ''
    
    let endpoint =
        `${url}${!!data ? `data=${data}` : 'info'}${!!vehicleTypes ? `&vehicleTypes=${vehicleTypes}` : ""}${!!carparkIds ? `&carparkIds=${carparkIds}` : ""}${!!lang ? `&lang=${lang}` : ""}
    `;
    const response = await fetch(endpoint);
    const result = await response.json();

    parkingLotInfo = getParkingInfo(result.results);
    return parkingLotInfo;
}

const placeholderPic = "https://socialistmodernism.com/wp-content/uploads/2017/07/placeholder-image.png?w=640";
const getParkingInfo = function (response) {
    const parkingLotsInfo = [];
    for (let i = 0; i < response.length; i++) {
        const info = {};
        const cur = response[i];

        info['index'] = i;
        info['name'] = cur.name;
        info['address'] = cur.address;
        info['displayAddress'] = cur.displayAddress;
        info['park_Id'] = cur.park_Id;
        info['openingHours'] = !!cur.openingHours ? cur.openingHours[0] : undefined;
        info['website'] = cur.website;
        info['heightLimits'] = !!cur.heightLimits && !!cur.heightLimits[0] ? cur.heightLimits[0].height : undefined;
        info['paymentMethods'] = cur.paymentMethods;
        info['contactNo'] = cur.contactNo;
        info['latitude'] = cur.latitude;
        info['longitude'] = cur.longitude;
        info['isOpen'] = cur.opening_status === "OPEN" ? true : false;
        info['thumbnail'] = cur.renditionUrls ?
            (cur.renditionUrls.thumbnail ? cur.renditionUrls.thumbnail : placeholderPic)
            : placeholderPic;
        parkingLotsInfo.push(info);
    }

    return parkingLotsInfo;
}

const createParkingLotCard = function (parkingLot) {
    const card = document.createElement("div");
    card.className = "card";

    const thumbnail = document.createElement('img');
    thumbnail.src = parkingLot['thumbnail'];
    thumbnail.classList.add("card-thumbnail", "card-img-top");

    const cardBody = document.createElement("div");
    cardBody.className = "card-body";

    const cardTitle = document.createElement("h5");
    cardTitle.className = "card-title"

    const cardText = document.createElement("p");
    cardText.className = "card-text";
    cardText.textContent = parkingLot.name;

    const address = document.createElement("div");
    address.className = "card-text";
    address.textContent = parkingLot.displayAddress;

    const openingStatus = document.createElement("div");
    openingStatus.classList.add("card-text", "opening-status");
    if (parkingLot.isOpen) {
        openingStatus.textContent = "Open"
        openingStatus.classList.add("opened");
    }
    else {
        openingStatus.textContent = "Closed"
        openingStatus.classList.add("closed");
    }

    const cardButton = document.createElement("button");
    cardButton.classList.add("btn", "btn-primary", "card-button");
    cardButton.setAttribute("data-bs-target", "#parking-lot-detail");
    cardButton.setAttribute("data-bs-toggle", "modal");
    cardButton.setAttribute("type", "button");
    cardButton.textContent = "More info";
    cardButton.addEventListener("click", (e) => {
        updateModal(parkingLot.index);
    })

    cardBody.appendChild(cardTitle);
    cardBody.appendChild(openingStatus);
    cardBody.appendChild(cardText);
    cardBody.appendChild(address);

    cardBody.appendChild(cardButton);

    card.appendChild(thumbnail);
    card.appendChild(cardBody);

    return card;
}

const updateModal = async function(index) {
    const parkingLot = parkingLotInfo[index];
    const modal = document.querySelector("#parking-lot-detail");
    const title = modal.querySelector(".modal-title");
    title.textContent = parkingLot.name;

    const body = modal.querySelector(".modal-body");
    body.innerHTML = ``
    const vacancyElement = document.createElement("div");
    vacancyElement.innerHTML = `
    <div class="spinner-border" role="status">
    <span class="visually-hidden">Loading...</span>
    </div>
    `

    body.appendChild(vacancyElement);

    

    const contactNo = document.createElement("div");

    const address = !!parkingLot.address ? `
    <p>
        Building Name: ${parkingLot.address.buildingName ? parkingLot.address.buildingName : "N/A"}
        <br>
        Street Name: ${parkingLot.address.streetName ? parkingLot.address.streetName : "N/A"},
        <br>
        Building Number: ${parkingLot.address.buildingNo ? parkingLot.address.buildingNo : "N/A"}
        <br>
        Floor: ${parkingLot.address.floor ? parkingLot.address.floor : "N/A"}
        <br>
        Sub District: ${parkingLot.address.subDistrict ? parkingLot.address.subDistrict : "N/A"},
        <br>
        District: ${parkingLot.address.dcDistrict ? parkingLot.address.dcDistrict : "N/A"}
        <br>
        Region: ${parkingLot.address.region ? parkingLot.address.region : "N/A"}
    </p>
    <hr>
    ` : "";

    contactNo.innerHTML = `
    <p>
        Opening hours (weekdays): ${!!parkingLot.openingHours && !!parkingLot.openingHours.weekdays ? formatArray(parkingLot.openingHours.weekdays) : "N/A"}
    </p>
    <hr>
    <div class="d-flex flex-row justify-content-between">
        <div>Start hour: ${!!parkingLot.openingHours ? parkingLot.openingHours.periodStart : "N/A"}</div>
        
        <div>End hour: ${!!parkingLot.openingHours ? parkingLot.openingHours.periodEnd : "N/A"}</div>
        <br>
    </div>
    <hr>
    <p>
        Height Limit: ${!!parkingLot.heightLimits ? parkingLot.heightLimits + " m" : "N/A"} 
    </p>
    <hr>
    <p>
    Website: ${!!parkingLot.website ? `<a href=${parkingLot.website}}>${parkingLot.website}</a>` : "N/A"}
    </p>
    <hr>
        ${address}
    
    <p>
        Payment method(s): ${!!parkingLot.paymentMethods ? formatArray(parkingLot.paymentMethods) : "N/A"}
    </p>
    <hr>
    <div>
        Contact Number(s): + ${parkingLot.contactNo}
    </div>
    
    `;


    body.appendChild(contactNo);

    const vacancy = await getVacancy(parkingLot.park_Id);
    let vacancyOfVehicles = [];
    if (vacancy){
        for(const k in vacancy){
            if (k === "park_Id"){
                continue;
            }
            vacancyOfVehicles.push(`${k}: ${vacancy[k][0].vacancy}`)
    
        }
    }
    
    vacancyElement.innerHTML = `
    <div>
    Vacancy
    <br>
    ${formatArray(vacancyOfVehicles)}
    </div>
    <hr>
    `

    const mapButton = document.querySelector("#modal-google-map");
    mapButton.addEventListener("click", (e) => {
        window.open(`https://www.google.com/maps/@${parkingLot.latitude},${parkingLot.longitude},15z`);
    })
}

const displayPagination = function(totalParkingLots) {
    const pagination = document.querySelector(".pagination");
    pagination.innerHTML = '';

    for (let i = 0; i < Math.ceil(totalParkingLots / parkingLotPerPage) && i < maxPage; i++) {
        const page = document.createElement("li");
        page.className = "page-item";

        const pageLink = document.createElement("div");


        pageLink.className = "page-link";
        pageLink.textContent = i + 1;
        pageLink.addEventListener("click", (e) => {
            if (!!currentPageElement) {
                currentPageElement.classList.remove('selected-page');
            }
            currentPageElement = e.target
            currentPageElement.classList.add("selected-page");


            const page = Number.parseInt(e.target.textContent) - 1;
            currentPage = page;

            window.scrollTo({ top: 0, behavior: 'smooth' });

            displayParkingLotCards(parkingLotInfo, page);
        })
        page.appendChild(pageLink);
        pagination.appendChild(page);
    }

    if (pagination.childNodes.length > 0) {
        pagination.childNodes.item(0).querySelector(".page-link").click();
    }
}

const displayParkingLotCards = function (parkingLots, page) {
    const parkingInfoElement = document.querySelector(".parking-info");
    parkingInfoElement.innerHTML = "";
    for (let i = page * parkingLotPerPage; i < page * parkingLotPerPage + parkingLotPerPage; i++) {
        let info = parkingLots[i];
        if (!!info) {
            const card = createParkingLotCard(info);
            parkingInfoElement.appendChild(card);
        }
    }

    if (!parkingInfoElement.innerHTML){
        parkingInfoElement.innerHTML = `
        <div>
            No parking lots found
        </div>
        `
    }
}

const updateParkingInfo = async function (data, vehicleType, id, lang) {
    const parkingLots = await requestParkingInfo(data, vehicleType, id, lang);
    currentPage = 0;
    displayPagination(parkingLotInfo.length);
    displayParkingLotCards(parkingLots, currentPage);
}



const selectVehicleTypes = document.querySelector('.search-box-vehicle-types');
const selectLanguage = document.querySelector('.search-box-languages');

const onFiltered = function(e){
    const value = selectVehicleTypes.value === "all" ? undefined : selectVehicleTypes.value;
    updateParkingInfo(undefined, value, undefined, selectLanguage.value).then(
        (res) =>{
            search(searchNameInput.value);
        }
    );
}

selectVehicleTypes.addEventListener("change", onFiltered);
selectLanguage.addEventListener("change", onFiltered);

const searchButton = document.querySelector('.search-btn');
const searchNameInput = document.querySelector('#addressOrName');
searchNameInput.addEventListener("keyup", (e) => {
    if(e.keyCode === 13){
        e.preventDefault();
        searchButton.click();
    }
});

searchNameInput.addEventListener('input', (e) => {
    search(searchNameInput.value);
});

searchButton.addEventListener("click", (e) => {
    search(searchNameInput.value);
});

const search = function(searchValue){
    if (!parkingLotInfo){
        return;
    }

    if (!searchValue) {
        currentPage = 0;
        displayPagination(parkingLotInfo.length);
        displayParkingLotCards(parkingLotInfo, currentPage);
        return;
    }

    const matches = [];
    for (let i = 0; i < parkingLotInfo.length; i++) {
        const name = parkingLotInfo[i].name.toLowerCase();
        const fullAddress = !!parkingLotInfo[i].address ? getFullAddress(parkingLotInfo[i].address): getFullAddress({});
        if (name.includes(searchValue.toLowerCase()) || fullAddress.includes(searchValue.toLowerCase())) {
            matches.push(parkingLotInfo[i]);
        }
    }

    currentPage = 0;
    displayPagination(matches.length);
    displayParkingLotCards(matches, currentPage);
}

const getFullAddress = function(address){
    let full = "";
    for(const k in address){
        full += address[k];
    }

    return full;
}


selectVehicleTypes.dispatchEvent(new Event('change'));


