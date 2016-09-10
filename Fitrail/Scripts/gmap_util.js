alert("HERE");

map.addEventListener(onclick, function (event) {
    var marker = new google.maps.Marker({
        position: event.latLng,
        map: map
    });
});