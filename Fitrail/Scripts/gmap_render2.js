

function InitializeMap() {
    var latlng = new google.maps.LatLng(35.133712, 33.388817);
    var myOptions = {
        zoom: 12,
        center: latlng,
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    var map = new google.maps.Map(document.getElementById("map"), myOptions);
    //map.data.loadGeoJson('/Scripts/route1.json');
    //data = JSON.parse('route1.json');
    //console.log(data.name);
    //alert("HERE");
    //var marker;// = new google.maps.Marker({
    //    position: latlng,
    //    map: map
    //});
   
}

//markersArray = [];
window.onload = InitializeMap;